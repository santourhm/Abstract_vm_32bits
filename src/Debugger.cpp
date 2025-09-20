#include "Debugger.hpp"
#include <stdexcept>
#include "EnvRegisters.hpp"
#include "Value.hpp"
#include <iostream>


Debugger::Debugger(VMState * vms, const std::vector<std::unique_ptr<IInstruction>>& inst)
    : size(inst.size()), instructions(inst), bkpt(size, false), ptrOp(nullptr)
{
    EnvRegisters* env = vms->getEnv_Registers();

  
    for (size_t s = 0; s <= 15; s++) {
        pointer_OnReg.insert({ "R" + std::to_string(s), env->getR(s) });
    }

    
    pointer_OnReg.insert({ "SP", env->getSP() });
    pointer_OnReg.insert({ "GB", env->getGB() });
    pointer_OnReg.insert({ "LB", env->getLB() });
    pointer_OnReg.insert({ "PC", env->getPC() });
}

void Debugger::setBreakpoint(uint32_t  a_bkpt)
{

    if(a_bkpt >= size)
        throw std::out_of_range("");
    
    bkpt[a_bkpt] = true;
}

void  Debugger::execute(VMState * vms)
{
        EnvRegisters * envReg = vms->getEnv_Registers();
        Register * PC =  envReg->getPC();
        Register * SP  = envReg->getSP();

        while (true)
        {
                Value V_PC = PC->read();
                
                if(size <= V_PC.getAddr() )
                {                       
                        std::cout << " End of program !" << std::endl;
                        break;
                }


                if(bkpt[V_PC.getAddr()])
                {
                    std::cout << "Breakpoint done at : 0x" << std::hex << V_PC.getAddr() << std::endl;
                    break;
                }

                instructions[V_PC.getAddr()]->execute(vms);

                V_PC++;

                PC->write(V_PC); 
        }
}



void  Debugger::execute_OneInstruction(VMState * vms)
{
        EnvRegisters * envReg = vms->getEnv_Registers();
        Register * PC =  envReg->getPC();

        Value V_PC = PC->read();
                
        if(size <= V_PC.getAddr() )
        {                       
                std::cout << " End of program !" << std::endl;
                return;
        }
        
        instructions[V_PC.getAddr()]->execute(vms);

        V_PC = PC->read();

        V_PC++;
        
        PC->write(V_PC); 
}


void Debugger::setReg_Pointer(std::string str_addr)
{
    if (pointer_OnReg.find(str_addr) == pointer_OnReg.end()) 
    {
        throw std::runtime_error("register name is invalid");
    }

    Register* reg = pointer_OnReg.at(str_addr);
    this->ptrOp = reg;  
}

void Debugger::setMemOP_Pointer(std::unique_ptr<Memory_AddressOperand> memOp) 
{
    this->memOp = std::move(memOp); 
    this->ptrOp = this->memOp.get(); 
}



Value Debugger::read_Pointer() const
{
        if(ptrOp == nullptr )
            throw std::runtime_error("null ptr, you need to point on a somthing");
        return ptrOp->read();
}


void Debugger::write_Pointer(uint32_t value)
{
        if(ptrOp == nullptr)
            throw std::runtime_error("null ptr, you need to point on a somthing");
        
        ptrOp->write(Value(value));
}