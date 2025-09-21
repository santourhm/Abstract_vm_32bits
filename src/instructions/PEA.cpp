#include "PEA.hpp"
#include "Memory_AddressOperand.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include "Value.hpp"
#include "EnvRegisters.hpp"
#include "Memory.hpp"

void PEA::execute(VMState * vms)
{
    
    (VMState*)vms;

    try
    {
        if (operands.size() != 1) {
            throw std::runtime_error(" : PEA requires 1 operand but got " + std::to_string(operands.size()));
            return;
        }

        Register * SP = vms->getEnv_Registers()->getSP();
        uint32_t   V_SP  = SP->read().getAddr();
        IOperand * base = operands[0].get();

        Memory_AddressOperand* Memory_Op = dynamic_cast<Memory_AddressOperand*>(base);

        if(Memory_Op == nullptr)
        {
            throw std::runtime_error(" : LEA requires a Meomery address left operand" );
            return;
        }

        Value srcValue(Memory_Op->getAddress());

        uint32_t newSP = V_SP + 1;
        SP->write(Value(newSP));

        vms->getMemory()->setWord(newSP, srcValue);


    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Error : " << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
    

}

void PEA::debug(VMState * vms)
{
    std::cout << "PEA    " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}


