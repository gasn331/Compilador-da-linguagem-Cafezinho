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
#line 1 "./fonte/cafezinho.y" /* yacc.c:339  */

      #include "type.h"
	#include <stdio.h>
      #include <string.h>
      #include <ctype.h>
      static char* enumStrings[] = {"programa","DeclFuncVar1","DeclFuncVar2","DeclFuncVar3","DeclFunc","ListaParametrosCont3",
"ListaParametrosCont4","Bloco1","ListaDeclVar2","ListaDeclVar3","Tipo","ListaComando2","Retorne","Leia","Escreva",
"EscrevaString","Novalinha","Se","SeSenao","Enquanto","Atribuir","SeTernario","Or","And","IgualIgual","Diferente","Menor",
"Maior","MenorIg","MaiorIg","Mais","Menos","Vezes","Divisao","Resto","Negativo","Negacao","IdentificadorBEB","Identificador",
"IdentificadorLista","Carconst","Intconst","Virgula","Main"};
      extern int yylineno;
      node *mknode(Operator type, int line, node *first, node *second, node *third, char *token);
      void printtree(node *tree);
      char *convert2Str(int x);
      void createSymbolTree(node *tree);
      char *newName(char *token);
      void createScopeTree(node *tree, char escopoAtual[100], symbolTree *noAtual);
      void insertChild(symbolTree *tree, symbolTree *newNode);
      symbolTable *initTable(char *token, int line, char *type, node *astPointer);
      void insertSymbol(symbolTable *table, char *token, int line, char *type, node *astPointer);
      int searchSymbol(symbolTable *table, char *token);
      //symbolTree operations
      symbolTree *createScope(char *scope);
      symbolTree *searchScope(symbolTree *tree, char *scope);
      void insertOnScope(symbolTree *tree,char *scope,char *token, int line, char *type, node *astPointer);
      symbolTree *scopeTree;
      node *tree;
      char escopo[100] = "global";
	yydebug=1;

#line 97 "cafezinho.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "cafezinho.tab.h".  */
#ifndef YY_YY_CAFEZINHO_TAB_H_INCLUDED
# define YY_YY_CAFEZINHO_TAB_H_INCLUDED
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
    PROGRAMA = 258,
    DECLARACAO_INT = 259,
    DECLARACAO_CAR = 260,
    RETORNE = 261,
    LEIA = 262,
    ESCREVA = 263,
    NOVALINHA = 264,
    SE = 265,
    ENTAO = 266,
    SENAO = 267,
    ENQUANTO = 268,
    EXECUTE = 269,
    MAIS = 270,
    MENOS = 271,
    VEZES = 272,
    DIV = 273,
    RESTO = 274,
    OUEXPR = 275,
    EEXPR = 276,
    ANULEXPR = 277,
    DBIGUAL = 278,
    DIFF = 279,
    MAIORQ = 280,
    MENORQ = 281,
    MAIORIGQ = 282,
    MENORIGQ = 283,
    INTERROG = 284,
    DOISPONT = 285,
    EPAREN = 286,
    DPAREN = 287,
    DBRACK = 288,
    EBRACK = 289,
    EBRACE = 290,
    DBRACE = 291,
    SEMI = 292,
    VIRGULA = 293,
    ATRIB = 294,
    ID = 295,
    INTCONST = 296,
    CARCONST = 297,
    STRING = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "./fonte/cafezinho.y" /* yacc.c:355  */

        int lineno;
        char *string;
        node* node_type;

