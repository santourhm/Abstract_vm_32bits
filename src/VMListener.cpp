#include "VMListener.hpp"
#include "IInstruction.hpp"
#include "Memory_AddressOperand.hpp"
#include "WSTR.hpp"
#include "LOAD.hpp"
#include "STORE.hpp"
#include "WINT.hpp"
#include "WNL.hpp"
#include "ADD.hpp"
#include "MUL.hpp"
#include "NEW.hpp"
#include "OPP.hpp"
#include "REM.hpp"
#include "QUO.hpp"
#include "DIV.hpp"
#include "SUB.hpp"
#include "BRA.hpp"
#include "BSR.hpp"
#include "RTS.hpp"
#include "POP.hpp"
#include "LEA.hpp"
#include "PEA.hpp"
#include "PUSH.hpp"
#include "ERROR.hpp"
#include "RINT.hpp"
#include "RFLOAT.hpp"
#include "SUBSP.hpp"
#include "ADDSP.hpp"
#include "TSTO.hpp"
#include "Bcc/BEQ.hpp"
#include "Bcc/BNE.hpp"
#include "Bcc/BLT.hpp"
#include "Bcc/BGT.hpp"
#include "Bcc/BLE.hpp"
#include "Bcc/BGE.hpp"
#include "Bcc/BOV.hpp"
#include "Scc/SEQ.hpp"
#include "Scc/SNE.hpp"
#include "Scc/SLT.hpp"
#include "Scc/SGT.hpp"
#include "Scc/SLE.hpp"
#include "Scc/SOV.hpp"
#include "Scc/SHL.hpp"
#include "Scc/SHR.hpp"
#include "Scc/SGE.hpp"
#include "HALT.hpp"
#include "WFLOAT.hpp"
#include "WADDR.hpp"
#include <memory>
#include "StringLiteralOperand.hpp"
#include "LabelOperand.hpp"
#include "VMGrammarParser.h"
#include "Register.hpp"
#include "ImmediateOperand.hpp"
#include "RRegOperand.hpp"
#include "Value.hpp"
#include "machine/EnvRegisters.hpp"
#include "Label.hpp"
#include "CMP.hpp"

VMListener::VMListener(VMState * vms) : ProgATS(std::make_unique<Program>()), vms(vms), nb_intsructions(0) {}

std::unique_ptr<RRegOperand> static parseRm_Operand(VMGrammarParser::OperandContext *operand, VMState * vs) {
    if (!operand->register_()) {
        throw std::runtime_error(" expected Rm register operand");
    }

    std::string regText = operand->register_()->RREGISTER()->getText();
    int regIndex = -1;
    if (!regText.empty() && regText[0] == 'R') {
        try {
            regIndex = std::stoi(regText.substr(1));
        } catch (const std::exception &) {
            throw std::runtime_error(" invalid register number in " + regText);
        }
    } else {
        throw std::runtime_error(" invalid register format in " + regText);
    }

    Register *reg = vs->getEnv_Registers()->getR(regIndex);
    return std::make_unique<RRegOperand>(reg);
}

std::unique_ptr<ImmediateOperand> static parseImm_Operand(VMGrammarParser::OperandContext *operand, VMState * vs) {
    if (!operand->immediate()) {
        throw std::runtime_error(" expected immediate operand");
    }

    std::string imm = operand->immediate()->getText();
    Value v ;

    if(!imm.empty() && imm[0] == '#')
    {
        if(operand->immediate()->FLOAT())
        {
            float f =  std::stof(imm.substr(1));
            v = Value(f);
        }
        else if (operand->immediate()->INT())
        {
            int32_t i = std::stoi(imm.substr(1));
            v = Value(i);
        }
        else if (operand->immediate()->VALLNULL())
        {
            v = Value(Value::NullAddr());
        }
        else
        {
            throw std::runtime_error("Undefined type immediate type");
        }
    } 

    return std::make_unique<ImmediateOperand>(v);
}

