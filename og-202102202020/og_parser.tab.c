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
#line 1 "og_parser.y"

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

#define NIL (new cdk::nil_node(LINE))

#line 87 "og_parser.tab.c"

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

#include "og_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tAND = 3,                       /* tAND  */
  YYSYMBOL_tOR = 4,                        /* tOR  */
  YYSYMBOL_tNE = 5,                        /* tNE  */
  YYSYMBOL_tLE = 6,                        /* tLE  */
  YYSYMBOL_tGE = 7,                        /* tGE  */
  YYSYMBOL_tSIZEOF = 8,                    /* tSIZEOF  */
  YYSYMBOL_tINPUT = 9,                     /* tINPUT  */
  YYSYMBOL_tWRITE = 10,                    /* tWRITE  */
  YYSYMBOL_tWRITELN = 11,                  /* tWRITELN  */
  YYSYMBOL_tPUBLIC = 12,                   /* tPUBLIC  */
  YYSYMBOL_tPRIVATE = 13,                  /* tPRIVATE  */
  YYSYMBOL_tREQUIRE = 14,                  /* tREQUIRE  */
  YYSYMBOL_tTYPE_STRING = 15,              /* tTYPE_STRING  */
  YYSYMBOL_tTYPE_INT = 16,                 /* tTYPE_INT  */
  YYSYMBOL_tTYPE_REAL = 17,                /* tTYPE_REAL  */
  YYSYMBOL_tTYPE_POINTER = 18,             /* tTYPE_POINTER  */
  YYSYMBOL_tTYPE_AUTO = 19,                /* tTYPE_AUTO  */
  YYSYMBOL_tPROCEDURE = 20,                /* tPROCEDURE  */
  YYSYMBOL_tIF = 21,                       /* tIF  */
  YYSYMBOL_tTHEN = 22,                     /* tTHEN  */
  YYSYMBOL_tELIF = 23,                     /* tELIF  */
  YYSYMBOL_tELSE = 24,                     /* tELSE  */
  YYSYMBOL_tFOR = 25,                      /* tFOR  */
  YYSYMBOL_tDO = 26,                       /* tDO  */
  YYSYMBOL_tBREAK = 27,                    /* tBREAK  */
  YYSYMBOL_tCONTINUE = 28,                 /* tCONTINUE  */
  YYSYMBOL_tRETURN = 29,                   /* tRETURN  */
  YYSYMBOL_tINTEGER = 30,                  /* tINTEGER  */
  YYSYMBOL_tREAL = 31,                     /* tREAL  */
  YYSYMBOL_tSTRING = 32,                   /* tSTRING  */
  YYSYMBOL_tID = 33,                       /* tID  */
  YYSYMBOL_tNULLPTR = 34,                  /* tNULLPTR  */
  YYSYMBOL_35_ = 35,                       /* '='  */
  YYSYMBOL_36_ = 36,                       /* '~'  */
  YYSYMBOL_tEQ = 37,                       /* tEQ  */
  YYSYMBOL_38_ = 38,                       /* '<'  */
  YYSYMBOL_39_ = 39,                       /* '>'  */
  YYSYMBOL_40_ = 40,                       /* '+'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '%'  */
  YYSYMBOL_tUMINUS = 45,                   /* tUMINUS  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* '{'  */
  YYSYMBOL_51_ = 51,                       /* '}'  */
  YYSYMBOL_52_ = 52,                       /* '@'  */
  YYSYMBOL_53_ = 53,                       /* '['  */
  YYSYMBOL_54_ = 54,                       /* ']'  */
  YYSYMBOL_55_ = 55,                       /* '?'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_file = 57,                      /* file  */
  YYSYMBOL_declarations = 58,              /* declarations  */
  YYSYMBOL_declaration = 59,               /* declaration  */
  YYSYMBOL_vardec = 60,                    /* vardec  */
  YYSYMBOL_vardecs = 61,                   /* vardecs  */
  YYSYMBOL_opt_vardecs = 62,               /* opt_vardecs  */
  YYSYMBOL_identifiers = 63,               /* identifiers  */
  YYSYMBOL_data_type = 64,                 /* data_type  */
  YYSYMBOL_opt_initializer = 65,           /* opt_initializer  */
  YYSYMBOL_void_type = 66,                 /* void_type  */
  YYSYMBOL_fundec = 67,                    /* fundec  */
  YYSYMBOL_fundef = 68,                    /* fundef  */
  YYSYMBOL_argdecs = 69,                   /* argdecs  */
  YYSYMBOL_argdec = 70,                    /* argdec  */
  YYSYMBOL_block = 71,                     /* block  */
  YYSYMBOL_fordec = 72,                    /* fordec  */
  YYSYMBOL_fordecs = 73,                   /* fordecs  */
  YYSYMBOL_opt_forinit = 74,               /* opt_forinit  */
  YYSYMBOL_return = 75,                    /* return  */
  YYSYMBOL_instructions = 76,              /* instructions  */
  YYSYMBOL_opt_instructions = 77,          /* opt_instructions  */
  YYSYMBOL_instruction = 78,               /* instruction  */
  YYSYMBOL_iffalse = 79,                   /* iffalse  */
  YYSYMBOL_lvalue = 80,                    /* lvalue  */
  YYSYMBOL_expression = 81,                /* expression  */
  YYSYMBOL_expressions = 82,               /* expressions  */
  YYSYMBOL_opt_expressions = 83,           /* opt_expressions  */
  YYSYMBOL_integer = 84,                   /* integer  */
  YYSYMBOL_real = 85,                      /* real  */
  YYSYMBOL_string = 86                     /* string  */
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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   493

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  240

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
       2,     2,     2,     2,     2,     2,     2,    44,     2,     2,
      48,    49,    42,    40,    47,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
      38,    35,    39,    55,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,    36,     2,     2,     2,
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
      37,    45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    88,    91,    92,    95,    96,    97,   100,
     101,   102,   103,   108,   115,   116,   119,   120,   123,   124,
     127,   128,   129,   130,   131,   134,   135,   138,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   152,   153,   154,
     155,   156,   157,   160,   161,   162,   165,   168,   171,   174,
     175,   178,   179,   180,   184,   187,   188,   191,   192,   195,
     196,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   211,   212,   213,   216,   217,   222,   226,   230,   231,
     232,   235,   236,   237,   238,   240,   242,   244,   245,   246,
     247,   248,   250,   251,   252,   253,   254,   255,   257,   258,
     260,   261,   262,   264,   266,   267,   269,   270,   271,   274,
     275,   278,   279,   282,   283,   284,   285
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
  "\"end of file\"", "error", "\"invalid token\"", "tAND", "tOR", "tNE",
  "tLE", "tGE", "tSIZEOF", "tINPUT", "tWRITE", "tWRITELN", "tPUBLIC",
  "tPRIVATE", "tREQUIRE", "tTYPE_STRING", "tTYPE_INT", "tTYPE_REAL",
  "tTYPE_POINTER", "tTYPE_AUTO", "tPROCEDURE", "tIF", "tTHEN", "tELIF",
  "tELSE", "tFOR", "tDO", "tBREAK", "tCONTINUE", "tRETURN", "tINTEGER",
  "tREAL", "tSTRING", "tID", "tNULLPTR", "'='", "'~'", "tEQ", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "tUMINUS", "';'", "','", "'('", "')'",
  "'{'", "'}'", "'@'", "'['", "']'", "'?'", "$accept", "file",
  "declarations", "declaration", "vardec", "vardecs", "opt_vardecs",
  "identifiers", "data_type", "opt_initializer", "void_type", "fundec",
  "fundef", "argdecs", "argdec", "block", "fordec", "fordecs",
  "opt_forinit", "return", "instructions", "opt_instructions",
  "instruction", "iffalse", "lvalue", "expression", "expressions",
  "opt_expressions", "integer", "real", "string", YY_NULLPTR
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
     285,   286,   287,   288,   289,    61,   126,   290,    60,    62,
      43,    45,    42,    47,    37,   291,    59,    44,    40,    41,
     123,   125,    64,    91,    93,    63
};
#endif

