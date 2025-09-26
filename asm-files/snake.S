; start main program
	TSTO #21	; 0 (temporaires) 2 (variables)19 (Stores) 
	BOV stack_overflow_error
	ADDSP #21
; Main program
; --------------------------------------------------
; |       Construction des tables des methodes     |
; --------------------------------------------------
; Code for Object method table
	LOAD #null, R0
	STORE R0, 1(GB)
	LOAD code.Object.equals, R0
	STORE R0, 2(GB)
; Code for the method table of Point
	LEA 1(GB), R0
	STORE R0, 3(GB)
	LOAD code.Point.equals, R0
	STORE R0, 4(GB)
	LOAD code.Point.init, R0
	STORE R0, 5(GB)
; Code for the method table of Snake
	LEA 1(GB), R0
	STORE R0, 6(GB)
	LOAD code.Object.equals, R0
	STORE R0, 7(GB)
	LOAD code.Snake.init, R0
	STORE R0, 8(GB)
	LOAD code.Snake.moveSnake, R0
	STORE R0, 9(GB)
	LOAD code.Snake.turnLeft, R0
	STORE R0, 10(GB)
	LOAD code.Snake.turnRight, R0
	STORE R0, 11(GB)
	LOAD code.Snake.printState, R0
	STORE R0, 12(GB)
; --------------------------------------------------
; |                  Main Program                  |
; --------------------------------------------------
; --- List  Of declarations --- 
; Variable declaration: game
; allocate R2
	NEW #5, R2
	BOV tas_plein
	LEA 6(GB), R0
	STORE R0, 0(R2)
	PUSH R2
	BSR init.Snake
	POP R2
	STORE R2, 13(GB)
; release R2
; Variable declaration: i
; allocate R2
	LOAD #0, R2
	STORE R2, 14(GB)
; release R2
; --- List  Of Instructions --- 
; Saving registers
	ADDSP #2
	LOAD 13(GB), R2
	STORE R2, 0(SP)
	LOAD 0(SP), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 0(R2), R2
	BSR 2(R2)
	SUBSP #2
; Restoring registers
	BRA while_test_0
while_body_1:
; Saving registers
	ADDSP #2
	LOAD 13(GB), R2
	STORE R2, 0(SP)
	LOAD 0(SP), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 0(R2), R2
	BSR 6(R2)
	SUBSP #2
; Restoring registers
; Beginning of if-then-else statement
	LOAD 14(GB), R2
	LOAD #3, R4
	REM R4, R2
	BOV div_by_zero_error	; Overflow check for previous operation
	LOAD #0, R3
	CMP R3, R2
	BNE E_Sinon.3
; Saving registers
	ADDSP #2
	LOAD 13(GB), R3
	STORE R3, 0(SP)
	LOAD 0(SP), R3
	CMP #null, R3
	BEQ null_deref
	LOAD 0(R3), R3
	BSR 5(R3)
	SUBSP #2
; Restoring registers
	WSTR "Turning right"
	WNL
	BRA E_Fin.4
E_Sinon.3:
; Beginning of if-then-else statement
	LOAD 14(GB), R3
	LOAD #3, R4
	REM R4, R3
	BOV div_by_zero_error	; Overflow check for previous operation
	LOAD #1, R2
	CMP R2, R3
	BNE E_Sinon.5
; Saving registers
	ADDSP #2
	LOAD 13(GB), R2
	STORE R2, 0(SP)
	LOAD 0(SP), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 0(R2), R2
	BSR 4(R2)
	SUBSP #2
; Restoring registers
	WSTR "Turning left"
	WNL
	BRA E_Fin.6
E_Sinon.5:
E_Fin.6:
; End of if-then-else statement
E_Fin.4:
; End of if-then-else statement
; Saving registers
	ADDSP #2
	LOAD 13(GB), R2
	STORE R2, 0(SP)
	LOAD 0(SP), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 0(R2), R2
	BSR 3(R2)
	SUBSP #2
; Restoring registers
; Assignment
	LOAD 14(GB), R2
; allocate R3
	LOAD #1, R3
	ADD R3, R2
; No need for overflow check for type int
; release R3
	STORE R2, 14(GB)
while_test_0:
	LOAD 14(GB), R2
	LOAD #10, R3
	CMP R3, R2
	BGE while_end_2
	LOAD 13(GB), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 4(R2), R3
	CMP #0, R3
	BEQ while_end_2
	BRA while_body_1
while_end_2:
	WSTR "Game finished!"
	WNL
	HALT
; ----------------------------------------
;              Class Point
; ----------------------------------------
init.Point:
	ADDSP #1
	LOAD -2(LB), R1
; Default initialization of field Point.2
	LOAD #0, R0
	STORE R0, 2(R1)
	STORE R0, 2(R1)