std::unique_ptr<Memory_AddressOperand> static parseAddr_Operand(VMGrammarParser::OperandContext *operand, VMState * vs) {
    if (!operand->memory_address()) {
        throw std::runtime_error(" expected memory address operand");
    }
    
    int offset = 0;  
    Register * reg = nullptr;

    if (operand->memory_address()->INT()) {
        std::string offsetStr = operand->memory_address()->INT()->getText();
        
        if (operand->memory_address()->MINUS()) {
            offsetStr = "-" + offsetStr;
        }
        
        try {
            offset = std::stoi(offsetStr);
        } catch (const std::exception &) {
            throw std::runtime_error(" invalid offset in memory address");
        }
    }

    if (!operand->memory_address()->register_()) {
        throw std::runtime_error(" missing register in memory address");
    }

    if (operand->memory_address()->register_()->RREGISTER()) {
        int regIndex;
        std::string regText = operand->memory_address()->register_()->RREGISTER()->getText();  
        if (!regText.empty() && regText[0] == 'R') {
            try {
                regIndex = std::stoi(regText.substr(1));
            } catch (const std::exception &) {
                throw std::runtime_error(" invalid register number in " + regText);
            }
        } else {
            throw std::runtime_error(" invalid register format in " + regText);
        }
        reg = vs->getEnv_Registers()->getR(regIndex);
    }
    else if (operand->memory_address()->register_()->LBREGISTER()) {
        reg = vs->getEnv_Registers()->getLB();
    }
    else if (operand->memory_address()->register_()->GBREGISTER()) {
        reg = vs->getEnv_Registers()->getGB();
    }
    else if (operand->memory_address()->register_()->SPREGISTER()) {
        reg = vs->getEnv_Registers()->getSP();
    }
    else {
        throw std::runtime_error(" unknown register in memory address");
    }

    if (!reg) {
        throw std::runtime_error(" failed to get register");
    }

    return std::make_unique<Memory_AddressOperand>(offset, reg, vs->getMemory());
}

std::unique_ptr<LabelOperand> static parseLabel_Operand(VMGrammarParser::OperandContext *operand) {
    if (!operand->label() && ! !operand->label()->ID()) {
        throw std::runtime_error(" expected Label operand");
    }

    std::string label = operand->label()->ID()->getText();
    
    Value  v(label);

    return std::make_unique<LabelOperand>(v);
}


static std::variant<std::unique_ptr<RRegOperand>, std::unique_ptr<ImmediateOperand>,std::unique_ptr<Memory_AddressOperand>,std::unique_ptr<LabelOperand>> parseDval_Operand(VMGrammarParser::OperandContext *operand, VMState *vs) {
    if (operand->register_() && operand->register_()->RREGISTER()) 
    {
        return parseRm_Operand(operand, vs);
    } else if (operand->immediate()) 
    {
        return parseImm_Operand(operand, vs);
    } 
    else if (operand->memory_address()) 
    {
        return parseAddr_Operand(operand, vs);
    }
    else if (operand->label()) 
    {
        return parseLabel_Operand(operand);
    }
    else {
        throw std::runtime_error(" unsupported operand type");
    }
}



