#include "NEW.hpp"
#include "ImmediateOperand.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include "Value.hpp"
#include "Memory.hpp"


void NEW::execute(VMState * vms)
{
    

    try
    {
        if (operands.size() < 2) {
            throw std::runtime_error(" : NEW requires 2 operands but got " + std::to_string(operands.size()));
            return;
        }

        auto& src = operands[0];
        auto& dst = operands[1];

        Value srcValue = src.get()->read();
        Value dstValue = dst.get()->read();
        uint32_t   neededSize;
        
        if(srcValue.getType() == TypeTag::INTEGER)
        {
            neededSize = static_cast<uint32_t>(srcValue.getInt());
        }
        else if(srcValue.getType() == TypeTag::ADDRESS)
        {
            neededSize = srcValue.getAddr();
        }
        else
        {
            std::runtime_error(" NEW unknown given type " + srcValue.get_str_type());
        }

        uint32_t allocated =  vms->getMemory()->allocate(neededSize);

        dst.get()->write(Value(allocated));

    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Error" << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
    

}

void NEW::debug(VMState * vms)
{
    std::cout << "NEW    " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}



