#include "LEA.hpp"
#include "Memory_AddressOperand.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include "Value.hpp"



void LEA::execute(VMState * vms)
{
    
    (VMState*)vms;

    try
    {
        if (operands.size() < 2) {
            throw std::runtime_error(" : LEA requires 2 operands but got " + std::to_string(operands.size()));
            return;
        }

         IOperand * base = operands[0].get();

        Memory_AddressOperand* Memory_Op = dynamic_cast<Memory_AddressOperand*>(base);

        if(Memory_Op == nullptr)
        {
            throw std::runtime_error(" : LEA requires a Meomery address left operand" );
            return;
        }

        auto& dst = operands[1];
          
        Value srcValue(Memory_Op->getAddress());
      

        dst.get()->write(srcValue);
        
        


    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Error" << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
    

}

void LEA::debug(VMState * vms)
{
    std::cout << "LEA    " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}

