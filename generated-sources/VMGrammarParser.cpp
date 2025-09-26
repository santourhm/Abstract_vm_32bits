
// Generated from /home/santourh/abstract-vm-32bits/grammar/VMGrammar.g4 by ANTLR 4.13.2


#include "VMGrammarListener.h"
#include "VMGrammarVisitor.h"

#include "VMGrammarParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct VMGrammarParserStaticData final {
  VMGrammarParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VMGrammarParserStaticData(const VMGrammarParserStaticData&) = delete;
  VMGrammarParserStaticData(VMGrammarParserStaticData&&) = delete;
  VMGrammarParserStaticData& operator=(const VMGrammarParserStaticData&) = delete;
  VMGrammarParserStaticData& operator=(VMGrammarParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag vmgrammarParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<VMGrammarParserStaticData> vmgrammarParserStaticData = nullptr;

void vmgrammarParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (vmgrammarParserStaticData != nullptr) {
    return;
  }
#else
  assert(vmgrammarParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<VMGrammarParserStaticData>(
    std::vector<std::string>{
      "program", "line", "instruction_line", "label_definition", "instruction", 
      "opcode", "operand", "string_literal", "register", "memory_address", 
      "immediate", "label"
    },
    std::vector<std::string>{
      "", "'OPP'", "'MUL'", "'QUO'", "'DIV'", "'ADD'", "'SUB'", "'REM'", 
      "'FMA'", "'WSTR'", "'LOAD'", "'NEW'", "'CMP'", "'BRA'", "'SEQ'", "'SNE'", 
      "'SLT'", "'SGT'", "'SGE'", "'SLE'", "'SOV'", "'SHL'", "'SHR'", "'BEQ'", 
      "'BNE'", "'BGE'", "'BLT'", "'BGT'", "'BLE'", "'BOV'", "'BSR'", "'RTS'", 
      "'STORE'", "'PUSH'", "'POP'", "'LEA'", "'PEA'", "'WINT'", "'WNL'", 
      "'HALT'", "'WFLOAT'", "'WTYPE'", "'WADDR'", "'SUBSP'", "'ADDSP'", 
      "'TSTO'", "'RINT'", "'RFLOAT'", "'ERROR'", "','", "'('", "')'", "'#'", 
      "'-'", "':'", "", "'GB'", "'LB'", "'SP'", "'null'"
    },
    std::vector<std::string>{
      "", "OPP", "MUL", "QUO", "DIV", "ADD", "SUB", "REM", "FMA", "WSTR", 
      "LOAD", "NEW", "CMP", "BRA", "SEQ", "SNE", "SLT", "SGT", "SGE", "SLE", 
      "SOV", "SHL", "SHR", "BEQ", "BNE", "BGE", "BLT", "BGT", "BLE", "BOV", 
      "BSR", "RTS", "STORE", "PUSH", "POP", "LEA", "PEA", "WINT", "WNL", 
      "HALT", "WFLOAT", "WTYPE", "WADDR", "SUBSP", "ADDSP", "TSTO", "RINT", 
      "RFLOAT", "ERROR", "COMMA", "OPARENT", "CPARENT", "HASH", "MINUS", 
      "COLON", "RREGISTER", "GBREGISTER", "LBREGISTER", "SPREGISTER", "VALLNULL", 
      "STRING_LITERAL", "INT", "FLOAT", "ID", "COMMENT", "WS", "NEWLINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,66,91,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,5,0,26,8,0,10,0,12,0,29,9,
  	0,1,0,3,0,32,8,0,1,0,1,0,1,1,1,1,3,1,38,8,1,1,1,4,1,41,8,1,11,1,12,1,
  	42,1,2,1,2,1,3,1,3,1,3,1,4,1,4,1,4,1,4,3,4,54,8,4,3,4,56,8,4,1,5,1,5,
  	1,6,1,6,1,6,1,6,1,6,3,6,65,8,6,1,7,1,7,1,8,1,8,1,9,3,9,72,8,9,1,9,3,9,
  	75,8,9,1,9,1,9,1,9,1,9,1,10,1,10,3,10,83,8,10,1,10,1,10,3,10,87,8,10,
  	1,11,1,11,1,11,0,0,12,0,2,4,6,8,10,12,14,16,18,20,22,0,3,1,0,1,48,1,0,
  	55,58,1,0,61,62,93,0,27,1,0,0,0,2,37,1,0,0,0,4,44,1,0,0,0,6,46,1,0,0,
  	0,8,49,1,0,0,0,10,57,1,0,0,0,12,64,1,0,0,0,14,66,1,0,0,0,16,68,1,0,0,
  	0,18,74,1,0,0,0,20,80,1,0,0,0,22,88,1,0,0,0,24,26,3,2,1,0,25,24,1,0,0,
  	0,26,29,1,0,0,0,27,25,1,0,0,0,27,28,1,0,0,0,28,31,1,0,0,0,29,27,1,0,0,
  	0,30,32,3,4,2,0,31,30,1,0,0,0,31,32,1,0,0,0,32,33,1,0,0,0,33,34,5,0,0,
  	1,34,1,1,0,0,0,35,38,3,6,3,0,36,38,3,4,2,0,37,35,1,0,0,0,37,36,1,0,0,
  	0,37,38,1,0,0,0,38,40,1,0,0,0,39,41,5,66,0,0,40,39,1,0,0,0,41,42,1,0,
  	0,0,42,40,1,0,0,0,42,43,1,0,0,0,43,3,1,0,0,0,44,45,3,8,4,0,45,5,1,0,0,
  	0,46,47,5,63,0,0,47,48,5,54,0,0,48,7,1,0,0,0,49,55,3,10,5,0,50,53,3,12,
  	6,0,51,52,5,49,0,0,52,54,3,12,6,0,53,51,1,0,0,0,53,54,1,0,0,0,54,56,1,
  	0,0,0,55,50,1,0,0,0,55,56,1,0,0,0,56,9,1,0,0,0,57,58,7,0,0,0,58,11,1,
  	0,0,0,59,65,3,18,9,0,60,65,3,20,10,0,61,65,3,16,8,0,62,65,3,14,7,0,63,
  	65,3,22,11,0,64,59,1,0,0,0,64,60,1,0,0,0,64,61,1,0,0,0,64,62,1,0,0,0,
  	64,63,1,0,0,0,65,13,1,0,0,0,66,67,5,60,0,0,67,15,1,0,0,0,68,69,7,1,0,
  	0,69,17,1,0,0,0,70,72,5,53,0,0,71,70,1,0,0,0,71,72,1,0,0,0,72,73,1,0,
  	0,0,73,75,5,61,0,0,74,71,1,0,0,0,74,75,1,0,0,0,75,76,1,0,0,0,76,77,5,
  	50,0,0,77,78,3,16,8,0,78,79,5,51,0,0,79,19,1,0,0,0,80,86,5,52,0,0,81,
  	83,5,53,0,0,82,81,1,0,0,0,82,83,1,0,0,0,83,84,1,0,0,0,84,87,7,2,0,0,85,
  	87,5,59,0,0,86,82,1,0,0,0,86,85,1,0,0,0,87,21,1,0,0,0,88,89,5,63,0,0,
  	89,23,1,0,0,0,11,27,31,37,42,53,55,64,71,74,82,86
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  vmgrammarParserStaticData = std::move(staticData);
}

}

VMGrammarParser::VMGrammarParser(TokenStream *input) : VMGrammarParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

VMGrammarParser::VMGrammarParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  VMGrammarParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *vmgrammarParserStaticData->atn, vmgrammarParserStaticData->decisionToDFA, vmgrammarParserStaticData->sharedContextCache, options);
}

