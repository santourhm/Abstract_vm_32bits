#include "IInstruction.hpp"
#include "Scc/SNE.hpp"
#include "RRegOperand.hpp"
#include <iostream>
#include <stdexcept>
#include "LabelOperand.hpp"
#include "EnvRegisters.hpp"
#include <unordered_map>

#include "Op_Results.hpp"

void SNE::execute(VMState * vms) 
{

    try
    {
        if (operands.size() != 1 ) {
            throw std::runtime_error(" : SNE requies 1 operand but got " + std::to_string(operands.size()));
        }

        IOperand * base = operands[0].get();
        
        RRegOperand* reg = dynamic_cast<RRegOperand*>(base);

        if(reg == nullptr)
        {
            throw std::runtime_error(" : SNE requires a Rm Operand" );
            return;
        }

        Value v(static_cast<int32_t>(vms->get_sCC()->NE));

        reg->getRegister()->write(v);
        

    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Error" << e.what() << '\n';
        exit(EXIT_SUCCESS);

    }
    
}

void SNE::debug(VMState * vms)
{
    std::cout << "SNE      " ;

    size_t numberOf_Operands = operands.size();

    for (size_t a = 0; a < numberOf_Operands ; a++ )
    {
        if(a >= 1)  std::cout << " , ";
        std::cout << operands[a].get()->show();
    }

    std::cout << std::endl;
}

