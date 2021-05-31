/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "pf2asm_parser.y"

// $Id: $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include "ast/all.h"
#define LINE                  compiler->scanner()->lineno()
#define yylex()               compiler->scanner()->scan()
#define yyerror(compiler, s)  compiler->scanner()->error(s)
//-- don't change *any* of these --- END!

#line 86 "pf2asm_parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "pf2asm_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tBSS = 3,                       /* tBSS  */
  YYSYMBOL_tDATA = 4,                      /* tDATA  */
  YYSYMBOL_tRODATA = 5,                    /* tRODATA  */
  YYSYMBOL_tTEXT = 6,                      /* tTEXT  */
  YYSYMBOL_tSBYTE = 7,                     /* tSBYTE  */
  YYSYMBOL_tSSHORT = 8,                    /* tSSHORT  */
  YYSYMBOL_tSINT = 9,                      /* tSINT  */
  YYSYMBOL_tSFLOAT = 10,                   /* tSFLOAT  */
  YYSYMBOL_tSDOUBLE = 11,                  /* tSDOUBLE  */
  YYSYMBOL_tSSTRING = 12,                  /* tSSTRING  */
  YYSYMBOL_tSALLOC = 13,                   /* tSALLOC  */
  YYSYMBOL_tSADDR = 14,                    /* tSADDR  */
  YYSYMBOL_tALIGN = 15,                    /* tALIGN  */
  YYSYMBOL_tLABEL = 16,                    /* tLABEL  */
  YYSYMBOL_tEXTERN = 17,                   /* tEXTERN  */
  YYSYMBOL_tGLOBAL = 18,                   /* tGLOBAL  */
  YYSYMBOL_tADDR = 19,                     /* tADDR  */
  YYSYMBOL_tADDRA = 20,                    /* tADDRA  */
  YYSYMBOL_tADDRV = 21,                    /* tADDRV  */
  YYSYMBOL_tLOCAL = 22,                    /* tLOCAL  */
  YYSYMBOL_tLOCA = 23,                     /* tLOCA  */
  YYSYMBOL_tLOCV = 24,                     /* tLOCV  */
  YYSYMBOL_tLDBYTE = 25,                   /* tLDBYTE  */
  YYSYMBOL_tLDSHORT = 26,                  /* tLDSHORT  */
  YYSYMBOL_tLDINT = 27,                    /* tLDINT  */
  YYSYMBOL_tLDFLOAT = 28,                  /* tLDFLOAT  */
  YYSYMBOL_tLDDOUBLE = 29,                 /* tLDDOUBLE  */
  YYSYMBOL_tSTBYTE = 30,                   /* tSTBYTE  */
  YYSYMBOL_tSTSHORT = 31,                  /* tSTSHORT  */
  YYSYMBOL_tSTINT = 32,                    /* tSTINT  */
  YYSYMBOL_tSTFLOAT = 33,                  /* tSTFLOAT  */
  YYSYMBOL_tSTDOUBLE = 34,                 /* tSTDOUBLE  */
  YYSYMBOL_tSP = 35,                       /* tSP  */
  YYSYMBOL_tALLOC = 36,                    /* tALLOC  */
  YYSYMBOL_tDUP32 = 37,                    /* tDUP32  */
  YYSYMBOL_tDUP64 = 38,                    /* tDUP64  */
  YYSYMBOL_tSWAP32 = 39,                   /* tSWAP32  */
  YYSYMBOL_tSWAP64 = 40,                   /* tSWAP64  */
  YYSYMBOL_tINT = 41,                      /* tINT  */
  YYSYMBOL_tFLOAT = 42,                    /* tFLOAT  */
  YYSYMBOL_tDOUBLE = 43,                   /* tDOUBLE  */
  YYSYMBOL_tNEG = 44,                      /* tNEG  */
  YYSYMBOL_tADD = 45,                      /* tADD  */
  YYSYMBOL_tSUB = 46,                      /* tSUB  */
  YYSYMBOL_tMUL = 47,                      /* tMUL  */
  YYSYMBOL_tDIV = 48,                      /* tDIV  */
  YYSYMBOL_tUDIV = 49,                     /* tUDIV  */
  YYSYMBOL_tMOD = 50,                      /* tMOD  */
  YYSYMBOL_tUMOD = 51,                     /* tUMOD  */
  YYSYMBOL_tDNEG = 52,                     /* tDNEG  */
  YYSYMBOL_tDADD = 53,                     /* tDADD  */
  YYSYMBOL_tDSUB = 54,                     /* tDSUB  */
  YYSYMBOL_tDMUL = 55,                     /* tDMUL  */
  YYSYMBOL_tDDIV = 56,                     /* tDDIV  */
  YYSYMBOL_tINCR = 57,                     /* tINCR  */
  YYSYMBOL_tDECR = 58,                     /* tDECR  */
  YYSYMBOL_tD2F = 59,                      /* tD2F  */
  YYSYMBOL_tF2D = 60,                      /* tF2D  */
  YYSYMBOL_tD2I = 61,                      /* tD2I  */
  YYSYMBOL_tI2D = 62,                      /* tI2D  */
  YYSYMBOL_tEQ = 63,                       /* tEQ  */
  YYSYMBOL_tNE = 64,                       /* tNE  */
  YYSYMBOL_tGT = 65,                       /* tGT  */
  YYSYMBOL_tGE = 66,                       /* tGE  */
  YYSYMBOL_tLE = 67,                       /* tLE  */
  YYSYMBOL_tLT = 68,                       /* tLT  */
  YYSYMBOL_tUGT = 69,                      /* tUGT  */
  YYSYMBOL_tUGE = 70,                      /* tUGE  */
  YYSYMBOL_tULE = 71,                      /* tULE  */
  YYSYMBOL_tULT = 72,                      /* tULT  */
  YYSYMBOL_tDCMP = 73,                     /* tDCMP  */
  YYSYMBOL_tNOT = 74,                      /* tNOT  */
  YYSYMBOL_tAND = 75,                      /* tAND  */
  YYSYMBOL_tOR = 76,                       /* tOR  */
  YYSYMBOL_tXOR = 77,                      /* tXOR  */
  YYSYMBOL_tROTL = 78,                     /* tROTL  */
  YYSYMBOL_tROTR = 79,                     /* tROTR  */
  YYSYMBOL_tSHTL = 80,                     /* tSHTL  */
  YYSYMBOL_tSHTRU = 81,                    /* tSHTRU  */
  YYSYMBOL_tSHTRS = 82,                    /* tSHTRS  */
  YYSYMBOL_tENTER = 83,                    /* tENTER  */
  YYSYMBOL_tSTART = 84,                    /* tSTART  */
  YYSYMBOL_tLEAVE = 85,                    /* tLEAVE  */
  YYSYMBOL_tRET = 86,                      /* tRET  */
  YYSYMBOL_tRETN = 87,                     /* tRETN  */
  YYSYMBOL_tCALL = 88,                     /* tCALL  */
  YYSYMBOL_tTRASH = 89,                    /* tTRASH  */
  YYSYMBOL_tSTFVAL32 = 90,                 /* tSTFVAL32  */
  YYSYMBOL_tSTFVAL64 = 91,                 /* tSTFVAL64  */
  YYSYMBOL_tLDFVAL32 = 92,                 /* tLDFVAL32  */
  YYSYMBOL_tLDFVAL64 = 93,                 /* tLDFVAL64  */
  YYSYMBOL_tJMP = 94,                      /* tJMP  */
  YYSYMBOL_tLEAP = 95,                     /* tLEAP  */
  YYSYMBOL_tBRANCH = 96,                   /* tBRANCH  */
  YYSYMBOL_tJZ = 97,                       /* tJZ  */
  YYSYMBOL_tJNZ = 98,                      /* tJNZ  */
  YYSYMBOL_tJEQ = 99,                      /* tJEQ  */
  YYSYMBOL_tJNE = 100,                     /* tJNE  */
  YYSYMBOL_tJGT = 101,                     /* tJGT  */
  YYSYMBOL_tJGE = 102,                     /* tJGE  */
  YYSYMBOL_tJLE = 103,                     /* tJLE  */
  YYSYMBOL_tJLT = 104,                     /* tJLT  */
  YYSYMBOL_tJUGT = 105,                    /* tJUGT  */
  YYSYMBOL_tJUGE = 106,                    /* tJUGE  */
  YYSYMBOL_tJULE = 107,                    /* tJULE  */
  YYSYMBOL_tJULT = 108,                    /* tJULT  */
  YYSYMBOL_tNIL = 109,                     /* tNIL  */
  YYSYMBOL_tNOP = 110,                     /* tNOP  */
  YYSYMBOL_T_AND = 111,                    /* T_AND  */
  YYSYMBOL_T_OR = 112,                     /* T_OR  */
  YYSYMBOL_T_NE = 113,                     /* T_NE  */
  YYSYMBOL_T_LE = 114,                     /* T_LE  */
  YYSYMBOL_T_GE = 115,                     /* T_GE  */
  YYSYMBOL_T_LIT_INT = 116,                /* T_LIT_INT  */
  YYSYMBOL_T_LIT_REAL = 117,               /* T_LIT_REAL  */
  YYSYMBOL_T_LIT_STRING = 118,             /* T_LIT_STRING  */
  YYSYMBOL_T_ID = 119,                     /* T_ID  */
  YYSYMBOL_120_ = 120,                     /* '?'  */
  YYSYMBOL_121_ = 121,                     /* ':'  */
  YYSYMBOL_T_EQ = 122,                     /* T_EQ  */
  YYSYMBOL_123_ = 123,                     /* '<'  */
  YYSYMBOL_124_ = 124,                     /* '>'  */
  YYSYMBOL_125_ = 125,                     /* '+'  */
  YYSYMBOL_126_ = 126,                     /* '-'  */
  YYSYMBOL_127_ = 127,                     /* '*'  */
  YYSYMBOL_128_ = 128,                     /* '/'  */
  YYSYMBOL_129_ = 129,                     /* '%'  */
  YYSYMBOL_T_UMINUS = 130,                 /* T_UMINUS  */
  YYSYMBOL_131_ = 131,                     /* '!'  */
  YYSYMBOL_132_ = 132,                     /* ','  */
  YYSYMBOL_133_ = 133,                     /* '('  */
  YYSYMBOL_134_ = 134,                     /* ')'  */
  YYSYMBOL_YYACCEPT = 135,                 /* $accept  */
  YYSYMBOL_file = 136,                     /* file  */
  YYSYMBOL_instructions = 137,             /* instructions  */
  YYSYMBOL_instruction = 138,              /* instruction  */
  YYSYMBOL_bytes = 139,                    /* bytes  */
  YYSYMBOL_data = 140,                     /* data  */
  YYSYMBOL_addressing = 141,               /* addressing  */
  YYSYMBOL_offset = 142,                   /* offset  */
  YYSYMBOL_label = 143,                    /* label  */
  YYSYMBOL_type = 144,                     /* type  */
  YYSYMBOL_function = 145,                 /* function  */
  YYSYMBOL_loadstore = 146,                /* loadstore  */
  YYSYMBOL_arithmetic = 147,               /* arithmetic  */
  YYSYMBOL_bitwise = 148,                  /* bitwise  */
  YYSYMBOL_relational = 149,               /* relational  */
  YYSYMBOL_jumps = 150,                    /* jumps  */
  YYSYMBOL_integer = 151                   /* integer  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  167
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  135
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   376


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   131,     2,     2,     2,   129,     2,     2,
     133,   134,   127,   125,   132,   126,     2,   128,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   121,     2,
     123,     2,   124,   120,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   122,   130
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    84,    84,    85,    88,    89,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   117,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   148,   149,   150,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tBSS", "tDATA",
  "tRODATA", "tTEXT", "tSBYTE", "tSSHORT", "tSINT", "tSFLOAT", "tSDOUBLE",
  "tSSTRING", "tSALLOC", "tSADDR", "tALIGN", "tLABEL", "tEXTERN",
  "tGLOBAL", "tADDR", "tADDRA", "tADDRV", "tLOCAL", "tLOCA", "tLOCV",
  "tLDBYTE", "tLDSHORT", "tLDINT", "tLDFLOAT", "tLDDOUBLE", "tSTBYTE",
  "tSTSHORT", "tSTINT", "tSTFLOAT", "tSTDOUBLE", "tSP", "tALLOC", "tDUP32",
  "tDUP64", "tSWAP32", "tSWAP64", "tINT", "tFLOAT", "tDOUBLE", "tNEG",
  "tADD", "tSUB", "tMUL", "tDIV", "tUDIV", "tMOD", "tUMOD", "tDNEG",
  "tDADD", "tDSUB", "tDMUL", "tDDIV", "tINCR", "tDECR", "tD2F", "tF2D",
  "tD2I", "tI2D", "tEQ", "tNE", "tGT", "tGE", "tLE", "tLT", "tUGT", "tUGE",
  "tULE", "tULT", "tDCMP", "tNOT", "tAND", "tOR", "tXOR", "tROTL", "tROTR",
  "tSHTL", "tSHTRU", "tSHTRS", "tENTER", "tSTART", "tLEAVE", "tRET",
  "tRETN", "tCALL", "tTRASH", "tSTFVAL32", "tSTFVAL64", "tLDFVAL32",
  "tLDFVAL64", "tJMP", "tLEAP", "tBRANCH", "tJZ", "tJNZ", "tJEQ", "tJNE",
  "tJGT", "tJGE", "tJLE", "tJLT", "tJUGT", "tJUGE", "tJULE", "tJULT",
  "tNIL", "tNOP", "T_AND", "T_OR", "T_NE", "T_LE", "T_GE", "T_LIT_INT",
  "T_LIT_REAL", "T_LIT_STRING", "T_ID", "'?'", "':'", "T_EQ", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "T_UMINUS", "'!'", "','", "'('",
  "')'", "$accept", "file", "instructions", "instruction", "bytes", "data",
  "addressing", "offset", "label", "type", "function", "loadstore",
  "arithmetic", "bitwise", "relational", "jumps", "integer", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
      63,    58,   375,    60,    62,    43,    45,    42,    47,    37,
     376,    33,    44,    40,    41
};
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     193,  -126,  -126,  -126,  -126,  -106,   -95,   -95,  -101,   -99,
     -83,   -95,   -87,  -126,   -87,   -87,   -87,   -87,   -87,   -87,
     -95,   -95,   -95,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,   -95,
     -80,   -56,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,   -95,   -95,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,   -95,  -126,  -126,  -126,   -95,   -87,   -95,  -126,  -126,
    -126,  -126,   -87,  -126,  -126,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,  -126,  -126,    62,
     193,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,   -95,   -95,   -95,   -95,   -14,   -14,  -126,  -126,
    -126,   -14,  -126,  -126,  -126,  -126,   -67,  -126,  -126,  -126,
    -126,   -14,  -126,  -126,   -14,  -126,  -126,   -14,   -14,  -126,
     -14,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -100,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -55,  -126,    23,   -86,   -86,
     -69,    23,   -86,   -86,  -125,  -125,  -126,  -126,  -126,  -126,
    -126,   -95,     7
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    44,    43,    42,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    70,    72,    74,    76,    69,    71,
      73,    75,    77,    15,     9,    11,    12,    13,    14,     0,
       0,     0,    83,    78,    79,    80,    81,    84,    82,    85,
      90,    86,    87,    88,    89,     0,     0,    19,    17,    18,
      16,   104,   105,   100,   101,   103,   102,   106,   107,   109,
     108,   110,    99,    96,    97,    98,    91,    92,    93,    94,
      95,     0,    59,    60,    62,     0,     0,     0,    65,    67,
      64,    66,     0,   112,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     6,     0,
       3,     4,    21,    23,    22,    24,    26,    25,    27,    28,
      33,   126,     0,     0,     0,     0,    31,    30,    36,    37,
      32,    35,    56,    34,    51,    50,     0,    52,    54,    53,
      46,    55,    48,    47,    38,    39,    40,     7,     8,    58,
      29,    63,    61,    10,   113,   114,   115,   116,   117,   118,
     119,   121,   120,   122,   123,   125,   124,     1,     5,   140,
     139,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   137,   133,   135,
       0,   134,   132,   136,   127,   128,   129,   130,   131,    57,
      49,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -126,  -126,  -126,   -47,   -68,  -126,  -126,    26,    -8,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,    -6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,   109,   110,   111,   149,   112,   113,   140,   133,   200,
     114,   115,   116,   117,   118,   119,   141
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     126,   127,   182,   183,   184,   131,   134,   135,   136,   137,
     138,   139,   120,   173,   174,   175,   128,   151,   129,   153,
     176,   121,   177,   178,   179,   180,   181,   182,   183,   184,
     122,   123,   132,   144,   186,   130,   124,   145,   125,   180,
     181,   182,   183,   184,   173,   174,   175,   142,   143,   147,
     148,   176,   201,   177,   178,   179,   180,   181,   182,   183,
     184,   146,   167,   168,   199,   185,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,     0,     0,   152,   150,
       0,   150,     0,     0,   154,     0,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   173,
     174,   175,     0,     0,     0,     0,   176,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   169,   170,   171,   172,
     173,   174,   175,     0,     0,     0,     0,     0,     0,   177,
     178,   179,   180,   181,   182,   183,   184,   174,   175,     0,
       0,     0,     0,     0,     0,     0,   178,   179,   180,   181,
     182,   183,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108
};

static const yytype_int16 yycheck[] =
{
       6,     7,   127,   128,   129,    11,    14,    15,    16,    17,
      18,    19,   118,   113,   114,   115,   117,    85,   117,    87,
     120,   116,   122,   123,   124,   125,   126,   127,   128,   129,
     125,   126,   119,    39,   134,   118,   131,   117,   133,   125,
     126,   127,   128,   129,   113,   114,   115,    21,    22,    55,
      56,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   117,     0,   110,   119,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    86,    85,
      -1,    87,    -1,    -1,    92,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   113,
     114,   115,    -1,    -1,    -1,    -1,   120,    -1,   122,   123,
     124,   125,   126,   127,   128,   129,   122,   123,   124,   125,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   136,
     137,   138,   140,   141,   145,   146,   147,   148,   149,   150,
     118,   116,   125,   126,   131,   133,   151,   151,   117,   117,
     118,   151,   119,   143,   143,   143,   143,   143,   143,   143,
     142,   151,   142,   142,   151,   117,   117,   151,   151,   139,
     151,   139,   143,   139,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,     0,   138,   151,
     151,   151,   151,   113,   114,   115,   120,   122,   123,   124,
     125,   126,   127,   128,   129,   132,   134,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   119,
     144,   121,   151
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   135,   136,   136,   137,   137,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   139,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   142,   143,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     2,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     2,     2,     4,
       2,     2,     2,     2,     2,     1,     1,     1,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (compiler, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (compiler);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, compiler);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, std::shared_ptr<cdk::compiler> compiler)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YY_USE (yyvaluep);
  YY_USE (compiler);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (std::shared_ptr<cdk::compiler> compiler)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* file: %empty  */
