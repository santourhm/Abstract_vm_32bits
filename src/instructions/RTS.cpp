#include "IInstruction.hpp"
#include "RTS.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include <stdexcept>
#include "LabelOperand.hpp"
#include "EnvRegisters.hpp"
#include <unordered_map>
#include "Memory.hpp"
#include "Op_Results.hpp"
#include "Memory.hpp"

void RTS::execute(VMState * vms) 
{
    try {
        if (operands.size() != 0) {
            throw std::runtime_error("RTS requires 0 operands but got " 
                                      + std::to_string(operands.size()));
        }

        Register * PC = vms->getEnv_Registers()->getPC();
        Register * SP = vms->getEnv_Registers()->getSP();
        Register * LB = vms->getEnv_Registers()->getLB();
        Memory * mem = vms->getMemory();

        uint32_t V_LB = LB->read().getAddr();

        Value returnAddr = mem->getWord(V_LB - 1);
        
        PC->write(returnAddr);

        SP->write(Value(V_LB - 2));

        Value callerLB = mem->getWord(V_LB);

        LB->write(callerLB);
    }
    catch(const std::runtime_error& e) {
        std::cerr << "Error " << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
}



void RTS::debug(VMState * vms)
{
    std::cout << "RTS    " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}


