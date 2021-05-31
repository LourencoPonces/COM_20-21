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
#line 1 "fir_parser.y"

//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include "ast/all.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!

#line 85 "fir_parser.tab.c"

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

#include "fir_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tTYPE_INT = 3,                  /* tTYPE_INT  */
  YYSYMBOL_tTYPE_FLOAT = 4,                /* tTYPE_FLOAT  */
  YYSYMBOL_tTYPE_STRING = 5,               /* tTYPE_STRING  */
  YYSYMBOL_tTYPE_VOID = 6,                 /* tTYPE_VOID  */
  YYSYMBOL_tSIZEOF = 7,                    /* tSIZEOF  */
  YYSYMBOL_tREQUIRE = 8,                   /* tREQUIRE  */
  YYSYMBOL_tIF = 9,                        /* tIF  */
  YYSYMBOL_tTHEN = 10,                     /* tTHEN  */
  YYSYMBOL_tELSE = 11,                     /* tELSE  */
  YYSYMBOL_tWHILE = 12,                    /* tWHILE  */
  YYSYMBOL_tDO = 13,                       /* tDO  */
  YYSYMBOL_tFINALLY = 14,                  /* tFINALLY  */
  YYSYMBOL_tLEAVE = 15,                    /* tLEAVE  */
  YYSYMBOL_tRESTART = 16,                  /* tRESTART  */
  YYSYMBOL_tGE = 17,                       /* tGE  */
  YYSYMBOL_tLE = 18,                       /* tLE  */
  YYSYMBOL_tEQ = 19,                       /* tEQ  */
  YYSYMBOL_tNE = 20,                       /* tNE  */
  YYSYMBOL_tAND = 21,                      /* tAND  */
  YYSYMBOL_tOR = 22,                       /* tOR  */
  YYSYMBOL_tRETURN = 23,                   /* tRETURN  */
  YYSYMBOL_tWRITE = 24,                    /* tWRITE  */
  YYSYMBOL_tWRITELN = 25,                  /* tWRITELN  */
  YYSYMBOL_tRET_VAL = 26,                  /* tRET_VAL  */
  YYSYMBOL_tEPILOGUE = 27,                 /* tEPILOGUE  */
  YYSYMBOL_tINTEGER = 28,                  /* tINTEGER  */
  YYSYMBOL_tFLOAT = 29,                    /* tFLOAT  */
  YYSYMBOL_tIDENTIFIER = 30,               /* tIDENTIFIER  */
  YYSYMBOL_tSTRING = 31,                   /* tSTRING  */
  YYSYMBOL_tNULL = 32,                     /* tNULL  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_34_ = 34,                       /* '~'  */
  YYSYMBOL_35_ = 35,                       /* '<'  */
  YYSYMBOL_36_ = 36,                       /* '>'  */
  YYSYMBOL_37_ = 37,                       /* '+'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '/'  */
  YYSYMBOL_41_ = 41,                       /* '%'  */
  YYSYMBOL_tUNARY = 42,                    /* tUNARY  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* '?'  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* '@'  */
  YYSYMBOL_50_ = 50,                       /* '{'  */
  YYSYMBOL_51_ = 51,                       /* '}'  */
  YYSYMBOL_52_ = 52,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_file = 54,                      /* file  */
  YYSYMBOL_declarations = 55,              /* declarations  */
  YYSYMBOL_declaration = 56,               /* declaration  */
  YYSYMBOL_variable = 57,                  /* variable  */
  YYSYMBOL_variables = 58,                 /* variables  */
  YYSYMBOL_opt_variables = 59,             /* opt_variables  */
  YYSYMBOL_opt_initializer = 60,           /* opt_initializer  */
  YYSYMBOL_function = 61,                  /* function  */
  YYSYMBOL_func_decl = 62,                 /* func_decl  */
  YYSYMBOL_func_def = 63,                  /* func_def  */
  YYSYMBOL_args = 64,                      /* args  */
  YYSYMBOL_arg = 65,                       /* arg  */
  YYSYMBOL_def_ret_val = 66,               /* def_ret_val  */
  YYSYMBOL_literal = 67,                   /* literal  */
  YYSYMBOL_body = 68,                      /* body  */
  YYSYMBOL_prologue = 69,                  /* prologue  */
  YYSYMBOL_epilogue = 70,                  /* epilogue  */
  YYSYMBOL_block = 71,                     /* block  */
  YYSYMBOL_instruction = 72,               /* instruction  */
  YYSYMBOL_instructions = 73,              /* instructions  */
  YYSYMBOL_opt_instructions = 74,          /* opt_instructions  */
  YYSYMBOL_data_type = 75,                 /* data_type  */
  YYSYMBOL_integer = 76,                   /* integer  */
  YYSYMBOL_float = 77,                     /* float  */
  YYSYMBOL_string = 78,                    /* string  */
  YYSYMBOL_expression = 79,                /* expression  */
  YYSYMBOL_expressions = 80,               /* expressions  */
  YYSYMBOL_lvalue = 81                     /* lvalue  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 84 "fir_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 204 "fir_parser.tab.c"


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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   408

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    41,     2,     2,
      46,    47,    39,    37,    48,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      35,    33,    36,    45,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,    34,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    92,    93,    96,    97,   100,   101,   102,
     105,   106,   108,   109,   112,   113,   116,   117,   120,   121,
     122,   123,   124,   125,   128,   129,   130,   131,   132,   133,
     136,   137,   138,   141,   144,   147,   148,   149,   150,   153,
     154,   155,   156,   157,   158,   159,   162,   165,   168,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   186,   187,   190,   191,   194,   195,   196,   197,
     200,   203,   206,   207,   210,   212,   213,   215,   216,   217,
     219,   220,   221,   222,   223,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   235,   237,   239,   240,   241,   242,
     245,   246,   249,   250
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
  "\"end of file\"", "error", "\"invalid token\"", "tTYPE_INT",
  "tTYPE_FLOAT", "tTYPE_STRING", "tTYPE_VOID", "tSIZEOF", "tREQUIRE",
  "tIF", "tTHEN", "tELSE", "tWHILE", "tDO", "tFINALLY", "tLEAVE",
  "tRESTART", "tGE", "tLE", "tEQ", "tNE", "tAND", "tOR", "tRETURN",
  "tWRITE", "tWRITELN", "tRET_VAL", "tEPILOGUE", "tINTEGER", "tFLOAT",
  "tIDENTIFIER", "tSTRING", "tNULL", "'='", "'~'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "tUNARY", "'['", "';'", "'?'", "'('", "')'",
  "','", "'@'", "'{'", "'}'", "']'", "$accept", "file", "declarations",
  "declaration", "variable", "variables", "opt_variables",
  "opt_initializer", "function", "func_decl", "func_def", "args", "arg",
  "def_ret_val", "literal", "body", "prologue", "epilogue", "block",
  "instruction", "instructions", "opt_instructions", "data_type",
  "integer", "float", "string", "expression", "expressions", "lvalue", YY_NULLPTR
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
     285,   286,   287,    61,   126,    60,    62,    43,    45,    42,
      47,    37,   288,    91,    59,    63,    40,    41,    44,    64,
     123,   125,    93
};
#endif

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      73,  -116,  -116,  -116,    85,   108,    16,    73,  -116,   -21,
    -116,  -116,  -116,    86,   -11,     7,    39,    36,  -116,  -116,
    -116,   115,    45,    99,   108,    88,    93,  -116,   178,   108,
    -116,   120,   116,    33,  -116,   135,   108,   108,   128,  -116,
    -116,   145,  -116,  -116,   178,   178,   178,   178,   178,  -116,
    -116,  -116,  -116,    59,   320,   -28,    97,   108,  -116,   108,
      71,   108,  -116,   131,   140,   178,   152,   356,   154,   154,
      -7,   221,  -116,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,  -116,    44,
     155,   157,   150,   150,   108,  -116,    17,  -116,   184,  -116,
      71,  -116,   252,  -116,   320,   166,  -116,  -116,   238,   238,
     365,   365,   356,   329,   238,   238,   153,   153,   154,   154,
     154,    66,   320,   139,    71,  -116,    44,  -116,  -116,  -116,
     175,   108,   126,   107,  -116,   184,  -116,  -116,  -116,  -116,
     178,  -116,  -116,  -116,    71,  -116,  -116,   176,   178,   178,
      -3,    82,  -116,   178,   178,  -116,  -116,   126,   172,   292,
     192,   196,   198,  -116,   320,  -116,  -116,   212,   283,   191,
    -116,   193,  -116,    92,   129,  -116,  -116,  -116,   192,  -116,
     126,   126,  -116,  -116,  -116,  -116,   225,   230,   126,   126,
    -116,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    67,    68,    66,     0,     0,     0,     2,     3,     0,
       6,    16,    17,     0,     0,     0,     0,     0,     1,     4,
       5,    14,     0,     0,    30,     0,     0,    69,     0,    30,
       8,    14,     9,     0,    31,     0,    30,    30,     0,    70,
      71,   102,    72,    38,     0,     0,     0,     0,     0,    98,
      74,    35,    36,    37,    15,    95,     0,    30,     7,    30,
      22,     0,    33,     0,     0,     0,     0,    91,    77,    78,
       0,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    19,
       0,     0,     0,     0,    12,    29,    39,    41,    40,    32,
      21,    23,     0,    96,   100,     0,    76,    75,    88,    87,
      89,    90,    92,    93,    85,    86,    83,    84,    80,    81,
      82,     0,    94,     0,     0,    27,    18,    20,    47,    46,
       0,    13,    64,     0,    43,    42,    44,    28,    99,    97,
       0,   103,    34,    25,     0,    26,    10,     0,     0,     0,
       0,     0,    60,     0,     0,    61,    62,    65,     0,     0,
      14,     0,     0,    45,   101,    24,    11,     0,     0,     0,
      56,     0,    58,     0,     0,    63,    48,    53,    14,     9,
       0,     0,    57,    59,    54,    55,    49,    51,     0,     0,
      50,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,   239,   -85,  -116,  -116,   -31,  -116,  -116,
    -116,    60,   202,   119,   142,   -62,  -116,   -72,   -89,  -115,
    -116,  -116,     1,  -116,  -116,  -116,   -26,    64,  -116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,   131,   132,    30,    10,    11,
      12,    33,    34,   124,    50,    95,    96,    97,    98,   156,
     157,   158,    35,    51,    52,    53,   159,   105,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    13,    54,   128,   129,    87,    17,   135,    13,   130,
      73,    74,    75,    76,    77,    78,    18,    88,    67,    68,
      69,    70,    71,    20,   134,   169,   136,   125,    79,    80,
      81,    82,    83,    84,    85,    24,    86,    25,   137,   102,
     104,   170,   175,   155,    92,   106,   147,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   143,   163,   145,   186,   187,    94,   155,    26,
     123,    92,    27,   190,   191,    31,     1,     2,     3,     4,
      60,    61,   165,    73,    74,    75,    76,    77,    78,    56,
      72,   155,   155,    93,    94,   133,    63,    64,    92,   155,
     155,    79,    80,    81,    82,    83,    84,    85,     5,    86,
     171,     1,     2,     3,   164,    14,    21,    90,   141,    91,
      93,    94,   167,   168,    15,    22,   172,   104,   104,    32,
      16,    23,   133,    38,    36,   148,   184,   160,   149,    37,
     140,   150,   151,     5,    89,    61,   161,    58,    28,   152,
     153,   154,   162,    28,    39,    40,    41,    42,    43,    38,
      44,    29,    59,    45,    46,    62,    57,    39,    40,    47,
      42,    43,    48,   185,    65,    49,    94,   140,   100,    61,
      39,    40,    41,    42,    43,    38,    44,   101,    61,    45,
      46,    66,    83,    84,    85,    47,    86,    86,    48,   103,
      94,    49,   126,    61,   127,    61,    39,    40,    41,    42,
      43,    92,    44,   139,   140,    45,    46,   173,   174,   146,
     166,    47,   180,   176,    48,    28,   178,    49,   179,    73,
      74,    75,    76,    77,    78,   182,   188,   183,    73,    74,
      75,    76,    77,    78,   189,   144,    19,    79,    80,    81,
      82,    83,    84,    85,     0,    86,    79,    80,    81,    82,
      83,    84,    85,    99,    86,   142,     0,     0,   107,    73,
      74,    75,    76,    77,    78,    81,    82,    83,    84,    85,
       0,    86,     0,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,     0,    86,   181,     0,     0,   138,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,     0,    86,    79,    80,    81,
      82,    83,    84,    85,     0,    86,   177,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    73,    74,    75,    76,
      77,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,     0,    86,    79,    80,    81,    82,    83,    84,
      85,     0,    86,    73,    74,    75,    76,     0,     0,     0,
       0,     0,    73,    74,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,     0,    86,
      79,    80,    81,    82,    83,    84,    85,     0,    86
};

static const yytype_int16 yycheck[] =
{
      31,     0,    28,    92,    93,    33,     5,    96,     7,    94,
      17,    18,    19,    20,    21,    22,     0,    45,    44,    45,
      46,    47,    48,    44,    96,    28,    98,    89,    35,    36,
      37,    38,    39,    40,    41,    46,    43,    30,   100,    65,
      66,    44,   157,   132,    27,    52,   131,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,   124,   135,   126,   180,   181,    50,   157,    30,
      26,    27,    36,   188,   189,    30,     3,     4,     5,     6,
      47,    48,   144,    17,    18,    19,    20,    21,    22,    29,
      31,   180,   181,    49,    50,    94,    36,    37,    27,   188,
     189,    35,    36,    37,    38,    39,    40,    41,    35,    43,
      28,     3,     4,     5,   140,    30,    30,    57,    52,    59,
      49,    50,   148,   149,    39,    39,    44,   153,   154,    30,
      45,    45,   131,     7,    46,     9,    44,    30,    12,    46,
      48,    15,    16,    35,    47,    48,    39,   178,    33,    23,
      24,    25,    45,    33,    28,    29,    30,    31,    32,     7,
      34,    46,    46,    37,    38,    30,    46,    28,    29,    43,
      31,    32,    46,    44,    46,    49,    50,    48,    47,    48,
      28,    29,    30,    31,    32,     7,    34,    47,    48,    37,
      38,    46,    39,    40,    41,    43,    43,    43,    46,    47,
      50,    49,    47,    48,    47,    48,    28,    29,    30,    31,
      32,    27,    34,    47,    48,    37,    38,   153,   154,    44,
      44,    43,    10,    51,    46,    33,    30,    49,    30,    17,
      18,    19,    20,    21,    22,    44,    11,    44,    17,    18,
      19,    20,    21,    22,    14,   126,     7,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    35,    36,    37,    38,
      39,    40,    41,    61,    43,   123,    -1,    -1,    47,    17,
      18,    19,    20,    21,    22,    37,    38,    39,    40,    41,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    13,    -1,    -1,    47,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    44,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      35,    36,    37,    38,    39,    40,    41,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    35,    54,    55,    56,    57,
      61,    62,    63,    75,    30,    39,    45,    75,     0,    56,
      44,    30,    39,    45,    46,    30,    30,    36,    33,    46,
      60,    30,    30,    64,    65,    75,    46,    46,     7,    28,
      29,    30,    31,    32,    34,    37,    38,    43,    46,    49,
      67,    76,    77,    78,    79,    81,    64,    46,    60,    46,
      47,    48,    30,    64,    64,    46,    46,    79,    79,    79,
      79,    79,    31,    17,    18,    19,    20,    21,    22,    35,
      36,    37,    38,    39,    40,    41,    43,    33,    45,    47,
      64,    64,    27,    49,    50,    68,    69,    70,    71,    65,
      47,    47,    79,    47,    79,    80,    52,    47,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    26,    66,    68,    47,    47,    71,    71,
      57,    58,    59,    75,    70,    71,    70,    68,    47,    47,
      48,    52,    67,    68,    66,    68,    44,    57,     9,    12,
      15,    16,    23,    24,    25,    71,    72,    73,    74,    79,
      30,    39,    45,    70,    79,    68,    44,    79,    79,    28,
      44,    28,    44,    80,    80,    72,    51,    44,    30,    30,
      10,    13,    44,    44,    44,    44,    72,    72,    11,    14,
      72,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63,
      64,    64,    64,    65,    66,    67,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    69,    70,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      76,    77,    78,    78,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    80,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     4,     3,     3,
       2,     3,     0,     1,     0,     2,     1,     1,     6,     5,
       6,     6,     5,     6,     8,     7,     7,     6,     7,     6,
       0,     1,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     3,     2,     2,     4,     4,
       6,     4,     6,     2,     3,     3,     2,     3,     2,     3,
       1,     1,     1,     2,     0,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     1,     3,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     1,     3,     4,     1,     4,
       1,     3,     1,     4
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
  case 2: /* file: declarations  */