#line 84 "pf2asm_parser.y"
                               { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, new cdk::nil_node(LINE))); }
#line 1427 "pf2asm_parser.tab.c"
    break;

  case 3: /* file: instructions  */
#line 85 "pf2asm_parser.y"
                               { compiler->ast((yyval.sequence) = (yyvsp[0].sequence)); }
#line 1433 "pf2asm_parser.tab.c"
    break;

  case 4: /* instructions: instruction  */
#line 88 "pf2asm_parser.y"
                                                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1439 "pf2asm_parser.tab.c"
    break;

  case 5: /* instructions: instructions instruction  */
#line 89 "pf2asm_parser.y"
                                                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1445 "pf2asm_parser.tab.c"
    break;

  case 6: /* instruction: tNOP  */
#line 92 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::NOP(LINE); }
#line 1451 "pf2asm_parser.tab.c"
    break;

  case 7: /* instruction: tINCR integer  */
#line 93 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::INCR(LINE, (yyvsp[0].i)); }
#line 1457 "pf2asm_parser.tab.c"
    break;

  case 8: /* instruction: tDECR integer  */
#line 94 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::DECR(LINE, (yyvsp[0].i)); }
#line 1463 "pf2asm_parser.tab.c"
    break;

  case 9: /* instruction: tALLOC  */
