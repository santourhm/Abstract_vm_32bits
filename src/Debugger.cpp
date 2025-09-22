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
                uint32_t addr = PC->read().getAddr();
                
                if(size <= addr )
                {                       
                        std::cout << " End of program !" << std::endl;
                        break;
                }

                if (isBreakpoint(addr)) 
                {
                        std::cout << "Hit breakpoint at 0x" << std::hex << addr << std::endl;
                        break; 
                }

                instructions[addr]->execute(vms);

                if (!vms->not_halt) break;

                Value v = PC->read();
                v++;
                PC->write(v);
        }
}



void Debugger::execute_OneInstruction(VMState* vms)
{
        auto regs = vms->getEnv_Registers();
        Register* PC = regs->getPC();

        uint32_t addr = PC->read().getAddr();
        instructions[addr]->execute(vms);

        if (!vms->not_halt) return;

        Value v = PC->read();
        v++;
        PC->write(v);
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


void Debugger::write_Pointer(Value value)
{
        if(ptrOp == nullptr)
            throw std::runtime_error("null ptr, you need to point on a somthing");
        
        ptrOp->write(value);
}


void Debugger::deleteBreakpoint(uint32_t addr)
{
    if (addr >= size) throw std::runtime_error("Breakpoint out of range");
    bkpt[addr] = false;
}


void Debugger::clearBreakpoints()
{
    std::fill(bkpt.begin(), bkpt.end(), false);
}


std::vector<uint32_t> Debugger::getBreakpoints() const
{
    std::vector<uint32_t> list;
    for (uint32_t i = 0; i < bkpt.size(); ++i) {
        if (bkpt[i]) list.push_back(i);
    }
    return list;
}


bool Debugger::isBreakpoint(uint32_t addr) const
{
    if (addr >= size) return false;
    return bkpt[addr];
}