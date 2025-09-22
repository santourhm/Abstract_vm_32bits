#ifndef FMA_HPP
#define FMA_HPP

#include "IInstruction.hpp"




class FMA  : public  IInstruction
{
    public :

        ~FMA() = default ;
        void execute(VMState * vms) override;
        void debug(VMState * vms) override;
};


#endif