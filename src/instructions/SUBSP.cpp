#include "SUBSP.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include "Op_Results.hpp"
#include "EnvRegisters.hpp"

void SUBSP::execute(VMState * vms) 
{
    try
    {
        if (operands.size() != 1) 
        {
            throw std::runtime_error(" : SUBSP requires 1 immediate operand but got " + std::to_string(operands.size()));
            return;
        }

        auto& src = operands[0];

        Value srcValue = src.get()->read();
        
        if(srcValue.getType() != TypeTag::INTEGER)
        {
            throw std::runtime_error(" SUBSP : you cannot pass a float type");
            return;
        }
        
        //Value Next_SP = Value(static_cast<uint32_t>(vms->getEnv_Registers()->getSP()->read().getAddr() - srcValue.getInt()));
        
        Op_Results Next_SP =   vms->getEnv_Registers()->getSP()->read() - srcValue;
        
        if(Next_SP.cc.NG)
        {
            throw std::runtime_error(" : Negative stack pointer  ");
            return;
        }

        vms->getEnv_Registers()->getSP()->write(Next_SP.val);

    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Error" << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
}

void SUBSP::debug(VMState * vms)
{
    std::cout << "SUBSP  " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}
