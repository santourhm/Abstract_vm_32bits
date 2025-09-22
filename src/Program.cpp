#include "Program.hpp"
#include <iostream>
#include "Register.hpp"
#include "EnvRegisters.hpp"
#include "Op_Results.hpp"
#include "Debugger.hpp"
#include <cctype>
#include <iomanip>
#include "Memory.hpp"
#include "Colors.hpp"
#include <algorithm>
extern bool ishalt_program;
extern bool debug_mode;

void    Program::addIntruction(std::unique_ptr<IInstruction> inst)
{
        this->instructions.push_back(std::move(inst));
        numberOfInstructions++;
}

int     Program::getNumberofInstructions(void)
{
        return this->numberOfInstructions;
}

const   std::vector<std::unique_ptr<IInstruction>>& Program::getInstructions() const 
{
        return instructions;
}

void    Program::setInstructions(std::vector<std::unique_ptr<IInstruction>>&& instrs)
{
        numberOfInstructions = instrs.size();
        instructions = std::move(instrs);
}

void Program::verifyProgram(void)
{
//      for(auto& ins : instructions)
//      {
//         if(ins)
//      }
}


void Program::executeProgram(VMState* vms)
{

        int i = 0;
        EnvRegisters * envReg = vms->getEnv_Registers();
        Register * PC =  envReg->getPC();
        Register * SP  = envReg->getSP();

        uint32_t   pc = 0x0;
        PC->write(Value(pc));
        int size = instructions.size();
        
        while(vms->not_halt)
        {                 
        

                instructions[PC->read().getAddr()]->execute(vms);

                if(!vms->not_halt)
                {       
                        break;
                }
                                          
                Value V_PC = PC->read();
                V_PC++;
 
                if(size <= V_PC.getAddr() )
                {
                        
                        throw std::runtime_error(" : PC register is out of program code region");
                        break;
                }

                PC->write(V_PC); 
        }

}


static std::vector<std::string> split_whitespace(const std::string& cmd) 
{
    std::istringstream iss(cmd);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {   
        tokens.push_back(token);
    }

    return tokens;
}


static std::unique_ptr<Memory_AddressOperand> parse_MemoryOp(const std::string& op, VMState* vms)
{
    Register* reg;

    size_t posParen = op.find('(');

    if (posParen == std::string::npos || op.back() != ')') throw std::runtime_error("Error : invalid input address!");
    

    
    std::string offStr = op.substr(0, posParen);
    if (offStr.empty()) throw std::runtime_error("Error : no offset detected!");
    

    int offset;
    try {
        offset = std::stoi(offStr); 
    } catch (...) {
        throw std::runtime_error("Error : invalid offset!");
    }

    
    std::string str_reg = op.substr(posParen + 1, op.size() - posParen - 2);

    if (str_reg[0] == 'R' && std::isdigit(str_reg[1])) 
    {
        int regNumber = std::stoi(str_reg.substr(1));

        if (regNumber < 0 || regNumber > 15)  throw std::runtime_error("Error : invalid register number!");
        
        reg = vms->getEnv_Registers()->getR(regNumber);
    }
    else if (str_reg == "GB") 
    {
        reg = vms->getEnv_Registers()->getGB();
    }
    else if (str_reg == "LB") 
    {
        reg = vms->getEnv_Registers()->getLB();
    }
    else if (str_reg == "SP") 
    {
        reg = vms->getEnv_Registers()->getSP();
    }
    else if (str_reg == "PC") 
    {
        reg = vms->getEnv_Registers()->getPC();
    }
    else 
    {
        throw std::runtime_error("Error : unknown register!");
    }

    return std::make_unique<Memory_AddressOperand>(offset, reg, vms->getMemory());
}