#define YYPACT_NINF (-206)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     285,   261,   304,  -206,  -206,  -206,   -27,   -19,  -206,    32,
     285,  -206,    -6,    10,    25,  -206,  -206,    64,    68,    78,
      92,   125,   140,    70,    97,   -14,  -206,  -206,  -206,   -26,
     136,   149,    48,   -23,   158,   192,   212,   221,   165,   209,
      76,   335,   155,   335,    76,  -206,    76,    76,   335,    76,
    -206,    76,    76,    76,    76,  -206,  -206,   225,    57,  -206,
     242,  -206,  -206,  -206,  -206,    -7,  -206,   335,   335,   335,
     335,   335,   -11,   429,   226,  -206,  -206,   251,  -206,   429,
      73,    81,    90,   226,    91,    99,   112,   131,   132,  -206,
      76,   241,   335,   335,   268,   449,  -206,  -206,    13,    75,
     335,   335,  -206,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,  -206,   241,   241,
     241,   241,   241,  -206,  -206,  -206,  -206,   204,  -206,   156,
     226,   257,  -206,    71,  -206,   429,   128,   449,   437,   169,
     110,   110,   169,   110,   110,     5,     5,  -206,  -206,  -206,
     429,  -206,  -206,  -206,  -206,  -206,   235,    76,   279,   270,
     204,   234,   293,  -206,   162,   297,   335,  -206,   279,   295,
     296,  -206,  -206,   286,   335,   335,   335,   277,  -206,  -206,
     306,  -206,  -206,   234,   280,  -206,   357,   298,   305,   335,
    -206,   187,   298,  -206,  -206,   116,   200,   386,   279,   301,
    -206,   294,   299,   226,  -206,   210,  -206,  -206,  -206,  -206,
     195,  -206,  -206,  -206,   234,    49,   313,    76,   335,  -206,
    -206,   248,   335,   335,  -206,   303,   335,   234,  -206,   226,
     429,   335,   409,  -206,   324,   234,   234,   248,  -206,  -206
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,    20,    21,    22,     0,     0,    27,     0,
       3,     4,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     1,     5,     6,    25,
       0,    18,     0,    25,     0,     0,     9,     0,     0,     0,
      43,     0,     0,     0,    43,    11,    43,    43,     0,    43,
      10,    43,    43,    43,    43,    24,    23,     0,     0,    44,
       0,   103,   113,   114,   115,    74,    84,     0,     0,     0,
       0,     0,    85,   109,    13,    81,    82,    83,    19,    26,
       0,     0,     0,    12,     0,     0,     0,     0,     0,    46,
       0,    31,     0,   111,     0,   102,   101,   100,     0,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,    28,    34,
      33,    30,    36,    32,    29,    35,    45,    16,    39,     0,
     112,     0,    75,   106,   107,    86,     0,    98,    99,    97,
      93,    95,    94,    92,    96,    87,    88,    89,    90,    91,
     110,    37,    41,    40,    38,    42,     0,     0,     0,     0,
      17,    59,     0,   105,   104,     0,     0,    78,     0,     0,
       0,    18,    14,     0,     0,     0,     0,    51,    67,    68,
       0,    70,    69,    60,     0,    57,     0,    25,     0,     0,
      76,     0,    25,     9,    15,     0,     0,     0,     0,     0,
      49,    52,     0,    54,    55,     0,    58,    47,    64,    77,
       0,    79,    65,    66,     0,     0,     0,     0,   111,    56,
      80,    61,     0,     0,    50,     0,     0,     0,    62,    53,
      48,   111,     0,    71,     0,     0,     0,    72,    63,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,  -206,  -206,   341,  -121,  -206,  -206,   -13,     0,   -28,
     287,  -206,  -206,    56,   263,   -84,   138,  -206,  -206,  -206,
    -206,  -206,  -137,   119,  -206,   -40,   -33,  -205,  -206,  -206,
    -206
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     9,    10,    11,    12,   160,   161,    25,    57,    45,
      14,    15,    16,    58,    59,   181,   200,   201,   202,   182,
     183,   184,   185,   228,    72,    73,   130,   131,    75,    76,
      77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    18,    21,    79,    32,    50,   159,   128,    74,    43,
      13,    23,    43,   225,    24,    83,   103,   104,   105,   106,
     107,    41,    44,    39,   100,    49,   234,    95,    96,    97,
      98,    99,    26,    42,   151,   152,   153,   154,   155,   173,
      28,    93,   101,    29,   102,    94,   206,   113,   114,   115,
     108,   109,   110,   111,   112,   113,   114,   115,    30,   129,
     135,   136,   133,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   221,   103,   104,
     105,   106,   107,    48,   222,     3,     4,     5,     6,    38,
     233,     3,     4,     5,     6,    42,    42,    31,   237,   238,
      80,    33,    81,    82,    90,    84,    91,    85,    86,    87,
      88,    34,   108,   109,   110,   111,   112,   113,   114,   115,
      90,   186,   118,   165,   166,    35,   191,   162,    90,   134,
     119,   103,   104,   105,   106,   107,   197,    90,    90,   120,
     121,   195,   196,   186,   203,    40,    90,   205,   122,   210,
     111,   112,   113,   114,   115,    32,   169,   170,    36,    90,
     162,   123,   212,   116,    50,   108,   109,   110,   111,   112,
     113,   114,   115,    37,   186,   106,   107,   199,    90,    90,
     124,   125,   167,   230,    46,   215,   232,   186,    78,   229,
     103,   104,   105,   106,   107,   186,   186,    47,   103,   104,
     105,   106,   107,   116,    55,   163,    51,   109,   110,   111,
     112,   113,   114,   115,   188,   189,   156,   199,   157,     3,
       4,     5,     6,   158,   108,   109,   110,   111,   112,   113,
     114,   115,   108,   109,   110,   111,   112,   113,   114,   115,
      52,   211,    60,    61,   174,   175,   213,   116,    56,   220,
       3,     4,     5,     6,   168,   176,   219,   116,    89,   177,
      53,   178,   179,   180,    62,    63,    64,    65,    66,    54,
      67,   226,   227,   116,    68,    69,     3,     4,     5,     6,
      17,     8,    70,   117,   127,    60,    61,    71,    19,    22,
      92,   127,     3,     4,     5,     6,   198,     1,   132,     2,
       3,     4,     5,     6,     7,     8,   164,    62,    63,    64,
      65,    66,   171,    67,    60,    61,   172,    68,    69,     3,
       4,     5,     6,    20,     8,    70,   187,   190,   192,   193,
      71,   207,   194,    43,   216,   209,    62,    63,    64,    65,
      66,   217,    67,    60,    61,   218,    68,    69,   223,   231,
     236,    27,   204,   126,    70,   224,   239,     0,     0,    71,
     103,   104,   105,   106,   107,    62,    63,    64,    65,    66,
       0,    67,     0,     0,     0,    68,    69,     0,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     0,    71,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   208,     0,     0,     0,     0,   214,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   235,   103,   104,   105,   106,   107,     0,     0,     0,
     103,     0,   105,   106,   107,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
       0,     1,     2,    43,    17,    33,   127,    91,    41,    35,
      10,    38,    35,   218,    33,    48,     3,     4,     5,     6,
       7,    35,    48,    23,    35,    48,   231,    67,    68,    69,
      70,    71,     0,    47,   118,   119,   120,   121,   122,   160,
      46,    48,    53,    33,    55,    52,   183,    42,    43,    44,
      37,    38,    39,    40,    41,    42,    43,    44,    33,    92,
     100,   101,    49,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   214,     3,     4,
       5,     6,     7,    35,    35,    15,    16,    17,    18,    19,
     227,    15,    16,    17,    18,    47,    47,    33,   235,   236,
      44,    33,    46,    47,    47,    49,    49,    51,    52,    53,
      54,    33,    37,    38,    39,    40,    41,    42,    43,    44,
      47,   161,    49,    52,    53,    33,   166,   127,    47,    54,
      49,     3,     4,     5,     6,     7,   176,    47,    47,    49,
      49,   174,   175,   183,   177,    48,    47,   180,    49,   189,
      40,    41,    42,    43,    44,   168,   156,   157,    33,    47,
     160,    49,    46,    47,   192,    37,    38,    39,    40,    41,
      42,    43,    44,    33,   214,     6,     7,   177,    47,    47,
      49,    49,    54,   223,    48,   198,   226,   227,    33,   222,
       3,     4,     5,     6,     7,   235,   236,    48,     3,     4,
       5,     6,     7,    47,    39,    49,    48,    38,    39,    40,
      41,    42,    43,    44,    52,    53,    12,   217,    14,    15,
      16,    17,    18,    19,    37,    38,    39,    40,    41,    42,
      43,    44,    37,    38,    39,    40,    41,    42,    43,    44,
      48,    54,     8,     9,    10,    11,    46,    47,    39,    54,
      15,    16,    17,    18,    19,    21,    46,    47,    33,    25,
      48,    27,    28,    29,    30,    31,    32,    33,    34,    48,
      36,    23,    24,    47,    40,    41,    15,    16,    17,    18,
      19,    20,    48,    32,    50,     8,     9,    53,     1,     2,
      48,    50,    15,    16,    17,    18,    19,    12,    30,    14,
      15,    16,    17,    18,    19,    20,    49,    30,    31,    32,
      33,    34,    33,    36,     8,     9,    46,    40,    41,    15,
      16,    17,    18,    19,    20,    48,    33,    30,    33,    33,
      53,    51,    46,    35,    33,    30,    30,    31,    32,    33,
      34,    47,    36,     8,     9,    46,    40,    41,    35,    46,
      26,    10,    46,    90,    48,   217,   237,    -1,    -1,    53,
       3,     4,     5,     6,     7,    30,    31,    32,    33,    34,
      -1,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    53,     3,
       4,     5,     6,     7,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    46,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    22,     3,     4,     5,     6,     7,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    14,    15,    16,    17,    18,    19,    20,    57,
      58,    59,    60,    64,    66,    67,    68,    19,    64,    66,
      19,    64,    66,    38,    33,    63,     0,    59,    46,    33,
      33,    33,    63,    33,    33,    33,    33,    33,    19,    64,
      48,    35,    47,    35,    48,    65,    48,    48,    35,    48,
      65,    48,    48,    48,    48,    39,    39,    64,    69,    70,
       8,     9,    30,    31,    32,    33,    34,    36,    40,    41,
      48,    53,    80,    81,    82,    84,    85,    86,    33,    81,
      69,    69,    69,    82,    69,    69,    69,    69,    69,    33,
      47,    49,    48,    48,    52,    81,    81,    81,    81,    81,
      35,    53,    55,     3,     4,     5,     6,     7,    37,    38,
      39,    40,    41,    42,    43,    44,    47,    32,    49,    49,
      49,    49,    49,    49,    49,    49,    70,    50,    71,    82,
      82,    83,    30,    49,    54,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    71,    71,    71,    71,    71,    12,    14,    19,    60,
      61,    62,    64,    49,    49,    52,    53,    54,    19,    64,
      64,    33,    46,    60,    10,    11,    21,    25,    27,    28,
      29,    71,    75,    76,    77,    78,    81,    33,    52,    53,
      30,    81,    33,    33,    46,    82,    82,    81,    19,    64,
      72,    73,    74,    82,    46,    82,    78,    51,    46,    30,
      81,    54,    46,    46,    22,    63,    33,    47,    46,    46,
      54,    78,    35,    35,    72,    83,    23,    24,    79,    82,
      81,    46,    81,    78,    83,    22,    26,    78,    78,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    59,    59,    59,    60,
      60,    60,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    65,    65,    66,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    68,
      68,    68,    68,    69,    69,    69,    70,    71,    72,    73,
      73,    74,    74,    74,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    83,    83,    84,    85,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     1,     1,     3,
       4,     3,     5,     4,     2,     3,     0,     1,     1,     3,
       1,     1,     1,     4,     4,     0,     2,     1,     5,     6,
       6,     5,     6,     6,     5,     6,     6,     6,     7,     6,
       7,     6,     7,     0,     1,     3,     2,     4,     4,     1,
       3,     0,     1,     4,     1,     2,     3,     1,     2,     0,
       1,     4,     5,     8,     2,     3,     3,     1,     1,     1,
       1,     2,     4,     5,     1,     3,     5,     6,     4,     6,
       7,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     1,     4,     4,     3,     3,     2,     1,
       3,     0,     1,     1,     1,     1,     2
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
#line 87 "og_parser.y"
                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE)); }
