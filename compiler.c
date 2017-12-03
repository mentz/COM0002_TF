/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compiler.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define YYSTYPE struct Atributo

int linha = 1;
extern struct Simbolo *tabSim;


#line 77 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TDO = 258,
    TIF = 259,
    TINT = 260,
    TELSE = 261,
    TFLOAT = 262,
    TPRINT = 263,
    TREAD = 264,
    TRETURN = 265,
    TSTRING = 266,
    TVOID = 267,
    TWHILE = 268,
    TMEIG = 269,
    TMAIG = 270,
    TEQ = 271,
    TDIF = 272,
    TAND = 273,
    TOR = 274,
    TID = 275,
    TLITERAL = 276
  };
#endif
/* Tokens.  */
#define TDO 258
#define TIF 259
#define TINT 260
#define TELSE 261
#define TFLOAT 262
#define TPRINT 263
#define TREAD 264
#define TRETURN 265
#define TSTRING 266
#define TVOID 267
#define TWHILE 268
#define TMEIG 269
#define TMAIG 270
#define TEQ 271
#define TDIF 272
#define TAND 273
#define TOR 274
#define TID 275
#define TLITERAL 276

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 167 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,     2,     2,     2,
      22,    23,    34,    32,    24,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
      29,    28,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    19,    19,    20,    29,    30,    34,    35,    39,    40,
      44,    45,    49,    53,    58,    65,    66,    70,    77,    81,
      85,    92,    96,   103,   110,   114,   121,   125,   129,   133,
     137,   141,   145,   152,   153,   157,   161,   168,   172,   179,
     196,   208,   215,   219,   227,   231,   235,   236,   240,   241,
     242,   243,   247,   268,   289,   311,   333,   355,   380,   384,
     388,   395,   399,   403,   410,   432,   454,   461,   482,   503,
     511,   516,   521,   525,   530,   535,   548,   557,   572,   581,
     596,   611
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TDO", "TIF", "TINT", "TELSE", "TFLOAT",
  "TPRINT", "TREAD", "TRETURN", "TSTRING", "TVOID", "TWHILE", "TMEIG",
  "TMAIG", "TEQ", "TDIF", "TAND", "TOR", "TID", "TLITERAL", "'('", "')'",
  "','", "'{'", "'}'", "';'", "'='", "'<'", "'>'", "'!'", "'+'", "'-'",
  "'*'", "'/'", "$accept", "Programa", "ListaFuncoes", "Funcao",
  "TipoRetorno", "DeclParametros", "Parametro", "BlocoPrincipal",
  "Declaracoes", "Declaracao", "Tipo", "ListaId", "Bloco", "ListaCmd",
  "Comando", "Retorno", "CmdSe", "CmdEnquanto", "CmdAtrib", "CmdEscrita",
  "CmdLeitura", "ChamadaProc", "ChamadaFuncao", "ListaParametros",
  "ExpressaoRelacional", "ExpressaoLogica", "ArgumentoLogico",
  "ExpressaoAritmetica", "TermoAritmetico", "FatorAritmetico",
  "AutoOperacao", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    40,    41,    44,   123,   125,    59,    61,    60,
      62,    33,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     117,  -109,  -109,  -109,  -109,   200,    11,   117,  -109,   -11,
    -109,  -109,    20,    35,    42,    48,    54,    50,   201,   200,
    -109,    -1,   137,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,     6,    72,  -109,  -109,  -109,    86,   218,   107,     5,
      74,   103,  -109,  -109,   105,   108,    45,    45,  -109,    -9,
      75,  -109,     5,     8,    93,    58,     9,   102,   109,  -109,
     145,  -109,    64,  -109,  -109,  -109,  -109,    66,   164,   156,
       5,     5,  -109,   120,  -109,   185,   160,    21,   166,  -109,
      60,  -109,  -109,    45,    45,    45,    45,   133,  -109,  -109,
      88,   153,   169,    36,    45,  -109,    45,  -109,    45,    45,
    -109,   167,  -109,   168,   146,  -109,   171,  -109,     5,   141,
     165,  -109,     5,     5,    20,    45,    45,    45,    45,    45,
      45,   179,   189,   192,  -109,    75,    75,  -109,  -109,    20,
    -109,   111,  -109,  -109,   153,   153,   153,   153,  -109,  -109,
     168,   114,  -109,   143,  -109,  -109,  -109,   186,   153,   153,
     153,   153,   153,   153,  -109,  -109,  -109,  -109,  -109,   153,
    -109,  -109,   197,    20,  -109,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,    20,    19,     9,     0,     0,     0,     5,     0,
       3,     8,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,    25,    32,    26,    27,    28,    29,    30,
      31,     0,     0,     1,     4,     2,     0,     0,     0,     0,
       0,     0,    73,    74,    75,     0,     0,     0,    72,     0,
      66,    69,     0,     0,     0,     0,     0,     0,     0,    15,
       0,    22,     0,    14,    24,    45,    41,     0,     0,     0,
       0,     0,    63,     0,    60,     0,     0,     0,     0,    34,
       0,    71,    33,     0,     0,     0,     0,     0,    51,    47,
       0,    50,     0,     0,     0,    76,     0,    78,     0,     0,
      13,     0,    17,     0,     0,    11,     0,    23,     0,     0,
       0,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    64,    65,    67,    68,     0,
      46,     0,    40,    39,    77,    79,    80,    81,    21,     7,
       0,     0,    12,     0,    61,    58,    59,    35,    54,    55,
      56,    57,    52,    53,    43,    42,    44,    37,    49,    48,
       6,    10,     0,     0,    38,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,   205,  -109,  -109,    84,    -6,  -109,   211,
      -5,  -109,  -108,    -3,   -17,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,    -2,  -109,  -109,   -48,   -64,   -14,    92,   -39,
    -109
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,   104,   105,    10,    19,    20,
      11,    62,    38,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    48,    90,    72,    73,    74,    75,    50,    51,
      32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      21,    35,    49,    31,    87,    64,   147,   111,    81,    36,
      42,    33,    43,    42,    21,    43,    60,    31,    82,    61,
      31,   157,   109,    83,    84,    44,    77,    70,    44,    88,
      46,    89,    80,    65,    68,    31,    71,    96,    47,    91,
      93,    47,    97,    64,   122,    37,   127,   128,   145,   146,
      42,    64,    43,    83,    84,   165,   110,    39,    31,    42,
     143,    43,   106,   133,    40,    44,    31,    46,    83,    84,
      41,     1,    52,     2,    44,    45,    46,     3,    47,    42,
     134,    43,   135,   124,   136,   137,    94,    47,   101,   103,
      95,   102,    83,    84,    44,    76,    46,   139,    42,    66,
      43,   148,   149,   150,   151,   152,   153,    47,    67,    85,
      86,   130,   131,    44,    92,    46,    42,   159,    43,     1,
      69,     2,     1,    78,     2,     3,    47,    53,     3,     4,
      98,    44,   158,    46,   160,    79,   106,    99,   112,   113,
      12,    13,     5,   114,    47,    14,    15,    16,    12,    13,
      17,   112,   113,    14,    15,    16,   129,    18,    17,   112,
     113,   112,   113,    63,   144,    18,   162,    12,    13,   140,
     141,   100,    14,    15,    16,   125,   126,    17,   108,   115,
     116,   117,   118,   121,    18,    83,    84,   138,   124,   123,
     107,   142,   163,     5,   119,   120,   132,    83,    84,   115,
     116,   117,   118,    12,    13,     1,   154,     2,    14,    15,
      16,     3,    34,    17,   119,   120,   155,    83,    84,   156,
      18,    12,    13,    53,   164,   161,    14,    15,    16,    54,
      59,    17,     0,    55,    56,    57,    58,     0,    18
};