void VMListener::enterInstruction(VMGrammarParser::InstructionContext *ctx) 
{
    //std::cout << "Instruction " << ctx->getText() << '\n';

    auto ops = ctx->operand();
    size_t numOperands = ctx->operand().size();
    size_t line = ctx->getStart()->getLine();
    std::unique_ptr<IInstruction> inst; 

    auto opcodeCtx = ctx->opcode();
    
    try {
        if (opcodeCtx->WSTR()) 
        {
            if (numOperands != 1) 
                throw std::runtime_error(" WSTR needs exactly one operand");
            
            inst = std::make_unique<WSTR>();
            
        }
        else if (opcodeCtx->LOAD()) 
        {
            if (numOperands != 2) 
                throw std::runtime_error(" LOAD needs exactly 2 operands");
            
            inst = std::make_unique<LOAD>();
            createDval_RmInstruction(inst.get(),ops,line);

        }
        else if (opcodeCtx->LEA()) 
        {
            if (numOperands != 2) 
                throw std::runtime_error(" LEA needs exactly 2 operands");
            
            inst = std::make_unique<LEA>();
            inst->addOperand(parseAddr_Operand(ops[0],vms));
            inst->addOperand(parseRm_Operand(ops[1],vms));

        }
        else if (opcodeCtx->LEA()) 
        {
            if (numOperands != 1) 
                throw std::runtime_error(" PEA needs exactly 1 operand");
            
            inst = std::make_unique<PEA>();
            inst->addOperand(parseAddr_Operand(ops[0],vms));
        }
        else if (opcodeCtx->STORE()) 
        {
            if (numOperands != 2) 
                throw std::runtime_error(" LOAD needs exactly 2 operands");
            
            inst = std::make_unique<STORE>();

            inst->addOperand(parseRm_Operand(ops[0],vms));
            inst->addOperand(parseAddr_Operand(ops[1],vms));

        }
        else if (opcodeCtx->WINT()) 
        {
            if (numOperands != 0) 
                throw std::runtime_error(" WINT does not support operands");
            inst = std::make_unique<WINT>();
            
        }
        else if (opcodeCtx->WNL()) 
        {
            if (numOperands != 0) 
                throw std::runtime_error(" WNL does not support operands");
            inst = std::make_unique<WNL>();
            
        }
        else if (opcodeCtx->WFLOAT()) 
        {
            if (numOperands != 0) 
                throw std::runtime_error(" WINT does not support operands");
            inst = std::make_unique<WFLOAT>();
            
        }
        else if (opcodeCtx->WADDR()) 
        {
            if (numOperands != 1) 
                throw std::runtime_error(" WADDR does not support operands");
            inst = std::make_unique<WADDR>();
            inst->addOperand(parseRm_Operand(ops[0],vms));
            
        }
        else if(opcodeCtx->ADD())
        {
            if (numOperands != 2) 
                throw std::runtime_error(" ADD needs exactly 2 operands");
            inst = std::make_unique<ADD>();
            createDval_RmInstruction(inst.get(),ops,line);
        }
        else if(opcodeCtx->NEW())
        {
            if (numOperands != 2) 
                throw std::runtime_error(" NEW needs exactly 2 operands");
            inst = std::make_unique<NEW>();
            createDval_RmInstruction(inst.get(),ops,line);
        }
        else if(opcodeCtx->SUB())
        {
            if (numOperands != 2) 
                throw std::runtime_error(" SUB needs exactly 2 operands");
            inst = std::make_unique<SUB>();
            createDval_RmInstruction(inst.get(),ops,line);
        }
        else if(opcodeCtx->QUO())
        {
            if (numOperands != 2) 
                throw std::runtime_error(" QUO needs exactly 2 operands");
            inst = std::make_unique<QUO>();
            createDval_RmInstruction(inst.get(),ops,line);
        }
        else if(opcodeCtx->DIV())
        {
            if (numOperands != 2) 
                throw std::runtime_error(" DIV needs exactly 2 operands");
            inst = std::make_unique<DIV>();
            createDval_RmInstruction(inst.get(),ops,line);
        }
        else if(opcodeCtx->OPP())
        {
            if (numOperands != 2) 
                throw std::runtime_error(" OPP needs exactly 2 operands");
            inst = std::make_unique<OPP>();
            createDval_RmInstruction(inst.get(),ops,line);
        }
        else if(opcodeCtx->REM())
        {
            if (numOperands != 2) 
                throw std::runtime_error(" REM needs exactly 2 operands");
            inst = std::make_unique<REM>();
            createDval_RmInstruction(inst.get(),ops,line);
        }
        else if(opcodeCtx->MUL())
        {
            if (numOperands != 2) 
                throw std::runtime_error(" MUL needs exactly 2 operands");
            inst = std::make_unique<MUL>();
            createDval_RmInstruction(inst.get(),ops,line);
        }
        else if(opcodeCtx->HALT())
        {
            if (numOperands != 0) 
                throw std::runtime_error(" HALT works without operands");
            inst = std::make_unique<HALT>();
        }
        else if(opcodeCtx->BRA())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" BRA needs exactly 1 label operand");

            inst = std::make_unique<BRA>();
            inst->addOperand(parseLabel_Operand(ops[0]));
        }
        else if(opcodeCtx->CMP())
        {
            if (numOperands != 2) 
                throw std::runtime_error(" CMP needs exactly 2 operands");

            inst = std::make_unique<CMP>();
            createDval_RmInstruction(inst.get(),ops,line);
        }
        else if(opcodeCtx->BEQ())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" BEQ needs exactly 1 operands");

            inst = std::make_unique<BEQ>();
            inst->addOperand(parseLabel_Operand(ops[0]));
        }
        else if(opcodeCtx->BGT())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" BGT needs exactly 1 operands");

            inst = std::make_unique<BGT>();
            inst->addOperand(parseLabel_Operand(ops[0]));
        }
        else if(opcodeCtx->BGE())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" BGE needs exactly 1 operands");

            inst = std::make_unique<BGE>();
            inst->addOperand(parseLabel_Operand(ops[0]));
        }
        else if(opcodeCtx->BLE())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" BLE needs exactly 1 operands");

            inst = std::make_unique<BLE>();
            inst->addOperand(parseLabel_Operand(ops[0]));
        }
        else if(opcodeCtx->BLT())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" BLT needs exactly 1 operands");

            inst = std::make_unique<BLT>();
            inst->addOperand(parseLabel_Operand(ops[0]));
        }
        else if(opcodeCtx->BNE())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" BNE needs exactly 1 operands");

            inst = std::make_unique<BNE>();
            inst->addOperand(parseLabel_Operand(ops[0]));
        }
        else if(opcodeCtx->BOV())
        {
            if (numOperands != 1)
            { 
                throw std::runtime_error(" BOV needs exactly 1 operands");
                return;
            }

            inst = std::make_unique<BOV>();
            inst->addOperand(parseLabel_Operand(ops[0]));
        }

        else if(opcodeCtx->SEQ())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" SEQ needs exactly 1 operands");

            inst = std::make_unique<SEQ>();
            inst->addOperand(parseRm_Operand(ops[0],vms));
        }
        else if(opcodeCtx->SGT())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" SGT needs exactly 1 operands");

            inst = std::make_unique<SGT>();
            inst->addOperand(parseRm_Operand(ops[0],vms));
        }
        else if(opcodeCtx->SLE())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" SLE needs exactly 1 operands");

            inst = std::make_unique<SLE>();
            inst->addOperand(parseRm_Operand(ops[0],vms));
        }
        else if(opcodeCtx->SLT())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" SLT needs exactly 1 operands");

            inst = std::make_unique<SLT>();
            inst->addOperand(parseRm_Operand(ops[0],vms));
        }
        else if(opcodeCtx->SNE())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" SNE needs exactly 1 operands");

            inst = std::make_unique<SNE>();
            inst->addOperand(parseRm_Operand(ops[0],vms));
        }
        else if(opcodeCtx->SGE())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" SGE needs exactly 1 operands");

            inst = std::make_unique<SGE>();
            inst->addOperand(parseRm_Operand(ops[0],vms));
        }
        else if(opcodeCtx->SOV())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" SOV needs exactly 1 operands");

            inst = std::make_unique<SOV>();
            inst->addOperand((parseRm_Operand(ops[0],vms)));
        }
        else if(opcodeCtx->SHL())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" SHL needs exactly 1 operands");

            inst = std::make_unique<SHL>();
            inst->addOperand((parseRm_Operand(ops[0],vms)));
        }
        else if(opcodeCtx->SHR())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" SHR needs exactly 1 operands");

            inst = std::make_unique<SHR>();
            inst->addOperand((parseRm_Operand(ops[0],vms)));
        }
        else if(opcodeCtx->POP())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" POP needs exactly 1 operands");

            inst = std::make_unique<POP>();
            inst->addOperand((parseRm_Operand(ops[0],vms)));
        }
        else if(opcodeCtx->PUSH())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" PUSH needs exactly 1 operands");

            inst = std::make_unique<PUSH>();
            inst->addOperand((parseRm_Operand(ops[0],vms)));
        }
        else if(opcodeCtx->BSR())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" BSR needs exactly 1 operands");

            inst = std::make_unique<BSR>();

            auto operand1 = parseDval_Operand(ops[0], vms);
    
            std::visit([&inst](auto &&op) {
                inst->addOperand(std::move(op));
            }, operand1);

        }
        else if(opcodeCtx->RTS())
        {
            if (numOperands != 0) 
                throw std::runtime_error(" BSR needs exactly 0 operands");

            inst = std::make_unique<RTS>();
        }
        else if(opcodeCtx->SUBSP())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" SUBSP needs exactly 1 operand");

            inst = std::make_unique<SUBSP>();
            inst->addOperand((parseImm_Operand(ops[0],vms)));
        }
        else if(opcodeCtx->ADDSP())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" SUBSP needs exactly 1 operand");

            inst = std::make_unique<ADDSP>();
            inst->addOperand((parseImm_Operand(ops[0],vms)));
        }
        else if(opcodeCtx->TSTO())
        {
            if (numOperands != 1) 
                throw std::runtime_error(" TSTO needs exactly 1 operand");

            inst = std::make_unique<TSTO>();
            inst->addOperand((parseImm_Operand(ops[0],vms)));
        }
        else if(opcodeCtx->RINT())
        {
            if (numOperands != 0) 
                throw std::runtime_error(" RINT needs exactly 0 operand");

            inst = std::make_unique<RINT>();
        }
        else if(opcodeCtx->RFLOAT())
        {
            if (numOperands != 0) 
                throw std::runtime_error(" RFLOAT needs exactly 0 operand");

            inst = std::make_unique<RFLOAT>();
        }
        else if(opcodeCtx->ERROR())
        {
            if (numOperands != 0) 
                throw std::runtime_error(" ERROR needs exactly 0 operand");

            inst = std::make_unique<ERROR>();
        }
        else
        {
            throw std::runtime_error(" Unknown instruction");
        }
    } 
    catch (const std::runtime_error &e) {
        std::cerr << "Semantic Error on line " 
                  << ctx->getStart()->getLine() 
                  << ": " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    
    TmpInst.push_back(std::move(inst));
    nb_intsructions++;
}