VMGrammarParser::~VMGrammarParser() {
  delete _interpreter;
}

const atn::ATN& VMGrammarParser::getATN() const {
  return *vmgrammarParserStaticData->atn;
}

std::string VMGrammarParser::getGrammarFileName() const {
  return "VMGrammar.g4";
}

const std::vector<std::string>& VMGrammarParser::getRuleNames() const {
  return vmgrammarParserStaticData->ruleNames;
}

const dfa::Vocabulary& VMGrammarParser::getVocabulary() const {
  return vmgrammarParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView VMGrammarParser::getSerializedATN() const {
  return vmgrammarParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

VMGrammarParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VMGrammarParser::ProgramContext::EOF() {
  return getToken(VMGrammarParser::EOF, 0);
}

std::vector<VMGrammarParser::LineContext *> VMGrammarParser::ProgramContext::line() {
  return getRuleContexts<VMGrammarParser::LineContext>();
}

VMGrammarParser::LineContext* VMGrammarParser::ProgramContext::line(size_t i) {
  return getRuleContext<VMGrammarParser::LineContext>(i);
}

VMGrammarParser::Instruction_lineContext* VMGrammarParser::ProgramContext::instruction_line() {
  return getRuleContext<VMGrammarParser::Instruction_lineContext>(0);
}


size_t VMGrammarParser::ProgramContext::getRuleIndex() const {
  return VMGrammarParser::RuleProgram;
}

void VMGrammarParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void VMGrammarParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any VMGrammarParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::ProgramContext* VMGrammarParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, VMGrammarParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(27);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(24);
        line(); 
      }
      setState(29);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(31);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 562949953421310) != 0)) {
      setState(30);
      instruction_line();
    }
    setState(33);
    match(VMGrammarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

VMGrammarParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VMGrammarParser::Label_definitionContext* VMGrammarParser::LineContext::label_definition() {
  return getRuleContext<VMGrammarParser::Label_definitionContext>(0);
}

VMGrammarParser::Instruction_lineContext* VMGrammarParser::LineContext::instruction_line() {
  return getRuleContext<VMGrammarParser::Instruction_lineContext>(0);
}

std::vector<tree::TerminalNode *> VMGrammarParser::LineContext::NEWLINE() {
  return getTokens(VMGrammarParser::NEWLINE);
}

tree::TerminalNode* VMGrammarParser::LineContext::NEWLINE(size_t i) {
  return getToken(VMGrammarParser::NEWLINE, i);
}


size_t VMGrammarParser::LineContext::getRuleIndex() const {
  return VMGrammarParser::RuleLine;
}

void VMGrammarParser::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void VMGrammarParser::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}


