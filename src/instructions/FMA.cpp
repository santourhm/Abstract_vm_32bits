#include "FMA.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include <stdexcept>
#include "Register.hpp"
#include "EnvRegisters.hpp"
#include "Op_Results.hpp"

void FMA::execute(VMState * vms) 
{

    try
    {
        auto& src = operands[0];
        auto& dst = operands[1];

        Register * R1 = vms->getEnv_Registers()->getR(1);

        Value srcValue = src.get()->read();
        Value dstValue = dst.get()->read();

        Op_Results results = srcValue*dstValue ;

        vms->set_sCC(results.cc);

        results = results.val  +  R1->read() ;

        dst.get()->write(results.val);

        vms->set_sCC(results.cc);

    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Error" << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
    
    
}

void FMA::debug(VMState * vms)
{
    std::cout << "FMA    " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}


