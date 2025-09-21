#include "ADD.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include <stdexcept>

#include "Op_Results.hpp"

void ADD::execute(VMState * vms) 
{

    try
    {
        auto& src = operands[0];
        auto& dst = operands[1];

        Value srcValue = src.get()->read();
        Value dstValue = dst.get()->read();

        Op_Results results = srcValue + dstValue ;

        dst.get()->write(results.val);

        vms->set_sCC(results.cc);

    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Error" << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
    
    
}

void ADD::debug(VMState * vms)
{
    std::cout << "ADD    " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}


