
// Generated from /home/santourh/abstract-vm-32bits/grammar/VMGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  VMGrammarLexer : public antlr4::Lexer {
public:
  enum {
    OPP = 1, MUL = 2, QUO = 3, DIV = 4, ADD = 5, SUB = 6, REM = 7, FMA = 8, 
    WSTR = 9, LOAD = 10, NEW = 11, CMP = 12, BRA = 13, SEQ = 14, SNE = 15, 
    SLT = 16, SGT = 17, SGE = 18, SLE = 19, SOV = 20, SHL = 21, SHR = 22, 
    BEQ = 23, BNE = 24, BGE = 25, BLT = 26, BGT = 27, BLE = 28, BOV = 29, 
    BSR = 30, RTS = 31, STORE = 32, PUSH = 33, POP = 34, LEA = 35, PEA = 36, 
    WINT = 37, WNL = 38, HALT = 39, WFLOAT = 40, WTYPE = 41, WADDR = 42, 
    SUBSP = 43, ADDSP = 44, TSTO = 45, RINT = 46, RFLOAT = 47, ERROR = 48, 
    COMMA = 49, OPARENT = 50, CPARENT = 51, HASH = 52, MINUS = 53, COLON = 54, 
    RREGISTER = 55, GBREGISTER = 56, LBREGISTER = 57, SPREGISTER = 58, VALLNULL = 59, 
    STRING_LITERAL = 60, INT = 61, FLOAT = 62, ID = 63, COMMENT = 64, WS = 65, 
    NEWLINE = 66
  };

  explicit VMGrammarLexer(antlr4::CharStream *input);

  ~VMGrammarLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