#line 95 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::ALLOC(LINE); }
#line 1469 "pf2asm_parser.tab.c"
    break;

  case 10: /* instruction: tTRASH bytes  */
#line 96 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::TRASH(LINE, (yyvsp[0].i)); }
#line 1475 "pf2asm_parser.tab.c"
    break;

  case 11: /* instruction: tDUP32  */
#line 97 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::DUP32(LINE); }
#line 1481 "pf2asm_parser.tab.c"
    break;

  case 12: /* instruction: tDUP64  */
#line 98 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::DUP64(LINE); }
#line 1487 "pf2asm_parser.tab.c"
    break;

  case 13: /* instruction: tSWAP32  */
#line 99 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::SWAP32(LINE); }
#line 1493 "pf2asm_parser.tab.c"
    break;

  case 14: /* instruction: tSWAP64  */
#line 100 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::SWAP64(LINE); }
#line 1499 "pf2asm_parser.tab.c"
    break;

  case 15: /* instruction: tSP  */
#line 101 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::SP(LINE); }
#line 1505 "pf2asm_parser.tab.c"
    break;

  case 16: /* instruction: tI2D  */
#line 102 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::I2D(LINE); }
#line 1511 "pf2asm_parser.tab.c"
    break;

  case 17: /* instruction: tF2D  */
