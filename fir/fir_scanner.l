%option c++ prefix="fir_scanner_" outfile="fir_scanner.cpp"
%option stack noyywrap yylineno 8bit
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "fir_parser.tab.h"

#include <iostream>

// don't change this
#define yyerror LexerError
%}

IDENTIFIER                        [A-Za-z][A-Za-z0-9_]*
INT                               0|[1-9][0-9]*  

%x X_COMMENT X_COMMENT_LINES X_OCTAL X_STRING X_TILDE X_IGNORE

%%

  //{set_debug(true);}

"!!"                              yy_push_state(X_COMMENT); 
<X_COMMENT>"\n"                   yy_pop_state();          
<X_COMMENT>.                      ;

"(*"                              yy_push_state(X_COMMENT);
<X_COMMENT_LINES>"*)"             yy_pop_state();
<X_COMMENT_LINES>.|"\n"           ;  /* ignore inside comments */

"int"                             return tTYPE_INT;
"float"                           return tTYPE_FLOAT;
"string"                          return tTYPE_STRING;

"void"                            return tTYPE_VOID;
"null"                            return tNULL;
"sizeof"                          return tSIZEOF;

"if"                              return tIF;
"then"                            return tTHEN;
"else"                            return tELSE;

"while"                           return tWHILE;
"do"                              return tDO;
"finally"                         return tFINALLY;
"leave"                           return tLEAVE;
"restart"                         return tRESTART;

">="                              return tGE; 
"<="                              return tLE; 
"=="                              return tEQ; 
"!="                              return tNE; 
"&&"                              return tAND;
"||"                              return tOR;

"return"                          return tRETURN;
"write"                           return tWRITE;
"writeln"                         return tWRITELN;  

"->"                              return tRET_VAL;
">>"                              return tEPILOGUE;

[-()\[\]+?*/%<>~=,;{}@]           return *yytext;

{IDENTIFIER}                      yylval.s = new std::string(yytext); return tIDENTIFIER;

0[0]+                             yyerror("Wrong zero representation!");

{INT}                             try { yylval.i = std::stoi(yytext, NULL, 10); return tINTEGER; }                        catch(const std::out_of_range & e) { yyerror("Overflow!"); }
0[0-7]+                           try { yylval.i = std::stoi(yytext, NULL, 8); return tINTEGER;}                          catch(const std::out_of_range & e) { yyerror("Overflow!"); }                                       
0[0-9]*                           yyerror("bad octal data!");

([0-9]*\.[0-9]+|[0-9]+\.[0-9]*|[0-9]+)([eE][-+]?[0-9]+)? try { yylval.d = std::stod(yytext, NULL); return tFLOAT; }       catch(const std::out_of_range & e) { yyerror("Overflow!"); }

"\'"                              yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>"\'"                    yy_pop_state(); return tSTRING;
<X_STRING>"~"                     yy_push_state(X_TILDE);
<X_STRING>.                       *yylval.s += yytext;

<X_TILDE>"0"                      yy_push_state(X_IGNORE);
<X_IGNORE>"~'"                    ;
<X_IGNORE>"\'"                    yy_pop_state(); yy_pop_state(); yy_pop_state(); return tSTRING;
<X_IGNORE>.                       ;

<X_TILDE>"n"                      *yylval.s += '\n'; yy_pop_state();
<X_TILDE>"r"                      *yylval.s += '\r'; yy_pop_state();
<X_TILDE>"t"                      *yylval.s += '\t'; yy_pop_state();
<X_TILDE>"\~"                     *yylval.s += '~'; yy_pop_state();
<X_TILDE>"\'"                     *yylval.s += '\''; yy_pop_state();

<X_TILDE>[a-fA-F0-9]{1,2}         *yylval.s += std::stoi(yytext, NULL, 16); yy_pop_state();

[ \t\n\r]+                        ; /* ignore whitespace */

.                                 yyerror("Unknown character");

%%