#line 187 "cafezinho.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CAFEZINHO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "cafezinho.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    55,    56,    57,    58,    62,    65,    66,
      67,    70,    73,    74,    77,    78,    79,    80,    83,    84,
      87,    88,    89,    92,    93,    96,    97,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   114,   116,
     117,   120,   121,   125,   126,   129,   130,   133,   134,   135,
     138,   139,   140,   141,   142,   145,   146,   147,   150,   151,
     152,   153,   156,   157,   158,   161,   162,   165,   166,   167,
     168,   169,   170,   171,   174,   175
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAMA", "DECLARACAO_INT",
  "DECLARACAO_CAR", "RETORNE", "LEIA", "ESCREVA", "NOVALINHA", "SE",
  "ENTAO", "SENAO", "ENQUANTO", "EXECUTE", "MAIS", "MENOS", "VEZES", "DIV",
  "RESTO", "OUEXPR", "EEXPR", "ANULEXPR", "DBIGUAL", "DIFF", "MAIORQ",
  "MENORQ", "MAIORIGQ", "MENORIGQ", "INTERROG", "DOISPONT", "EPAREN",
  "DPAREN", "DBRACK", "EBRACK", "EBRACE", "DBRACE", "SEMI", "VIRGULA",
  "ATRIB", "ID", "INTCONST", "CARCONST", "STRING", "$accept", "programa",
  "DeclFuncVar", "DeclProg", "DeclVar", "DeclFunc", "ListaParametros",
  "ListaParametrosCont", "Bloco", "ListaDeclVar", "Tipo", "ListaComando",
  "Comando", "Expr", "AssignExpr", "CondExpr", "OrExpr", "AndExpr",
  "EqExpr", "DesigExpr", "AddExpr", "MulExpr", "UnExpr", "LValueExpr",
  "PrimExpr", "ListExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -139

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-139)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      42,  -139,  -139,    10,    28,   -23,  -139,   -12,  -139,    47,
      42,  -139,    42,    -4,    12,    22,    42,    35,    34,    55,
    -139,    39,    76,    20,    42,  -139,    51,    71,   102,    25,
      82,    96,   -15,   -15,    51,  -139,  -139,    29,  -139,  -139,
    -139,    95,    88,    97,  -139,  -139,    -1,   128,    41,    80,
      84,   119,  -139,   117,  -139,    46,   -12,    52,   120,   116,
    -139,  -139,   122,   126,   124,   125,   127,  -139,    51,    51,
       1,  -139,  -139,   131,    -2,    51,  -139,  -139,  -139,   110,
      51,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,    51,   129,   130,  -139,   132,    42,   134,
     133,  -139,    51,  -139,  -139,  -139,   136,   137,    51,  -139,
    -139,  -139,   -14,   139,   128,   143,    41,    80,    80,    84,
      84,    84,    84,   119,   119,  -139,  -139,  -139,  -139,   141,
      42,   138,  -139,    42,   120,   142,   166,   164,   146,  -139,
      51,   144,   110,   120,  -139,    42,  -139,  -139,  -139,    88,
      88,  -139,  -139,  -139,   145,  -139,   168,  -139,    42,    88,
    -139,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    23,    24,     0,     0,     0,     1,     0,     2,    10,
      20,     7,    12,     0,     0,     0,     6,     0,     0,     0,
      13,     0,     0,    10,     6,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    27,    70,    72,    71,
      37,     0,    25,     0,    38,    39,    41,    44,    46,    49,
      54,    57,    61,     0,    64,    10,     0,    14,    10,     0,
       8,     3,     0,    66,     0,     0,     0,    33,     0,     0,
      70,    62,    63,     0,     0,     0,    18,    26,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,    29,     0,    30,    32,    31,     0,     0,     0,    73,
      68,    74,     0,     0,    43,     0,    45,    47,    48,    51,
      50,    53,    52,    55,    56,    58,    59,    60,    40,     0,
      20,    15,    16,     6,    10,     0,     0,     0,     0,    67,
       0,    69,     0,    10,    21,     0,     4,     9,    65,     0,
       0,    69,    75,    42,     0,    17,    34,    36,    20,     0,
      22,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,   -11,  -139,   -22,  -139,  -139,   -90,    -3,  -124,
     -10,   147,  -138,   -19,   -71,    43,  -139,   105,   100,    57,
      30,    14,    63,   159,   114,  -139
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     8,    15,    16,    19,    20,    40,    17,
       5,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    60,    21,   111,    11,    25,   144,    62,   132,    66,
       6,   156,   157,    61,    32,    73,    34,     9,   139,    79,
      33,   161,   128,    10,   140,    70,    38,    39,    80,    34,
     110,     7,    74,    95,   160,   108,    99,    22,    37,    38,
      39,    26,    27,    28,    29,    30,     1,     2,    31,   106,
     107,    32,    23,    96,    59,   155,   113,    33,    14,    24,
      74,   115,    67,    75,    82,    83,    34,    32,   -66,   152,
      10,    35,    36,    33,    55,    37,    38,    39,    12,    57,
      94,    13,    34,   135,    14,    14,    97,    56,    21,   138,
      98,    37,    38,    39,    26,    27,    28,    29,    30,    88,
      89,    31,   123,   124,    32,    84,    85,    86,    87,    58,
      33,    63,   147,    68,   119,   120,   121,   122,    32,    34,
      18,   154,   146,    10,    33,    36,    32,    69,    37,    38,
      39,    76,    33,    34,    78,    21,    90,    91,    92,   117,
     118,    34,    37,    38,    39,    65,    71,    72,    18,    81,
      70,    38,    39,   125,   126,   127,    93,   100,    14,   101,
     102,   103,   104,   109,   105,   131,   134,   130,   136,   137,
     129,   133,   141,   142,   143,   148,   145,   149,   150,   151,
     159,   116,   158,   -65,   114,   153,    64,     0,     0,    77
};

