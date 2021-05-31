%option c++ prefix="gr8_scanner_" outfile="gr8_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <vector>
#include <sstream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "gr8_parser.tab.h"

static bool restart_functions = false;

static int lLevelsToPop = 0, lIndex = 0;
static std::vector<int> indents;   // known indentation levels
static std::vector<int> deferred;  // deferred tokens

// output stream for building string literals
static std::ostringstream strlit;

inline bool valid(int indent) {
    lLevelsToPop = lIndex = -1;
    bool indentOk = false;
    for (size_t ix = 0; ix < indents.size(); ix++) {
        if (indent == indents[ix]) {
            lLevelsToPop = indents.size() - ix - 1;
            lIndex = ix;
            indentOk = true;
        }
    }
    return indentOk;
}

// don't change this
#define yyerror LexerError
%}

SPACE     [ \t]
INT       [[:digit:]]+

LETTER  [A-Za-z]
IDENTIFIER   {LETTER}({LETTER}|"-"|[:digit:])*

%x X_COMMENT

%x X_STRING  X_TILDE
%x X_OCTAL   X_HEX_INT
%x X_NEWLINE

%%
  {
        //std::cerr << "################" << std::endl;
        set_debug(true);
        if (restart_functions) {
          std::cerr << "POPPING FUNCTIONS (" << indents.size() << ")" << std::endl;
          indents.pop_back();
          if (indents.size() == 0) restart_functions = false;
          return '}';
        }
        else {
          if (lLevelsToPop > 0) {
            std::cerr << "POPPING LEVELS (" << lLevelsToPop << ")" << std::endl;
            lLevelsToPop--;
            indents.pop_back();
            return '}';
          }
        }
        
  }

  /* ====================================================================== */
  /* ====[                      2.2 - COMMENTS                        ]==== */
  /* ====================================================================== */

{SPACE}*"..."\n        ; /* ignore continuation marks */

"!!".*\n                 ; /* ignore comments */

"<<"                   yy_push_state(X_COMMENT);
<X_COMMENT>"<<"        yy_push_state(X_COMMENT);
<X_COMMENT>">>"        yy_pop_state();
<X_COMMENT>.|\n        ; /* ignore content */

  /* ====================================================================== */
  /* ====[                      2.2 - INDENTATION                     ]==== */
  /* ====================================================================== */

\n                   yy_push_state(X_NEWLINE); /* delay decision */

<X_NEWLINE>^{SPACE}+  {
    yy_pop_state();

    if (valid(yyleng)) {
          std::cerr << "CASE 1" << std::endl;
          if (lLevelsToPop == 0) {
            // at the same level: ignore index
            // do not return tINDENT;
            std::cerr << "CASE 1a (levels to pop = 0)" << std::endl;
            return ';';
          }
          else {
            // nothing is done here: the scanner will ignore the input while levels > 0
            // and send block-end tokens to the parser
            std::cerr << "CASE 1b (levels to pop = " << lLevelsToPop << ")" << std::endl;
            // at least one has to be returned here...
            if (lLevelsToPop > 0) {
              std::cerr << "POPPING LEVELS (" << lLevelsToPop << ")" << std::endl;
              lLevelsToPop--;
              indents.pop_back();
              return '}';
            }
          }
    }
    else if (indents.size() == 0) {
          // first block to open
          std::cerr << "CASE 2" << std::endl;
          indents.push_back(yyleng);
          return '{';
    }
    else if (yyleng > indents.back()) {
          // this is like the one before, but not the first
          std::cerr << "CASE 3" << std::endl;
          indents.push_back(yyleng);
          return '{';
    }
    else {
          // something wrong: bad indent: communicate to user
          std::cerr << "CASE 4" << std::endl;
          std::cerr << "bad indent at line " << yylineno;
    }

}
<X_NEWLINE>\n      ; // ignore successive newline chars
<X_NEWLINE>.       {
  // in this case, we have a new function starting
  // first, return whatever we are seeing to the input
  yyless(0);
  yy_pop_state();
  if (indents.size() > 0) {
    std::cerr << "should restart " << indents.size() << " functions at " << yylineno << std::endl;
    indents.pop_back();
    if (indents.size() > 0) { restart_functions = true; }
    return '}';
  }
  else return ';'; // top-level declarations
}

  /* ====================================================================== */
  /* ====[                  1.1   - Tipos de dados                    ]==== */
  /* ====[                  3.4.1 - Constantes                        ]==== */
  /* ====[                  3.4.2 - Símbolos globais                  ]==== */
  /* ====================================================================== */

"small"                return tINT_TYPE;
"huge"                 return tREAL_TYPE;
"news"                 return tSTRING_TYPE;