; Default initialization of field Point.1
	LOAD #0, R0
	STORE R0, 1(R1)
	STORE R0, 1(R1)
	RTS
code.Point.init:
	TSTO #4
	BOV stack_overflow_error
	ADDSP #2
; Saving registers
; Saving registers
; Assignment
	LOAD -3(LB), R3
	LOAD -2(LB), R2
	STORE R3, 1(R2)
; Assignment
	LOAD -4(LB), R3
	LOAD -2(LB), R2
	STORE R3, 2(R2)
; Restoring registers
fin.Point.init:
; Restoring registers
	RTS
code.Point.equals:
	TSTO #1
	BOV stack_overflow_error
	ADDSP #1
; Saving registers
; Saving registers
	LOAD #1, R0
	LOAD -2(LB), R3
	LOAD 1(R3), R3
	LOAD -3(LB), R4
	CMP #null, R4
	BEQ null_deref
	LOAD 1(R4), R2
	CMP R2, R3
	BNE bool_false_7
	LOAD -2(LB), R2
	LOAD 2(R2), R2
	LOAD -3(LB), R4
	CMP #null, R4
	BEQ null_deref
	LOAD 2(R4), R3
	CMP R3, R2
	BNE bool_false_7
	BRA bool_end_8
bool_false_7:
	LOAD #0, R0
bool_end_8:
	BRA fin.Point.equals
; Restoring registers
fin.Point.equals:
; Restoring registers
	RTS
; ----------------------------------------
;              Class Snake
; ----------------------------------------
init.Snake:
	ADDSP #1
	LOAD -2(LB), R1
; Default initialization of field Snake.3
	LOAD #0, R0
	STORE R0, 3(R1)
	STORE R0, 3(R1)
; Default initialization of field Snake.1
	LOAD #null, R0
	STORE R0, 1(R1)
	STORE R0, 1(R1)
; Default initialization of field Snake.4
	LOAD #0, R0
	STORE R0, 4(R1)
	STORE R0, 4(R1)
; Default initialization of field Snake.2
	LOAD #null, R0
	STORE R0, 2(R1)
	STORE R0, 2(R1)
	RTS
code.Snake.init:
	TSTO #6
	BOV stack_overflow_error
	ADDSP #0
; Saving registers
; Saving registers
; Assignment
	NEW #3, R3
	BOV tas_plein
	LEA 3(GB), R0
	STORE R0, 0(R3)
	PUSH R3
	BSR init.Point
	POP R3
	LOAD -2(LB), R2
	STORE R3, 1(R2)
; Assignment
	NEW #3, R3
	BOV tas_plein
	LEA 3(GB), R0
	STORE R0, 0(R3)
	PUSH R3
	BSR init.Point
	POP R3
	LOAD -2(LB), R2
	STORE R3, 2(R2)
; Saving registers
	ADDSP #4
	LOAD -2(LB), R3
	LOAD 1(R3), R3
	STORE R3, 0(SP)
	LOAD #5, R3
	STORE R3, -1(SP)
	LOAD #5, R3
	STORE R3, -2(SP)
	LOAD 0(SP), R3
	CMP #null, R3
	BEQ null_deref
	LOAD 0(R3), R3
	BSR 2(R3)
	SUBSP #4
; Restoring registers
; Saving registers
	ADDSP #4
	LOAD -2(LB), R3
	LOAD 2(R3), R3
	STORE R3, 0(SP)
	LOAD #5, R3
	STORE R3, -1(SP)
	LOAD #5, R3
	STORE R3, -2(SP)
	LOAD 0(SP), R3
	CMP #null, R3
	BEQ null_deref
	LOAD 0(R3), R3
	BSR 2(R3)
	SUBSP #4
; Restoring registers
; Assignment
	LOAD #1, R3
	LOAD -2(LB), R2
	STORE R3, 3(R2)
; Assignment
	LOAD #1, R3
	LOAD -2(LB), R2
	STORE R3, 4(R2)
; Restoring registers
fin.Snake.init:
; Restoring registers
	RTS
code.Snake.moveSnake:
	TSTO #2
	BOV stack_overflow_error
	ADDSP #2
; Saving registers
; Saving registers
; Local Variable declaration: oldX
; allocate R3
	LOAD -2(LB), R2
	LOAD 1(R2), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 1(R2), R3
	STORE R3, 1(LB)
; release R3
; Local Variable declaration: oldY
; allocate R3
	LOAD -2(LB), R2
	LOAD 1(R2), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 2(R2), R3
	STORE R3, 2(LB)
; release R3
; Beginning of if-then-else statement
	LOAD -2(LB), R3
	LOAD 4(R3), R3
	CMP #0, R3
	BEQ E_Sinon.9
