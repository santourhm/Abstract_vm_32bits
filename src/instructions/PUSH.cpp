#include "IInstruction.hpp"
#include "PUSH.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include <stdexcept>
#include "RRegOperand.hpp"
#include "EnvRegisters.hpp"
#include <unordered_map>
#include "Memory.hpp"
#include "Op_Results.hpp"

void PUSH::execute(VMState * vms) 
{

    try
    {
        if (operands.size() != 1 ) {
            throw std::runtime_error(" : PUSH requires 1 operand but got " + std::to_string(operands.size()));
        }

        IOperand * base = operands[0].get();
        
        RRegOperand* reg = dynamic_cast<RRegOperand*>(base);

        if(reg == nullptr)
        {
            throw std::runtime_error(" : PUSH requires a Rm Operand" );
            return;
        }

        vms->getMemory()->push(reg->read());
        
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Error" << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
    
}

void PUSH::debug(VMState * vms)
{
    std::cout << "PUSH   " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}