#line 1382 "og_parser.tab.c"
    break;

  case 3: /* file: declarations  */
#line 88 "og_parser.y"
                            { compiler->ast((yyval.sequence) = (yyvsp[0].sequence)); }
#line 1388 "og_parser.tab.c"
    break;

  case 4: /* declarations: declaration  */
#line 91 "og_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1394 "og_parser.tab.c"
    break;

  case 5: /* declarations: declarations declaration  */
#line 92 "og_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1400 "og_parser.tab.c"
    break;

  case 6: /* declaration: vardec ';'  */
#line 95 "og_parser.y"
                          { (yyval.node) = (yyvsp[-1].node); }
#line 1406 "og_parser.tab.c"
    break;

  case 7: /* declaration: fundec  */
#line 96 "og_parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1412 "og_parser.tab.c"
    break;

  case 8: /* declaration: fundef  */
#line 97 "og_parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1418 "og_parser.tab.c"
    break;

  case 9: /* vardec: tREQUIRE data_type tID  */
#line 100 "og_parser.y"
                                                               { (yyval.node) = new og::variable_declaration_node(LINE, tPUBLIC,  (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1424 "og_parser.tab.c"
    break;

  case 10: /* vardec: tPUBLIC data_type tID opt_initializer  */
#line 101 "og_parser.y"
                                                               { (yyval.node) = new og::variable_declaration_node(LINE, tPUBLIC,  (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1430 "og_parser.tab.c"
    break;

  case 11: /* vardec: data_type tID opt_initializer  */
#line 102 "og_parser.y"
                                                               { (yyval.node) = new og::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1436 "og_parser.tab.c"
    break;

  case 12: /* vardec: tPUBLIC tTYPE_AUTO identifiers '=' expressions  */
#line 104 "og_parser.y"
             {
               (yyval.node) = new og::tuple_declaration_node(LINE, tPUBLIC,  *(yyvsp[-2].ids), new og::tuple_node(LINE, (yyvsp[0].sequence)));
               delete (yyvsp[-2].ids);
             }
#line 1445 "og_parser.tab.c"
    break;

  case 13: /* vardec: tTYPE_AUTO identifiers '=' expressions  */
#line 109 "og_parser.y"
             {
               (yyval.node) = new og::tuple_declaration_node(LINE, tPRIVATE, *(yyvsp[-2].ids), new og::tuple_node(LINE, (yyvsp[0].sequence)));
               delete (yyvsp[-2].ids);
             }
#line 1454 "og_parser.tab.c"
    break;

  case 14: /* vardecs: vardec ';'  */
#line 115 "og_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node));     }
#line 1460 "og_parser.tab.c"
    break;

  case 15: /* vardecs: vardecs vardec ';'  */
#line 116 "og_parser.y"
                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence)); }
#line 1466 "og_parser.tab.c"
    break;

  case 16: /* opt_vardecs: %empty  */
#line 119 "og_parser.y"
                           { (yyval.sequence) = NULL; }
#line 1472 "og_parser.tab.c"
    break;

  case 17: /* opt_vardecs: vardecs  */
#line 120 "og_parser.y"
                           { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1478 "og_parser.tab.c"
    break;

  case 18: /* identifiers: tID  */
#line 123 "og_parser.y"
                   { (yyval.ids) = new std::vector<std::string>(); (yyval.ids)->push_back(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1484 "og_parser.tab.c"
    break;

  case 19: /* identifiers: identifiers ',' tID  */
#line 124 "og_parser.y"
                                         { (yyval.ids) = (yyvsp[-2].ids); (yyval.ids)->push_back(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1490 "og_parser.tab.c"
    break;

  case 20: /* data_type: tTYPE_STRING  */
#line 127 "og_parser.y"
                                                { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
#line 1496 "og_parser.tab.c"
    break;

  case 21: /* data_type: tTYPE_INT  */
#line 128 "og_parser.y"
                                                { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT);     }
#line 1502 "og_parser.tab.c"
    break;

  case 22: /* data_type: tTYPE_REAL  */
#line 129 "og_parser.y"
                                                { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
#line 1508 "og_parser.tab.c"
    break;

  case 23: /* data_type: tTYPE_POINTER '<' data_type '>'  */
#line 130 "og_parser.y"
                                                { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1514 "og_parser.tab.c"
    break;

  case 24: /* data_type: tTYPE_POINTER '<' tTYPE_AUTO '>'  */
#line 131 "og_parser.y"
                                                { (yyval.type) = cdk::reference_type::create(4, nullptr); }
#line 1520 "og_parser.tab.c"
    break;

  case 25: /* opt_initializer: %empty  */
#line 134 "og_parser.y"
                                       { (yyval.expression) = nullptr; /* must be nullptr, not NIL */ }
#line 1526 "og_parser.tab.c"
    break;

  case 26: /* opt_initializer: '=' expression  */
#line 135 "og_parser.y"
                                       { (yyval.expression) = (yyvsp[0].expression); }
#line 1532 "og_parser.tab.c"
    break;

  case 27: /* void_type: tPROCEDURE  */
#line 138 "og_parser.y"
                         { (yyval.type) = cdk::primitive_type::create(0, cdk::TYPE_VOID);   }
#line 1538 "og_parser.tab.c"
    break;

  case 28: /* fundec: data_type tID '(' argdecs ')'  */
#line 141 "og_parser.y"
                                                   { (yyval.node) = new og::function_declaration_node(LINE, tPRIVATE, (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1544 "og_parser.tab.c"
    break;

  case 29: /* fundec: tREQUIRE data_type tID '(' argdecs ')'  */
#line 142 "og_parser.y"
                                                   { (yyval.node) = new og::function_declaration_node(LINE, tPUBLIC,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1550 "og_parser.tab.c"
    break;

  case 30: /* fundec: tPUBLIC data_type tID '(' argdecs ')'  */
#line 143 "og_parser.y"
                                                   { (yyval.node) = new og::function_declaration_node(LINE, tPUBLIC,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1556 "og_parser.tab.c"
    break;

  case 31: /* fundec: tTYPE_AUTO tID '(' argdecs ')'  */
#line 144 "og_parser.y"
                                                   { (yyval.node) = new og::function_declaration_node(LINE, tPRIVATE, nullptr, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1562 "og_parser.tab.c"
    break;

  case 32: /* fundec: tREQUIRE tTYPE_AUTO tID '(' argdecs ')'  */
#line 145 "og_parser.y"
                                                   { (yyval.node) = new og::function_declaration_node(LINE, tPUBLIC,  nullptr, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1568 "og_parser.tab.c"
    break;

  case 33: /* fundec: tPUBLIC tTYPE_AUTO tID '(' argdecs ')'  */
#line 146 "og_parser.y"
                                                   { (yyval.node) = new og::function_declaration_node(LINE, tPUBLIC,  nullptr, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1574 "og_parser.tab.c"
    break;

  case 34: /* fundec: void_type tID '(' argdecs ')'  */
#line 147 "og_parser.y"
                                                   { (yyval.node) = new og::function_declaration_node(LINE, tPRIVATE, (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1580 "og_parser.tab.c"
    break;

  case 35: /* fundec: tREQUIRE void_type tID '(' argdecs ')'  */
#line 148 "og_parser.y"
                                                   { (yyval.node) = new og::function_declaration_node(LINE, tPUBLIC,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1586 "og_parser.tab.c"
    break;

  case 36: /* fundec: tPUBLIC void_type tID '(' argdecs ')'  */
#line 149 "og_parser.y"
                                                   { (yyval.node) = new og::function_declaration_node(LINE, tPUBLIC,  (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1592 "og_parser.tab.c"
    break;

  case 37: /* fundef: data_type tID '(' argdecs ')' block  */
#line 152 "og_parser.y"
                                                        { (yyval.node) = new og::function_definition_node(LINE, tPRIVATE, (yyvsp[-5].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); }
#line 1598 "og_parser.tab.c"
    break;

  case 38: /* fundef: tPUBLIC data_type tID '(' argdecs ')' block  */
#line 153 "og_parser.y"
                                                        { (yyval.node) = new og::function_definition_node(LINE, tPUBLIC,  (yyvsp[-5].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); }
#line 1604 "og_parser.tab.c"
    break;

  case 39: /* fundef: tTYPE_AUTO tID '(' argdecs ')' block  */
#line 154 "og_parser.y"
                                                        { (yyval.node) = new og::function_definition_node(LINE, tPRIVATE, nullptr, *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); }
#line 1610 "og_parser.tab.c"
    break;

  case 40: /* fundef: tPUBLIC tTYPE_AUTO tID '(' argdecs ')' block  */
#line 155 "og_parser.y"
                                                        { (yyval.node) = new og::function_definition_node(LINE, tPUBLIC,  nullptr, *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); }
#line 1616 "og_parser.tab.c"
    break;

  case 41: /* fundef: void_type tID '(' argdecs ')' block  */
#line 156 "og_parser.y"
                                                        { (yyval.node) = new og::function_definition_node(LINE, tPRIVATE, (yyvsp[-5].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); }
#line 1622 "og_parser.tab.c"
    break;

  case 42: /* fundef: tPUBLIC void_type tID '(' argdecs ')' block  */
#line 157 "og_parser.y"
                                                        { (yyval.node) = new og::function_definition_node(LINE, tPUBLIC,  (yyvsp[-5].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].block)); }
#line 1628 "og_parser.tab.c"
    break;

  case 43: /* argdecs: %empty  */
#line 160 "og_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE);  }
#line 1634 "og_parser.tab.c"
    break;

  case 44: /* argdecs: argdec  */
#line 161 "og_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1640 "og_parser.tab.c"
    break;

  case 45: /* argdecs: argdecs ',' argdec  */
#line 162 "og_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1646 "og_parser.tab.c"
    break;

  case 46: /* argdec: data_type tID  */
#line 165 "og_parser.y"
                         { (yyval.node) = new og::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1652 "og_parser.tab.c"
    break;

  case 47: /* block: '{' opt_vardecs opt_instructions '}'  */
#line 168 "og_parser.y"
                                                { (yyval.block) = new og::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1658 "og_parser.tab.c"
    break;

  case 48: /* fordec: data_type tID '=' expression  */
#line 171 "og_parser.y"
                                               { (yyval.node) = new og::variable_declaration_node(LINE, tPRIVATE,  (yyvsp[-3].type), *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1664 "og_parser.tab.c"
    break;

  case 49: /* fordecs: fordec  */
#line 174 "og_parser.y"
                                     { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1670 "og_parser.tab.c"
    break;

  case 50: /* fordecs: fordecs ',' fordec  */
#line 175 "og_parser.y"
                                     { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1676 "og_parser.tab.c"
    break;

  case 51: /* opt_forinit: %empty  */
#line 178 "og_parser.y"
                           { (yyval.node) = new cdk::sequence_node(LINE, NIL); }
#line 1682 "og_parser.tab.c"
    break;

  case 52: /* opt_forinit: fordecs  */
#line 179 "og_parser.y"
                           { (yyval.node) = (yyvsp[0].sequence); }
#line 1688 "og_parser.tab.c"
    break;

  case 53: /* opt_forinit: tTYPE_AUTO identifiers '=' expressions  */
#line 180 "og_parser.y"
                                                         {
                   (yyval.node) = new og::tuple_declaration_node(LINE, tPRIVATE, *(yyvsp[-2].ids), new og::tuple_node(LINE, (yyvsp[0].sequence)));
                   delete (yyvsp[-2].ids);
                }
#line 1697 "og_parser.tab.c"
    break;

  case 54: /* opt_forinit: expressions  */
#line 184 "og_parser.y"
                              { (yyval.node) = new og::tuple_node(LINE, (yyvsp[0].sequence)); }
#line 1703 "og_parser.tab.c"
    break;

  case 55: /* return: tRETURN ';'  */
#line 187 "og_parser.y"
                                          { (yyval.node) = new og::return_node(LINE, nullptr); }
#line 1709 "og_parser.tab.c"
    break;

  case 56: /* return: tRETURN expressions ';'  */
#line 188 "og_parser.y"
                                          { (yyval.node) = new og::return_node(LINE, new og::tuple_node(LINE, (yyvsp[-1].sequence))); }
#line 1715 "og_parser.tab.c"
    break;

  case 57: /* instructions: instruction  */
#line 191 "og_parser.y"
                                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1721 "og_parser.tab.c"
    break;

  case 58: /* instructions: instructions instruction  */
#line 192 "og_parser.y"
                                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1727 "og_parser.tab.c"
    break;

  case 59: /* opt_instructions: %empty  */
#line 195 "og_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1733 "og_parser.tab.c"
    break;

  case 60: /* opt_instructions: instructions  */
#line 196 "og_parser.y"
                               { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1739 "og_parser.tab.c"
    break;

  case 61: /* instruction: tIF expression tTHEN instruction  */
#line 199 "og_parser.y"
                                                                                            { (yyval.node) = new og::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1745 "og_parser.tab.c"
    break;

  case 62: /* instruction: tIF expression tTHEN instruction iffalse  */
#line 200 "og_parser.y"
                                                                                            { (yyval.node) = new og::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1751 "og_parser.tab.c"
    break;

  case 63: /* instruction: tFOR opt_forinit ';' opt_expressions ';' opt_expressions tDO instruction  */
#line 201 "og_parser.y"
                                                                                            { (yyval.node) = new og::for_node(LINE, (yyvsp[-6].node), (yyvsp[-4].sequence), (yyvsp[-2].sequence), (yyvsp[0].node)); }
#line 1757 "og_parser.tab.c"
    break;

  case 64: /* instruction: expression ';'  */
#line 202 "og_parser.y"
                                                                                            { (yyval.node) = new og::evaluation_node(LINE, (yyvsp[-1].expression)); }
#line 1763 "og_parser.tab.c"
    break;

  case 65: /* instruction: tWRITE expressions ';'  */
#line 203 "og_parser.y"
                                                                                            { (yyval.node) = new og::print_node(LINE, (yyvsp[-1].sequence), false); }
#line 1769 "og_parser.tab.c"
    break;

  case 66: /* instruction: tWRITELN expressions ';'  */
#line 204 "og_parser.y"
                                                                                            { (yyval.node) = new og::print_node(LINE, (yyvsp[-1].sequence), true); }
#line 1775 "og_parser.tab.c"
    break;

  case 67: /* instruction: tBREAK  */
#line 205 "og_parser.y"
                                                                                            { (yyval.node) = new og::break_node(LINE);  }
#line 1781 "og_parser.tab.c"
    break;

  case 68: /* instruction: tCONTINUE  */
#line 206 "og_parser.y"
                                                                                            { (yyval.node) = new og::continue_node(LINE); }
#line 1787 "og_parser.tab.c"
    break;

  case 69: /* instruction: return  */
#line 207 "og_parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1793 "og_parser.tab.c"
    break;

  case 70: /* instruction: block  */
#line 208 "og_parser.y"
                                                                                            { (yyval.node) = (yyvsp[0].block); }
#line 1799 "og_parser.tab.c"
    break;

  case 71: /* iffalse: tELSE instruction  */
#line 211 "og_parser.y"
                                                                { (yyval.node) = (yyvsp[0].node); }
#line 1805 "og_parser.tab.c"
    break;

  case 72: /* iffalse: tELIF expression tTHEN instruction  */
#line 212 "og_parser.y"
                                                                { (yyval.node) = new og::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1811 "og_parser.tab.c"
    break;

  case 73: /* iffalse: tELIF expression tTHEN instruction iffalse  */
#line 213 "og_parser.y"
                                                                { (yyval.node) = new og::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1817 "og_parser.tab.c"
    break;

  case 74: /* lvalue: tID  */
#line 216 "og_parser.y"
                                                                 { (yyval.lvalue) = new cdk::variable_node(LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1823 "og_parser.tab.c"
    break;

  case 75: /* lvalue: tID '@' tINTEGER  */
#line 218 "og_parser.y"
                {
                  (yyval.lvalue) = new og::tuple_index_node(LINE, new cdk::rvalue_node(LINE, new cdk::variable_node(LINE, *(yyvsp[-2].s))), (yyvsp[0].i));
                  delete (yyvsp[-2].s);
                }
#line 1832 "og_parser.tab.c"
    break;

  case 76: /* lvalue: '(' expression ')' '@' tINTEGER  */
#line 223 "og_parser.y"
                {
                  (yyval.lvalue) = new og::tuple_index_node(LINE, (yyvsp[-3].expression), (yyvsp[0].i));
                }
#line 1840 "og_parser.tab.c"
    break;

  case 77: /* lvalue: tID '(' opt_expressions ')' '@' tINTEGER  */
#line 227 "og_parser.y"
                { 
                  (yyval.lvalue) = new og::tuple_index_node(LINE, new og::function_call_node(LINE, *(yyvsp[-5].s), (yyvsp[-3].sequence)), (yyvsp[0].i)); 
                }
#line 1848 "og_parser.tab.c"
    break;

  case 78: /* lvalue: lvalue '[' expression ']'  */
#line 230 "og_parser.y"
                                                                 { (yyval.lvalue) = new og::index_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-3].lvalue)), (yyvsp[-1].expression)); }
#line 1854 "og_parser.tab.c"
    break;

  case 79: /* lvalue: '(' expression ')' '[' expression ']'  */
#line 231 "og_parser.y"
                                                                 { (yyval.lvalue) = new og::index_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].expression)); }
#line 1860 "og_parser.tab.c"
    break;

  case 80: /* lvalue: tID '(' opt_expressions ')' '[' expression ']'  */
#line 232 "og_parser.y"
                                                                 { (yyval.lvalue) = new og::index_node(LINE, new og::function_call_node(LINE, *(yyvsp[-6].s), (yyvsp[-4].sequence)), (yyvsp[-1].expression)); }
#line 1866 "og_parser.tab.c"
    break;

  case 81: /* expression: integer  */
#line 235 "og_parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 1872 "og_parser.tab.c"
    break;

  case 82: /* expression: real  */
#line 236 "og_parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 1878 "og_parser.tab.c"
    break;

  case 83: /* expression: string  */
#line 237 "og_parser.y"
                                                { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1884 "og_parser.tab.c"
    break;

  case 84: /* expression: tNULLPTR  */
#line 238 "og_parser.y"
                                                { (yyval.expression) = new og::nullptr_node(LINE); }
#line 1890 "og_parser.tab.c"
    break;

  case 85: /* expression: lvalue  */
#line 240 "og_parser.y"
                                                { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 1896 "og_parser.tab.c"
    break;

  case 86: /* expression: lvalue '=' expression  */
#line 242 "og_parser.y"
                                                { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 1902 "og_parser.tab.c"
    break;

  case 87: /* expression: expression '+' expression  */
#line 244 "og_parser.y"
                                               { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1908 "og_parser.tab.c"
    break;

  case 88: /* expression: expression '-' expression  */
#line 245 "og_parser.y"
                                               { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1914 "og_parser.tab.c"
    break;

  case 89: /* expression: expression '*' expression  */
#line 246 "og_parser.y"
                                               { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1920 "og_parser.tab.c"
    break;

  case 90: /* expression: expression '/' expression  */
#line 247 "og_parser.y"
                                               { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1926 "og_parser.tab.c"
    break;

  case 91: /* expression: expression '%' expression  */
#line 248 "og_parser.y"
                                               { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1932 "og_parser.tab.c"
    break;

  case 92: /* expression: expression '<' expression  */
#line 250 "og_parser.y"
                                                { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1938 "og_parser.tab.c"
    break;

  case 93: /* expression: expression tLE expression  */
#line 251 "og_parser.y"
                                                { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1944 "og_parser.tab.c"
    break;

  case 94: /* expression: expression tEQ expression  */
#line 252 "og_parser.y"
                                                { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1950 "og_parser.tab.c"
    break;

  case 95: /* expression: expression tGE expression  */
#line 253 "og_parser.y"
                                                { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1956 "og_parser.tab.c"
    break;

  case 96: /* expression: expression '>' expression  */
#line 254 "og_parser.y"
                                                { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1962 "og_parser.tab.c"
    break;

  case 97: /* expression: expression tNE expression  */
#line 255 "og_parser.y"
                                                { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1968 "og_parser.tab.c"
    break;

  case 98: /* expression: expression tAND expression  */
#line 257 "og_parser.y"
                                                 { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1974 "og_parser.tab.c"
    break;

  case 99: /* expression: expression tOR expression  */
#line 258 "og_parser.y"
                                                 { (yyval.expression) = new cdk::or_node (LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1980 "og_parser.tab.c"
    break;

  case 100: /* expression: '-' expression  */
#line 260 "og_parser.y"
                                                { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression)); }
#line 1986 "og_parser.tab.c"
    break;

  case 101: /* expression: '+' expression  */
#line 261 "og_parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 1992 "og_parser.tab.c"
    break;

  case 102: /* expression: '~' expression  */
#line 262 "og_parser.y"
                                                { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 1998 "og_parser.tab.c"
    break;

  case 103: /* expression: tINPUT  */
#line 264 "og_parser.y"
                                                { (yyval.expression) = new og::input_node(LINE); }
#line 2004 "og_parser.tab.c"
    break;

  case 104: /* expression: tID '(' opt_expressions ')'  */
#line 266 "og_parser.y"
                                                { (yyval.expression) = new og::function_call_node(LINE, *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 2010 "og_parser.tab.c"
    break;

  case 105: /* expression: tSIZEOF '(' expressions ')'  */
#line 267 "og_parser.y"
                                                { (yyval.expression) = new og::sizeof_node(LINE, new og::tuple_node(LINE, (yyvsp[-1].sequence))); }
#line 2016 "og_parser.tab.c"
    break;

  case 106: /* expression: '(' expression ')'  */
#line 269 "og_parser.y"
                                                { (yyval.expression) = (yyvsp[-1].expression); }
#line 2022 "og_parser.tab.c"
    break;

  case 107: /* expression: '[' expression ']'  */
#line 270 "og_parser.y"
                                                { (yyval.expression) = new og::stack_alloc_node(LINE, (yyvsp[-1].expression)); }
#line 2028 "og_parser.tab.c"
    break;

  case 108: /* expression: lvalue '?'  */
#line 271 "og_parser.y"
                                                { (yyval.expression) = new og::address_of_node(LINE, (yyvsp[-1].lvalue)); }
#line 2034 "og_parser.tab.c"
    break;

  case 109: /* expressions: expression  */
#line 274 "og_parser.y"
                                                 { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression));     }
#line 2040 "og_parser.tab.c"
    break;

  case 110: /* expressions: expressions ',' expression  */
#line 275 "og_parser.y"
                                                 { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 2046 "og_parser.tab.c"
    break;

  case 111: /* opt_expressions: %empty  */
#line 278 "og_parser.y"
                                      { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 2052 "og_parser.tab.c"
    break;

  case 112: /* opt_expressions: expressions  */
#line 279 "og_parser.y"
                                      { (yyval.sequence) = (yyvsp[0].sequence); }
#line 2058 "og_parser.tab.c"
    break;

  case 113: /* integer: tINTEGER  */
#line 282 "og_parser.y"
                                                { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 2064 "og_parser.tab.c"
    break;

  case 114: /* real: tREAL  */
#line 283 "og_parser.y"
                                                { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 2070 "og_parser.tab.c"
    break;

  case 115: /* string: tSTRING  */
#line 284 "og_parser.y"
                                                { (yyval.s) = (yyvsp[0].s); }
#line 2076 "og_parser.tab.c"
    break;

  case 116: /* string: string tSTRING  */
#line 285 "og_parser.y"
                                                { (yyval.s) = (yyvsp[-1].s); (yyval.s)->append(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2082 "og_parser.tab.c"
    break;


#line 2086 "og_parser.tab.c"

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

#line 288 "og_parser.y"

