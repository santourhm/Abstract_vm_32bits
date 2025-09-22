#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <vector>
#include <cstdint>
#include "Value.hpp" 
#include "Register.hpp"

class Memory 
{
    public:

        static constexpr uint32_t STACK_BASE_ADDR      = 1;
        static constexpr uint32_t STACK_SIZE_WORDS     = 65536*2; 
        static constexpr uint32_t STACK_LIMIT_ADDR     = STACK_BASE_ADDR + STACK_SIZE_WORDS;
        
        static constexpr uint32_t HEAP_START_ADDR      = 100000;
        static constexpr uint32_t HEAP_SIZE_WORDS      = 4 * 1024 * 1024; // ~4M words
        static constexpr uint32_t TOTAL_MEMORY_WORDS   = HEAP_START_ADDR + HEAP_SIZE_WORDS;

        Memory(EnvRegisters * r_env,size_t total_memory_words = TOTAL_MEMORY_WORDS);
        ~Memory() = default;

        uint32_t getTotalSize() const {return TOTAL_MEMORY_WORDS;};

        void initialize();
        void push(const Value& v);
        Value pop();

        Value getWord(uint32_t address) const;
        void setWord(uint32_t address, const Value& v);

        uint32_t  allocate(uint32_t size);

        uint32_t getSP() const { return sp_val->read().getAddr(); }
        uint32_t getGB() const { return gb_val->read().getAddr(); }
        uint32_t getLB() const { return lb_val->read().getAddr(); }

        void setSP(uint32_t value) { sp_val->write(Value((uint32_t)value)); }
        void setLB(uint32_t value) { lb_val->write(Value((uint32_t)value)); }

    private:
        
        std::vector<Value> mem;

        Register * sp_val; 
        Register * gb_val; 
        Register * lb_val; 

        uint32_t heap_ptr;
};

#endif 