std::any VMGrammarParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::LineContext* VMGrammarParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, VMGrammarParser::RuleLine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(37);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VMGrammarParser::ID: {
        setState(35);
        label_definition();
        break;
      }

      case VMGrammarParser::OPP:
      case VMGrammarParser::MUL:
      case VMGrammarParser::QUO:
      case VMGrammarParser::DIV:
      case VMGrammarParser::ADD:
      case VMGrammarParser::SUB:
      case VMGrammarParser::REM:
      case VMGrammarParser::FMA:
      case VMGrammarParser::WSTR:
      case VMGrammarParser::LOAD:
      case VMGrammarParser::NEW:
      case VMGrammarParser::CMP:
      case VMGrammarParser::BRA:
      case VMGrammarParser::SEQ:
      case VMGrammarParser::SNE:
      case VMGrammarParser::SLT:
      case VMGrammarParser::SGT:
      case VMGrammarParser::SGE:
      case VMGrammarParser::SLE:
      case VMGrammarParser::SOV:
      case VMGrammarParser::SHL:
      case VMGrammarParser::SHR:
      case VMGrammarParser::BEQ:
      case VMGrammarParser::BNE:
      case VMGrammarParser::BGE:
      case VMGrammarParser::BLT:
      case VMGrammarParser::BGT:
      case VMGrammarParser::BLE:
      case VMGrammarParser::BOV:
      case VMGrammarParser::BSR:
      case VMGrammarParser::RTS:
      case VMGrammarParser::STORE:
      case VMGrammarParser::PUSH:
      case VMGrammarParser::POP:
      case VMGrammarParser::LEA:
      case VMGrammarParser::PEA:
      case VMGrammarParser::WINT:
      case VMGrammarParser::WNL:
      case VMGrammarParser::HALT:
      case VMGrammarParser::WFLOAT:
      case VMGrammarParser::WTYPE:
      case VMGrammarParser::WADDR:
      case VMGrammarParser::SUBSP:
      case VMGrammarParser::ADDSP:
      case VMGrammarParser::TSTO:
      case VMGrammarParser::RINT:
      case VMGrammarParser::RFLOAT:
      case VMGrammarParser::ERROR: {
        setState(36);
        instruction_line();
        break;
      }

      case VMGrammarParser::NEWLINE: {
        break;
      }

    default:
      break;
    }
    setState(40); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(39);
              match(VMGrammarParser::NEWLINE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(42); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Instruction_lineContext ------------------------------------------------------------------

VMGrammarParser::Instruction_lineContext::Instruction_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VMGrammarParser::InstructionContext* VMGrammarParser::Instruction_lineContext::instruction() {
  return getRuleContext<VMGrammarParser::InstructionContext>(0);
}


size_t VMGrammarParser::Instruction_lineContext::getRuleIndex() const {
  return VMGrammarParser::RuleInstruction_line;
}

void VMGrammarParser::Instruction_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstruction_line(this);
}