static void displayMemoryView(VMState* vms, uint32_t start_addr, uint32_t count)
{
    Memory* memo = vms->getMemory();
    EnvRegisters* regs = vms->getEnv_Registers();

    uint32_t sp_addr = regs->getSP()->read().getAddr();
    uint32_t gb_addr = regs->getGB()->read().getAddr();
    uint32_t lb_addr = regs->getLB()->read().getAddr();

    std::cout << BOLD_WHITE << "--- Memory Dump @ 0x" 
              << std::hex << start_addr << " ---" << RESET << std::endl;

    for (uint32_t i = 0; i < count; ++i)
    {
        uint32_t current_addr = start_addr + i;

        std::cout << "  " << WHITE 
                  << "0x" << std::hex << std::setw(8) << std::setfill('0') 
                  << current_addr << RESET << ": ";

        try {
            if (current_addr >= Memory::TOTAL_MEMORY_WORDS) 
                throw std::out_of_range("Address out of bounds");

            Value val = memo->getWord(current_addr);
            std::cout << std::setw(20) << std::left << val;
        } catch (const std::exception&) {
            std::cout << std::setw(20) << std::left << BOLD_RED << "<out of bounds>" << RESET;
        }

        std::string pointers_str;

        if (current_addr == sp_addr) { pointers_str += " " + std::string(BOLD_CYAN) + "<= SP" + std::string(RESET); }
        if (current_addr == gb_addr) { pointers_str += " " + std::string(BOLD_MAGENTA) + "<= GB" + std::string(RESET); }
        if (current_addr == lb_addr) { pointers_str += " " + std::string(BOLD_YELLOW) + "<= LB" + std::string(RESET); }


        std::cout << pointers_str << std::endl;
    }
}