; Beginning of if-then-else statement
	LOAD -2(LB), R3
	LOAD 3(R3), R3
	LOAD #0, R2
	CMP R2, R3
	BNE E_Sinon.11
; Assignment
	LOAD -2(LB), R3
	LOAD 1(R3), R3
	CMP #null, R3
	BEQ null_deref
	LOAD 2(R3), R2
; allocate R3
	LOAD #1, R3
	SUB R3, R2
; No need for overflow check for type int
; release R3
	LOAD -2(LB), R3
	LOAD 1(R3), R3
	CMP #null, R3
	BEQ null_deref
	STORE R2, 2(R3)
	BRA E_Fin.12
E_Sinon.11:
; Beginning of if-then-else statement
	LOAD -2(LB), R2
	LOAD 3(R2), R2
	LOAD #1, R3
	CMP R3, R2
	BNE E_Sinon.13
; Assignment
	LOAD -2(LB), R2
	LOAD 1(R2), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 1(R2), R3
; allocate R2
	LOAD #1, R2
	ADD R2, R3
; No need for overflow check for type int
; release R2
	LOAD -2(LB), R2
	LOAD 1(R2), R2
	CMP #null, R2
	BEQ null_deref
	STORE R3, 1(R2)
	BRA E_Fin.14
E_Sinon.13:
; Beginning of if-then-else statement
	LOAD -2(LB), R3
	LOAD 3(R3), R3
	LOAD #2, R2
	CMP R2, R3
	BNE E_Sinon.15
; Assignment
	LOAD -2(LB), R3
	LOAD 1(R3), R3
	CMP #null, R3
	BEQ null_deref
	LOAD 2(R3), R2
; allocate R3
	LOAD #1, R3
	ADD R3, R2
; No need for overflow check for type int
; release R3
	LOAD -2(LB), R3
	LOAD 1(R3), R3
	CMP #null, R3
	BEQ null_deref
	STORE R2, 2(R3)
	BRA E_Fin.16
E_Sinon.15:
; Assignment
	LOAD -2(LB), R3
	LOAD 1(R3), R3
	CMP #null, R3
	BEQ null_deref
	LOAD 1(R3), R2
; allocate R3
	LOAD #1, R3
	SUB R3, R2
; No need for overflow check for type int
; release R3
	LOAD -2(LB), R3
	LOAD 1(R3), R3
	CMP #null, R3
	BEQ null_deref
	STORE R2, 1(R3)
E_Fin.16:
; End of if-then-else statement
E_Fin.14:
; End of if-then-else statement
E_Fin.12:
; End of if-then-else statement
; Beginning of if-then-else statement
	LOAD -2(LB), R4
	LOAD 1(R4), R4
	CMP #null, R4
	BEQ null_deref
	LOAD 1(R4), R2
	LOAD #0, R3
	CMP R3, R2
	BLT E_Fin_19
	LOAD -2(LB), R4
	LOAD 1(R4), R4
	CMP #null, R4
	BEQ null_deref
	LOAD 1(R4), R3
	LOAD #10, R2
	CMP R2, R3
	BGE E_Fin_19
	LOAD -2(LB), R4
	LOAD 1(R4), R4
	CMP #null, R4
	BEQ null_deref
	LOAD 2(R4), R2
	LOAD #0, R3
	CMP R3, R2
	BLT E_Fin_19
	LOAD -2(LB), R4
	LOAD 1(R4), R4
	CMP #null, R4
	BEQ null_deref
	LOAD 2(R4), R3
	LOAD #10, R2
	CMP R2, R3
	BLT E_Sinon.17
E_Fin_19:
; Assignment
	LOAD #0, R2
	LOAD -2(LB), R3
	STORE R2, 4(R3)
	WSTR "Game Over! Hit boundary!"
	WNL
	BRA E_Fin.18
E_Sinon.17:
; Beginning of if-then-else statement
; Saving registers
	PUSH R2
	ADDSP #4
	LOAD -2(LB), R3
	LOAD 1(R3), R3
	STORE R3, 0(SP)
	LOAD -2(LB), R3
	LOAD 2(R3), R3
	STORE R3, -1(SP)
	LOAD 0(SP), R3
	CMP #null, R3
	BEQ null_deref
	LOAD 0(R3), R3
	BSR 1(R3)
	SUBSP #4
; Restoring registers
	POP R2
	LOAD R0, R2
	CMP #0, R2
	BEQ E_Sinon.20
	WSTR "Food eaten!"
	WNL
; Assignment
	LOAD -2(LB), R3
	LOAD 2(R3), R3
	CMP #null, R3
	BEQ null_deref
	LOAD 1(R3), R2
; allocate R3
	LOAD #7, R3
	MUL R3, R2