void VMGrammarParser::Instruction_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstruction_line(this);
}


std::any VMGrammarParser::Instruction_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitInstruction_line(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::Instruction_lineContext* VMGrammarParser::instruction_line() {
  Instruction_lineContext *_localctx = _tracker.createInstance<Instruction_lineContext>(_ctx, getState());
  enterRule(_localctx, 4, VMGrammarParser::RuleInstruction_line);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    instruction();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Label_definitionContext ------------------------------------------------------------------

VMGrammarParser::Label_definitionContext::Label_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VMGrammarParser::Label_definitionContext::ID() {
  return getToken(VMGrammarParser::ID, 0);
}

tree::TerminalNode* VMGrammarParser::Label_definitionContext::COLON() {
  return getToken(VMGrammarParser::COLON, 0);
}


size_t VMGrammarParser::Label_definitionContext::getRuleIndex() const {
  return VMGrammarParser::RuleLabel_definition;
}

void VMGrammarParser::Label_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel_definition(this);
}

void VMGrammarParser::Label_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel_definition(this);
}


std::any VMGrammarParser::Label_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitLabel_definition(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::Label_definitionContext* VMGrammarParser::label_definition() {
  Label_definitionContext *_localctx = _tracker.createInstance<Label_definitionContext>(_ctx, getState());
  enterRule(_localctx, 6, VMGrammarParser::RuleLabel_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    match(VMGrammarParser::ID);
    setState(47);
    match(VMGrammarParser::COLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionContext ------------------------------------------------------------------

VMGrammarParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VMGrammarParser::OpcodeContext* VMGrammarParser::InstructionContext::opcode() {
  return getRuleContext<VMGrammarParser::OpcodeContext>(0);
}

std::vector<VMGrammarParser::OperandContext *> VMGrammarParser::InstructionContext::operand() {
  return getRuleContexts<VMGrammarParser::OperandContext>();
}

VMGrammarParser::OperandContext* VMGrammarParser::InstructionContext::operand(size_t i) {
  return getRuleContext<VMGrammarParser::OperandContext>(i);
}

tree::TerminalNode* VMGrammarParser::InstructionContext::COMMA() {
  return getToken(VMGrammarParser::COMMA, 0);
}


size_t VMGrammarParser::InstructionContext::getRuleIndex() const {
  return VMGrammarParser::RuleInstruction;
}

void VMGrammarParser::InstructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstruction(this);
}

void VMGrammarParser::InstructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstruction(this);
}


std::any VMGrammarParser::InstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitInstruction(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::InstructionContext* VMGrammarParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 8, VMGrammarParser::RuleInstruction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    opcode();
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -5209538868960821248) != 0)) {
      setState(50);
      operand();
      setState(53);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == VMGrammarParser::COMMA) {
        setState(51);
        match(VMGrammarParser::COMMA);
        setState(52);
        operand();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpcodeContext ------------------------------------------------------------------

VMGrammarParser::OpcodeContext::OpcodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::ADD() {
  return getToken(VMGrammarParser::ADD, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::MUL() {
  return getToken(VMGrammarParser::MUL, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::QUO() {
  return getToken(VMGrammarParser::QUO, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::DIV() {
  return getToken(VMGrammarParser::DIV, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::OPP() {
  return getToken(VMGrammarParser::OPP, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::REM() {
  return getToken(VMGrammarParser::REM, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::SUB() {
  return getToken(VMGrammarParser::SUB, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::WSTR() {
  return getToken(VMGrammarParser::WSTR, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::LOAD() {
  return getToken(VMGrammarParser::LOAD, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::CMP() {
  return getToken(VMGrammarParser::CMP, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::BEQ() {
  return getToken(VMGrammarParser::BEQ, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::BNE() {
  return getToken(VMGrammarParser::BNE, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::BLT() {
  return getToken(VMGrammarParser::BLT, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::BGT() {
  return getToken(VMGrammarParser::BGT, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::BGE() {
  return getToken(VMGrammarParser::BGE, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::BLE() {
  return getToken(VMGrammarParser::BLE, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::BOV() {
  return getToken(VMGrammarParser::BOV, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::SEQ() {
  return getToken(VMGrammarParser::SEQ, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::SNE() {
  return getToken(VMGrammarParser::SNE, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::SLT() {
  return getToken(VMGrammarParser::SLT, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::SGT() {
  return getToken(VMGrammarParser::SGT, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::SGE() {
  return getToken(VMGrammarParser::SGE, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::SLE() {
  return getToken(VMGrammarParser::SLE, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::SOV() {
  return getToken(VMGrammarParser::SOV, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::SHL() {
  return getToken(VMGrammarParser::SHL, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::SHR() {
  return getToken(VMGrammarParser::SHR, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::BRA() {
  return getToken(VMGrammarParser::BRA, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::WINT() {
  return getToken(VMGrammarParser::WINT, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::WNL() {
  return getToken(VMGrammarParser::WNL, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::WFLOAT() {
  return getToken(VMGrammarParser::WFLOAT, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::HALT() {
  return getToken(VMGrammarParser::HALT, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::STORE() {
  return getToken(VMGrammarParser::STORE, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::PUSH() {
  return getToken(VMGrammarParser::PUSH, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::POP() {
  return getToken(VMGrammarParser::POP, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::LEA() {
  return getToken(VMGrammarParser::LEA, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::PEA() {
  return getToken(VMGrammarParser::PEA, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::BSR() {
  return getToken(VMGrammarParser::BSR, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::RTS() {
  return getToken(VMGrammarParser::RTS, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::SUBSP() {
  return getToken(VMGrammarParser::SUBSP, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::ADDSP() {
  return getToken(VMGrammarParser::ADDSP, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::RINT() {
  return getToken(VMGrammarParser::RINT, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::RFLOAT() {
  return getToken(VMGrammarParser::RFLOAT, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::ERROR() {
  return getToken(VMGrammarParser::ERROR, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::TSTO() {
  return getToken(VMGrammarParser::TSTO, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::NEW() {
  return getToken(VMGrammarParser::NEW, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::WTYPE() {
  return getToken(VMGrammarParser::WTYPE, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::WADDR() {
  return getToken(VMGrammarParser::WADDR, 0);
}

tree::TerminalNode* VMGrammarParser::OpcodeContext::FMA() {
  return getToken(VMGrammarParser::FMA, 0);
}


size_t VMGrammarParser::OpcodeContext::getRuleIndex() const {
  return VMGrammarParser::RuleOpcode;
}

void VMGrammarParser::OpcodeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpcode(this);
}

void VMGrammarParser::OpcodeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpcode(this);
}


std::any VMGrammarParser::OpcodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitOpcode(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::OpcodeContext* VMGrammarParser::opcode() {
  OpcodeContext *_localctx = _tracker.createInstance<OpcodeContext>(_ctx, getState());
  enterRule(_localctx, 10, VMGrammarParser::RuleOpcode);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 562949953421310) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperandContext ------------------------------------------------------------------

VMGrammarParser::OperandContext::OperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VMGrammarParser::Memory_addressContext* VMGrammarParser::OperandContext::memory_address() {
  return getRuleContext<VMGrammarParser::Memory_addressContext>(0);
}

VMGrammarParser::ImmediateContext* VMGrammarParser::OperandContext::immediate() {
  return getRuleContext<VMGrammarParser::ImmediateContext>(0);
}

VMGrammarParser::RegisterContext* VMGrammarParser::OperandContext::register_() {
  return getRuleContext<VMGrammarParser::RegisterContext>(0);
}

VMGrammarParser::String_literalContext* VMGrammarParser::OperandContext::string_literal() {
  return getRuleContext<VMGrammarParser::String_literalContext>(0);
}

VMGrammarParser::LabelContext* VMGrammarParser::OperandContext::label() {
  return getRuleContext<VMGrammarParser::LabelContext>(0);
}


size_t VMGrammarParser::OperandContext::getRuleIndex() const {
  return VMGrammarParser::RuleOperand;
}

void VMGrammarParser::OperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperand(this);
}

void VMGrammarParser::OperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperand(this);
}


std::any VMGrammarParser::OperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitOperand(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::OperandContext* VMGrammarParser::operand() {
  OperandContext *_localctx = _tracker.createInstance<OperandContext>(_ctx, getState());
  enterRule(_localctx, 12, VMGrammarParser::RuleOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(64);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VMGrammarParser::OPARENT:
      case VMGrammarParser::MINUS:
      case VMGrammarParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(59);
        memory_address();
        break;
      }

      case VMGrammarParser::HASH: {
        enterOuterAlt(_localctx, 2);
        setState(60);
        immediate();
        break;
      }

      case VMGrammarParser::RREGISTER:
      case VMGrammarParser::GBREGISTER:
      case VMGrammarParser::LBREGISTER:
      case VMGrammarParser::SPREGISTER: {
        enterOuterAlt(_localctx, 3);
        setState(61);
        register_();
        break;
      }

      case VMGrammarParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(62);
        string_literal();
        break;
      }

      case VMGrammarParser::ID: {
        enterOuterAlt(_localctx, 5);
        setState(63);
        label();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- String_literalContext ------------------------------------------------------------------

VMGrammarParser::String_literalContext::String_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VMGrammarParser::String_literalContext::STRING_LITERAL() {
  return getToken(VMGrammarParser::STRING_LITERAL, 0);
}


size_t VMGrammarParser::String_literalContext::getRuleIndex() const {
  return VMGrammarParser::RuleString_literal;
}

void VMGrammarParser::String_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString_literal(this);
}

void VMGrammarParser::String_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString_literal(this);
}


std::any VMGrammarParser::String_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitString_literal(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::String_literalContext* VMGrammarParser::string_literal() {
  String_literalContext *_localctx = _tracker.createInstance<String_literalContext>(_ctx, getState());
  enterRule(_localctx, 14, VMGrammarParser::RuleString_literal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(VMGrammarParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegisterContext ------------------------------------------------------------------

VMGrammarParser::RegisterContext::RegisterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VMGrammarParser::RegisterContext::RREGISTER() {
  return getToken(VMGrammarParser::RREGISTER, 0);
}

tree::TerminalNode* VMGrammarParser::RegisterContext::GBREGISTER() {
  return getToken(VMGrammarParser::GBREGISTER, 0);
}

tree::TerminalNode* VMGrammarParser::RegisterContext::LBREGISTER() {
  return getToken(VMGrammarParser::LBREGISTER, 0);
}

tree::TerminalNode* VMGrammarParser::RegisterContext::SPREGISTER() {
  return getToken(VMGrammarParser::SPREGISTER, 0);
}


size_t VMGrammarParser::RegisterContext::getRuleIndex() const {
  return VMGrammarParser::RuleRegister;
}

void VMGrammarParser::RegisterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegister(this);
}

void VMGrammarParser::RegisterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegister(this);
}


std::any VMGrammarParser::RegisterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitRegister(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::RegisterContext* VMGrammarParser::register_() {
  RegisterContext *_localctx = _tracker.createInstance<RegisterContext>(_ctx, getState());
  enterRule(_localctx, 16, VMGrammarParser::RuleRegister);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 540431955284459520) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Memory_addressContext ------------------------------------------------------------------

VMGrammarParser::Memory_addressContext::Memory_addressContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VMGrammarParser::Memory_addressContext::OPARENT() {
  return getToken(VMGrammarParser::OPARENT, 0);
}

VMGrammarParser::RegisterContext* VMGrammarParser::Memory_addressContext::register_() {
  return getRuleContext<VMGrammarParser::RegisterContext>(0);
}

tree::TerminalNode* VMGrammarParser::Memory_addressContext::CPARENT() {
  return getToken(VMGrammarParser::CPARENT, 0);
}

tree::TerminalNode* VMGrammarParser::Memory_addressContext::INT() {
  return getToken(VMGrammarParser::INT, 0);
}

tree::TerminalNode* VMGrammarParser::Memory_addressContext::MINUS() {
  return getToken(VMGrammarParser::MINUS, 0);
}


size_t VMGrammarParser::Memory_addressContext::getRuleIndex() const {
  return VMGrammarParser::RuleMemory_address;
}

void VMGrammarParser::Memory_addressContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemory_address(this);
}

void VMGrammarParser::Memory_addressContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemory_address(this);
}


std::any VMGrammarParser::Memory_addressContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitMemory_address(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::Memory_addressContext* VMGrammarParser::memory_address() {
  Memory_addressContext *_localctx = _tracker.createInstance<Memory_addressContext>(_ctx, getState());
  enterRule(_localctx, 18, VMGrammarParser::RuleMemory_address);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VMGrammarParser::MINUS

    || _la == VMGrammarParser::INT) {
      setState(71);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == VMGrammarParser::MINUS) {
        setState(70);
        match(VMGrammarParser::MINUS);
      }
      setState(73);
      match(VMGrammarParser::INT);
    }
    setState(76);
    match(VMGrammarParser::OPARENT);
    setState(77);
    register_();
    setState(78);
    match(VMGrammarParser::CPARENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImmediateContext ------------------------------------------------------------------

VMGrammarParser::ImmediateContext::ImmediateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VMGrammarParser::ImmediateContext::HASH() {
  return getToken(VMGrammarParser::HASH, 0);
}

tree::TerminalNode* VMGrammarParser::ImmediateContext::VALLNULL() {
  return getToken(VMGrammarParser::VALLNULL, 0);
}

tree::TerminalNode* VMGrammarParser::ImmediateContext::INT() {
  return getToken(VMGrammarParser::INT, 0);
}

tree::TerminalNode* VMGrammarParser::ImmediateContext::FLOAT() {
  return getToken(VMGrammarParser::FLOAT, 0);
}

tree::TerminalNode* VMGrammarParser::ImmediateContext::MINUS() {
  return getToken(VMGrammarParser::MINUS, 0);
}


size_t VMGrammarParser::ImmediateContext::getRuleIndex() const {
  return VMGrammarParser::RuleImmediate;
}

void VMGrammarParser::ImmediateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImmediate(this);
}

void VMGrammarParser::ImmediateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImmediate(this);
}


std::any VMGrammarParser::ImmediateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitImmediate(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::ImmediateContext* VMGrammarParser::immediate() {
  ImmediateContext *_localctx = _tracker.createInstance<ImmediateContext>(_ctx, getState());
  enterRule(_localctx, 20, VMGrammarParser::RuleImmediate);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(VMGrammarParser::HASH);
    setState(86);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VMGrammarParser::MINUS:
      case VMGrammarParser::INT:
      case VMGrammarParser::FLOAT: {
        setState(82);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == VMGrammarParser::MINUS) {
          setState(81);
          match(VMGrammarParser::MINUS);
        }
        setState(84);
        _la = _input->LA(1);
        if (!(_la == VMGrammarParser::INT

        || _la == VMGrammarParser::FLOAT)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case VMGrammarParser::VALLNULL: {
        setState(85);
        match(VMGrammarParser::VALLNULL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelContext ------------------------------------------------------------------

VMGrammarParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VMGrammarParser::LabelContext::ID() {
  return getToken(VMGrammarParser::ID, 0);
}


size_t VMGrammarParser::LabelContext::getRuleIndex() const {
  return VMGrammarParser::RuleLabel;
}

void VMGrammarParser::LabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel(this);
}

void VMGrammarParser::LabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VMGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel(this);
}


std::any VMGrammarParser::LabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VMGrammarVisitor*>(visitor))
    return parserVisitor->visitLabel(this);
  else
    return visitor->visitChildren(this);
}

VMGrammarParser::LabelContext* VMGrammarParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 22, VMGrammarParser::RuleLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(VMGrammarParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void VMGrammarParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  vmgrammarParserInitialize();
#else
  ::antlr4::internal::call_once(vmgrammarParserOnceFlag, vmgrammarParserInitialize);
#endif
}
