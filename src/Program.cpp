#include "Program.hpp"
#include <iostream>
#include "Register.hpp"
#include "EnvRegisters.hpp"
#include "Op_Results.hpp"
#include "Debugger.hpp"
#include <cctype>

extern bool ishalt_program;
extern bool debug_mode;

void    Program::addIntruction(std::unique_ptr<IInstruction> inst)
{
        this->instructions.push_back(std::move(inst));
        numberOfInstructions++;
}

int     Program::getNumberofInstructions(void)
{
        return this->numberOfInstructions;
}

const   std::vector<std::unique_ptr<IInstruction>>& Program::getInstructions() const 
{
        return instructions;
}

void    Program::setInstructions(std::vector<std::unique_ptr<IInstruction>>&& instrs)
{
        numberOfInstructions = instrs.size();
        instructions = std::move(instrs);
}

void Program::verifyProgram(void)
{
//      for(auto& ins : instructions)
//      {
//         if(ins)
//      }
}


void Program::executeProgram(VMState* vms)
{

        int i = 0;
        EnvRegisters * envReg = vms->getEnv_Registers();
        Register * PC =  envReg->getPC();
        Register * SP  = envReg->getSP();

        uint32_t   pc = 0x0;
        PC->write(Value(pc));
        int size = instructions.size();
        
        while(vms->not_halt)
        {                 
        

                instructions[PC->read().getAddr()]->execute(vms);

                if(!vms->not_halt)
                {       
                        break;
                }
                                          
                Value V_PC = PC->read();
                V_PC++;
 
                if(size <= V_PC.getAddr() )
                {
                        
                        throw std::runtime_error(" : PC register is out of program code region");
                        break;
                }

                PC->write(V_PC); 
        }

}


static std::vector<std::string> split_whitespace(const std::string& cmd) 
{
    std::istringstream iss(cmd);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {   
        tokens.push_back(token);
    }

    return tokens;
}


static std::unique_ptr<Memory_AddressOperand> parse_MemoryOp(const std::string& op, VMState* vms)
{
    Register* reg;

    size_t posParen = op.find('(');

    if (posParen == std::string::npos || op.back() != ')') throw std::runtime_error("Error : invalid input address!");
    

    
    std::string offStr = op.substr(0, posParen);
    if (offStr.empty()) throw std::runtime_error("Error : no offset detected!");
    

    int offset;
    try {
        offset = std::stoi(offStr); 
    } catch (...) {
        throw std::runtime_error("Error : invalid offset!");
    }

    
    std::string str_reg = op.substr(posParen + 1, op.size() - posParen - 2);

    if (str_reg[0] == 'R' && std::isdigit(str_reg[1])) 
    {
        int regNumber = std::stoi(str_reg.substr(1));

        if (regNumber < 0 || regNumber > 15)  throw std::runtime_error("Error : invalid register number!");
        
        reg = vms->getEnv_Registers()->getR(regNumber);
    }
    else if (str_reg == "GB") 
    {
        reg = vms->getEnv_Registers()->getGB();
    }
    else if (str_reg == "LB") 
    {
        reg = vms->getEnv_Registers()->getLB();
    }
    else if (str_reg == "SP") 
    {
        reg = vms->getEnv_Registers()->getSP();
    }
    else if (str_reg == "PC") 
    {
        reg = vms->getEnv_Registers()->getPC();
    }
    else 
    {
        throw std::runtime_error("Error : unknown register!");
    }

    return std::make_unique<Memory_AddressOperand>(offset, reg, vms->getMemory());
}