void VMListener::enterOpcode(VMGrammarParser::OpcodeContext * ctx)
{
    // std::cout << "Opcode  " << ctx->getText() << '\n';
    
}


void VMListener::enterString_literal(VMGrammarParser::String_literalContext * ctx)
{

    if(ctx->STRING_LITERAL())
    {
        std::string text = ctx->STRING_LITERAL()->getText();

        if (!text.empty() && text.front() == '"' && text.back() == '"') {
            text = text.substr(1, text.size() - 2);
        }

        std::string unescaped;
        for (size_t i = 0; i < text.size(); ++i) 
        {
            if (text[i] == '\\' && i + 1 < text.size()) 
            {
                i++;
                switch (text[i]) {
                    case 'n': unescaped += '\n'; break;
                    case 't': unescaped += '\t'; break;
                    case '\\': unescaped += '\\'; break;
                    case '"': unescaped += '"'; break;
                    default: unescaped += text[i]; break;
                }
            } else
            {
                unescaped += text[i];
            }
        }
        
        IInstruction* lastInstruction = TmpInst.back().get();
        lastInstruction->addOperand(
            std::make_unique<StringLiteralOperand>(unescaped)
        );
    }
}


void VMListener::enterLabel_definition(VMGrammarParser::Label_definitionContext * ctx)
{

    // std::cout << "enterLabel_definition " << label << '\n';
    
    std::unique_ptr<IInstruction> inst; 
    std::string label = ctx->getText();

    if (!label.empty() && label.back() == ':') {
        label = label.substr(0, label.size() - 1);  
    }
    else{
        throw std::runtime_error(" unsupported label definition"); 
    }
    
    uint32_t address = static_cast<uint32_t>(nb_intsructions);
    
    Value v(address);
                                                                                 
    vms->getSymbol_Table()[label] = v++;

    inst = std::make_unique<Label>();

    inst->addOperand(std::make_unique<LabelOperand>(v));

    TmpInst.push_back(std::move(inst));
 
    nb_intsructions++;
}