"fake"                 return tFAKE;
"null"                 return tNULL;

"initially"            return tINITIALLY;

"use"                   return tUSE;
"public"                return tPUBLIC;

"input"                 return tINPUT;

  /* ====================================================================== */
  /* ====[                 5.5 - Instrução condicional                ]==== */
  /* ====================================================================== */

"if"                   return tIF; 
"then"                 return tTHEN; 
"elsif"                return tELSIF; 
"else"                 return tELSE; 

  /* ====================================================================== */
  /* ====[                 5.3 - Instrução de retorno                 ]==== */
  /* ====[                 5.4 - Instrução de continuação             ]==== */
  /* ====[                 5.5 - Instrução de terminação              ]==== */
  /* ====================================================================== */

"sweeping"             return tSWEEPING;
"from"                 return tFROM;
"to"                   return tTO;
"by"                   return tBY;
"do"                   return tDO;
"stop"                 return tSTOP;
"again"                return tAGAIN;
"return"               return tRETURN;

  /* ====================================================================== */
  /* ====[                 6 - Operadores de expressões               ]==== */
  /* ====================================================================== */

[(),?]       return *yytext;

"above"                return '>'; 
"below"                return '<'; 
"equals"               return tEQ; 

"not"                  return tNOT; 
"and"                  return '&'; 
"or"                   return '|'; 

"plus"                 return '+';
"minus"                return '-';
"times"                return '*'; 
"over"                 return '/';  
"modulus"              return '%';  

"assign"               return tASSIGN;

"at"                   return tAT;
"cell"                 return tCELL;
"objects"              return tOBJECTS;

  /* ====================================================================== */
  /* ====[              3   - Delimitadores e separadores             ]==== */
  /* ====[              4.3 - Corpo (de função)                       ]==== */
  /* ====================================================================== */

"post"                 return tPOST; 
"tweet"                return tTWEET; 

"define"               return tDEFINE;
"procedure"            return tPROCEDURE;
"function"             return tFUNCTION;
"on"                   return tON;
"as"                   return tAS;
"for"                  return tFOR;
"uses"                 return tUSES;

  /* ====================================================================== */
  /* ====[                   2.7.1 - inteiros                         ]==== */
  /* ====================================================================== */

0[0-6]+              yylval.i = strtoul(yytext, NULL, 7); return tINTEGER;
0[0-9]+              yyerror("Invalid base 7 number.");

0|[1-9][0-9]*        yylval.i = strtoul(yytext, NULL, 10); return tINTEGER;

  /* ====================================================================== */
  /* ====[                   2.7.2 - reais                            ]==== */
  /* ====================================================================== */

([0-9]*\.[0-9]+|[0-9]+\.[0-9])([Ee]([-+])?[0-9]+)? { yylval.d = strtod(yytext, NULL); return tREAL; }

  /* ====================================================================== */
  /* ====[                2.6 - Identificadores (nomes)               ]==== */
  /* ====================================================================== */

{IDENTIFIER}  yylval.s = new std::string(yytext); return tID;

  /* ====================================================================== */
  /* ====[              2.7.3 - Cadeias de caracteres                 ]==== */
  /* ====================================================================== */

"\""                   yy_push_state(X_STRING);
<X_STRING>"~"          yy_push_state(X_TILDE);
<X_STRING>"\""         {
                         yylval.s = new std::string(strlit.str());
                         strlit.str("");
                         yy_pop_state();
                         return tSTRING;
                       }
<X_STRING>.            strlit << *yytext;

<X_TILDE>n         strlit << '\n'; yy_pop_state();
<X_TILDE>r         strlit << '\r'; yy_pop_state();
<X_TILDE>t         strlit << '\t'; yy_pop_state();
<X_TILDE>"\""      strlit << '"'; yy_pop_state();
<X_TILDE>"~"       strlit << '~'; yy_pop_state();

<X_TILDE>[0-6]{1,3} {
                                 strlit << (char)(unsigned char)strtoul(yytext, NULL, 7);
                                 yy_pop_state();
                               }
<X_TILDE>.                 strlit << *yytext; yy_pop_state();

  /* ====================================================================== */
  /* ====[                    (other characters)                      ]==== */
  /* ====================================================================== */

<<EOF>>                {
  std::cout << "AT <<EOF>> OPEN INDENTS ARE " << indents.size() << std::endl;
  if (indents.size() > 0) {
    indents.pop_back();
    return '}';
  }
  return 0;  // nothing left to do: tell parser to proceed
}

[[:space:]]         /* ignore remaining white space inside the program */
.                      yyerror(yytext);    /* all other chars: error! */

  /* ====================================================================== */
  /* ====[                           THE END                          ]==== */
  /* ====================================================================== */

%%