static const yytype_int16 yycheck[] =
{
       5,     7,    16,     5,    52,    22,   114,    71,    47,    20,
       5,     0,     7,     5,    19,     7,    19,    19,    27,    20,
      22,   129,    70,    32,    33,    20,    40,    22,    20,    21,
      22,    23,    46,    27,    37,    37,    31,    28,    33,    53,
      54,    33,    33,    60,    23,    25,    85,    86,   112,   113,
       5,    68,     7,    32,    33,   163,    70,    22,    60,     5,
     108,     7,    67,    27,    22,    20,    68,    22,    32,    33,
      22,     5,    22,     7,    20,    21,    22,    11,    33,     5,
      94,     7,    96,    23,    98,    99,    28,    33,    24,    23,
      32,    27,    32,    33,    20,    21,    22,   103,     5,    27,
       7,   115,   116,   117,   118,   119,   120,    33,    22,    34,
      35,    23,    24,    20,    21,    22,     5,   131,     7,     5,
      13,     7,     5,    20,     7,    11,    33,    22,    11,    12,
      28,    20,    21,    22,   140,    27,   141,    28,    18,    19,
       3,     4,    25,    23,    33,     8,     9,    10,     3,     4,
      13,    18,    19,     8,     9,    10,    23,    20,    13,    18,
      19,    18,    19,    26,    23,    20,    23,     3,     4,    23,
      24,    26,     8,     9,    10,    83,    84,    13,    22,    14,
      15,    16,    17,    23,    20,    32,    33,    20,    23,    23,
      26,    20,     6,    25,    29,    30,    27,    32,    33,    14,
      15,    16,    17,     3,     4,     5,    27,     7,     8,     9,
      10,    11,     7,    13,    29,    30,    27,    32,    33,    27,
      20,     3,     4,    22,    27,   141,     8,     9,    10,    28,
      19,    13,    -1,    32,    33,    34,    35,    -1,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    11,    12,    25,    37,    38,    39,    40,
      43,    46,     3,     4,     8,     9,    10,    13,    20,    44,
      45,    46,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    66,     0,    39,    43,    20,    25,    48,    22,
      22,    22,     5,     7,    20,    21,    22,    33,    58,    63,
      64,    65,    22,    22,    28,    32,    33,    34,    35,    45,
      49,    20,    47,    26,    50,    27,    27,    22,    49,    13,
      22,    31,    60,    61,    62,    63,    21,    63,    20,    27,
      63,    65,    27,    32,    33,    34,    35,    61,    21,    23,
      59,    63,    21,    63,    28,    32,    28,    33,    28,    28,
      26,    24,    27,    23,    41,    42,    46,    26,    22,    61,
      63,    62,    18,    19,    23,    14,    15,    16,    17,    29,
      30,    23,    23,    23,    23,    64,    64,    65,    65,    23,
      23,    24,    27,    27,    63,    63,    63,    63,    20,    43,
      23,    24,    20,    61,    23,    62,    62,    48,    63,    63,
      63,    63,    63,    63,    27,    27,    27,    48,    21,    63,
      43,    42,    23,     6,    27,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    40,    40,
      41,    41,    42,    43,    43,    44,    44,    45,    46,    46,
      46,    47,    47,    48,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    55,    55,    56,    57,    58,    58,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    62,    62,    62,    63,    63,    63,    64,    64,    64,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    66,
      66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     6,     5,     1,     1,
       3,     1,     2,     4,     3,     2,     1,     3,     1,     1,
       1,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     5,     7,     5,     7,     4,
       4,     2,     5,     5,     5,     2,     4,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     2,     1,     3,     3,     1,     3,     3,     1,
       3,     2,     1,     1,     1,     1,     3,     4,     3,     4,
       4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 3:
#line 21 "compiler.y" /* yacc.c:1646  */
    {
		printInicioArquivo();
		printAST((yyvsp[0]).ptr);
		printFinalMain();
	}
#line 1375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 54 "compiler.y" /* yacc.c:1646  */
    {
		//$$.ptr = criarNoAST(AST_BLOCO, $2.ptr, $3.ptr);
		(yyval).ptr = (yyvsp[-1]).ptr;
	}
#line 1384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 59 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[-1]).ptr;
	}