void VMListener::finalizeProgram() 
{
    ProgATS->setInstructions(std::move(TmpInst));
}

void VMListener::enterOperand(VMGrammarParser::OperandContext * ctx)
{

}


void VMListener::enterMemory_address(VMGrammarParser::Memory_addressContext * ctx)
{
   // std::cout << "Memory_address  " << ctx->getText() << '\n';
}


void VMListener::enterImmediate(VMGrammarParser::ImmediateContext * ctx)
{
    // std::cout << "Immediate  " << ctx->getText() << '\n';
}


void VMListener::enterLabel(VMGrammarParser::LabelContext * ctx)
{
    // std::cout << "Label  " << ctx->getText() << '\n';
}

void VMListener::visitErrorNode(antlr4::tree::ErrorNode *node) {
    std::cerr << "Semantic Error " 
                  << node->getText() << std::endl;
    exit(EXIT_FAILURE);
}

// void VMListener::exitInvalid_opcode(VMGrammarParser::Invalid_opcodeContext *ctx) {
//     std::cerr << "Semantic Error: unknown opcode '" 
//               << ctx->getText() << "' at line "
//               << ctx->start->getLine() << std::endl;
//     exit(EXIT_FAILURE);
// }



// OPCODE dval, Rm

void VMListener::createDval_RmInstruction(IInstruction * inst ,const std::vector<VMGrammarParser::OperandContext *> &operands, size_t line) 
{
    if (operands.size() != 2) {
        throw std::runtime_error(" Instruction requires exactly 2 operands");
    }
    
    auto operand1 = parseDval_Operand(operands[0], vms);
    

    std::visit([&inst](auto &&op) {
        inst->addOperand(std::move(op));
    }, operand1);

    inst->addOperand(parseRm_Operand(operands[1],vms));
}