void  Program::debugProgram(VMState* vms)
{
        int i = 0;
        EnvRegisters * envReg = vms->getEnv_Registers();
        Register * PC =  envReg->getPC();
        Register * SP  = envReg->getSP();

        uint32_t   pc = 0x0;
        PC->write(Value(pc));
        int size = instructions.size();
        Value V_PC = PC->read();

        for (const auto& [key, value] : vms->getSymbol_Table()) {
                std::cout << key << " : " << value << '\n';
        }
        
        Debugger debug(vms,instructions);

            std::cout << R"(
                __      __       .__                                  ________               
                /  \    /  \ ____ |  |   ____  ____   _____   ____    \_____  \___  __ ____  
                \   \/\/   // __ \|  |  /  _ \/    \ /     \_/ __ \    /   |   \  \/ // __ \ 
                \        /\  ___/|  |_(  <_> )   |  \  Y Y  \  ___/   /    |    \   /\  ___/ 
                \__/\  /  \___  >____/\____/|___|  /__|_|  /\___  >  \_______  /\_/  \___  >
                        \/       \/                 \/      \/     \/           \/          \/ 
                        ---- AVM Debugger ----
                )" << std::endl;

        while (vms->not_halt)
        {       
                std::cout << "-----> " ;
                
                Value V_PC = PC->read();
                instructions[V_PC.getAddr()]->debug(vms);
                std::cout << std::endl ;

                std::cout << "$ avm-dbg >> " ;
                std::string cmd ;
                
                std::getline(std::cin,cmd);

                if(cmd == "s" || cmd == "step")
                {

                        std::cout <<  std::endl;
                        debug.execute_OneInstruction(vms);

                }
                else if(cmd == "c" || cmd == "continue")
                {
                        
                        std::cout <<  std::endl;
                        debug.execute(vms);

                }
                else if (cmd.rfind("p", 0) == 0)  
                {
                        auto tokens = split_whitespace(cmd);
                        size_t s = tokens.size() ;
                        if(s == 2 && tokens[1].size() == 2) // reg
                        {
                                std::string reg = tokens[1] ;  
                                

                                try {
                                        debug.setReg_Pointer(reg);
                                        std::cout << "pointing on : " << reg << std::endl;

                                }
                                catch (const std::runtime_error& e) {
                                        std::cerr << e.what() << std::endl;
                                }
                        }    
                        if(s == 2 && (tokens[1].size() == 5 || (tokens[1].size() == 6 && tokens[1][0] == '-')) ) // mem
                        {
                                std::string mem = tokens[1] ;  
                                
                                try {
                                        debug.setMemOP_Pointer(parse_MemoryOp(mem,vms));
                                        std::cout << "pointing on : " << mem << std::endl;
                                }
                                catch (const std::runtime_error& e) {
                                        std::cerr << e.what() << std::endl;
                                }
                        }
                        else if (s > 2)
                        {
                                std::cerr << "unknown p arguement" << std::endl;
                        }
                        else 
                        {
                                 std::cerr << "ignoring ... " << std::endl;
                                continue;
                        }
                }                           
                else if(cmd == "r" || cmd == "read")
                {
                        try
                        {  
                                Value val =  debug.read_Pointer() ;

                                std::cout << "Value = " << val << std::endl;

                        }
                        catch(const std::runtime_error& e)
                        {
                                std::cerr << e.what() << std::endl;
                        }
                        
                }
                else if(cmd == "w" || cmd == "write")
                {
                        try
                        {  
                                Value val =  debug.read_Pointer() ;
                                
                                std::cout << "Value = " << val << std::endl;

                        }
                        catch(const std::runtime_error& e)
                        {
                                std::cerr << e.what() << std::endl;
                        }
                        
                }
                else if(cmd.rfind("sw",0) == 0 || cmd.rfind("show",0) == 0)
                {
                        try 
                        {
                           uint32_t addr = std::stoul(cmd.substr(2), nullptr, 0); 
                           std::cout << "Instruction at 0x" << std::hex << addr ;
                           std::cout << "  :" ;
                           instructions[addr].get()->debug(vms);

                        } catch (...) 
                        {
                                std::cerr << "Invalid address." << std::endl;
                        }
                        
                }
                else if(cmd.rfind("b",0) == 0)
                {
                        try 
                        {
                           uint32_t addr = std::stoul(cmd.substr(2), nullptr, 0); 
                           debug.setBreakpoint(addr);
                           std::cout << "Breakpoint set at 0x" << std::hex << addr << std::endl;

                        } catch (...) 
                        {
                                std::cerr << "Invalid address." << std::endl;
                        }
                }
                else if(split_whitespace(cmd).size() == 0) 
                {
                    continue;
                }
                else 
                {
                    std::cerr << "Error : invalid input" << std::endl;
                }

                std::cout << std::endl ;

        }
        
        
        
}