#line 1392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 71 "compiler.y" /* yacc.c:1646  */
    {
		insTabSim((yyvsp[-2]).tipo, (yyvsp[-1]).listaId);
	}
#line 1400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 78 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).tipo = T_INT;
	}
#line 1408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 82 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).tipo = T_STR;
	}
#line 1416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 86 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).tipo = T_FLT;
	}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 93 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).listaId = insLista(&(yyvsp[-2]), (yyvsp[0]).id);
	}
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 97 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).listaId = criarLista((yyvsp[0]).id);
	}
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 104 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[-1]).ptr;
	}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 111 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarNoAST(AST_LISTA, (yyvsp[-1]).ptr, (yyvsp[0]).ptr);
	}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 115 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarNoAST(AST_LISTA, (yyvsp[0]).ptr, NULL);
	}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 122 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[0]).ptr;
	}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 126 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[0]).ptr;
	}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 130 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[0]).ptr;
	}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 134 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[0]).ptr;
	}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 138 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = NULL;
	}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 142 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = NULL;
	}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 146 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = NULL;
	}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 158 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarNoIF((yyvsp[-2]).ptr, (yyvsp[0]).ptr, NULL);
	}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 162 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarNoIF((yyvsp[-4]).ptr, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
	}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 169 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarNoWhile((yyvsp[-2]).ptr, (yyvsp[0]).ptr);
	}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 173 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarNoDoWhile((yyvsp[-2]).ptr, (yyvsp[-5]).ptr);
	}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 180 "compiler.y" /* yacc.c:1646  */
    {
		(yyvsp[-3]).ptr = criarFolhaID(AST_VAR, (yyvsp[-3]).id);
		(yyvsp[-3]).tipo = consultaTipo((yyvsp[-3]).id);
		if ((yyvsp[-3]).tipo == T_INT && (yyvsp[-1]).tipo == T_FLT) {
			(yyval).ptr = criarNoAST(AST_ATRIB, (yyvsp[-3]).ptr, f2iAST((yyvsp[-1]).ptr));
			addError(ERR_1, linha);
		}
		else if ((yyvsp[-3]).tipo == T_FLT && (yyvsp[-1]).tipo == T_INT) {
			(yyval).ptr = criarNoAST(AST_ATRIB, (yyvsp[-3]).ptr, i2fAST((yyvsp[-1]).ptr));
			addError(ERR_1, linha);
		}
		else {
			(yyval).ptr = criarNoAST(AST_ATRIB, (yyvsp[-3]).ptr, (yyvsp[-1]).ptr);
			(yyval).tipo = (yyvsp[-3]).tipo;
		}
	}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 197 "compiler.y" /* yacc.c:1646  */
    {
		(yyvsp[-3]).ptr = criarFolhaID(AST_VAR, (yyvsp[-3]).id);
		(yyvsp[-3]).tipo = consultaTipo((yyvsp[-3]).id);
		if ((yyvsp[-3]).tipo != T_STR)
		{
			addError(ERR_4, linha);
			YYABORT;
		}
		(yyvsp[-1]).ptr = criarFolhaLiteral((yyvsp[-1]).text);
		(yyval).ptr = criarNoAST(AST_ATRIB, (yyvsp[-3]).ptr, (yyvsp[-1]).ptr);
	}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 209 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[-1]).ptr;
	}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 216 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarNoAST(AST_PRINT, (yyvsp[-2]).ptr, NULL);
	}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 220 "compiler.y" /* yacc.c:1646  */
    {
		(yyvsp[-2]).ptr = criarFolhaLiteral((yyvsp[-2]).text);
		(yyval).ptr = criarNoAST(AST_PRINT, (yyvsp[-2]).ptr, NULL);
	}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 248 "compiler.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipo == T_STR || (yyvsp[0]).tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ((yyvsp[-2]).tipo == T_INT && (yyvsp[0]).tipo == T_FLT) {
			(yyval).ptr = criarNoRel(AST_REL_LT, i2fAST((yyvsp[-2]).ptr), (yyvsp[0]).ptr);
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else if ((yyvsp[-2]).tipo == T_FLT && (yyvsp[0]).tipo == T_INT) {
			(yyval).ptr = criarNoRel(AST_REL_LT, (yyvsp[-2]).ptr, i2fAST((yyvsp[0]).ptr));
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			(yyval).ptr = criarNoRel(AST_REL_LT, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
			(yyval).tipo = (yyvsp[-2]).tipo;
		}
	}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 269 "compiler.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipo == T_STR || (yyvsp[0]).tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ((yyvsp[-2]).tipo == T_INT && (yyvsp[0]).tipo == T_FLT) {
			(yyval).ptr = criarNoRel(AST_REL_GT, i2fAST((yyvsp[-2]).ptr), (yyvsp[0]).ptr);
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else if ((yyvsp[-2]).tipo == T_FLT && (yyvsp[0]).tipo == T_INT) {
			(yyval).ptr = criarNoRel(AST_REL_GT, (yyvsp[-2]).ptr, i2fAST((yyvsp[0]).ptr));
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			(yyval).ptr = criarNoRel(AST_REL_GT, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
			(yyval).tipo = (yyvsp[-2]).tipo;
		}
	}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 290 "compiler.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipo == T_STR || (yyvsp[0]).tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ((yyvsp[-2]).tipo == T_INT && (yyvsp[0]).tipo == T_FLT) {
			(yyval).ptr = criarNoRel(AST_REL_LE, i2fAST((yyvsp[-2]).ptr), (yyvsp[0]).ptr);
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ((yyvsp[-2]).tipo == T_FLT && (yyvsp[0]).tipo == T_INT) {
			(yyval).ptr = criarNoRel(AST_REL_LE, (yyvsp[-2]).ptr, i2fAST((yyvsp[0]).ptr));
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			(yyval).ptr = criarNoRel(AST_REL_LE, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
			(yyval).tipo = (yyvsp[-2]).tipo;
		}
	}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 312 "compiler.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipo == T_STR || (yyvsp[0]).tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ((yyvsp[-2]).tipo == T_INT && (yyvsp[0]).tipo == T_FLT) {
			(yyval).ptr = criarNoRel(AST_REL_GE, i2fAST((yyvsp[-2]).ptr), (yyvsp[0]).ptr);
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ((yyvsp[-2]).tipo == T_FLT && (yyvsp[0]).tipo == T_INT) {
			(yyval).ptr = criarNoRel(AST_REL_GE, (yyvsp[-2]).ptr, i2fAST((yyvsp[0]).ptr));
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			(yyval).ptr = criarNoRel(AST_REL_GE, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
			(yyval).tipo = (yyvsp[-2]).tipo;
		}
	}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 334 "compiler.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipo == T_STR || (yyvsp[0]).tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ((yyvsp[-2]).tipo == T_INT && (yyvsp[0]).tipo == T_FLT) {
			(yyval).ptr = criarNoRel(AST_REL_EQ, i2fAST((yyvsp[-2]).ptr), (yyvsp[0]).ptr);
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ((yyvsp[-2]).tipo == T_FLT && (yyvsp[0]).tipo == T_INT) {
			(yyval).ptr = criarNoRel(AST_REL_EQ, (yyvsp[-2]).ptr, i2fAST((yyvsp[0]).ptr));
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			(yyval).ptr = criarNoRel(AST_REL_EQ, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
			(yyval).tipo = (yyvsp[-2]).tipo;
		}
	}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 356 "compiler.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipo == T_STR || (yyvsp[0]).tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ((yyvsp[-2]).tipo == T_INT && (yyvsp[0]).tipo == T_FLT) {
			(yyval).ptr = criarNoRel(AST_REL_NE, i2fAST((yyvsp[-2]).ptr), (yyvsp[0]).ptr);
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ((yyvsp[-2]).tipo == T_FLT && (yyvsp[0]).tipo == T_INT) {
			(yyval).ptr = criarNoRel(AST_REL_NE, (yyvsp[-2]).ptr, i2fAST((yyvsp[0]).ptr));
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			(yyval).ptr = criarNoRel(AST_REL_NE, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
			(yyval).tipo = (yyvsp[-2]).tipo;
		}
	}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 381 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarNoAST(AST_LOG_AND, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
	}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 385 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarNoAST(AST_LOG_OR, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
	}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 389 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[0]).ptr;
	}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 396 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[-1]).ptr;
	}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 400 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarNoAST(AST_LOG_NOT, (yyvsp[0]).ptr, NULL);
	}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 404 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[0]).ptr;
	}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 411 "compiler.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipo == T_STR || (yyvsp[0]).tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ((yyvsp[-2]).tipo == T_INT && (yyvsp[0]).tipo == T_FLT) {
			(yyval).ptr = criarNoArit(AST_ARIT_ADD, i2fAST((yyvsp[-2]).ptr), (yyvsp[0]).ptr);
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ((yyvsp[-2]).tipo == T_FLT && (yyvsp[0]).tipo == T_INT) {
			(yyval).ptr = criarNoArit(AST_ARIT_ADD, (yyvsp[-2]).ptr, i2fAST((yyvsp[0]).ptr));
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			(yyval).ptr = criarNoArit(AST_ARIT_ADD, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
			(yyval).tipo = (yyvsp[-2]).tipo;
		}
	}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 433 "compiler.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipo == T_STR || (yyvsp[0]).tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ((yyvsp[-2]).tipo == T_INT && (yyvsp[0]).tipo == T_FLT) {
			(yyval).ptr = criarNoArit(AST_ARIT_SUB, i2fAST((yyvsp[-2]).ptr), (yyvsp[0]).ptr);
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ((yyvsp[-2]).tipo == T_FLT && (yyvsp[0]).tipo == T_INT) {
			(yyval).ptr = criarNoArit(AST_ARIT_SUB, (yyvsp[-2]).ptr, i2fAST((yyvsp[0]).ptr));
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			(yyval).ptr = criarNoArit(AST_ARIT_SUB, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
			(yyval).tipo = (yyvsp[-2]).tipo;
		}
	}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 455 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[0]).ptr;
	}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 462 "compiler.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipo == T_STR || (yyvsp[0]).tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ((yyvsp[-2]).tipo == T_INT && (yyvsp[0]).tipo == T_FLT) {
			(yyval).ptr = criarNoArit(AST_ARIT_MUL, i2fAST((yyvsp[-2]).ptr), (yyvsp[0]).ptr);
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else if ((yyvsp[-2]).tipo == T_FLT && (yyvsp[0]).tipo == T_INT) {
			(yyval).ptr = criarNoArit(AST_ARIT_MUL, (yyvsp[-2]).ptr, i2fAST((yyvsp[0]).ptr));
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			(yyval).ptr = criarNoArit(AST_ARIT_MUL, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
			(yyval).tipo = (yyvsp[-2]).tipo;
		}
	}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 483 "compiler.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipo == T_STR || (yyvsp[0]).tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ((yyvsp[-2]).tipo == T_INT && (yyvsp[0]).tipo == T_FLT) {
			(yyval).ptr = criarNoArit(AST_ARIT_DIV, i2fAST((yyvsp[-2]).ptr), (yyvsp[0]).ptr);
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else if ((yyvsp[-2]).tipo == T_FLT && (yyvsp[0]).tipo == T_INT) {
			(yyval).ptr = criarNoArit(AST_ARIT_DIV, (yyvsp[-2]).ptr, i2fAST((yyvsp[0]).ptr));
			(yyval).tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			(yyval).ptr = criarNoArit(AST_ARIT_DIV, (yyvsp[-2]).ptr, (yyvsp[0]).ptr);
			(yyval).tipo = (yyvsp[-2]).tipo;
		}
	}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 504 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = (yyvsp[0]).ptr;
		(yyval).tipo = (yyvsp[0]).tipo;
	}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 512 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).tipo = (yyvsp[-1]).tipo;
		(yyval).ptr = (yyvsp[-1]).ptr;
	}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 517 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).tipo = (yyvsp[0]).tipo;
		(yyval).ptr = criarNoAST(AST_NEG, (yyvsp[0]).ptr, NULL);
	}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 522 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarFolhaID(AST_FUNCAO, (yyvsp[0]).id);
	}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 526 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).tipo = T_INT;
		(yyval).ptr = criarFolhaInt((yyvsp[0]).ival);
	}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 531 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).tipo = T_FLT;
		(yyval).ptr = criarFolhaFloat((yyvsp[0]).fval);
	}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 536 "compiler.y" /* yacc.c:1646  */
    {
		(yyval).ptr = criarFolhaID(AST_VAR, (yyvsp[0]).id);
		(yyval).tipo = consultaTipo((yyvsp[0]).id);
		if ((yyval).tipo == T_NEX)
		{
			addError(ERR_3, linha);
			YYABORT;
		}
	}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 549 "compiler.y" /* yacc.c:1646  */
    {
		(yyvsp[-2]).ptr = criarFolhaID(AST_VAR, (yyvsp[-2]).id);
		(yyval).tipo = consultaTipo((yyvsp[-2]).id);
		if ((yyval).tipo == T_FLT)
			(yyval).ptr = criarNoAuto(AST_AUTO_ADD, (yyvsp[-2]).ptr, i2fAST(criarFolhaInt(1)));
		else
			(yyval).ptr = criarNoAuto(AST_AUTO_ADD, (yyvsp[-2]).ptr, criarFolhaInt(1));
	}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 558 "compiler.y" /* yacc.c:1646  */
    {
		(yyvsp[-3]).ptr = criarFolhaID(AST_VAR, (yyvsp[-3]).id);
		(yyval).tipo = consultaTipo((yyvsp[-3]).id);
		if ((yyval).tipo == T_FLT)
			if ((yyvsp[0]).tipo == T_INT)
				(yyval).ptr = criarNoAuto(AST_AUTO_ADD, (yyvsp[-3]).ptr, i2fAST((yyvsp[0]).ptr));
			else
				(yyval).ptr = criarNoAuto(AST_AUTO_ADD, (yyvsp[-3]).ptr, (yyvsp[0]).ptr);
		else
			if ((yyvsp[0]).tipo == T_INT)
				(yyval).ptr = criarNoAuto(AST_AUTO_ADD, (yyvsp[-3]).ptr, (yyvsp[0]).ptr);
			else
				(yyval).ptr = criarNoAuto(AST_AUTO_ADD, (yyvsp[-3]).ptr, f2iAST((yyvsp[0]).ptr));
	}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 573 "compiler.y" /* yacc.c:1646  */
    {
		(yyvsp[-2]).ptr = criarFolhaID(AST_VAR, (yyvsp[-2]).id);
		(yyval).tipo = consultaTipo((yyvsp[-2]).id);
		if ((yyval).tipo == T_FLT)
			(yyval).ptr = criarNoAuto(AST_AUTO_SUB, (yyvsp[-2]).ptr, i2fAST(criarFolhaInt(1)));
		else
			(yyval).ptr = criarNoAuto(AST_AUTO_SUB, (yyvsp[-2]).ptr, criarFolhaInt(1));
	}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 582 "compiler.y" /* yacc.c:1646  */
    {
		(yyvsp[-3]).ptr = criarFolhaID(AST_VAR, (yyvsp[-3]).id);
		(yyval).tipo = consultaTipo((yyvsp[-3]).id);
		if ((yyval).tipo == T_FLT)
			if ((yyvsp[0]).tipo == T_INT)
				(yyval).ptr = criarNoAuto(AST_AUTO_SUB, (yyvsp[-3]).ptr, i2fAST((yyvsp[0]).ptr));
			else
				(yyval).ptr = criarNoAuto(AST_AUTO_SUB, (yyvsp[-3]).ptr, (yyvsp[0]).ptr);
		else
			if ((yyvsp[0]).tipo == T_INT)
				(yyval).ptr = criarNoAuto(AST_AUTO_SUB, (yyvsp[-3]).ptr, (yyvsp[0]).ptr);
			else
				(yyval).ptr = criarNoAuto(AST_AUTO_SUB, (yyvsp[-3]).ptr, f2iAST((yyvsp[0]).ptr));
	}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 597 "compiler.y" /* yacc.c:1646  */
    {
		(yyvsp[-3]).ptr = criarFolhaID(AST_VAR, (yyvsp[-3]).id);
		(yyval).tipo = consultaTipo((yyvsp[-3]).id);
		if ((yyval).tipo == T_FLT)
			if ((yyvsp[0]).tipo == T_INT)
				(yyval).ptr = criarNoAuto(AST_AUTO_MUL, (yyvsp[-3]).ptr, i2fAST((yyvsp[0]).ptr));
			else
				(yyval).ptr = criarNoAuto(AST_AUTO_MUL, (yyvsp[-3]).ptr, (yyvsp[0]).ptr);
		else
			if ((yyvsp[0]).tipo == T_INT)
				(yyval).ptr = criarNoAuto(AST_AUTO_MUL, (yyvsp[-3]).ptr, (yyvsp[0]).ptr);
			else
				(yyval).ptr = criarNoAuto(AST_AUTO_MUL, (yyvsp[-3]).ptr, f2iAST((yyvsp[0]).ptr));
	}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 612 "compiler.y" /* yacc.c:1646  */
    {
		(yyvsp[-3]).ptr = criarFolhaID(AST_VAR, (yyvsp[-3]).id);
		(yyval).tipo = consultaTipo((yyvsp[-3]).id);
		if ((yyval).tipo == T_FLT)
			if ((yyvsp[0]).tipo == T_INT)
				(yyval).ptr = criarNoAuto(AST_AUTO_DIV, (yyvsp[-3]).ptr, i2fAST((yyvsp[0]).ptr));
			else
				(yyval).ptr = criarNoAuto(AST_AUTO_DIV, (yyvsp[-3]).ptr, (yyvsp[0]).ptr);
		else
			if ((yyvsp[0]).tipo == T_INT)
				(yyval).ptr = criarNoAuto(AST_AUTO_DIV, (yyvsp[-3]).ptr, (yyvsp[0]).ptr);
			else
				(yyval).ptr = criarNoAuto(AST_AUTO_DIV, (yyvsp[-3]).ptr, f2iAST((yyvsp[0]).ptr));
	}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2099 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 628 "compiler.y" /* yacc.c:1906  */


#include "lex.yy.c"

int yyerror (char *str)
{
	printf("Linha %d: %s - antes %s\n", linha, str, yytext);
}

int yywrap()
{
	return 1;
}
