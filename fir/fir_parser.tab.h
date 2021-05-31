/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_FIR_PARSER_TAB_H_INCLUDED
# define YY_YY_FIR_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tTYPE_INT = 258,               /* tTYPE_INT  */
    tTYPE_FLOAT = 259,             /* tTYPE_FLOAT  */
    tTYPE_STRING = 260,            /* tTYPE_STRING  */
    tTYPE_VOID = 261,              /* tTYPE_VOID  */
    tSIZEOF = 262,                 /* tSIZEOF  */
    tREQUIRE = 263,                /* tREQUIRE  */
    tIF = 264,                     /* tIF  */
    tTHEN = 265,                   /* tTHEN  */
    tELSE = 266,                   /* tELSE  */
    tWHILE = 267,                  /* tWHILE  */
    tDO = 268,                     /* tDO  */
    tFINALLY = 269,                /* tFINALLY  */
    tLEAVE = 270,                  /* tLEAVE  */
    tRESTART = 271,                /* tRESTART  */
    tGE = 272,                     /* tGE  */
    tLE = 273,                     /* tLE  */
    tEQ = 274,                     /* tEQ  */
    tNE = 275,                     /* tNE  */
    tAND = 276,                    /* tAND  */
    tOR = 277,                     /* tOR  */
    tRETURN = 278,                 /* tRETURN  */
    tWRITE = 279,                  /* tWRITE  */
    tWRITELN = 280,                /* tWRITELN  */
    tRET_VAL = 281,                /* tRET_VAL  */
    tEPILOGUE = 282,               /* tEPILOGUE  */
    tINTEGER = 283,                /* tINTEGER  */
    tFLOAT = 284,                  /* tFLOAT  */
    tIDENTIFIER = 285,             /* tIDENTIFIER  */
    tSTRING = 286,                 /* tSTRING  */
    tNULL = 287,                   /* tNULL  */
    tUNARY = 288                   /* tUNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "fir_parser.y"

  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	                   /* integer value */
  double                d;                       /* float value */
  std::string          *s;	                   /* symbol name or string literal */
  cdk::basic_node      *node;	                   /* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression;              /* expression nodes */
  cdk::lvalue_node     *lvalue;
  std::vector<std::string> *ids;
  fir::block_node          *block;
  fir::body_node           *body;
  fir::prologue_node       *prologue;

#line 120 "fir_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::shared_ptr<cdk::compiler> compiler);

#endif /* !YY_YY_FIR_PARSER_TAB_H_INCLUDED  */