#line 103 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::F2D(LINE); }
#line 1517 "pf2asm_parser.tab.c"
    break;

  case 18: /* instruction: tD2I  */
#line 104 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::D2I(LINE); }
#line 1523 "pf2asm_parser.tab.c"
    break;

  case 19: /* instruction: tD2F  */
#line 105 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::D2F(LINE); }
#line 1529 "pf2asm_parser.tab.c"
    break;

  case 20: /* instruction: tNIL  */
#line 106 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::NIL(LINE); }
#line 1535 "pf2asm_parser.tab.c"
    break;

  case 21: /* instruction: data  */
#line 107 "pf2asm_parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1541 "pf2asm_parser.tab.c"
    break;

  case 22: /* instruction: function  */
#line 108 "pf2asm_parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1547 "pf2asm_parser.tab.c"
    break;

  case 23: /* instruction: addressing  */
#line 109 "pf2asm_parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1553 "pf2asm_parser.tab.c"
    break;

  case 24: /* instruction: loadstore  */
#line 110 "pf2asm_parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1559 "pf2asm_parser.tab.c"
    break;

  case 25: /* instruction: bitwise  */
#line 111 "pf2asm_parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1565 "pf2asm_parser.tab.c"
    break;

  case 26: /* instruction: arithmetic  */
