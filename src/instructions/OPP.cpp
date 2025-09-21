#include "IInstruction.hpp"
#include "OPP.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include "Op_Results.hpp"


void OPP::execute(VMState * vms) 
{
    try
    {
        if (operands.size() < 2) {
            throw std::runtime_error(" : MUL requires 2 operands but got " + std::to_string(operands.size()));
            return;
        }

        auto& src = operands[0];
        auto& dst = operands[1];

        Value srcValue = src.get()->read();

        Op_Results results = srcValue*Value(-1) ;

        dst.get()->write(results.val);

        vms->set_sCC(results.cc);

    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Error" << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
}



void OPP::debug(VMState * vms)
{
    std::cout << "OPP    " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}
