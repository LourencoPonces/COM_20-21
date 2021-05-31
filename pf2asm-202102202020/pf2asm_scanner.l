%option c++ prefix="pf2asm_scanner_" outfile="pf2asm_scanner.cpp"
%option stack noyywrap yylineno 8bit debug yymore
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "pf2asm_parser.tab.h"

// output stream for building string literals
static std::ostringstream strlit;

// don't change this
#define yyerror LexerError
%}

SPACE     ([ \t\r]|\n)
INT       [[:digit:]]+

%x X_COMMENT X_STRING X_BACKSLASH X_HEXADECIMAL X_HEX_INT

%%

  /* ====================================================================== */
  /* ====[                         COMMENTS                           ]==== */
  /* ====================================================================== */

";".*$                /* match the whole line (it is ignored) */

"/*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"*/"        yy_pop_state();
<X_COMMENT>.|"\n"      ;  /* ignore inside comments */

  /* ====================================================================== */
  /* ====[                  MNEMONICS / INTRUCTIONS                   ]==== */
  /* ====================================================================== */

BSS     return tBSS;
DATA    return tDATA;
RODATA  return tRODATA;
TEXT    return tTEXT;

SBYTE   return tSBYTE;
SSHORT  return tSSHORT;
SINT    return tSINT;
SFLOAT  return tSFLOAT;
SDOUBLE return tSDOUBLE;
SSTRING return tSSTRING;
SALLOC  return tSALLOC;
SADDR   return tSADDR;

ALIGN  return tALIGN;
LABEL  return tLABEL;
EXTERN return tEXTERN;
GLOBAL return tGLOBAL;

ADDR   return tADDR;
ADDRA  return tADDRA;
ADDRV  return tADDRV;
LOCAL  return tLOCAL;
LOCA   return tLOCA;
LOCV   return tLOCV;

LDBYTE   return tLDBYTE;  
LDSHORT  return tLDSHORT;
LDINT    return tLDINT;
LDFLOAT  return tLDFLOAT;
LDDOUBLE return tLDDOUBLE; 

STBYTE     return tSTBYTE;
STSHORT    return tSTSHORT;
STINT      return tSTINT;
STFLOAT    return tSTFLOAT;
STDOUBLE   return tSTDOUBLE;

SP         return tSP;
ALLOC      return tALLOC;
DUP32      return tDUP32;
DUP64      return tDUP64;
SWAP32     return tSWAP32;
SWAP64     return tSWAP64;
INT        return tINT;
FLOAT      return tFLOAT;
DOUBLE     return tDOUBLE;

NEG        return tNEG;
ADD        return tADD;
SUB        return tSUB;
MUL        return tMUL;
DIV        return tDIV;
UDIV       return tUDIV;
MOD        return tMOD;
UMOD       return tUMOD;

DNEG       return tDNEG;
DADD       return tDADD;
DSUB       return tDSUB;
DMUL       return tDMUL;
DDIV       return tDDIV;

INCR       return tINCR;
DECR       return tDECR;

D2F        return tD2F;
F2D        return tF2D;
D2I        return tD2I;
I2D        return tI2D;

EQ         return tEQ;
NE         return tNE;

GT         return tGT;
GE         return tGE;
LE         return tLE;
LT         return tLT;

UGT        return tUGT;
UGE        return tUGE;
ULE        return tULE;
ULT        return tULT;

DCMP       return tDCMP;

NOT        return tNOT;
AND        return tAND;
OR         return tOR;
XOR        return tXOR;

ROTL       return tROTL;
ROTR       return tROTR;
SHTL       return tSHTL;
SHTRU      return tSHTRU;
SHTRS      return tSHTRS;

ENTER      return tENTER;
START      return tSTART;
STFVAL32   return tSTFVAL32;
STFVAL64   return tSTFVAL64;
LEAVE      return tLEAVE;
RET        return tRET;
RETN       return tRETN;
CALL       return tCALL;
TRASH      return tTRASH;
LDFVAL32   return tLDFVAL32;
LDFVAL64   return tLDFVAL64;

JMP        return tJMP;
LEAP       return tLEAP;
BRANCH     return tBRANCH;

JZ         return tJZ;
JNZ        return tJNZ;

JEQ        return tJEQ;
JNE        return tJNE;

JGT        return tJGT;
JGE        return tJGE;
JLE        return tJLE;
JLT        return tJLT;

JUGT       return tJUGT;
JUGE       return tJUGE;
JULE       return tJULE;
JULT       return tJULT;

NIL        return tNIL;
NOP        return tNOP;

  /* ====================================================================== */
  /* ====[               EXPRESSION OPERATORS (LITERALS)              ]==== */
  /* ====================================================================== */

[-+*/%!<>?:@]          return *yytext;
"=="                   return T_EQ;
"!="                   return T_NE;
"<="                   return T_LE;
">="                   return T_GE;
"&&"                   return T_AND;
"||"                   return T_OR;

  /* ====================================================================== */
  /* ====[                DELIMITERS AND SEPARATORS                   ]==== */
  /* ====================================================================== */

[(),]                return *yytext;

  /* ====================================================================== */
  /* ====[                     INTEGER NUMBERS                        ]==== */
  /* ====================================================================== */

"0x"[[:xdigit:]]+    yylval.i = strtoul(yytext+2, NULL, 16); return T_LIT_INT;
{INT}                yylval.i = strtoul(yytext,   NULL, 10); return T_LIT_INT;

  /* ====================================================================== */
  /* ====[                       REAL NUMBERS                         ]==== */
  /* ====================================================================== */

([0-9]*\.[0-9]+|[0-9]+\.[0-9])([Ee]([-+])?[0-9]+)? { yylval.d = strtod(yytext, NULL); return T_LIT_REAL; }

  /* ====================================================================== */
  /* ====[                        IDENTIFIERS                         ]==== */
  /* ====================================================================== */

([[:alpha:]]|[_.:])([[:alnum:]]|[_.:])*  yylval.s = new std::string(yytext); return T_ID;

  /* ====================================================================== */
  /* ====[                          STRINGS                           ]==== */
  /* ====================================================================== */

"\""                           yy_push_state(X_STRING);
<X_STRING>\\                   yy_push_state(X_BACKSLASH);
<X_STRING>"\""                 {
                                 yylval.s = new std::string(strlit.str());
                                 strlit.str("");
                                 yy_pop_state();
                                 return T_LIT_STRING;
                               }
<X_STRING>.                    strlit << *yytext;

<X_BACKSLASH>n                 strlit << '\n'; yy_pop_state();
<X_BACKSLASH>r                 strlit << '\r'; yy_pop_state();
<X_BACKSLASH>t                 strlit << '\t'; yy_pop_state();
<X_BACKSLASH>"\""              strlit << '\"'; yy_pop_state();
<X_BACKSLASH>\\                strlit << '\\'; yy_pop_state();
<X_BACKSLASH>.                 strlit << *yytext; yy_pop_state();

  /* ====================================================================== */
  /* ====[                         AFTER THE END                      ]==== */
  /* ====================================================================== */

[[:space:]]|\n         /* ignore remaining white space inside the program */
.                      yyerror(yytext);    /* all other chars: error! */

  /* ====================================================================== */
  /* ====[                           THE END                          ]==== */
  /* ====================================================================== */

%%