#line 112 "pf2asm_parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1571 "pf2asm_parser.tab.c"
    break;

  case 27: /* instruction: relational  */
#line 113 "pf2asm_parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1577 "pf2asm_parser.tab.c"
    break;

  case 28: /* instruction: jumps  */
#line 114 "pf2asm_parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1583 "pf2asm_parser.tab.c"
    break;

  case 29: /* bytes: integer  */
#line 117 "pf2asm_parser.y"
                                    { (yyval.i) = (yyvsp[0].i); }
#line 1589 "pf2asm_parser.tab.c"
    break;

  case 30: /* data: tSINT integer  */
#line 119 "pf2asm_parser.y"
                                        { (yyval.node) = new pf2asm::SINT   (LINE, (yyvsp[0].i)); }
#line 1595 "pf2asm_parser.tab.c"
    break;

  case 31: /* data: tSSHORT integer  */
#line 120 "pf2asm_parser.y"
                                        { (yyval.node) = new pf2asm::SSHORT (LINE, (yyvsp[0].i)); }
#line 1601 "pf2asm_parser.tab.c"
    break;

  case 32: /* data: tSSTRING T_LIT_STRING  */
#line 121 "pf2asm_parser.y"
                                        { (yyval.node) = new pf2asm::SSTRING(LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1607 "pf2asm_parser.tab.c"
    break;

  case 33: /* data: tSBYTE T_LIT_STRING  */
#line 122 "pf2asm_parser.y"
                                        { (yyval.node) = new pf2asm::SBYTE  (LINE, (*(yyvsp[0].s))[0]); delete (yyvsp[0].s); }
#line 1613 "pf2asm_parser.tab.c"
    break;

  case 34: /* data: tSADDR label  */
#line 123 "pf2asm_parser.y"
                                        { (yyval.node) = new pf2asm::SADDR  (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1619 "pf2asm_parser.tab.c"
    break;

  case 35: /* data: tSALLOC integer  */
#line 124 "pf2asm_parser.y"
                                        { (yyval.node) = new pf2asm::SALLOC (LINE, (yyvsp[0].i)); }
#line 1625 "pf2asm_parser.tab.c"
    break;

  case 36: /* data: tSFLOAT T_LIT_REAL  */
#line 125 "pf2asm_parser.y"
                                        { (yyval.node) = new pf2asm::SFLOAT (LINE, (yyvsp[0].d)); }
#line 1631 "pf2asm_parser.tab.c"
    break;

  case 37: /* data: tSDOUBLE T_LIT_REAL  */
#line 126 "pf2asm_parser.y"
                                        { (yyval.node) = new pf2asm::SDOUBLE(LINE, (yyvsp[0].d)); }
#line 1637 "pf2asm_parser.tab.c"
    break;

  case 38: /* data: tINT integer  */
#line 127 "pf2asm_parser.y"
                                        { (yyval.node) = new pf2asm::INT    (LINE, (yyvsp[0].i)); }
#line 1643 "pf2asm_parser.tab.c"
    break;

  case 39: /* data: tFLOAT T_LIT_REAL  */
#line 128 "pf2asm_parser.y"
                                        { (yyval.node) = new pf2asm::FLOAT  (LINE, (yyvsp[0].d)); }
#line 1649 "pf2asm_parser.tab.c"
    break;

  case 40: /* data: tDOUBLE T_LIT_REAL  */
#line 129 "pf2asm_parser.y"
                                        { (yyval.node) = new pf2asm::DOUBLE (LINE, (yyvsp[0].d)); }
#line 1655 "pf2asm_parser.tab.c"
    break;

  case 41: /* addressing: tTEXT  */
#line 132 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::TEXT   (LINE); }
#line 1661 "pf2asm_parser.tab.c"
    break;

  case 42: /* addressing: tRODATA  */
#line 133 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::RODATA (LINE); }
#line 1667 "pf2asm_parser.tab.c"
    break;

  case 43: /* addressing: tDATA  */
#line 134 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::DATA   (LINE); }
#line 1673 "pf2asm_parser.tab.c"
    break;

  case 44: /* addressing: tBSS  */
#line 135 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::BSS    (LINE); }
#line 1679 "pf2asm_parser.tab.c"
    break;

  case 45: /* addressing: tALIGN  */
#line 136 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::ALIGN  (LINE); }
#line 1685 "pf2asm_parser.tab.c"
    break;

  case 46: /* addressing: tLOCAL offset  */
#line 137 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::LOCAL  (LINE, (yyvsp[0].i)); }
#line 1691 "pf2asm_parser.tab.c"
    break;

  case 47: /* addressing: tLOCV offset  */
#line 138 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::LOCV   (LINE, (yyvsp[0].i)); }
#line 1697 "pf2asm_parser.tab.c"
    break;

  case 48: /* addressing: tLOCA offset  */
#line 139 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::LOCA   (LINE, (yyvsp[0].i)); }
#line 1703 "pf2asm_parser.tab.c"
    break;

  case 49: /* addressing: tGLOBAL label ',' type  */
#line 140 "pf2asm_parser.y"
                                          { (yyval.node) = new pf2asm::GLOBAL(LINE, *(yyvsp[-2].s), *(yyvsp[0].s)); delete (yyvsp[-2].s); delete (yyvsp[0].s); }
#line 1709 "pf2asm_parser.tab.c"
    break;

  case 50: /* addressing: tEXTERN label  */
#line 141 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::EXTERN (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1715 "pf2asm_parser.tab.c"
    break;

  case 51: /* addressing: tLABEL label  */
#line 142 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::LABEL  (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1721 "pf2asm_parser.tab.c"
    break;

  case 52: /* addressing: tADDR label  */
#line 143 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::ADDR   (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1727 "pf2asm_parser.tab.c"
    break;

  case 53: /* addressing: tADDRV label  */
#line 144 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::ADDRV  (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1733 "pf2asm_parser.tab.c"
    break;

  case 54: /* addressing: tADDRA label  */
#line 145 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::ADDRA  (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1739 "pf2asm_parser.tab.c"
    break;

  case 55: /* offset: integer  */
#line 148 "pf2asm_parser.y"
                                  { (yyval.i) = (yyvsp[0].i); }
#line 1745 "pf2asm_parser.tab.c"
    break;

  case 56: /* label: T_ID  */
#line 149 "pf2asm_parser.y"
                                  { (yyval.s) = (yyvsp[0].s); }
#line 1751 "pf2asm_parser.tab.c"
    break;

  case 57: /* type: T_ID  */
#line 150 "pf2asm_parser.y"
                                  { (yyval.s) = (yyvsp[0].s); }
#line 1757 "pf2asm_parser.tab.c"
    break;

  case 58: /* function: tENTER bytes  */
#line 152 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::ENTER(LINE, (yyvsp[0].i)); }
#line 1763 "pf2asm_parser.tab.c"
    break;

  case 59: /* function: tSTART  */
#line 153 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::START(LINE);   }
#line 1769 "pf2asm_parser.tab.c"
    break;

  case 60: /* function: tLEAVE  */
#line 154 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::LEAVE(LINE);   }
#line 1775 "pf2asm_parser.tab.c"
    break;

  case 61: /* function: tCALL label  */
#line 155 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::CALL(LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1781 "pf2asm_parser.tab.c"
    break;

  case 62: /* function: tRET  */
#line 156 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::RET(LINE);      }
#line 1787 "pf2asm_parser.tab.c"
    break;

  case 63: /* function: tRETN bytes  */
#line 157 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::RETN(LINE, (yyvsp[0].i)); }
#line 1793 "pf2asm_parser.tab.c"
    break;

  case 64: /* function: tLDFVAL32  */
#line 158 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::LDFVAL32(LINE); }
#line 1799 "pf2asm_parser.tab.c"
    break;

  case 65: /* function: tSTFVAL32  */
#line 159 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::STFVAL32(LINE); }
#line 1805 "pf2asm_parser.tab.c"
    break;

  case 66: /* function: tLDFVAL64  */
#line 160 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::LDFVAL64(LINE); }
#line 1811 "pf2asm_parser.tab.c"
    break;

  case 67: /* function: tSTFVAL64  */
#line 161 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::STFVAL64(LINE); }
#line 1817 "pf2asm_parser.tab.c"
    break;

  case 68: /* loadstore: tLDBYTE  */
#line 164 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::LDBYTE(LINE);   }
#line 1823 "pf2asm_parser.tab.c"
    break;

  case 69: /* loadstore: tSTBYTE  */
#line 165 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::STBYTE(LINE);   }
#line 1829 "pf2asm_parser.tab.c"
    break;

  case 70: /* loadstore: tLDSHORT  */
#line 166 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::LDSHORT(LINE);  }
#line 1835 "pf2asm_parser.tab.c"
    break;

  case 71: /* loadstore: tSTSHORT  */
#line 167 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::STSHORT(LINE);  }
#line 1841 "pf2asm_parser.tab.c"
    break;

  case 72: /* loadstore: tLDINT  */
#line 168 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::LDINT(LINE);    }
#line 1847 "pf2asm_parser.tab.c"
    break;

  case 73: /* loadstore: tSTINT  */
#line 169 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::STINT(LINE);    }
#line 1853 "pf2asm_parser.tab.c"
    break;

  case 74: /* loadstore: tLDFLOAT  */
#line 170 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::LDFLOAT(LINE);  }
#line 1859 "pf2asm_parser.tab.c"
    break;

  case 75: /* loadstore: tSTFLOAT  */
#line 171 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::STFLOAT(LINE);  }
#line 1865 "pf2asm_parser.tab.c"
    break;

  case 76: /* loadstore: tLDDOUBLE  */
#line 172 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::LDDOUBLE(LINE); }
#line 1871 "pf2asm_parser.tab.c"
    break;

  case 77: /* loadstore: tSTDOUBLE  */
#line 173 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::STDOUBLE(LINE); }
#line 1877 "pf2asm_parser.tab.c"
    break;

  case 78: /* arithmetic: tADD  */
#line 176 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::ADD(LINE);  }
#line 1883 "pf2asm_parser.tab.c"
    break;

  case 79: /* arithmetic: tSUB  */
#line 177 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::SUB(LINE);  }
#line 1889 "pf2asm_parser.tab.c"
    break;

  case 80: /* arithmetic: tMUL  */
#line 178 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::MUL(LINE);  }
#line 1895 "pf2asm_parser.tab.c"
    break;

  case 81: /* arithmetic: tDIV  */
#line 179 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::DIV(LINE);  }
#line 1901 "pf2asm_parser.tab.c"
    break;

  case 82: /* arithmetic: tMOD  */
#line 180 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::MOD(LINE);  }
#line 1907 "pf2asm_parser.tab.c"
    break;

  case 83: /* arithmetic: tNEG  */
#line 181 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::NEG(LINE);  }
#line 1913 "pf2asm_parser.tab.c"
    break;

  case 84: /* arithmetic: tUDIV  */
#line 182 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::UDIV(LINE); }
#line 1919 "pf2asm_parser.tab.c"
    break;

  case 85: /* arithmetic: tUMOD  */
#line 183 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::UMOD(LINE); }
#line 1925 "pf2asm_parser.tab.c"
    break;

  case 86: /* arithmetic: tDADD  */
#line 184 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::DADD(LINE); }
#line 1931 "pf2asm_parser.tab.c"
    break;

  case 87: /* arithmetic: tDSUB  */
#line 185 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::DSUB(LINE); }
#line 1937 "pf2asm_parser.tab.c"
    break;

  case 88: /* arithmetic: tDMUL  */
#line 186 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::DMUL(LINE); }
#line 1943 "pf2asm_parser.tab.c"
    break;

  case 89: /* arithmetic: tDDIV  */
#line 187 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::DDIV(LINE); }
#line 1949 "pf2asm_parser.tab.c"
    break;

  case 90: /* arithmetic: tDNEG  */
#line 188 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::DNEG(LINE); }
#line 1955 "pf2asm_parser.tab.c"
    break;

  case 91: /* bitwise: tROTL  */
#line 191 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::ROTL(LINE);  }
#line 1961 "pf2asm_parser.tab.c"
    break;

  case 92: /* bitwise: tROTR  */
#line 192 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::ROTR(LINE);  }
#line 1967 "pf2asm_parser.tab.c"
    break;

  case 93: /* bitwise: tSHTL  */
#line 193 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::SHTL(LINE);  }
#line 1973 "pf2asm_parser.tab.c"
    break;

  case 94: /* bitwise: tSHTRU  */
#line 194 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::SHTRU(LINE); }
#line 1979 "pf2asm_parser.tab.c"
    break;

  case 95: /* bitwise: tSHTRS  */
#line 195 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::SHTRS(LINE); }
#line 1985 "pf2asm_parser.tab.c"
    break;

  case 96: /* bitwise: tAND  */
#line 196 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::AND(LINE); }
#line 1991 "pf2asm_parser.tab.c"
    break;

  case 97: /* bitwise: tOR  */
#line 197 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::OR(LINE);  }
#line 1997 "pf2asm_parser.tab.c"
    break;

  case 98: /* bitwise: tXOR  */
#line 198 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::XOR(LINE); }
#line 2003 "pf2asm_parser.tab.c"
    break;

  case 99: /* bitwise: tNOT  */
#line 199 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::NOT(LINE); }
#line 2009 "pf2asm_parser.tab.c"
    break;

  case 100: /* relational: tGT  */
#line 202 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::GT(LINE);   }
#line 2015 "pf2asm_parser.tab.c"
    break;

  case 101: /* relational: tGE  */
#line 203 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::GE(LINE);   }
#line 2021 "pf2asm_parser.tab.c"
    break;

  case 102: /* relational: tLT  */
#line 204 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::LT(LINE);   }
#line 2027 "pf2asm_parser.tab.c"
    break;

  case 103: /* relational: tLE  */
#line 205 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::LE(LINE);   }
#line 2033 "pf2asm_parser.tab.c"
    break;

  case 104: /* relational: tEQ  */
#line 206 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::EQ(LINE);   }
#line 2039 "pf2asm_parser.tab.c"
    break;

  case 105: /* relational: tNE  */
#line 207 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::NE(LINE);   }
#line 2045 "pf2asm_parser.tab.c"
    break;

  case 106: /* relational: tUGT  */
#line 208 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::UGT(LINE);  }
#line 2051 "pf2asm_parser.tab.c"
    break;

  case 107: /* relational: tUGE  */
#line 209 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::UGE(LINE);  }
#line 2057 "pf2asm_parser.tab.c"
    break;

  case 108: /* relational: tULT  */
#line 210 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::ULT(LINE);  }
#line 2063 "pf2asm_parser.tab.c"
    break;

  case 109: /* relational: tULE  */
#line 211 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::ULE(LINE);  }
#line 2069 "pf2asm_parser.tab.c"
    break;

  case 110: /* relational: tDCMP  */
#line 212 "pf2asm_parser.y"
                                 { (yyval.node) = new pf2asm::DCMP(LINE); }
#line 2075 "pf2asm_parser.tab.c"
    break;

  case 111: /* jumps: tBRANCH  */
#line 215 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::BRANCH (LINE); }
#line 2081 "pf2asm_parser.tab.c"
    break;

  case 112: /* jumps: tLEAP  */
#line 216 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::LEAP   (LINE); }
#line 2087 "pf2asm_parser.tab.c"
    break;

  case 113: /* jumps: tJMP label  */
#line 217 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JMP    (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2093 "pf2asm_parser.tab.c"
    break;

  case 114: /* jumps: tJZ label  */
#line 218 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JZ     (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2099 "pf2asm_parser.tab.c"
    break;

  case 115: /* jumps: tJNZ label  */
#line 219 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JNZ    (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2105 "pf2asm_parser.tab.c"
    break;

  case 116: /* jumps: tJEQ label  */
#line 220 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JEQ    (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2111 "pf2asm_parser.tab.c"
    break;

  case 117: /* jumps: tJNE label  */
#line 221 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JNE    (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2117 "pf2asm_parser.tab.c"
    break;

  case 118: /* jumps: tJGT label  */
#line 222 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JGT    (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2123 "pf2asm_parser.tab.c"
    break;

  case 119: /* jumps: tJGE label  */
#line 223 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JGE    (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2129 "pf2asm_parser.tab.c"
    break;

  case 120: /* jumps: tJLT label  */
#line 224 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JLT    (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2135 "pf2asm_parser.tab.c"
    break;

  case 121: /* jumps: tJLE label  */
#line 225 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JLE    (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2141 "pf2asm_parser.tab.c"
    break;

  case 122: /* jumps: tJUGT label  */
#line 226 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JUGT   (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2147 "pf2asm_parser.tab.c"
    break;

  case 123: /* jumps: tJUGE label  */
#line 227 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JUGE   (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2153 "pf2asm_parser.tab.c"
    break;

  case 124: /* jumps: tJULT label  */
#line 228 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JULT   (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2159 "pf2asm_parser.tab.c"
    break;

  case 125: /* jumps: tJULE label  */
#line 229 "pf2asm_parser.y"
                                    { (yyval.node) = new pf2asm::JULE   (LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2165 "pf2asm_parser.tab.c"
    break;

  case 126: /* integer: T_LIT_INT  */
#line 232 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[0].i); }
#line 2171 "pf2asm_parser.tab.c"
    break;

  case 127: /* integer: integer '+' integer  */
#line 233 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-2].i) +  (yyvsp[0].i); }
#line 2177 "pf2asm_parser.tab.c"
    break;

  case 128: /* integer: integer '-' integer  */
#line 234 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-2].i) -  (yyvsp[0].i); }
#line 2183 "pf2asm_parser.tab.c"
    break;

  case 129: /* integer: integer '*' integer  */
#line 235 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-2].i) *  (yyvsp[0].i); }
#line 2189 "pf2asm_parser.tab.c"
    break;

  case 130: /* integer: integer '/' integer  */
#line 236 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-2].i) /  (yyvsp[0].i); }
#line 2195 "pf2asm_parser.tab.c"
    break;

  case 131: /* integer: integer '%' integer  */
#line 237 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-2].i) %  (yyvsp[0].i); }
#line 2201 "pf2asm_parser.tab.c"
    break;

  case 132: /* integer: integer '<' integer  */
#line 238 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-2].i) <  (yyvsp[0].i); }
#line 2207 "pf2asm_parser.tab.c"
    break;

  case 133: /* integer: integer T_LE integer  */
#line 239 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-2].i) <= (yyvsp[0].i); }
#line 2213 "pf2asm_parser.tab.c"
    break;

  case 134: /* integer: integer T_EQ integer  */
#line 240 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-2].i) == (yyvsp[0].i); }
#line 2219 "pf2asm_parser.tab.c"
    break;

  case 135: /* integer: integer T_GE integer  */
#line 241 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-2].i) >= (yyvsp[0].i); }
#line 2225 "pf2asm_parser.tab.c"
    break;

  case 136: /* integer: integer '>' integer  */
#line 242 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-2].i) >  (yyvsp[0].i); }
#line 2231 "pf2asm_parser.tab.c"
    break;

  case 137: /* integer: integer T_NE integer  */
#line 243 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-2].i) != (yyvsp[0].i); }
#line 2237 "pf2asm_parser.tab.c"
    break;

  case 138: /* integer: '!' integer  */
#line 244 "pf2asm_parser.y"
                                                  { (yyval.i) = !(yyvsp[0].i); }
#line 2243 "pf2asm_parser.tab.c"
    break;

  case 139: /* integer: '-' integer  */
#line 245 "pf2asm_parser.y"
                                                  { (yyval.i) = -(yyvsp[0].i); }
#line 2249 "pf2asm_parser.tab.c"
    break;

  case 140: /* integer: '+' integer  */
#line 246 "pf2asm_parser.y"
                                                  { (yyval.i) =  (yyvsp[0].i); }
#line 2255 "pf2asm_parser.tab.c"
    break;

  case 141: /* integer: '(' integer ')'  */
#line 247 "pf2asm_parser.y"
                                                  { (yyval.i) =  (yyvsp[-1].i); }
#line 2261 "pf2asm_parser.tab.c"
    break;

  case 142: /* integer: integer '?' integer ':' integer  */
#line 248 "pf2asm_parser.y"
                                                  { (yyval.i) = (yyvsp[-4].i) ? (yyvsp[-2].i) : (yyvsp[0].i); }
#line 2267 "pf2asm_parser.tab.c"
    break;


#line 2271 "pf2asm_parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (compiler, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, compiler);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, compiler);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (compiler, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, compiler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 251 "pf2asm_parser.y"