static const yytype_int16 yycheck[] =
{
      10,    23,    12,    74,     7,    16,   130,    26,    98,    28,
       0,   149,   150,    24,    16,    34,    31,    40,    32,    20,
      22,   159,    93,    35,    38,    40,    41,    42,    29,    31,
      32,     3,    31,    55,   158,    34,    58,    41,    40,    41,
      42,     6,     7,     8,     9,    10,     4,     5,    13,    68,
      69,    16,    40,    56,    34,   145,    75,    22,    38,    37,
      31,    80,    37,    34,    23,    24,    31,    16,    39,   140,
      35,    36,    37,    22,    40,    40,    41,    42,    31,    40,
      34,    34,    31,   102,    38,    38,    34,    32,    98,   108,
      38,    40,    41,    42,     6,     7,     8,     9,    10,    15,
      16,    13,    88,    89,    16,    25,    26,    27,    28,    33,
      22,    40,   134,    31,    84,    85,    86,    87,    16,    31,
     130,   143,   133,    35,    22,    37,    16,    31,    40,    41,
      42,    36,    22,    31,    37,   145,    17,    18,    19,    82,
      83,    31,    40,    41,    42,    43,    32,    33,   158,    21,
      40,    41,    42,    90,    91,    92,    39,    41,    38,    37,
      34,    37,    37,    32,    37,    33,    33,    37,    32,    32,
      41,    37,    33,    30,    33,    33,    38,    11,    14,    33,
      12,    81,    37,    39,    79,   142,    27,    -1,    -1,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    45,    46,    54,     0,     3,    47,    40,
      35,    52,    31,    34,    38,    48,    49,    53,    54,    50,
      51,    54,    41,    40,    37,    46,     6,     7,     8,     9,
      10,    13,    16,    22,    31,    36,    37,    40,    41,    42,
      52,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    40,    32,    40,    33,    34,
      48,    46,    57,    40,    67,    43,    57,    37,    31,    31,
      40,    68,    68,    57,    31,    34,    36,    55,    37,    20,
      29,    21,    23,    24,    25,    26,    27,    28,    15,    16,
      17,    18,    19,    39,    34,    48,    52,    34,    38,    48,
      41,    37,    34,    37,    37,    37,    57,    57,    34,    32,
      32,    58,    69,    57,    61,    57,    62,    63,    63,    64,
      64,    64,    64,    65,    65,    66,    66,    66,    58,    41,
      37,    33,    51,    37,    33,    57,    32,    32,    57,    32,
      38,    33,    30,    33,    53,    38,    46,    48,    33,    11,
      14,    33,    58,    59,    48,    51,    56,    56,    37,    12,
      53,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    46,    47,    48,    48,
      48,    49,    50,    50,    51,    51,    51,    51,    52,    52,
      53,    53,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    63,    63,    63,    64,    64,    64,    65,    65,
      65,    65,    66,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     5,     8,     4,     0,     2,     3,     6,
       0,     4,     0,     1,     2,     4,     4,     6,     4,     3,
       0,     5,     8,     1,     1,     1,     2,     1,     2,     3,
       3,     3,     3,     2,     6,     8,     6,     1,     1,     1,
       3,     1,     5,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     1,     4,     1,     4,     3,     4,
       1,     1,     1,     3,     1,     3
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
        case 2:
#line 52 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {tree = mknode(programa,yylineno,(yyvsp[-1].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1396 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(DeclFuncVar1,yylineno,(yyvsp[-4].node_type),(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL);}
#line 1402 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(DeclFuncVar2,yylineno,(yyvsp[-7].node_type),(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL);}
#line 1408 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(DeclFuncVar3,yylineno,(yyvsp[-3].node_type),(yyvsp[-1].node_type),(yyvsp[0].node_type),NULL);}
#line 1414 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = NULL;}
#line 1420 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 62 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Main,yylineno,(yyvsp[0].node_type),NULL,NULL,NULL);}
#line 1426 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 65 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1432 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 66 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1438 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 67 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = NULL;}
#line 1444 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 70 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(DeclFunc,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,newName(yyval.string));}
#line 1450 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 73 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = NULL;}
#line 1456 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 74 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1462 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 77 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[-1].node_type);}
#line 1468 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 78 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[-3].node_type);}
#line 1474 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 79 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(ListaParametrosCont3,yylineno,(yyvsp[-3].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1480 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 80 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(ListaParametrosCont4,yylineno,(yyvsp[-5].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1486 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 83 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Bloco1,yylineno,(yyvsp[-2].node_type),(yyvsp[-1].node_type),NULL,NULL);}
#line 1492 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 84 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[-1].node_type);}
#line 1498 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 87 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = NULL;}
#line 1504 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 88 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(ListaDeclVar2,yylineno,(yyvsp[-4].node_type),(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL);}
#line 1510 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 89 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(ListaDeclVar3,yylineno,(yyvsp[-7].node_type),(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL);}
#line 1516 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 92 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Tipo,yylineno,NULL,NULL,NULL,"int");}
#line 1522 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 93 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Tipo,yylineno,NULL,NULL,NULL,"car");}
#line 1528 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 96 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1534 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 97 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(ListaComando2,yylineno,(yyvsp[-1].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1540 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 101 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = NULL;}
#line 1546 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 102 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[-1].node_type);}
#line 1552 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 103 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Retorne,yylineno,(yyvsp[-1].node_type),NULL,NULL,NULL);}
#line 1558 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 104 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Leia,yylineno,(yyvsp[-1].node_type),NULL,NULL,NULL);}
#line 1564 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 105 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Escreva,yylineno,(yyvsp[-1].node_type),NULL,NULL,NULL);}
#line 1570 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 106 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(EscrevaString,yylineno,NULL,NULL,NULL,NULL);}
#line 1576 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 107 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Novalinha,yylineno,NULL,NULL,NULL,NULL);}
#line 1582 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 108 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Se,yylineno,(yyvsp[-3].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1588 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 109 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(SeSenao,yylineno,(yyvsp[-5].node_type),(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL);}
#line 1594 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 110 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Enquanto,yylineno,(yyvsp[-3].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1600 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 111 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1606 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 114 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1612 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 116 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1618 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 117 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Atribuir,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1624 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 120 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1630 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 121 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(SeTernario,yylineno,(yyvsp[-4].node_type),(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL);}
#line 1636 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 125 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Or,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1642 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 126 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1648 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 129 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(And,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1654 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 130 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1660 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 133 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(IgualIgual,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1666 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 134 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Diferente,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1672 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 135 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1678 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 138 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Menor,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1684 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 139 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Maior,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1690 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 140 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(MenorIg,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1696 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 141 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(MaiorIg,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1702 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 142 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1708 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 145 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Mais,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1714 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 146 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Menos,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1720 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 147 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1726 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 150 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Vezes,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1732 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 151 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Divisao,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1738 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 152 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Resto,yylineno,(yyvsp[-2].node_type),(yyvsp[0].node_type),NULL,NULL);}
#line 1744 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 153 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1750 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 156 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Negativo,yylineno,(yyvsp[0].node_type),NULL,NULL,NULL);}
#line 1756 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 157 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Negacao,yylineno,(yyvsp[0].node_type),NULL,NULL,NULL);}
#line 1762 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 158 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1768 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 161 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(IdentificadorBEB,yylineno,(yyvsp[-1].node_type),NULL,NULL,newName(yyval.string));}
#line 1774 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 162 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Identificador,yylineno,NULL,NULL,NULL,newName(yyval.string));}
#line 1780 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 165 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(IdentificadorLista,yylineno,(yyvsp[-1].node_type),NULL,NULL,newName(yyval.string));}
#line 1786 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 166 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Identificador,yylineno,NULL,NULL,NULL,newName(yyval.string));}
#line 1792 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 167 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(IdentificadorBEB,yylineno,(yyvsp[-1].node_type),NULL,NULL,newName(yyval.string));}
#line 1798 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 168 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Identificador,yylineno,NULL,NULL,NULL,newName(yyval.string));}
#line 1804 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 169 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Carconst,yylineno,NULL,NULL,NULL,newName(yyval.string));}
#line 1810 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 170 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Intconst,yylineno,NULL,NULL,NULL,convert2Str(yyval.string));}
#line 1816 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 171 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[-1].node_type);}
#line 1822 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 174 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = (yyvsp[0].node_type);}
#line 1828 "cafezinho.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 175 "./fonte/cafezinho.y" /* yacc.c:1646  */
    {(yyval.node_type) = mknode(Virgula, yylineno,(yyvsp[-2].node_type), (yyvsp[0].node_type), NULL, NULL);}
#line 1834 "cafezinho.tab.c" /* yacc.c:1646  */
    break;


#line 1838 "cafezinho.tab.c" /* yacc.c:1646  */
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
#line 177 "./fonte/cafezinho.y" /* yacc.c:1906  */


yywrap(){
	return 1;
}

main(){
        #ifdef YYDEBUG
                yydebug = 1;
        #endif
	yyparse();
      //printtree(tree);
      scopeTree = createScope("programa");
      createScopeTree(tree, "programa", scopeTree);
      printScopeTree(scopeTree);       
}

node *mknode(Operator type, int line, node *first, node *second, node *third, char *token){
       // printf("MAKE NEW NODE");
        //printf("TRYING TO SAVE: %s %d\n", enumStrings[(int)type],line);
        node *newnode = (node *)malloc(sizeof(node));
        if(newnode == NULL) return NULL;
        newnode->type = type;
        newnode->line = line;
        newnode->first = first;
        newnode->second = second;
        newnode->third = third;
        //printf("TRYING TO SAVE: %s %d\n", enumStrings[(int)type],line);
        //if(!token) printf("TOKEN NULL\n");
        if(token != NULL){
               newnode->token = (char *)malloc(sizeof(char)*(strlen(token)+1));
               strcpy(newnode->token,token); 
        }
        else newnode->token = NULL;
        //printf("WILL RETURN NOW\n");
        return newnode;
}
void printtree(node *tree) {
        //printf("PRINTING TREE\n");
        if(tree == NULL) return;
        //switch 
        printf("(");
        switch(tree->type){
            case Main:
                  printf("PROGRAMA ");
                  break;
          case programa:
                printf("programa %s", tree->token);
                break;
          case DeclFuncVar1:
                printf("DeclFuncVar1 %s", tree->token);
                break;
          case DeclFuncVar2:
                printf("DeclFuncVar2 %s", tree->token);
                break;
          case DeclFuncVar3:
                printf("DeclFuncVar3 %s", tree->token);
                break;
          case DeclFunc:
                printf("ListaParametrosCont3 %s", tree->token);
                break;
          case ListaParametrosCont4:
                printf("ListaParametrosCont4 %s", tree->token);
                break;
          case Bloco1:
                printf("Bloco1 %s", tree->token);
                break;
          case ListaDeclVar2:
                printf("ListaDeclVar2 %s", tree->token);
                break;
          case ListaDeclVar3:
                printf("ListaDeclVar3 %s", tree->token);
                break;
          case Tipo:
                printf("Tipo %s ", tree->token);
                break;
          case ListaComando2:
                printf("ListaComando2 ");
                printf("DeclFunc %s", tree->token);
                break;
          case ListaParametrosCont3:
                break;
          case Retorne:
                printf("Retorne ");
                break;
          case Leia:
                printf("Leia ");
                break;
          case Escreva:
                printf("Escreva ");
                break;
          case EscrevaString:
                printf("EscrevaString %s ", tree->token);
                break;
          case Novalinha:
                printf("Novalinha ");
                break;
          case Se:
                printf("Se ");
                break;
          case SeSenao:
                printf("SeSenao ");
                break;
          case Enquanto:
                printf("Enquanto ");
                break;
          case Atribuir:
                printf("= ");
                break;
          case SeTernario:
                printf("SeTernario ");
                break;
          case Or:
                printf("OU ");
                break;
          case And:
                printf("E ");
                break;
          case IgualIgual:
                printf("== ");
                break;
          case Diferente:
                printf("!= ");
                break;
          case Menor:
                printf("< ");
                break;
          case Maior:
                printf("> ");
                break;
          case MenorIg:
                printf("<= ");
                break;
          case MaiorIg:
                printf(">= ");
                break;
          case Mais:
                printf("+ ");
                break;
          case Menos:
                printf("- ");
                break;
          case Vezes:
                printf("* ");
                break;
          case Divisao:
                printf("/ ");
                break;
          case Resto:
                printf("% ");
                break;
          case Negativo:
                printf("- Un ");
                break;
          case Negacao:
                printf("! ");
                break;
          case IdentificadorBEB:
                printf("Identificador[] %s", tree->token);
                break;
          case Identificador:
                printf("Identificador %s", tree->token);
                break;
          case IdentificadorLista:
                printf("Identificador() %s", tree->token);
                break;
          case Carconst:
                printf("Carconst %s ", tree->token);
                break;
          case Intconst:
                printf("Intconst %s ", tree->token);
                break;
          case Virgula:
                printf(", ");
                break;
        }
        //printf(" - Line: %d", tree->line);
        
        //
        printtree(tree->first);
        printtree(tree->second);
        printtree(tree->third);
        printf(")");
 }

void printScopeTree(symbolTree *tree){
      if(tree == NULL){
            printf("ERROR: SymbolTree NULL\n");
            return;
      }
      printf("ESCOPO %s NumChild %d;", tree->scope, tree->nChild);
      if(!tree->nChild) return;
      int i;
      printf("(");
      for(i = 0; i < tree->nChild; i++) printScopeTree(tree->childs[i]);
      printf(")");
}

void insertChild(symbolTree *tree, symbolTree *newNode){
      if(tree == NULL) return;
      printf("got here %s\n", newNode->scope);
      //if(tree->childs == NULL) tree->childs = (symbolTree **)malloc(sizeof(symbolTree *));
      //tree->childs[tree->nChild] = (symbolTree *)malloc(sizeof(symbolTree));
      tree->childs[tree->nChild] = newNode;
      tree->nChild++;
      printf("%s %d\n",tree->childs[tree->nChild-1]->scope,tree->childs[tree->nChild-1]->nChild);
      return; 
}
void createScopeTree(node *tree, char escopoAtual[100], symbolTree *noAtual) {
        //printf("Creating Tree....\n");
        symbolTree *nodeAux, *newNode;
        if(tree == NULL){
            //printf("ERROR: NULL AST\n");
            return;
        }
        //switch operator
        switch(tree->type){
            
            case programa:
                  printf("Atualizando escopo para programa\n");
                  escopoAtual = "programa"; 
                  break;
            case DeclFunc:
                  nodeAux = searchScope(scopeTree,tree->token);
                  if(nodeAux == NULL){
                        printf("Criando escopo %s como subescopo de %s\n", tree->token,escopoAtual);
                        //newNode = searchScope(scopeTree,escopoAtual);
                        newNode = createScope(tree->token);
                        if(newNode != NULL) insertChild(noAtual,newNode);
                        else printf("newNode NULL\n");
                  }
                  escopoAtual=tree->token;
                  noAtual = newNode;
                  printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case Main:
                  nodeAux = searchScope(scopeTree,"PROGRAMA");
                  if(nodeAux == NULL){
                        printf("Criando escopo PROGRAMA como subescopo de programa\n");
                        noAtual = searchScope(scopeTree,"programa");
                        newNode = createScope("PROGRAMA");
                        if(newNode != NULL) insertChild(noAtual,newNode);
                  }
                  escopoAtual="PROGRAMA";
                  noAtual = newNode;
                  printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case Se:
                  printf("Criando escopo Se como subescopo de %s\n",escopoAtual);
                  newNode = createScope("Se");
                  if(newNode != NULL) insertChild(noAtual,newNode);
                  escopoAtual="Se";
                  noAtual = newNode;
                  printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case SeSenao:
                  printf("Criando escopo SeSenao como subescopo de %s\n",escopoAtual);
                  newNode = createScope("SeSenao");
                  if(newNode != NULL) insertChild(noAtual,newNode);
                  escopoAtual="SeSenao";
                  noAtual = newNode;
                  printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case Enquanto:
                  printf("Criando escopo Enquanto como subescopo de %s\n",escopoAtual);
                  newNode = createScope("Enquanto");
                  if(newNode != NULL) insertChild(noAtual,newNode);
                  noAtual = newNode;
                  escopoAtual="Enquanto";
                  printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
        }
          
        createScopeTree(tree->first,escopoAtual,noAtual);
        createScopeTree(tree->second,escopoAtual,noAtual);
        createScopeTree(tree->third,escopoAtual,noAtual);
 }

 char *convert2Str(int x){
        int length = snprintf( NULL, 0, "%d", x );
        char* str = malloc( length + 1 );
        snprintf( str, length + 1, "%d", x );
        return str;
}

char *newName(char *token){
      if(token == NULL) return NULL;
      //printf("NEWNAME ");
      int it, token_size,pos;
      token_size = strlen(token);
     // printf("NEWNAME2 ");
      pos = 0;
      char *aux = (char *)malloc(sizeof(char)*(strlen(token)+1));
      //printf("NEWNAME3 ");
      for(it = 0; it < token_size;it++){
            if(!isalnum(token[(int)it])){
                  //printf("NEWNAME4 ");
                  pos = it;
                  break;
            }
      }
      if(pos != 0){
            for(it = 0; it < pos; it++){
                  aux[it] = token[it];
            }
            return aux;
      }
      return token;
}
symbolTable *initTable(char *token, int line, char *type, node *astPointer){
    symbolTable *newnode = (symbolTable *)malloc(sizeof(symbolTable));
    newnode->token = (char *)malloc(sizeof(char)*(strlen(token)+1));
    strcpy(newnode->token,token);
    newnode->line = line;
    newnode->type = (char *)malloc(sizeof(char)*(strlen(type)+1));
    strcpy(newnode->type,type);
    newnode->astPointer = astPointer;
    newnode->next = NULL;
    return newnode;
}

void insertSymbol(symbolTable *table, char *token, int line, char *type, node *astPointer){
    if(table == NULL){
        table = initTable(token,line,type,astPointer);
        return;
    }
    symbolTable *aux, *auxNext = table;
    while(auxNext != NULL){
        aux = auxNext;
        auxNext = auxNext->next;
        if(auxNext == NULL) break;
    }
    if(aux == NULL) { printf("ERRO: INSERCAO FALIDA\n"); return;}
    symbolTable *newnode = (symbolTable *)malloc(sizeof(symbolTable));
    newnode->token = (char *)malloc(sizeof(char)*(strlen(token)+1));
    strcpy(newnode->token,token);
    newnode->line = line;
    newnode->type = (char *)malloc(sizeof(char)*(strlen(type)+1));
    strcpy(newnode->type,type);
    newnode->astPointer = astPointer;
    newnode->next = NULL;
    aux->next = newnode;
    return;
}

int searchSymbol(symbolTable *table, char *token){
    if(table == NULL) return 0;
    symbolTable *it,*aux;
    while(it != NULL){
        if(it == NULL) break;
        if(strcmp(it->token,token)==0){
            return 1;
            break;
        }
        it = it->next;
    }
    return 0;
}

//symbolTable operations end

//symbolTree operations

symbolTree *createScope(char *scope){
    symbolTree *newnode = (symbolTree *)malloc(sizeof(symbolTree));
    newnode->nChild = 0;
    newnode->childs = (symbolTree **)malloc(sizeof(symbolTree *));
    newnode->table = NULL;
    newnode->scope = (char *)malloc(sizeof(char)*(strlen(scope)+1));
    //printf("scope be4 %s", scope);
    strcpy(newnode->scope,scope);
    //printf("scope after %s", newnode->scope);
    return newnode;
}

symbolTree *searchScope(symbolTree *tree, char *scope){
      if(tree == NULL) return NULL;
      if(strcmp(tree->scope,scope) == 0) return tree;
      if(tree->nChild == 0) return NULL;
      int i;
      symbolTree *retorn;
      for(i = 0; i < tree->nChild; i++) 
            retorn = searchScope(tree->childs[i],scope);
      return retorn;
}

void insertOnScope(symbolTree *tree,char *scope,char *token, int line, char *type, node *astPointer){
    if(tree == NULL){
        tree = createScope(scope);
        if(token != NULL) insertSymbol(tree->table,token,line,type,astPointer);
        return;
    }
    symbolTree *node = searchScope(tree,scope);
    if(node != NULL) insertSymbol(node->table,token,line,type,astPointer);
    else{
        tree->nChild++;
        insertOnScope(&tree->childs[tree->nChild-1],scope,token,line,type,astPointer);
    }
    return;
}