; No need for overflow check for type int
; release R3
; allocate R3
	LOAD #3, R3
	ADD R3, R2
; No need for overflow check for type int
; release R3
	LOAD #10, R3
	REM R3, R2
	BOV div_by_zero_error	; Overflow check for previous operation
	LOAD -2(LB), R3
	LOAD 2(R3), R3
	CMP #null, R3
	BEQ null_deref
	STORE R2, 1(R3)
; Assignment
	LOAD -2(LB), R3
	LOAD 2(R3), R3
	CMP #null, R3
	BEQ null_deref
	LOAD 2(R3), R2
; allocate R3
	LOAD #5, R3
	MUL R3, R2
; No need for overflow check for type int
; release R3
; allocate R3
	LOAD #2, R3
	ADD R3, R2
; No need for overflow check for type int
; release R3
	LOAD #10, R3
	REM R3, R2
	BOV div_by_zero_error	; Overflow check for previous operation
	LOAD -2(LB), R3
	LOAD 2(R3), R3
	CMP #null, R3
	BEQ null_deref
	STORE R2, 2(R3)
	BRA E_Fin.21
E_Sinon.20:
E_Fin.21:
; End of if-then-else statement
E_Fin.18:
; End of if-then-else statement
	BRA E_Fin.10
E_Sinon.9:
E_Fin.10:
; End of if-then-else statement
; Restoring registers
fin.Snake.moveSnake:
; Restoring registers
	RTS
code.Snake.turnLeft:
	TSTO #4
	BOV stack_overflow_error
	ADDSP #0
; Saving registers
; Saving registers
; Assignment
	LOAD -2(LB), R2
	LOAD 3(R2), R2
; allocate R3
	LOAD #3, R3
	ADD R3, R2
; No need for overflow check for type int
; release R3
	LOAD #4, R3
	REM R3, R2
	BOV div_by_zero_error	; Overflow check for previous operation
	LOAD -2(LB), R3
	STORE R2, 3(R3)
; Restoring registers
fin.Snake.turnLeft:
; Restoring registers
	RTS
code.Snake.turnRight:
	TSTO #4
	BOV stack_overflow_error
	ADDSP #0
; Saving registers
; Saving registers
; Assignment
	LOAD -2(LB), R2
	LOAD 3(R2), R2
; allocate R3
	LOAD #1, R3
	ADD R3, R2
; No need for overflow check for type int
; release R3
	LOAD #4, R3
	REM R3, R2
	BOV div_by_zero_error	; Overflow check for previous operation
	LOAD -2(LB), R3
	STORE R2, 3(R3)
; Restoring registers
fin.Snake.turnRight:
; Restoring registers
	RTS
code.Snake.printState:
	TSTO #0
	BOV stack_overflow_error
	ADDSP #0
; Saving registers
; Saving registers
	WSTR "Snake head at ("
; Load in R1 to be able to display
	LOAD -2(LB), R2
	LOAD 1(R2), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 1(R2), R1
	WINT
	WSTR ","
; Load in R1 to be able to display
	LOAD -2(LB), R2
	LOAD 1(R2), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 2(R2), R1
	WINT
	WSTR ")"
	WNL
	WSTR "Food at ("
; Load in R1 to be able to display
	LOAD -2(LB), R2
	LOAD 2(R2), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 1(R2), R1
	WINT
	WSTR ","
; Load in R1 to be able to display
	LOAD -2(LB), R2
	LOAD 2(R2), R2
	CMP #null, R2
	BEQ null_deref
	LOAD 2(R2), R1
	WINT
	WSTR ")"
	WNL
	WSTR "Direction: "
; Load in R1 to be able to display
	LOAD -2(LB), R1
	LOAD 3(R1), R1
	WINT
	WNL
	WSTR "---------------"
	WNL
; Restoring registers
fin.Snake.printState:
; Restoring registers
	RTS
; |------ code.Object.equals --------|
init.Object:
	LOAD #null, R0
	STORE R0, 1(GB)
	RTS
code.Object.equals:
	LOAD -2(LB), R1
	LOAD -3(LB), R0
	CMP R0, R1
	SEQ R0
	RTS
; end main program
; --------------------------------------------------
; |                  ERROR Handling                |
; --------------------------------------------------
stack_overflow_error:
	WSTR "Error: Stack Overflow"
	WNL
	ERROR
div_by_zero_error:
	WSTR "Error: Division by zero"
	WNL
	ERROR
null_deref:
	WSTR "Erreur : dereferencement de null"
	WNL
	ERROR
tas_plein:
	WSTR "Erreur : tas_plein"
	WNL
	ERROR
cast_error:
	WSTR "Error: Invalid cast"
	WNL
	ERROR