#line 89 "fir_parser.y"
                                                                                   { compiler->ast((yyval.sequence) = (yyvsp[0].sequence)); }
#line 1344 "fir_parser.tab.c"
    break;

  case 3: /* declarations: declaration  */
#line 92 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1350 "fir_parser.tab.c"
    break;

  case 4: /* declarations: declarations declaration  */
#line 93 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1356 "fir_parser.tab.c"
    break;

  case 5: /* declaration: variable ';'  */
#line 96 "fir_parser.y"
                                                                                   { (yyval.node) = (yyvsp[-1].node); }
#line 1362 "fir_parser.tab.c"
    break;

  case 6: /* declaration: function  */
#line 97 "fir_parser.y"
                                                                                   { (yyval.node) = (yyvsp[0].node); }
#line 1368 "fir_parser.tab.c"
    break;

  case 7: /* variable: data_type '*' tIDENTIFIER opt_initializer  */
#line 100 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::variable_definition_node(LINE, (yyvsp[-3].type), 1, *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1374 "fir_parser.tab.c"
    break;

  case 8: /* variable: data_type tIDENTIFIER opt_initializer  */
#line 101 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::variable_definition_node(LINE, (yyvsp[-2].type), 0, *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1380 "fir_parser.tab.c"
    break;

  case 9: /* variable: data_type '?' tIDENTIFIER  */
