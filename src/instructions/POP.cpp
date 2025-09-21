#include "IInstruction.hpp"
#include "POP.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include <stdexcept>
#include "RRegOperand.hpp"
#include "EnvRegisters.hpp"
#include <unordered_map>
#include "Memory.hpp"
#include "Op_Results.hpp"

void POP::execute(VMState * vms) 
{

    try
    {
        if (operands.size() != 1 ) {
            throw std::runtime_error(" : POP requires 1 operand but got " + std::to_string(operands.size()));
        }

        IOperand * base = operands[0].get();
        
        RRegOperand* reg = dynamic_cast<RRegOperand*>(base);

        if(reg == nullptr)
        {
            throw std::runtime_error(" : POP requires a Rm Operand" );
            return;
        }

        reg->getRegister()->write(vms->getMemory()->pop());
        
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Error" << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
    
}

void POP::debug(VMState * vms)
{
    std::cout << "POP    " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}


