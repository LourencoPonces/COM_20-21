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

#ifndef YY_YY_PF2ASM_PARSER_TAB_H_INCLUDED
# define YY_YY_PF2ASM_PARSER_TAB_H_INCLUDED
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
    tBSS = 258,                    /* tBSS  */
    tDATA = 259,                   /* tDATA  */
    tRODATA = 260,                 /* tRODATA  */
    tTEXT = 261,                   /* tTEXT  */
    tSBYTE = 262,                  /* tSBYTE  */
    tSSHORT = 263,                 /* tSSHORT  */
    tSINT = 264,                   /* tSINT  */
    tSFLOAT = 265,                 /* tSFLOAT  */
    tSDOUBLE = 266,                /* tSDOUBLE  */
    tSSTRING = 267,                /* tSSTRING  */
    tSALLOC = 268,                 /* tSALLOC  */
    tSADDR = 269,                  /* tSADDR  */
    tALIGN = 270,                  /* tALIGN  */
    tLABEL = 271,                  /* tLABEL  */
    tEXTERN = 272,                 /* tEXTERN  */
    tGLOBAL = 273,                 /* tGLOBAL  */
    tADDR = 274,                   /* tADDR  */
    tADDRA = 275,                  /* tADDRA  */
    tADDRV = 276,                  /* tADDRV  */
    tLOCAL = 277,                  /* tLOCAL  */
    tLOCA = 278,                   /* tLOCA  */
    tLOCV = 279,                   /* tLOCV  */
    tLDBYTE = 280,                 /* tLDBYTE  */
    tLDSHORT = 281,                /* tLDSHORT  */
    tLDINT = 282,                  /* tLDINT  */
    tLDFLOAT = 283,                /* tLDFLOAT  */
    tLDDOUBLE = 284,               /* tLDDOUBLE  */
    tSTBYTE = 285,                 /* tSTBYTE  */
    tSTSHORT = 286,                /* tSTSHORT  */
    tSTINT = 287,                  /* tSTINT  */
    tSTFLOAT = 288,                /* tSTFLOAT  */
    tSTDOUBLE = 289,               /* tSTDOUBLE  */
    tSP = 290,                     /* tSP  */
    tALLOC = 291,                  /* tALLOC  */
    tDUP32 = 292,                  /* tDUP32  */
    tDUP64 = 293,                  /* tDUP64  */
    tSWAP32 = 294,                 /* tSWAP32  */
    tSWAP64 = 295,                 /* tSWAP64  */
    tINT = 296,                    /* tINT  */
    tFLOAT = 297,                  /* tFLOAT  */
    tDOUBLE = 298,                 /* tDOUBLE  */
    tNEG = 299,                    /* tNEG  */
    tADD = 300,                    /* tADD  */
    tSUB = 301,                    /* tSUB  */
    tMUL = 302,                    /* tMUL  */
    tDIV = 303,                    /* tDIV  */
    tUDIV = 304,                   /* tUDIV  */
    tMOD = 305,                    /* tMOD  */
    tUMOD = 306,                   /* tUMOD  */
    tDNEG = 307,                   /* tDNEG  */
    tDADD = 308,                   /* tDADD  */
    tDSUB = 309,                   /* tDSUB  */
    tDMUL = 310,                   /* tDMUL  */
    tDDIV = 311,                   /* tDDIV  */
    tINCR = 312,                   /* tINCR  */
    tDECR = 313,                   /* tDECR  */
    tD2F = 314,                    /* tD2F  */
    tF2D = 315,                    /* tF2D  */
    tD2I = 316,                    /* tD2I  */
    tI2D = 317,                    /* tI2D  */
    tEQ = 318,                     /* tEQ  */
    tNE = 319,                     /* tNE  */
    tGT = 320,                     /* tGT  */
    tGE = 321,                     /* tGE  */
    tLE = 322,                     /* tLE  */
    tLT = 323,                     /* tLT  */
    tUGT = 324,                    /* tUGT  */
    tUGE = 325,                    /* tUGE  */
    tULE = 326,                    /* tULE  */
    tULT = 327,                    /* tULT  */
    tDCMP = 328,                   /* tDCMP  */
    tNOT = 329,                    /* tNOT  */
    tAND = 330,                    /* tAND  */
    tOR = 331,                     /* tOR  */
    tXOR = 332,                    /* tXOR  */
    tROTL = 333,                   /* tROTL  */
    tROTR = 334,                   /* tROTR  */
    tSHTL = 335,                   /* tSHTL  */
    tSHTRU = 336,                  /* tSHTRU  */
    tSHTRS = 337,                  /* tSHTRS  */
    tENTER = 338,                  /* tENTER  */
    tSTART = 339,                  /* tSTART  */
    tLEAVE = 340,                  /* tLEAVE  */
    tRET = 341,                    /* tRET  */
    tRETN = 342,                   /* tRETN  */
    tCALL = 343,                   /* tCALL  */
    tTRASH = 344,                  /* tTRASH  */
    tSTFVAL32 = 345,               /* tSTFVAL32  */
    tSTFVAL64 = 346,               /* tSTFVAL64  */
    tLDFVAL32 = 347,               /* tLDFVAL32  */
    tLDFVAL64 = 348,               /* tLDFVAL64  */
    tJMP = 349,                    /* tJMP  */
    tLEAP = 350,                   /* tLEAP  */
    tBRANCH = 351,                 /* tBRANCH  */
    tJZ = 352,                     /* tJZ  */
    tJNZ = 353,                    /* tJNZ  */
    tJEQ = 354,                    /* tJEQ  */
    tJNE = 355,                    /* tJNE  */
    tJGT = 356,                    /* tJGT  */
    tJGE = 357,                    /* tJGE  */
    tJLE = 358,                    /* tJLE  */
    tJLT = 359,                    /* tJLT  */
    tJUGT = 360,                   /* tJUGT  */
    tJUGE = 361,                   /* tJUGE  */
    tJULE = 362,                   /* tJULE  */
    tJULT = 363,                   /* tJULT  */
    tNIL = 364,                    /* tNIL  */
    tNOP = 365,                    /* tNOP  */
    T_AND = 366,                   /* T_AND  */
    T_OR = 367,                    /* T_OR  */
    T_NE = 368,                    /* T_NE  */
    T_LE = 369,                    /* T_LE  */
    T_GE = 370,                    /* T_GE  */
    T_LIT_INT = 371,               /* T_LIT_INT  */
    T_LIT_REAL = 372,              /* T_LIT_REAL  */
    T_LIT_STRING = 373,            /* T_LIT_STRING  */
    T_ID = 374,                    /* T_ID  */
    T_EQ = 375,                    /* T_EQ  */
    T_UMINUS = 376                 /* T_UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "pf2asm_parser.y"

  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                  i;             /* integer number */
  double               d;             /* real number */
  std::string         *s;             /* symbol name or string literal */
  cdk::basic_node     *node;          /* node pointer */
  cdk::sequence_node  *sequence;      /* node pointer */

#line 202 "pf2asm_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::shared_ptr<cdk::compiler> compiler);

#endif /* !YY_YY_PF2ASM_PARSER_TAB_H_INCLUDED  */
