#pragma once
#include "antlr4-runtime.h"
#include <iostream>
#include <stdexcept>

class VMErrorListener : public antlr4::BaseErrorListener {
public:
    void syntaxError(antlr4::Recognizer *recognizer,
                     antlr4::Token *offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string &msg,
                     std::exception_ptr e) override 
    {
        std::cerr << "Syntax Error at line " << line
                  << ":" << charPositionInLine << std::endl;

        throw std::runtime_error("Parsing aborted due to syntax error.");
    }
};
