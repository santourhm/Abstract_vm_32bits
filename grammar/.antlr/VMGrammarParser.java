// Generated from /home/santourh/abstract-vm-32bits/grammar/VMGrammar.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class VMGrammarParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		OPP=1, MUL=2, QUO=3, DIV=4, ADD=5, SUB=6, REM=7, FMA=8, WSTR=9, LOAD=10, 
		NEW=11, CMP=12, BRA=13, SEQ=14, SNE=15, SLT=16, SGT=17, SGE=18, SLE=19, 
		SOV=20, SHL=21, SHR=22, BEQ=23, BNE=24, BGE=25, BLT=26, BGT=27, BLE=28, 
		BOV=29, BSR=30, RTS=31, STORE=32, PUSH=33, POP=34, LEA=35, PEA=36, WINT=37, 
		WNL=38, HALT=39, WFLOAT=40, WTYPE=41, WADDR=42, SUBSP=43, ADDSP=44, TSTO=45, 
		RINT=46, RFLOAT=47, ERROR=48, COMMA=49, OPARENT=50, CPARENT=51, HASH=52, 
		MINUS=53, COLON=54, RREGISTER=55, GBREGISTER=56, LBREGISTER=57, SPREGISTER=58, 
		VALLNULL=59, STRING_LITERAL=60, INT=61, FLOAT=62, ID=63, COMMENT=64, WS=65, 
		NEWLINE=66;
	public static final int
		RULE_program = 0, RULE_line = 1, RULE_instruction_line = 2, RULE_label_definition = 3, 
		RULE_instruction = 4, RULE_opcode = 5, RULE_operand = 6, RULE_string_literal = 7, 
		RULE_register = 8, RULE_memory_address = 9, RULE_immediate = 10, RULE_label = 11;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "line", "instruction_line", "label_definition", "instruction", 
			"opcode", "operand", "string_literal", "register", "memory_address", 
			"immediate", "label"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'OPP'", "'MUL'", "'QUO'", "'DIV'", "'ADD'", "'SUB'", "'REM'", 
			"'FMA'", "'WSTR'", "'LOAD'", "'NEW'", "'CMP'", "'BRA'", "'SEQ'", "'SNE'", 
			"'SLT'", "'SGT'", "'SGE'", "'SLE'", "'SOV'", "'SHL'", "'SHR'", "'BEQ'", 
			"'BNE'", "'BGE'", "'BLT'", "'BGT'", "'BLE'", "'BOV'", "'BSR'", "'RTS'", 
			"'STORE'", "'PUSH'", "'POP'", "'LEA'", "'PEA'", "'WINT'", "'WNL'", "'HALT'", 
			"'WFLOAT'", "'WTYPE'", "'WADDR'", "'SUBSP'", "'ADDSP'", "'TSTO'", "'RINT'", 
			"'RFLOAT'", "'ERROR'", "','", "'('", "')'", "'#'", "'-'", "':'", null, 
			"'GB'", "'LB'", "'SP'", "'null'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "OPP", "MUL", "QUO", "DIV", "ADD", "SUB", "REM", "FMA", "WSTR", 
			"LOAD", "NEW", "CMP", "BRA", "SEQ", "SNE", "SLT", "SGT", "SGE", "SLE", 
			"SOV", "SHL", "SHR", "BEQ", "BNE", "BGE", "BLT", "BGT", "BLE", "BOV", 
			"BSR", "RTS", "STORE", "PUSH", "POP", "LEA", "PEA", "WINT", "WNL", "HALT", 
			"WFLOAT", "WTYPE", "WADDR", "SUBSP", "ADDSP", "TSTO", "RINT", "RFLOAT", 
			"ERROR", "COMMA", "OPARENT", "CPARENT", "HASH", "MINUS", "COLON", "RREGISTER", 
			"GBREGISTER", "LBREGISTER", "SPREGISTER", "VALLNULL", "STRING_LITERAL", 
			"INT", "FLOAT", "ID", "COMMENT", "WS", "NEWLINE"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "VMGrammar.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public VMGrammarParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(VMGrammarParser.EOF, 0); }
		public List<LineContext> line() {
			return getRuleContexts(LineContext.class);
		}
		public LineContext line(int i) {
			return getRuleContext(LineContext.class,i);
		}
		public Instruction_lineContext instruction_line() {
			return getRuleContext(Instruction_lineContext.class,0);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(27);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(24);
					line();
					}
					} 
				}
				setState(29);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			setState(31);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 562949953421310L) != 0)) {
				{
				setState(30);
				instruction_line();
				}
			}

			setState(33);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LineContext extends ParserRuleContext {
		public Label_definitionContext label_definition() {
			return getRuleContext(Label_definitionContext.class,0);
		}
		public Instruction_lineContext instruction_line() {
			return getRuleContext(Instruction_lineContext.class,0);
		}
		public List<TerminalNode> NEWLINE() { return getTokens(VMGrammarParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(VMGrammarParser.NEWLINE, i);
		}
		public LineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_line; }
	}

	public final LineContext line() throws RecognitionException {
		LineContext _localctx = new LineContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_line);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(37);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ID:
				{
				setState(35);
				label_definition();
				}
				break;
			case OPP:
			case MUL:
			case QUO:
			case DIV:
			case ADD:
			case SUB:
			case REM:
			case FMA:
			case WSTR:
			case LOAD:
			case NEW:
			case CMP:
			case BRA:
			case SEQ:
			case SNE:
			case SLT:
			case SGT:
			case SGE:
			case SLE:
			case SOV:
			case SHL:
			case SHR:
			case BEQ:
			case BNE:
			case BGE:
			case BLT:
			case BGT:
			case BLE:
			case BOV:
			case BSR:
			case RTS:
			case STORE:
			case PUSH:
			case POP:
			case LEA:
			case PEA:
			case WINT:
			case WNL:
			case HALT:
			case WFLOAT:
			case WTYPE:
			case WADDR:
			case SUBSP:
			case ADDSP:
			case TSTO:
			case RINT:
			case RFLOAT:
			case ERROR:
				{
				setState(36);
				instruction_line();
				}
				break;
			case NEWLINE:
				break;
			default:
				break;
			}
			setState(40); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(39);
					match(NEWLINE);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(42); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Instruction_lineContext extends ParserRuleContext {
		public InstructionContext instruction() {
			return getRuleContext(InstructionContext.class,0);
		}
		public Instruction_lineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_instruction_line; }
	}

	public final Instruction_lineContext instruction_line() throws RecognitionException {
		Instruction_lineContext _localctx = new Instruction_lineContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_instruction_line);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(44);
			instruction();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Label_definitionContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(VMGrammarParser.ID, 0); }
		public TerminalNode COLON() { return getToken(VMGrammarParser.COLON, 0); }
		public Label_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_label_definition; }
	}

	public final Label_definitionContext label_definition() throws RecognitionException {
		Label_definitionContext _localctx = new Label_definitionContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_label_definition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(46);
			match(ID);
			setState(47);
			match(COLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class InstructionContext extends ParserRuleContext {
		public OpcodeContext opcode() {
			return getRuleContext(OpcodeContext.class,0);
		}
		public List<OperandContext> operand() {
			return getRuleContexts(OperandContext.class);
		}
		public OperandContext operand(int i) {
			return getRuleContext(OperandContext.class,i);
		}
		public TerminalNode COMMA() { return getToken(VMGrammarParser.COMMA, 0); }
		public InstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_instruction; }
	}

	public final InstructionContext instruction() throws RecognitionException {
		InstructionContext _localctx = new InstructionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_instruction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(49);
			opcode();
			setState(55);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & -5209538868960821248L) != 0)) {
				{
				setState(50);
				operand();
				setState(53);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(51);
					match(COMMA);
					setState(52);
					operand();
					}
				}

				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class OpcodeContext extends ParserRuleContext {
		public TerminalNode ADD() { return getToken(VMGrammarParser.ADD, 0); }
		public TerminalNode MUL() { return getToken(VMGrammarParser.MUL, 0); }
		public TerminalNode QUO() { return getToken(VMGrammarParser.QUO, 0); }
		public TerminalNode DIV() { return getToken(VMGrammarParser.DIV, 0); }
		public TerminalNode OPP() { return getToken(VMGrammarParser.OPP, 0); }
		public TerminalNode REM() { return getToken(VMGrammarParser.REM, 0); }
		public TerminalNode SUB() { return getToken(VMGrammarParser.SUB, 0); }
		public TerminalNode WSTR() { return getToken(VMGrammarParser.WSTR, 0); }
		public TerminalNode LOAD() { return getToken(VMGrammarParser.LOAD, 0); }
		public TerminalNode CMP() { return getToken(VMGrammarParser.CMP, 0); }
		public TerminalNode BEQ() { return getToken(VMGrammarParser.BEQ, 0); }
		public TerminalNode BNE() { return getToken(VMGrammarParser.BNE, 0); }
		public TerminalNode BLT() { return getToken(VMGrammarParser.BLT, 0); }
		public TerminalNode BGT() { return getToken(VMGrammarParser.BGT, 0); }
		public TerminalNode BGE() { return getToken(VMGrammarParser.BGE, 0); }
		public TerminalNode BLE() { return getToken(VMGrammarParser.BLE, 0); }
		public TerminalNode BOV() { return getToken(VMGrammarParser.BOV, 0); }
		public TerminalNode SEQ() { return getToken(VMGrammarParser.SEQ, 0); }
		public TerminalNode SNE() { return getToken(VMGrammarParser.SNE, 0); }
		public TerminalNode SLT() { return getToken(VMGrammarParser.SLT, 0); }
		public TerminalNode SGT() { return getToken(VMGrammarParser.SGT, 0); }
		public TerminalNode SGE() { return getToken(VMGrammarParser.SGE, 0); }
		public TerminalNode SLE() { return getToken(VMGrammarParser.SLE, 0); }
		public TerminalNode SOV() { return getToken(VMGrammarParser.SOV, 0); }
		public TerminalNode SHL() { return getToken(VMGrammarParser.SHL, 0); }
		public TerminalNode SHR() { return getToken(VMGrammarParser.SHR, 0); }
		public TerminalNode BRA() { return getToken(VMGrammarParser.BRA, 0); }
		public TerminalNode WINT() { return getToken(VMGrammarParser.WINT, 0); }
		public TerminalNode WNL() { return getToken(VMGrammarParser.WNL, 0); }
		public TerminalNode WFLOAT() { return getToken(VMGrammarParser.WFLOAT, 0); }
		public TerminalNode HALT() { return getToken(VMGrammarParser.HALT, 0); }
		public TerminalNode STORE() { return getToken(VMGrammarParser.STORE, 0); }
		public TerminalNode PUSH() { return getToken(VMGrammarParser.PUSH, 0); }
		public TerminalNode POP() { return getToken(VMGrammarParser.POP, 0); }
		public TerminalNode LEA() { return getToken(VMGrammarParser.LEA, 0); }
		public TerminalNode PEA() { return getToken(VMGrammarParser.PEA, 0); }
		public TerminalNode BSR() { return getToken(VMGrammarParser.BSR, 0); }
		public TerminalNode RTS() { return getToken(VMGrammarParser.RTS, 0); }
		public TerminalNode SUBSP() { return getToken(VMGrammarParser.SUBSP, 0); }
		public TerminalNode ADDSP() { return getToken(VMGrammarParser.ADDSP, 0); }
		public TerminalNode RINT() { return getToken(VMGrammarParser.RINT, 0); }
		public TerminalNode RFLOAT() { return getToken(VMGrammarParser.RFLOAT, 0); }
		public TerminalNode ERROR() { return getToken(VMGrammarParser.ERROR, 0); }
		public TerminalNode TSTO() { return getToken(VMGrammarParser.TSTO, 0); }
		public TerminalNode NEW() { return getToken(VMGrammarParser.NEW, 0); }
		public TerminalNode WTYPE() { return getToken(VMGrammarParser.WTYPE, 0); }
		public TerminalNode WADDR() { return getToken(VMGrammarParser.WADDR, 0); }
		public TerminalNode FMA() { return getToken(VMGrammarParser.FMA, 0); }
		public OpcodeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_opcode; }
	}

	public final OpcodeContext opcode() throws RecognitionException {
		OpcodeContext _localctx = new OpcodeContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_opcode);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(57);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 562949953421310L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class OperandContext extends ParserRuleContext {
		public Memory_addressContext memory_address() {
			return getRuleContext(Memory_addressContext.class,0);
		}
		public ImmediateContext immediate() {
			return getRuleContext(ImmediateContext.class,0);
		}
		public RegisterContext register() {
			return getRuleContext(RegisterContext.class,0);
		}
		public String_literalContext string_literal() {
			return getRuleContext(String_literalContext.class,0);
		}
		public LabelContext label() {
			return getRuleContext(LabelContext.class,0);
		}
		public OperandContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_operand; }
	}

	public final OperandContext operand() throws RecognitionException {
		OperandContext _localctx = new OperandContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_operand);
		try {
			setState(64);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OPARENT:
			case MINUS:
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(59);
				memory_address();
				}
				break;
			case HASH:
				enterOuterAlt(_localctx, 2);
				{
				setState(60);
				immediate();
				}
				break;
			case RREGISTER:
			case GBREGISTER:
			case LBREGISTER:
			case SPREGISTER:
				enterOuterAlt(_localctx, 3);
				{
				setState(61);
				register();
				}
				break;
			case STRING_LITERAL:
				enterOuterAlt(_localctx, 4);
				{
				setState(62);
				string_literal();
				}
				break;
			case ID:
				enterOuterAlt(_localctx, 5);
				{
				setState(63);
				label();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class String_literalContext extends ParserRuleContext {
		public TerminalNode STRING_LITERAL() { return getToken(VMGrammarParser.STRING_LITERAL, 0); }
		public String_literalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_string_literal; }
	}

	public final String_literalContext string_literal() throws RecognitionException {
		String_literalContext _localctx = new String_literalContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_string_literal);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(66);
			match(STRING_LITERAL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RegisterContext extends ParserRuleContext {
		public TerminalNode RREGISTER() { return getToken(VMGrammarParser.RREGISTER, 0); }
		public TerminalNode GBREGISTER() { return getToken(VMGrammarParser.GBREGISTER, 0); }
		public TerminalNode LBREGISTER() { return getToken(VMGrammarParser.LBREGISTER, 0); }
		public TerminalNode SPREGISTER() { return getToken(VMGrammarParser.SPREGISTER, 0); }
		public RegisterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_register; }
	}

	public final RegisterContext register() throws RecognitionException {
		RegisterContext _localctx = new RegisterContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_register);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 540431955284459520L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Memory_addressContext extends ParserRuleContext {
		public TerminalNode OPARENT() { return getToken(VMGrammarParser.OPARENT, 0); }
		public RegisterContext register() {
			return getRuleContext(RegisterContext.class,0);
		}
		public TerminalNode CPARENT() { return getToken(VMGrammarParser.CPARENT, 0); }
		public TerminalNode INT() { return getToken(VMGrammarParser.INT, 0); }
		public TerminalNode MINUS() { return getToken(VMGrammarParser.MINUS, 0); }
		public Memory_addressContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_memory_address; }
	}

	public final Memory_addressContext memory_address() throws RecognitionException {
		Memory_addressContext _localctx = new Memory_addressContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_memory_address);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(74);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==MINUS || _la==INT) {
				{
				setState(71);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==MINUS) {
					{
					setState(70);
					match(MINUS);
					}
				}

				setState(73);
				match(INT);
				}
			}

			setState(76);
			match(OPARENT);
			setState(77);
			register();
			setState(78);
			match(CPARENT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ImmediateContext extends ParserRuleContext {
		public TerminalNode HASH() { return getToken(VMGrammarParser.HASH, 0); }
		public TerminalNode VALLNULL() { return getToken(VMGrammarParser.VALLNULL, 0); }
		public TerminalNode INT() { return getToken(VMGrammarParser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(VMGrammarParser.FLOAT, 0); }
		public TerminalNode MINUS() { return getToken(VMGrammarParser.MINUS, 0); }
		public ImmediateContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_immediate; }
	}

	public final ImmediateContext immediate() throws RecognitionException {
		ImmediateContext _localctx = new ImmediateContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_immediate);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(80);
			match(HASH);
			setState(86);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case MINUS:
			case INT:
			case FLOAT:
				{
				setState(82);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==MINUS) {
					{
					setState(81);
					match(MINUS);
					}
				}

				setState(84);
				_la = _input.LA(1);
				if ( !(_la==INT || _la==FLOAT) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			case VALLNULL:
				{
				setState(85);
				match(VALLNULL);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LabelContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(VMGrammarParser.ID, 0); }
		public LabelContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_label; }
	}

	public final LabelContext label() throws RecognitionException {
		LabelContext _localctx = new LabelContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_label);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(88);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001B[\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002\u0002"+
		"\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002\u0005"+
		"\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002\b\u0007"+
		"\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0001\u0000"+
		"\u0005\u0000\u001a\b\u0000\n\u0000\f\u0000\u001d\t\u0000\u0001\u0000\u0003"+
		"\u0000 \b\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0003"+
		"\u0001&\b\u0001\u0001\u0001\u0004\u0001)\b\u0001\u000b\u0001\f\u0001*"+
		"\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u00046\b\u0004\u0003\u0004"+
		"8\b\u0004\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0003\u0006A\b\u0006\u0001\u0007\u0001\u0007"+
		"\u0001\b\u0001\b\u0001\t\u0003\tH\b\t\u0001\t\u0003\tK\b\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\n\u0001\n\u0003\nS\b\n\u0001\n\u0001\n\u0003"+
		"\nW\b\n\u0001\u000b\u0001\u000b\u0001\u000b\u0000\u0000\f\u0000\u0002"+
		"\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0000\u0003\u0001\u0000"+
		"\u00010\u0001\u00007:\u0001\u0000=>]\u0000\u001b\u0001\u0000\u0000\u0000"+
		"\u0002%\u0001\u0000\u0000\u0000\u0004,\u0001\u0000\u0000\u0000\u0006."+
		"\u0001\u0000\u0000\u0000\b1\u0001\u0000\u0000\u0000\n9\u0001\u0000\u0000"+
		"\u0000\f@\u0001\u0000\u0000\u0000\u000eB\u0001\u0000\u0000\u0000\u0010"+
		"D\u0001\u0000\u0000\u0000\u0012J\u0001\u0000\u0000\u0000\u0014P\u0001"+
		"\u0000\u0000\u0000\u0016X\u0001\u0000\u0000\u0000\u0018\u001a\u0003\u0002"+
		"\u0001\u0000\u0019\u0018\u0001\u0000\u0000\u0000\u001a\u001d\u0001\u0000"+
		"\u0000\u0000\u001b\u0019\u0001\u0000\u0000\u0000\u001b\u001c\u0001\u0000"+
		"\u0000\u0000\u001c\u001f\u0001\u0000\u0000\u0000\u001d\u001b\u0001\u0000"+
		"\u0000\u0000\u001e \u0003\u0004\u0002\u0000\u001f\u001e\u0001\u0000\u0000"+
		"\u0000\u001f \u0001\u0000\u0000\u0000 !\u0001\u0000\u0000\u0000!\"\u0005"+
		"\u0000\u0000\u0001\"\u0001\u0001\u0000\u0000\u0000#&\u0003\u0006\u0003"+
		"\u0000$&\u0003\u0004\u0002\u0000%#\u0001\u0000\u0000\u0000%$\u0001\u0000"+
		"\u0000\u0000%&\u0001\u0000\u0000\u0000&(\u0001\u0000\u0000\u0000\')\u0005"+
		"B\u0000\u0000(\'\u0001\u0000\u0000\u0000)*\u0001\u0000\u0000\u0000*(\u0001"+
		"\u0000\u0000\u0000*+\u0001\u0000\u0000\u0000+\u0003\u0001\u0000\u0000"+
		"\u0000,-\u0003\b\u0004\u0000-\u0005\u0001\u0000\u0000\u0000./\u0005?\u0000"+
		"\u0000/0\u00056\u0000\u00000\u0007\u0001\u0000\u0000\u000017\u0003\n\u0005"+
		"\u000025\u0003\f\u0006\u000034\u00051\u0000\u000046\u0003\f\u0006\u0000"+
		"53\u0001\u0000\u0000\u000056\u0001\u0000\u0000\u000068\u0001\u0000\u0000"+
		"\u000072\u0001\u0000\u0000\u000078\u0001\u0000\u0000\u00008\t\u0001\u0000"+
		"\u0000\u00009:\u0007\u0000\u0000\u0000:\u000b\u0001\u0000\u0000\u0000"+
		";A\u0003\u0012\t\u0000<A\u0003\u0014\n\u0000=A\u0003\u0010\b\u0000>A\u0003"+
		"\u000e\u0007\u0000?A\u0003\u0016\u000b\u0000@;\u0001\u0000\u0000\u0000"+
		"@<\u0001\u0000\u0000\u0000@=\u0001\u0000\u0000\u0000@>\u0001\u0000\u0000"+
		"\u0000@?\u0001\u0000\u0000\u0000A\r\u0001\u0000\u0000\u0000BC\u0005<\u0000"+
		"\u0000C\u000f\u0001\u0000\u0000\u0000DE\u0007\u0001\u0000\u0000E\u0011"+
		"\u0001\u0000\u0000\u0000FH\u00055\u0000\u0000GF\u0001\u0000\u0000\u0000"+
		"GH\u0001\u0000\u0000\u0000HI\u0001\u0000\u0000\u0000IK\u0005=\u0000\u0000"+
		"JG\u0001\u0000\u0000\u0000JK\u0001\u0000\u0000\u0000KL\u0001\u0000\u0000"+
		"\u0000LM\u00052\u0000\u0000MN\u0003\u0010\b\u0000NO\u00053\u0000\u0000"+
		"O\u0013\u0001\u0000\u0000\u0000PV\u00054\u0000\u0000QS\u00055\u0000\u0000"+
		"RQ\u0001\u0000\u0000\u0000RS\u0001\u0000\u0000\u0000ST\u0001\u0000\u0000"+
		"\u0000TW\u0007\u0002\u0000\u0000UW\u0005;\u0000\u0000VR\u0001\u0000\u0000"+
		"\u0000VU\u0001\u0000\u0000\u0000W\u0015\u0001\u0000\u0000\u0000XY\u0005"+
		"?\u0000\u0000Y\u0017\u0001\u0000\u0000\u0000\u000b\u001b\u001f%*57@GJ"+
		"RV";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}