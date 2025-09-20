#include "IInstruction.hpp"
#include "BSR.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include <stdexcept>
#include "LabelOperand.hpp"
#include "Memory_AddressOperand.hpp"
#include "EnvRegisters.hpp"
#include <unordered_map>
#include "Memory.hpp"
#include "Op_Results.hpp"
#include <iostream>

void BSR::execute(VMState * vms) 
{
    try {
        if (operands.size() != 1) {
            throw std::runtime_error("BSR requires 1 operand but got " 
                                     + std::to_string(operands.size()));
        }

        Value addr;

        IOperand * base = operands[0].get();
        LabelOperand* label = dynamic_cast<LabelOperand*>(base);
        Memory_AddressOperand* Memory_Op = dynamic_cast<Memory_AddressOperand*>(base);
        if(label != nullptr || Memory_Op!= nullptr) {

            std::string label_str ;
            if(label)
                label_str = label->read().getStr();
            else if(Memory_Op)
                label_str = Memory_Op->read().getStr();
            else
            {
                throw std::runtime_error("Error : unkown label operand");
            }
            std::unordered_map<std::string, Value>& Symbol_Table = vms->getSymbol_Table();

            if (Symbol_Table.find(label_str) == Symbol_Table.end()) 
            {
                throw std::runtime_error("Undefined label '" + label_str + "'");
                return;
            }
            addr = Symbol_Table.at(label_str);
            //std::cout << "LABEL Addr : " << addr.getAddr() << std::endl;
        }
        else 
        {
            throw std::runtime_error("Error : unkown label operand");
        }

        Register * PC = vms->getEnv_Registers()->getPC();
        Register * SP = vms->getEnv_Registers()->getSP();
        Register * LB = vms->getEnv_Registers()->getLB();
        Memory * mem  = vms->getMemory();

        Value V_SP = SP->read();
        uint32_t V_LB = LB->read().getAddr();
        Value V_PC    = PC->read();

        V_SP++;
        V_SP++;

        SP->write(V_SP);

        mem->setWord(V_SP.getAddr() - 1, V_PC);

        mem->setWord(V_SP.getAddr(), Value(V_LB));

        LB->write(V_SP);

        PC->write(addr);

    }
    catch(const std::runtime_error& e) {
        std::cerr << "Error at " << __FILE__ << ":" << __LINE__ 
                  << " " << e.what() << '\n';
    }
}


void BSR::debug(VMState * vms)
{
    std::cout << "BSR    " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}


