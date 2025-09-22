grammar VMGrammar;

// --- Parser Rules ---

program: line* (instruction_line)? EOF;

line: (label_definition | instruction_line)? NEWLINE+;

instruction_line: instruction;

label_definition: ID ':'; 

instruction
    : opcode (operand (COMMA operand)?)?
    ;

opcode
    : ADD | MUL | QUO | DIV | OPP | REM | SUB | WSTR | LOAD | CMP | 
      BEQ | BNE | BLT | BGT | BGE | BLE | BOV  | SEQ | SNE | SLT 
      | SGT  | SGE | SLE | SOV | SHL | SHR | BRA | WINT | WNL | WFLOAT | HALT 
      | STORE |  PUSH | POP |  LEA | PEA | BSR | RTS | SUBSP | ADDSP | RINT | RFLOAT | ERROR
      | TSTO | NEW | WTYPE | WADDR | FMA
    ;

operand
    : memory_address
    | immediate
    | register        
    | string_literal
    | label           
    ;
string_literal
    : STRING_LITERAL
    ;
    
register
    : RREGISTER | GBREGISTER | LBREGISTER | SPREGISTER
    ;

memory_address
    : (MINUS? INT)? OPARENT register CPARENT 
    ;

immediate
    : HASH ( MINUS? (INT | FLOAT) | VALLNULL)  
    ;

label
    : ID 
    ;


// --- Lexer Rules ---

OPP : 'OPP';
MUL : 'MUL';
QUO : 'QUO';
DIV : 'DIV';
ADD : 'ADD';
SUB : 'SUB';
REM : 'REM'; 
FMA : 'FMA';
WSTR: 'WSTR';
LOAD: 'LOAD';
NEW : 'NEW' ;
CMP : 'CMP';
BRA : 'BRA';
SEQ : 'SEQ';
SNE : 'SNE';
SLT : 'SLT';
SGT : 'SGT';
SGE : 'SGE';
SLE : 'SLE';
SOV : 'SOV';
SHL : 'SHL';
SHR : 'SHR';

BEQ : 'BEQ';
BNE : 'BNE';
BGE : 'BGE';
BLT : 'BLT';
BGT : 'BGT';
BLE : 'BLE';
BOV : 'BOV';

BSR : 'BSR';
RTS : 'RTS';

STORE : 'STORE';
PUSH  : 'PUSH' ;
POP   : 'POP'  ;
LEA   : 'LEA'  ;
PEA   : 'PEA'  ;

WINT: 'WINT';
WNL : 'WNL';
HALT : 'HALT';
WFLOAT : 'WFLOAT';
WTYPE : 'WTYPE';
WADDR : 'WADDR';

SUBSP  : 'SUBSP';
ADDSP  : 'ADDSP';
TSTO   : 'TSTO' ;
RINT    :  'RINT';
RFLOAT  :  'RFLOAT';

ERROR   : 'ERROR';


COMMA  : ',';
OPARENT: '(';
CPARENT: ')';
HASH   : '#';
MINUS  : '-';
COLON  : ':'; 

// Operands & Identifiers
RREGISTER      : 'R' INT;
GBREGISTER     : 'GB';
LBREGISTER     : 'LB';
SPREGISTER     : 'SP';
VALLNULL           : 'null';
STRING_LITERAL: '"' STRING '"';
INT           : [0-9]+;
FLOAT: [0-9]+ '.' [0-9]+;
ID: [a-zA-Z_] [a-zA-Z0-9_.]*;

fragment STRING        : ( ~["\\] | '\\' . )*;

COMMENT : ';' ~[\r\n]* -> skip;
WS      : [ \t]+ -> skip;
NEWLINE : ('\r'? '\n' | '\r');