void Program::debugProgram(VMState* vms)
{
    EnvRegisters* envReg = vms->getEnv_Registers();
    Register* PC = envReg->getPC();
    int size = instructions.size();
    Debugger debug(vms, instructions);

    PC->write(Value(static_cast<uint32_t>(0x0)));
    
    std::cout << BOLD_CYAN << R"(
        __      __       .__                                  ________               
        /  \    /  \ ____ |  |   ____  ____   _____   ____    \_____  \___  __ ____  
        \   \/\/   // __ \|  |  /  _ \/    \ /     \_/ __ \    /   |   \  \/ // __ \ 
        \        /\  ___/|  |_(  <_> )   |  \  Y Y  \  ___/   /    |    \   /\  ___/ 
        \__/\  /  \___  >____/\____/|___|  /__|_|  /\___  >  \_______  /\_/  \___  >
                \/       \/                 \/      \/     \/           \/          \/ 
    )" << RESET << std::endl;
    std::cout << BOLD_WHITE << "                ---- AVM Debugger Initialized ----" << RESET << std::endl;
    std::cout << "Type '" << BOLD_GREEN << "help" << RESET << "' for a list of commands." << std::endl << std::endl;

    while (vms->not_halt)
    {

        uint32_t current_pc = PC->read().getAddr();
        std::cout << BOLD_YELLOW << "[PC: 0x" << std::hex << std::setw(8) << std::setfill('0') << current_pc << "]" << RESET << " => ";
        if (current_pc < size) {
            instructions[current_pc]->debug(vms); 
        } else {
            std::cout << BOLD_RED << "End of program" << RESET;
        }
        std::cout << std::endl;

        std::cout << BOLD_GREEN << "(avm-dbg) " << RESET;
        std::string cmd;
        std::getline(std::cin, cmd);

        auto tokens = split_whitespace(cmd);
        if (tokens.empty()) {
            continue; 
        }
        const std::string& command = tokens[0];

        if (command == "s" || command == "step") 
        {
            debug.execute_OneInstruction(vms);
        }
        else if (command == "c" || command == "continue") 
        {
            debug.execute(vms);
        }
        else if (command == "p" && tokens.size() == 2) 
        {
             try {
                
                if (tokens[1].find('(') != std::string::npos) 
                { 
                        
                    debug.setMemOP_Pointer(parse_MemoryOp(tokens[1], vms));
                    std::cout << GREEN << "Pointer set to memory location: " << RESET << tokens[1] << std::endl;
                } else { 
                    debug.setReg_Pointer(tokens[1]);
                    std::cout << GREEN << "Pointer set to register: " << RESET << tokens[1] << std::endl;
                }
            } catch (const std::runtime_error& e) {
                std::cerr << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
            }
        }
        else if (command == "r" || command == "read") 
        {
            try {
                Value val = debug.read_Pointer();
                std::cout << "Value: " << BOLD_CYAN << val << RESET << std::endl;
            } catch(const std::runtime_error& e) {
                std::cerr << BOLD_RED << e.what() << RESET << std::endl;
            }
        }
        else if (command == "w" || command == "write") 
        {
                if (tokens.size() < 2) {
                        std::cerr << BOLD_RED << "Error: missing value to write." << RESET << std::endl;
                        continue;
                }

                std::string input;

               
                if (tokens[1][0] == '"') {
                        input = tokens[1];
                        for (size_t i = 2; i < tokens.size(); ++i) {
                        input += " " + tokens[i];
                        }

                        if (input.front() == '"' && input.back() == '"') {
                        input = input.substr(1, input.size() - 2);
                        } else {
                                std::cerr << BOLD_RED << "Error: unterminated string literal." << RESET << std::endl;
                                continue;
                        }
                        debug.write_Pointer(Value(input));
                        continue;
                } else {
                        input = tokens[1];
                }

                try {
                        
                        if (std::all_of(input.begin(), input.end(), ::isdigit) || 
                        (input[0] == '-' && std::all_of(input.begin()+1, input.end(), ::isdigit))) 
                        {
                                uint32_t value = std::stoul(input, nullptr, 0);
                                debug.write_Pointer(Value(value));
                        }
                        
                        else if (input.find('.') != std::string::npos) 
                        {
                                float fvalue = std::stof(input);
                                debug.write_Pointer(Value(fvalue));
                        }
                } 
                catch (const std::exception& e) {
                        std::cerr << BOLD_RED << "Error: invalid value." << RESET << std::endl;
                }
        }
        else if ((command == "sw" || command == "show") && tokens.size() == 2) 
        {
            try {
                uint32_t addr = std::stoul(tokens[1], nullptr, 0);
                if (addr >= size) throw std::runtime_error("Address out of bounds.");
                std::cout << BOLD_YELLOW << "[0x" << std::hex << std::setw(8) << std::setfill('0') << addr << "]" << RESET << " : ";
                instructions[addr]->debug(vms);
                std::cout << std::endl;
            } catch (...) {
                std::cerr << BOLD_RED << "Error: Invalid address format or value." << RESET << std::endl;
            }
        }
        else if (command == "b" && tokens.size() == 2) 
        {
            try {
                uint32_t addr = std::stoul(tokens[1], nullptr, 0);
                debug.setBreakpoint(addr);
                std::cout << GREEN << "Breakpoint set at 0x" << std::hex << addr << RESET << std::endl;
            } catch (...) {
                std::cerr << BOLD_RED << "Error: Invalid address for breakpoint." << RESET << std::endl;
            }
        }
        else if (command == "info" && tokens.size() > 1) 
        {
            if (tokens[1] == "r") {
              
                auto regs = vms->getEnv_Registers();
                std::cout << BOLD_WHITE << "--- General Purpose Registers ---" << RESET << std::endl;
                for (int i = 0; i < 16; ++i) {
                    std::cout << "  " << BOLD_YELLOW << "R" << std::left << std::setw(2) << i << RESET << " = " << regs->getR(i)->read() << std::endl;
                }
                std::cout << BOLD_WHITE << "--- Special Purpose Registers ---" << RESET << std::endl;
                std::cout << "  " << BOLD_CYAN << "PC" << RESET << " = " << regs->getPC()->read() << std::endl;
                std::cout << "  " << BOLD_CYAN << "SP" << RESET << " = " << regs->getSP()->read() << std::endl;
                std::cout << "  " << BOLD_CYAN << "GB" << RESET << " = " << regs->getGB()->read() << std::endl;
                std::cout << "  " << BOLD_CYAN << "LB" << RESET << " = " << regs->getLB()->read() << std::endl;
            } else if (tokens[1] == "b") {
               
                auto bps = debug.getBreakpoints();
                if (bps.empty()) {
                    std::cout << "No breakpoints set." << std::endl;
                } else {
                    std::cout << BOLD_WHITE << "--- Active Breakpoints ---" << RESET << std::endl;
                    int i = 1;
                    for (auto addr : bps) {
                        std::cout << " " << i++ << ". at 0x" << std::hex << addr << std::endl;
                    }
                }
            } else {
                 std::cerr << BOLD_RED << "Error: Unknown 'info' argument. Try 'info r' or 'info b'." << RESET << std::endl;
            }
        }
        else if (command == "reset") 
        {
                auto regs = vms->getEnv_Registers();
                regs->getPC()->write(Value((uint32_t)0));
                regs->getSP()->write(Value((uint32_t)0));
                regs->getGB()->write(Value((uint32_t)0));
                regs->getLB()->write(Value((uint32_t)0));
                for (int i = 0; i < 16; i++) regs->getR(i)->write(Value());

                debug.clearBreakpoints();
                std::cout << YELLOW << "Program state has been reset." << RESET << std::endl;
        }
        else if (command == "mem") 
        {
            const uint32_t DEFAULT_MEM_DUMP_COUNT = 16;
            uint32_t start_addr = 0;
            uint32_t count = DEFAULT_MEM_DUMP_COUNT;

            try {
                if (tokens.size() == 1) { 
                    uint32_t sp = vms->getEnv_Registers()->getSP()->read().getAddr();
                    
                    start_addr = (sp > (DEFAULT_MEM_DUMP_COUNT / 2)) ? (sp - (DEFAULT_MEM_DUMP_COUNT / 2)) : 1;
                } else if (tokens.size() >= 2) { 
                    start_addr = std::stoul(tokens[1], nullptr, 0);
                    if (tokens.size() == 3) {
                        count = std::stoul(tokens[2], nullptr, 0);
                    }
                }
                displayMemoryView(vms, start_addr, count);
            } catch (...) {
                std::cerr << BOLD_RED << "Error: Invalid address or count for 'mem' command." << RESET << std::endl;
            }
        }
        else if (command == "h" || command == "help") {
           
            std::cout << BOLD_WHITE << "--- AVM Debugger Commands ---" << RESET << std::endl
                      << "  " << BOLD_GREEN << "s, step" << RESET << "        : Execute the next instruction.\n"
                      << "  " << BOLD_GREEN << "c, continue" << RESET << "    : Continue execution until a breakpoint or halt.\n"
                      << "  " << BOLD_GREEN << "b <addr>" << RESET << "       : Set a breakpoint at the given address (e.g., b 0x1A).\n"
                      << "  " << BOLD_GREEN << "info r" << RESET << "         : Display all register values.\n"
                      << "  " << BOLD_GREEN << "info b" << RESET << "         : List all active breakpoints.\n"
                      << "  " << BOLD_GREEN << "mem [a]  [c]" << RESET << "    : Dump memory. [a]=address, [c]=count. Default: around SP.\n" 
                      << "  " << BOLD_GREEN << "p <reg|mem>" << RESET << "    : Set the inspection pointer (e.g., p R5, p 100(SP)).\n"
                      << "  " << BOLD_GREEN << "r, read" << RESET << "        : Read the value at the current inspection pointer.\n"
                      << "  " << BOLD_GREEN << "w <value>, write <value>" << RESET << "       : Write the value at the current inspection pointer , (value = int, float , str =\"value\").\n"
                      << "  " << BOLD_GREEN << "show <addr>" << RESET << "    : Show the instruction at a specific address.\n"
                      << "  " << BOLD_GREEN << "reset" << RESET << "          : Reset the VM state to its initial condition.\n"
                      << "  " << BOLD_GREEN << "h, help" << RESET << "        : Display this help message." << std::endl;
        }
        else {
            std::cerr << BOLD_RED << "Error: Unknown command '" << command << "'" << RESET << std::endl;
        }
        std::cout << std::endl; 
    }
    
   
    std::cout << BOLD_MAGENTA << "--- Program halted ---" << RESET << std::endl;
}