#ifndef DEBUGGER_HPP
#define DEBUGGER_HPP

#include <vector>
#include "VMState.hpp"
#include "Program.hpp"
#include "Register.hpp"
#include "Memory_AddressOperand.hpp"



class Debugger
{
        size_t size;
        const std::vector<std::unique_ptr<IInstruction>>& instructions;  
        std::vector<bool> bkpt;
        std::unordered_map<std::string, Register*> pointer_OnReg;
        IOperand* ptrOp ;  
        std::unique_ptr<Memory_AddressOperand> memOp;
        
    public:

        Debugger(VMState * vms,const std::vector<std::unique_ptr<IInstruction>>& inst);
        ~Debugger() = default;


        void  execute(VMState * vms);
        void  execute_OneInstruction(VMState * vms);

        void  setBreakpoint(uint32_t  bkpt);

        void deleteBreakpoint(uint32_t addr);

        void clearBreakpoints();
        void  setReg_Pointer(std::string str_addr);
        std::vector<uint32_t> getBreakpoints() const;
        bool  isBreakpoint(uint32_t addr) const;
        void  setMemOP_Pointer(std::unique_ptr<Memory_AddressOperand> memOp);
        Value read_Pointer() const;
        void  write_Pointer(Value value);
};



                                                                          

#endif
