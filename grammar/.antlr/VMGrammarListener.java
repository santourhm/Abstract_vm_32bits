// Generated from /home/santourh/abstract-vm-32bits/grammar/VMGrammar.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link VMGrammarParser}.
 */
public interface VMGrammarListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(VMGrammarParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(VMGrammarParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#line}.
	 * @param ctx the parse tree
	 */
	void enterLine(VMGrammarParser.LineContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#line}.
	 * @param ctx the parse tree
	 */
	void exitLine(VMGrammarParser.LineContext ctx);
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#instruction_line}.
	 * @param ctx the parse tree
	 */
	void enterInstruction_line(VMGrammarParser.Instruction_lineContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#instruction_line}.
	 * @param ctx the parse tree
	 */
	void exitInstruction_line(VMGrammarParser.Instruction_lineContext ctx);
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#label_definition}.
	 * @param ctx the parse tree
	 */
	void enterLabel_definition(VMGrammarParser.Label_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#label_definition}.
	 * @param ctx the parse tree
	 */
	void exitLabel_definition(VMGrammarParser.Label_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#instruction}.
	 * @param ctx the parse tree
	 */
	void enterInstruction(VMGrammarParser.InstructionContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#instruction}.
	 * @param ctx the parse tree
	 */
	void exitInstruction(VMGrammarParser.InstructionContext ctx);
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#opcode}.
	 * @param ctx the parse tree
	 */
	void enterOpcode(VMGrammarParser.OpcodeContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#opcode}.
	 * @param ctx the parse tree
	 */
	void exitOpcode(VMGrammarParser.OpcodeContext ctx);
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#operand}.
	 * @param ctx the parse tree
	 */
	void enterOperand(VMGrammarParser.OperandContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#operand}.
	 * @param ctx the parse tree
	 */
	void exitOperand(VMGrammarParser.OperandContext ctx);
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#string_literal}.
	 * @param ctx the parse tree
	 */
	void enterString_literal(VMGrammarParser.String_literalContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#string_literal}.
	 * @param ctx the parse tree
	 */
	void exitString_literal(VMGrammarParser.String_literalContext ctx);
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#register}.
	 * @param ctx the parse tree
	 */
	void enterRegister(VMGrammarParser.RegisterContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#register}.
	 * @param ctx the parse tree
	 */
	void exitRegister(VMGrammarParser.RegisterContext ctx);
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#memory_address}.
	 * @param ctx the parse tree
	 */
	void enterMemory_address(VMGrammarParser.Memory_addressContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#memory_address}.
	 * @param ctx the parse tree
	 */
	void exitMemory_address(VMGrammarParser.Memory_addressContext ctx);
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#immediate}.
	 * @param ctx the parse tree
	 */
	void enterImmediate(VMGrammarParser.ImmediateContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#immediate}.
	 * @param ctx the parse tree
	 */
	void exitImmediate(VMGrammarParser.ImmediateContext ctx);
	/**
	 * Enter a parse tree produced by {@link VMGrammarParser#label}.
	 * @param ctx the parse tree
	 */
	void enterLabel(VMGrammarParser.LabelContext ctx);
	/**
	 * Exit a parse tree produced by {@link VMGrammarParser#label}.
	 * @param ctx the parse tree
	 */
	void exitLabel(VMGrammarParser.LabelContext ctx);
}