#line 102 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::variable_definition_node(LINE, (yyvsp[-2].type), 2, *(yyvsp[0].s), nullptr); }
#line 1386 "fir_parser.tab.c"
    break;

  case 10: /* variables: variable ';'  */
#line 105 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node));     }
#line 1392 "fir_parser.tab.c"
    break;

  case 11: /* variables: variables variable ';'  */
#line 106 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence)); }
#line 1398 "fir_parser.tab.c"
    break;

  case 12: /* opt_variables: %empty  */
#line 108 "fir_parser.y"
                                                                                   { (yyval.sequence) = NULL; }
#line 1404 "fir_parser.tab.c"
    break;

  case 13: /* opt_variables: variables  */
#line 109 "fir_parser.y"
                                                                                   { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1410 "fir_parser.tab.c"
    break;

  case 14: /* opt_initializer: %empty  */
#line 112 "fir_parser.y"
                                                                                   { (yyval.expression) = nullptr; }
#line 1416 "fir_parser.tab.c"
    break;

  case 15: /* opt_initializer: '=' expression  */
#line 113 "fir_parser.y"
                                                                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 1422 "fir_parser.tab.c"
    break;

  case 16: /* function: func_decl  */
#line 116 "fir_parser.y"
                                                                                   { (yyval.node) = (yyvsp[0].node); }
#line 1428 "fir_parser.tab.c"
    break;

  case 17: /* function: func_def  */
#line 117 "fir_parser.y"
                                                                                   { (yyval.node) = (yyvsp[0].node); }
#line 1434 "fir_parser.tab.c"
    break;

  case 18: /* func_decl: data_type '*' tIDENTIFIER '(' args ')'  */
#line 120 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_declaration_node(LINE, (yyvsp[-5].type), 1,  *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1440 "fir_parser.tab.c"
    break;

  case 19: /* func_decl: data_type tIDENTIFIER '(' args ')'  */
#line 121 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_declaration_node(LINE, (yyvsp[-4].type), 0, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1446 "fir_parser.tab.c"
    break;

  case 20: /* func_decl: data_type '?' tIDENTIFIER '(' args ')'  */
#line 122 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_declaration_node(LINE, (yyvsp[-5].type), 2, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1452 "fir_parser.tab.c"
    break;

  case 21: /* func_decl: tTYPE_VOID '*' tIDENTIFIER '(' args ')'  */
#line 123 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_declaration_node(LINE,     1,  *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1458 "fir_parser.tab.c"
    break;

  case 22: /* func_decl: tTYPE_VOID tIDENTIFIER '(' args ')'  */
#line 124 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_declaration_node(LINE,     0, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1464 "fir_parser.tab.c"
    break;

  case 23: /* func_decl: tTYPE_VOID '?' tIDENTIFIER '(' args ')'  */
#line 125 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_declaration_node(LINE,     2, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1470 "fir_parser.tab.c"
    break;

  case 24: /* func_def: data_type '*' tIDENTIFIER '(' args ')' def_ret_val body  */
#line 128 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_definition_node(LINE, (yyvsp[-7].type), 1,  *(yyvsp[-5].s), (yyvsp[-3].sequence), (yyvsp[-1].expression), (yyvsp[0].body)); }
#line 1476 "fir_parser.tab.c"
    break;

  case 25: /* func_def: data_type tIDENTIFIER '(' args ')' def_ret_val body  */
#line 129 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_definition_node(LINE, (yyvsp[-6].type), 0, *(yyvsp[-5].s), (yyvsp[-3].sequence), (yyvsp[-1].expression), (yyvsp[0].body)); }
#line 1482 "fir_parser.tab.c"
    break;

  case 26: /* func_def: data_type '*' tIDENTIFIER '(' args ')' body  */
#line 130 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_definition_node(LINE,     1,  *(yyvsp[-4].s), (yyvsp[-2].sequence),     (yyvsp[0].body)); }
#line 1488 "fir_parser.tab.c"
    break;

  case 27: /* func_def: data_type tIDENTIFIER '(' args ')' body  */
#line 131 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_definition_node(LINE,     0, *(yyvsp[-4].s), (yyvsp[-2].sequence),     (yyvsp[0].body)); }
#line 1494 "fir_parser.tab.c"
    break;

  case 28: /* func_def: tTYPE_VOID '*' tIDENTIFIER '(' args ')' body  */
#line 132 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_definition_node(LINE,     1,  *(yyvsp[-4].s), (yyvsp[-2].sequence),     (yyvsp[0].body)); }
#line 1500 "fir_parser.tab.c"
    break;

  case 29: /* func_def: tTYPE_VOID tIDENTIFIER '(' args ')' body  */
#line 133 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::function_definition_node(LINE,     0, *(yyvsp[-4].s), (yyvsp[-2].sequence),     (yyvsp[0].body)); }
#line 1506 "fir_parser.tab.c"
    break;

  case 30: /* args: %empty  */
#line 136 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE);  }
#line 1512 "fir_parser.tab.c"
    break;

  case 31: /* args: arg  */
#line 137 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1518 "fir_parser.tab.c"
    break;

  case 32: /* args: args ',' arg  */
#line 138 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1524 "fir_parser.tab.c"
    break;

  case 33: /* arg: data_type tIDENTIFIER  */
#line 141 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::variable_definition_node(LINE, (yyvsp[-1].type), 0, *(yyvsp[0].s), nullptr); }
#line 1530 "fir_parser.tab.c"
    break;

  case 34: /* def_ret_val: tRET_VAL literal  */
#line 144 "fir_parser.y"
                                                                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 1536 "fir_parser.tab.c"
    break;

  case 35: /* literal: integer  */
#line 147 "fir_parser.y"
                                                                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 1542 "fir_parser.tab.c"
    break;

  case 36: /* literal: float  */
#line 148 "fir_parser.y"
                                                                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 1548 "fir_parser.tab.c"
    break;

  case 37: /* literal: string  */
#line 149 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1554 "fir_parser.tab.c"
    break;

  case 38: /* literal: tNULL  */
#line 150 "fir_parser.y"
                                                                                   { (yyval.expression) = new fir::null_node(LINE); }
#line 1560 "fir_parser.tab.c"
    break;

  case 39: /* body: prologue  */
#line 153 "fir_parser.y"
                                                                                   { (yyval.body) = new fir::body_node(LINE, (yyvsp[0].prologue),      nullptr, nullptr); }
#line 1566 "fir_parser.tab.c"
    break;

  case 40: /* body: block  */
#line 154 "fir_parser.y"
                                                                                   { (yyval.body) = new fir::body_node(LINE, nullptr, (yyvsp[0].block),      nullptr); }
#line 1572 "fir_parser.tab.c"
    break;

  case 41: /* body: epilogue  */
#line 155 "fir_parser.y"
                                                                                   { (yyval.body) = new fir::body_node(LINE, nullptr, nullptr, (yyvsp[0].block)); }
#line 1578 "fir_parser.tab.c"
    break;

  case 42: /* body: prologue block  */
#line 156 "fir_parser.y"
                                                                                   { (yyval.body) = new fir::body_node(LINE, (yyvsp[-1].prologue),      (yyvsp[0].block),      nullptr); }
#line 1584 "fir_parser.tab.c"
    break;

  case 43: /* body: prologue epilogue  */
#line 157 "fir_parser.y"
                                                                                   { (yyval.body) = new fir::body_node(LINE, (yyvsp[-1].prologue),      nullptr, (yyvsp[0].block)); }
#line 1590 "fir_parser.tab.c"
    break;

  case 44: /* body: block epilogue  */
#line 158 "fir_parser.y"
                                                                                   { (yyval.body) = new fir::body_node(LINE, nullptr, (yyvsp[-1].block),      (yyvsp[0].block)); }
#line 1596 "fir_parser.tab.c"
    break;

  case 45: /* body: prologue block epilogue  */
#line 159 "fir_parser.y"
                                                                                   { (yyval.body) = new fir::body_node(LINE, (yyvsp[-2].prologue),      (yyvsp[-1].block),      (yyvsp[0].block)); }
#line 1602 "fir_parser.tab.c"
    break;

  case 46: /* prologue: '@' block  */
#line 162 "fir_parser.y"
                                                                                   { (yyval.prologue) = new fir::prologue_node(LINE, (yyvsp[0].block)); }
#line 1608 "fir_parser.tab.c"
    break;

  case 47: /* epilogue: tEPILOGUE block  */
#line 165 "fir_parser.y"
                                                                                   { (yyval.block) = (yyvsp[0].block); }
#line 1614 "fir_parser.tab.c"
    break;

  case 48: /* block: '{' opt_variables opt_instructions '}'  */
#line 168 "fir_parser.y"
                                                                                   { (yyval.block) = new fir::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1620 "fir_parser.tab.c"
    break;

  case 49: /* instruction: tIF expression tTHEN instruction  */
#line 171 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1626 "fir_parser.tab.c"
    break;

  case 50: /* instruction: tIF expression tTHEN instruction tELSE instruction  */
#line 172 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::if_else_node(LINE, (yyvsp[-4].expression), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1632 "fir_parser.tab.c"
    break;

  case 51: /* instruction: tWHILE expression tDO instruction  */
#line 173 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::while_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1638 "fir_parser.tab.c"
    break;

  case 52: /* instruction: tWHILE expression tDO instruction tFINALLY instruction  */
#line 174 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::while_finally_node(LINE, (yyvsp[-4].expression), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1644 "fir_parser.tab.c"
    break;

  case 53: /* instruction: expression ';'  */
#line 175 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::evaluation_node(LINE, (yyvsp[-1].expression)); }
#line 1650 "fir_parser.tab.c"
    break;

  case 54: /* instruction: tWRITE expressions ';'  */
#line 176 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::write_node(LINE, (yyvsp[-1].sequence), false); }
#line 1656 "fir_parser.tab.c"
    break;

  case 55: /* instruction: tWRITELN expressions ';'  */
#line 177 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::write_node(LINE, (yyvsp[-1].sequence), true); }
#line 1662 "fir_parser.tab.c"
    break;

  case 56: /* instruction: tLEAVE ';'  */
#line 178 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::leave_node(LINE); }
#line 1668 "fir_parser.tab.c"
    break;

  case 57: /* instruction: tLEAVE tINTEGER ';'  */
#line 179 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::leave_node(LINE, (yyvsp[-1].i)); }
#line 1674 "fir_parser.tab.c"
    break;

  case 58: /* instruction: tRESTART ';'  */
#line 180 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::restart_node(LINE); }
#line 1680 "fir_parser.tab.c"
    break;

  case 59: /* instruction: tRESTART tINTEGER ';'  */
#line 181 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::restart_node(LINE, (yyvsp[-1].i)); }
#line 1686 "fir_parser.tab.c"
    break;

  case 60: /* instruction: tRETURN  */
#line 182 "fir_parser.y"
                                                                                   { (yyval.node) = new fir::return_node(LINE); }
#line 1692 "fir_parser.tab.c"
    break;

  case 61: /* instruction: block  */
#line 183 "fir_parser.y"
                                                                                   { (yyval.node) = (yyvsp[0].block); }
#line 1698 "fir_parser.tab.c"
    break;

  case 62: /* instructions: instruction  */
#line 186 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1704 "fir_parser.tab.c"
    break;

  case 63: /* instructions: instructions instruction  */
#line 187 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1710 "fir_parser.tab.c"
    break;

  case 64: /* opt_instructions: %empty  */
#line 190 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1716 "fir_parser.tab.c"
    break;

  case 65: /* opt_instructions: instructions  */
#line 191 "fir_parser.y"
                                                                                   { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1722 "fir_parser.tab.c"
    break;

  case 66: /* data_type: tTYPE_STRING  */
#line 194 "fir_parser.y"
                                                                                   { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
#line 1728 "fir_parser.tab.c"
    break;

  case 67: /* data_type: tTYPE_INT  */
#line 195 "fir_parser.y"
                                                                                   { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT);     }
#line 1734 "fir_parser.tab.c"
    break;

  case 68: /* data_type: tTYPE_FLOAT  */
#line 196 "fir_parser.y"
                                                                                   { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
#line 1740 "fir_parser.tab.c"
    break;

  case 69: /* data_type: '<' data_type '>'  */
#line 197 "fir_parser.y"
                                                                                   { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1746 "fir_parser.tab.c"
    break;

  case 70: /* integer: tINTEGER  */
#line 200 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 1752 "fir_parser.tab.c"
    break;

  case 71: /* float: tFLOAT  */
#line 203 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 1758 "fir_parser.tab.c"
    break;

  case 72: /* string: tSTRING  */
#line 206 "fir_parser.y"
                                                                                   { (yyval.s) = (yyvsp[0].s); }
#line 1764 "fir_parser.tab.c"
    break;

  case 73: /* string: string tSTRING  */
#line 207 "fir_parser.y"
                                                                                   { (yyval.s) = (yyvsp[-1].s); (yyval.s)->append(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1770 "fir_parser.tab.c"
    break;

  case 74: /* expression: literal  */
#line 210 "fir_parser.y"
                                                                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 1776 "fir_parser.tab.c"
    break;

  case 75: /* expression: '(' expression ')'  */
#line 212 "fir_parser.y"
                                                                                   { (yyval.expression) = (yyvsp[-1].expression); }
#line 1782 "fir_parser.tab.c"
    break;

  case 76: /* expression: '[' expression ']'  */
#line 213 "fir_parser.y"
                                                                                   { (yyval.expression) = new fir::stack_alloc_node(LINE, (yyvsp[-1].expression)); }
#line 1788 "fir_parser.tab.c"
    break;

  case 77: /* expression: '+' expression  */
#line 215 "fir_parser.y"
                                                                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 1794 "fir_parser.tab.c"
    break;

  case 78: /* expression: '-' expression  */
#line 216 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression)); }
#line 1800 "fir_parser.tab.c"
    break;

  case 79: /* expression: lvalue '?'  */
#line 217 "fir_parser.y"
                                                                                   { (yyval.expression) = new fir::address_of_node(LINE, (yyvsp[-1].lvalue)); }
#line 1806 "fir_parser.tab.c"
    break;

  case 80: /* expression: expression '*' expression  */
#line 219 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1812 "fir_parser.tab.c"
    break;

  case 81: /* expression: expression '/' expression  */
#line 220 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1818 "fir_parser.tab.c"
    break;

  case 82: /* expression: expression '%' expression  */
#line 221 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1824 "fir_parser.tab.c"
    break;

  case 83: /* expression: expression '+' expression  */
#line 222 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1830 "fir_parser.tab.c"
    break;

  case 84: /* expression: expression '-' expression  */
#line 223 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1836 "fir_parser.tab.c"
    break;

  case 85: /* expression: expression '<' expression  */
#line 225 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1842 "fir_parser.tab.c"
    break;

  case 86: /* expression: expression '>' expression  */
#line 226 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1848 "fir_parser.tab.c"
    break;

  case 87: /* expression: expression tLE expression  */
#line 227 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1854 "fir_parser.tab.c"
    break;

  case 88: /* expression: expression tGE expression  */
#line 228 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1860 "fir_parser.tab.c"
    break;

  case 89: /* expression: expression tEQ expression  */
#line 229 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1866 "fir_parser.tab.c"
    break;

  case 90: /* expression: expression tNE expression  */
#line 230 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1872 "fir_parser.tab.c"
    break;

  case 91: /* expression: '~' expression  */
#line 231 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 1878 "fir_parser.tab.c"
    break;

  case 92: /* expression: expression tAND expression  */
#line 232 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1884 "fir_parser.tab.c"
    break;

  case 93: /* expression: expression tOR expression  */
#line 233 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::or_node (LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1890 "fir_parser.tab.c"
    break;

  case 94: /* expression: lvalue '=' expression  */
#line 235 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 1896 "fir_parser.tab.c"
    break;

  case 95: /* expression: lvalue  */
#line 237 "fir_parser.y"
                                                                                   { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 1902 "fir_parser.tab.c"
    break;

  case 96: /* expression: tIDENTIFIER '(' ')'  */
#line 239 "fir_parser.y"
                                                                                   { (yyval.expression) = new fir::function_call_node(LINE, *(yyvsp[-2].s)    ); delete (yyvsp[-2].s); }
#line 1908 "fir_parser.tab.c"
    break;

  case 97: /* expression: tIDENTIFIER '(' expressions ')'  */
#line 240 "fir_parser.y"
                                                                                   { (yyval.expression) = new fir::function_call_node(LINE, *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1914 "fir_parser.tab.c"
    break;

  case 98: /* expression: '@'  */
#line 241 "fir_parser.y"
                                                                                   { (yyval.expression) = new fir::read_node(LINE); }
#line 1920 "fir_parser.tab.c"
    break;

  case 99: /* expression: tSIZEOF '(' expression ')'  */
#line 242 "fir_parser.y"
                                                                                   { (yyval.expression) = new fir::sizeof_node(LINE, (yyvsp[-1].expression)); }
#line 1926 "fir_parser.tab.c"
    break;

  case 100: /* expressions: expression  */
#line 245 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression));     }
#line 1932 "fir_parser.tab.c"
    break;

  case 101: /* expressions: expressions ',' expression  */
#line 246 "fir_parser.y"
                                                                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 1938 "fir_parser.tab.c"
    break;

  case 102: /* lvalue: tIDENTIFIER  */
#line 249 "fir_parser.y"
                                                                                   { (yyval.lvalue) = new cdk::variable_node(LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1944 "fir_parser.tab.c"
    break;

  case 103: /* lvalue: expression '[' expression ']'  */
#line 250 "fir_parser.y"
                                                                                   { (yyval.lvalue) = new fir::index_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1950 "fir_parser.tab.c"
    break;


#line 1954 "fir_parser.tab.c"

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

#line 253 "fir_parser.y"

