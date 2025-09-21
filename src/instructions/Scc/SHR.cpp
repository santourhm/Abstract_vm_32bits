#include "IInstruction.hpp"
#include "Scc/SHR.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include <stdexcept>
#include "LabelOperand.hpp"
#include "EnvRegisters.hpp"
#include <unordered_map>

#include "Op_Results.hpp"

void SHR::execute(VMState * vms) 
{

    try
    {
        if (operands.size() != 1 ) {
            throw std::runtime_error(" : SHR requies 1 operand but got " + std::to_string(operands.size()));
        }

        IOperand * base = operands[0].get();
        
        RRegOperand* reg = dynamic_cast<RRegOperand*>(base);

        if(reg == nullptr)
        {
            throw std::runtime_error(" : SHR requires a Rm Operand" );
            return;
        }

        Value V_Reg = reg->read();

        if(V_Reg.getType() == TypeTag::INTEGER)
        {
            Value V_result(Value(V_Reg.getInt() >> 1));
            reg->getRegister()->write(V_result);
            Op_Results new_cc = V_result - Value(0);
            vms->set_sCC(new_cc.cc);
        }
        else
        {
            throw std::runtime_error(" : Undefined shit operantion for the given register value type" );
        }

    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Error" << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
    
}

void SHR::debug(VMState * vms)
{
    std::cout << "SHR      " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}

