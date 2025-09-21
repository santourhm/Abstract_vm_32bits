#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "VMGrammarLexer.h"
#include "VMGrammarParser.h"
#include "VMGrammarBaseListener.h"
#include "VM.hpp"
#include "VMListener.hpp"
#include "Program.hpp"
#include <memory>
#include "VMState.hpp"
#include "VMErrorListener.hpp"
using namespace antlr4;

bool ishalt_program = false; 
bool debug_mode = false;

int main(int argc, const char* argv[]) {
    
    if (argc < 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <file.S> [-d|--debug]\n";
        return 1;
    }

    std::string filePath;
        
    for (int i = 1; i < argc; ++i) 
    {
        std::string arg = argv[i];
        size_t  size = arg.size();

        if (arg == "-d" || arg == "--debug") 
        {
                debug_mode = true;
        } 
        else if( arg.size() > 2  && (arg.substr(size - 2, size ) == ".S" || arg.substr(size - 2, size ) == ".ass")) 
        {
                filePath = arg; 
        }
        else
        {
            std::cerr << "Error: unknown argument / option" << arg << std::endl;
            return 1;
        }
        
    }

    if(filePath.empty())
    {
        std::cerr << "Error : you must give a assembly (.S , .ass) file"  << std::endl;
        return 1;
    }

    try {
        
        std::ifstream stream(filePath);
        
        if (!stream.is_open()) 
        {
            std::cerr << "Error: Could not open file " << filePath << std::endl;
            return 1;
        }

        ANTLRInputStream  input(stream);
        VMGrammarLexer    lexer(&input);
        CommonTokenStream tokens(&lexer);
        VMGrammarParser   parser(&tokens);

        lexer.removeErrorListeners();
        parser.removeErrorListeners();

        auto errorListener = new VMErrorListener();
        lexer.addErrorListener(errorListener);
        parser.addErrorListener(errorListener);

        tree::ParseTree *tree = parser.program();
        
        auto vms  = std::make_unique<VMState>() ;

        VMListener listener(vms.get());
        
        tree::ParseTreeWalker walker;
        
        walker.walk(&listener, tree);
        
        listener.finalizeProgram();
        
        Program& programAST = listener.getProgramAST();
        
        if(debug_mode)
            programAST.debugProgram(vms.get());
        else
            programAST.executeProgram(vms.get());
        
        delete errorListener;
    }
    catch (const std::exception& e) {
        std::cerr << std::string("Error at ")  << e.what() << std::endl;
        
        return 1;
    }

    return 0;
}