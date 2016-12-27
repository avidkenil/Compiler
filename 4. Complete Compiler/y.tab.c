/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "b_old.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <string>
    #include <iostream>
    #include <vector>
    
    int yylex(void);
    extern int lineno;
    void yyerror(char *);
    using namespace std;
    
    struct varParListEntry
    {
        string type;
        string eleType;
        string name;
        int scope=0;
        vector<int> dimList;
        int offset;
    };
    
    //struct change karne par lex me bhi karna hai
    struct allAttributes
    {
        string name;
        string type;            //simple or array or func
        string eleType;         //int or bool or char or void
        int val;
        int scope;
        vector <int> dimList;       //for DIMLIST
        vector <string> listOfVar;          //for id_list
        vector< struct varParListEntry> parList;
        int alreadyDefined;
        int offset;
        vector< string> code;
        
    } tempValues;
    //initial stack pointer
    int currentScope, loadAddr, targetCount=0, spInitial = 2147479548, currentOffset, mainOffset;
    FILE *fp;
    //print symbol table
    FILE *fp2;
    
    struct globalTableEntry
    {
        string name;
        string type;
        string eleType;
        int scope=0;
        vector <struct varParListEntry> parList;
        vector <struct varParListEntry> varList;
        vector <int> dimList;
        int alreadyDefined;
        int offset;
    } *activeFuncPtr, *callFuncPtr;
    
   
    vector<globalTableEntry> symTab;
    //traverse in varList then parList then globalTableEntry
    void findEntry(struct allAttributes *, int *, struct varParListEntry *);
    
    
    void insertSymTab(struct allAttributes *);
    
    
    void compatibleArithOp(struct allAttributes *, struct allAttributes *, int *);
    
    void patch(vector <string> &, string);

    bool coercible(string, string);

    //insert func in symbol table
    void insertFunc(struct allAttributes *);
    
    //search function
    struct globalTableEntry *searchFunc(struct allAttributes *, int *);


#line 147 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NUM = 258,
    CHARACTER = 259,
    ID = 260,
    NEGATION = 261,
    PLUS = 262,
    MINUS = 263,
    TIMES = 264,
    DIV = 265,
    LTE = 266,
    GTE = 267,
    LT = 268,
    GT = 269,
    EQU = 270,
    ASSIGN = 271,
    SEMI = 272,
    COMMA = 273,
    COLON = 274,
    LP = 275,
    RP = 276,
    IF = 277,
    THEN = 278,
    ELSE = 279,
    WHILE = 280,
    DO = 281,
    BEGIN1 = 282,
    END = 283,
    INT = 284,
    BOOL = 285,
    CHAR = 286,
    VOID = 287,
    TRUE = 288,
    FALSE = 289,
    CIN = 290,
    COUT = 291,
    LL = 292,
    GG = 293,
    CSB = 294,
    OSB = 295,
    RETURN = 296
  };
#endif
/* Tokens.  */
#define NUM 258
#define CHARACTER 259
#define ID 260
#define NEGATION 261
#define PLUS 262
#define MINUS 263
#define TIMES 264
#define DIV 265
#define LTE 266
#define GTE 267
#define LT 268
#define GT 269
#define EQU 270
#define ASSIGN 271
#define SEMI 272
#define COMMA 273
#define COLON 274
#define LP 275
#define RP 276
#define IF 277
#define THEN 278
#define ELSE 279
#define WHILE 280
#define DO 281
#define BEGIN1 282
#define END 283
#define INT 284
#define BOOL 285
#define CHAR 286
#define VOID 287
#define TRUE 288
#define FALSE 289
#define CIN 290
#define COUT 291
#define LL 292
#define GG 293
#define CSB 294
#define OSB 295
#define RETURN 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 86 "b_old.y" /* yacc.c:355  */

    struct allAttributes *node1;


#line 274 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 289 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   162,   168,   169,   177,   184,   206,   218,
     232,   238,   245,   257,   274,   288,   287,   430,   431,   432,
     439,   440,   452,   456,   467,   600,   621,   639,   639,   640,
     641,   646,   652,   653,   663,   664,   671,   679,   807,   818,
     826,   838,   839,   840,   841,   842,   849,   909,   919,   929,
     940,  1005,  1014,  1024,  1035,  1061,  1081,  1185,  1195,  1202,
    1209,  1217,  1232,  1233,  1239,  1251,  1251,  1327,  1394,  1414,
    1414,  1439,  1452,  1471,  1472,  1473,  1480,  1529,  1536,  1545,
    1558,  1571,  1574,  1579,  1580,  1587,  1588,  1593,  1594,  1603,
    1604,  1609,  1610,  1615,  1616,  1622,  1623
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "CHARACTER", "ID", "NEGATION",
  "PLUS", "MINUS", "TIMES", "DIV", "LTE", "GTE", "LT", "GT", "EQU",
  "ASSIGN", "SEMI", "COMMA", "COLON", "LP", "RP", "IF", "THEN", "ELSE",
  "WHILE", "DO", "BEGIN1", "END", "INT", "BOOL", "CHAR", "VOID", "TRUE",
  "FALSE", "CIN", "COUT", "LL", "GG", "CSB", "OSB", "RETURN", "$accept",
  "S1", "S", "func_decl1", "func_decl", "opt_arg_list", "arg_list", "arg",
  "func_defn", "$@1", "func_stmt", "rt", "stmt_list", "stmt", "$@2",
  "then", "opt_else", "else_stmt", "expr", "rel", "operator", "expr1",
  "add_sub", "expr2", "mul_div", "expr3", "term", "opt_stmt_list",
  "var_decl", "id_list", "$@3", "id_array", "$@4", "DIMLIST", "datatype",
  "func_call", "opt_expr_list", "expr_list", "io", "gg", "ll", "rp",
  "colon", "semi", "end", "do", YY_NULLPTR
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
     295,   296
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      88,    22,    26,    26,   -63,   -63,   -63,   -63,    -2,     1,
      17,    38,   -63,    88,    20,    88,    88,    56,    32,    43,
      56,    56,    26,     3,   -63,   -63,    26,    26,   -63,   -63,
      13,   114,    77,    -1,   -63,   -63,   -63,    23,   117,    60,
     -63,   -63,    90,   -63,   -63,    26,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,    24,    35,   -63,
      82,   -63,   -63,    85,    68,   -63,    26,   -63,    68,   -63,
     -63,   117,   -63,   -63,   -63,   -63,   -63,   -63,    26,    26,
      26,   -63,    26,    26,   -63,   -63,   -63,   117,   -63,   117,
      16,   101,   120,   -63,   -63,    36,    26,   120,    93,    26,
     -63,   -63,   -63,    96,    69,   -63,    92,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   100,    68,   -63,
     115,   127,    26,    16,    36,    56,    68,   101,   -63,    26,
     -63,   117,   -63,   -63,   -63,   120,   -63,    56,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    68,     0,     0,    27,    73,    74,    75,     0,     0,
       0,     0,     2,     6,     0,     6,     6,     0,     0,     0,
       0,     0,    78,     0,    57,    61,     0,     0,    58,    59,
       0,    40,    49,    53,    55,    56,    60,     0,    63,     0,
      84,    83,     0,    86,    85,     0,     1,     4,    92,    91,
      15,     7,     3,     5,    29,    90,    89,     0,    68,    64,
      67,    30,    31,    80,     0,    77,     0,    54,     0,    33,
      32,     0,    41,    42,    45,    44,    43,    37,     0,     0,
       0,    46,     0,     0,    50,    96,    95,     0,    62,    23,
       0,     0,    11,    81,    82,    19,     0,    11,     0,     0,
      88,    87,    76,    71,     0,    38,    35,    39,    47,    48,
      51,    52,    26,    22,    94,    93,    28,    68,     0,    10,
      13,     0,    21,     0,    19,     0,     0,     0,    79,     0,
      70,     0,    25,    34,     9,     0,    14,     0,    20,    16,
      17,    24,     8,    66,    72,    36,    12,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,    66,   -63,   -63,    44,    10,   -63,   -63,   -63,
      30,   -63,    67,   -19,   -63,   -63,   -63,   -63,     8,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,    28,
     -63,     7,   -63,    29,     0,    12,   -63,    58,   -63,   -63,
     -63,   -62,   -63,   -16,    37,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,   118,   119,   120,    15,    95,
     123,   137,    88,    16,    38,    71,   132,   133,    63,    77,
      78,    31,    81,    32,    84,    33,    34,    90,    17,    59,
      98,    35,    23,   104,    91,    36,    64,    65,    21,    42,
      45,   102,    57,    51,   116,    87
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    54,    40,    39,    61,    62,   105,    18,    82,    83,
      30,    37,    20,    19,    69,    19,    19,   114,    43,    89,
      18,    48,    18,    18,    85,    20,    60,    20,    20,    24,
      25,     1,    26,    55,    67,    68,    70,    49,    46,    41,
      96,     1,    22,    66,   115,    18,    27,    50,    58,    86,
      20,    56,   106,    94,    44,    97,   134,    48,     2,    28,
      29,     3,   -69,     4,   142,     5,     6,     7,   112,   100,
      89,     9,    10,    49,   103,   -69,   124,   122,    18,    47,
      92,    52,    53,    20,    79,    80,   107,   108,   109,   101,
     110,   111,   121,     1,    18,    93,    18,   121,    60,    20,
     -65,    20,    18,    99,   125,   124,   117,    20,   130,   141,
       2,   127,   145,     3,   129,     4,   131,     5,     6,     7,
       8,   147,     1,     9,    10,    72,    73,    74,    75,    76,
     138,    18,   136,   135,    60,   121,    20,   103,    18,     2,
     -69,   126,     3,    20,     4,   146,     5,     6,     7,     5,
       6,     7,     9,    10,   140,   143,   113,   128,   144,     0,
     139
};

static const yytype_int16 yycheck[] =
{
       0,    17,     1,     5,    20,    21,    68,     0,     9,    10,
       2,     3,     0,    13,     1,    15,    16,     1,     1,    38,
      13,     1,    15,    16,     1,    13,    19,    15,    16,     3,
       4,     5,     6,     1,    26,    27,    23,    17,     0,    38,
      16,     5,    20,    40,    28,    38,    20,    27,     5,    26,
      38,    19,    71,    45,    37,    20,   118,     1,    22,    33,
      34,    25,    40,    27,   126,    29,    30,    31,    87,     1,
      89,    35,    36,    17,    66,    40,    95,    41,    71,    13,
      20,    15,    16,    71,     7,     8,    78,    79,    80,    21,
      82,    83,    92,     5,    87,     5,    89,    97,    91,    87,
      18,    89,    95,    18,    96,   124,     5,    95,    39,   125,
      22,    18,   131,    25,    18,    27,    24,    29,    30,    31,
      32,   137,     5,    35,    36,    11,    12,    13,    14,    15,
     122,   124,     5,    18,   127,   135,   124,   129,   131,    22,
      40,    97,    25,   131,    27,   135,    29,    30,    31,    29,
      30,    31,    35,    36,   124,   127,    89,    99,   129,    -1,
     123
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    22,    25,    27,    29,    30,    31,    32,    35,
      36,    43,    44,    45,    46,    50,    55,    70,    73,    76,
      77,    80,    20,    74,     3,     4,     6,    20,    33,    34,
      60,    63,    65,    67,    68,    73,    77,    60,    56,     5,
       1,    38,    81,     1,    37,    82,     0,    44,     1,    17,
      27,    85,    44,    44,    85,     1,    19,    84,     5,    71,
      73,    85,    85,    60,    78,    79,    40,    60,    60,     1,
      23,    57,    11,    12,    13,    14,    15,    61,    62,     7,
       8,    64,     9,    10,    66,     1,    26,    87,    54,    55,
      69,    76,    20,     5,    60,    51,    16,    20,    72,    18,
       1,    21,    83,    60,    75,    83,    55,    60,    60,    60,
      60,    60,    55,    54,     1,    28,    86,     5,    47,    48,
      49,    76,    41,    52,    55,    60,    47,    18,    79,    18,
      39,    24,    58,    59,    83,    18,     5,    53,    60,    86,
      52,    85,    83,    71,    75,    55,    48,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    51,    50,    52,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    56,    55,    55,
      55,    55,    57,    57,    58,    58,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    63,    64,    64,    64,
      65,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    72,    71,    71,    73,    74,
      73,    75,    75,    76,    76,    76,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     2,     5,     5,
       1,     0,     3,     1,     2,     0,     5,     2,     3,     0,
       1,     0,     2,     1,     5,     5,     4,     0,     4,     2,
       2,     2,     1,     1,     1,     0,     2,     2,     3,     2,
       0,     1,     1,     1,     1,     1,     2,     2,     2,     0,
       2,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     0,     4,     1,     1,     0,
       5,     1,     3,     1,     1,     1,     4,     1,     0,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 151 "b_old.y" /* yacc.c:1646  */
    {    
            
            for(int i=0; i<(yyvsp[0].node1)->code.size(); i++)
                fprintf(fp,  "%s\n", (yyvsp[0].node1)->code[i].c_str() );
            printf("S! : S\n");}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 162 "b_old.y" /* yacc.c:1646  */
    {
                        (yyval.node1) =new struct allAttributes;
                        (yyval.node1)->code = (yyvsp[-1].node1)->code; 
                        (yyval.node1)->code.insert((yyval.node1)->code.end(), (yyvsp[0].node1)->code.begin(), (yyvsp[0].node1)->code.end() ); 
                        printf("S : func_defn S\n");
                        }
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 168 "b_old.y" /* yacc.c:1646  */
    { (yyval.node1) =new struct allAttributes; (yyval.node1)->code = (yyvsp[0].node1)->code; printf("S : func_decl1 S\n"); }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 169 "b_old.y" /* yacc.c:1646  */
    {  
                            (yyval.node1) =new struct allAttributes;
                            (yyval.node1)->code.insert((yyval.node1)->code.end(), (yyvsp[-1]. node1)->code.begin(), (yyvsp[-1]. node1)->code.end() );
                            (yyval.node1)->code.insert((yyval.node1)->code.end(), (yyvsp[0].node1)->code.begin(), (yyvsp[0].node1)->code.end() ); 
                            
                            printf("S : stmt S\n"); 
                               
    }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 177 "b_old.y" /* yacc.c:1646  */
    { (yyval.node1)=new struct allAttributes; printf("S : epsilon\n"); }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 184 "b_old.y" /* yacc.c:1646  */
    {
                                        cout << "in func_decl1";
                                        int found;
                                        struct globalTableEntry *rec1;
                                        rec1 = searchFunc((yyvsp[-1].node1), &found);
                                        
                                        if(found)
                                        {
                                            yyerror("function already declared or defined");
                                        }
                                        else
                                        {
                                            (yyvsp[-1].node1)->alreadyDefined=0;
                                            insertFunc((yyvsp[-1].node1));
                                        }
                                        printf("func_decl1 : func_decl semi\n");
                                    }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 206 "b_old.y" /* yacc.c:1646  */
    {  
                                                        (yyval.node1) = new struct allAttributes;
                                                        (yyval.node1)->type="function";
                                                        (yyval.node1)->eleType = (yyvsp[-4]. node1)->eleType;      //return type of function
                                                        (yyval.node1)->name = (yyvsp[-3]. node1)->name;
                                                        //listOfVar contains eleType of the variable
                                                        (yyval.node1)->parList = (yyvsp[-1]. node1)->parList;
                                                    
                                                        
                                                        printf("func_decl : func_type ID LP opt_arg_list rp\n"); 
                                                    }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 218 "b_old.y" /* yacc.c:1646  */
    { 
                                                        (yyval.node1) = new struct allAttributes;
                                                        (yyval.node1)->type="function";
                                                        (yyval.node1)->eleType = "void";
                                                        (yyval.node1)->name = (yyvsp[-3]. node1)->name;
                                                        (yyval.node1)->parList = (yyvsp[-1]. node1)->parList;
                                                        
                                                        printf("func_decl : VOID ID LP opt_arg_list rp\n"); }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 232 "b_old.y" /* yacc.c:1646  */
    { 
                                    (yyval. node1) = new struct allAttributes;
                                    (yyval. node1)->parList = (yyvsp[0]. node1)->parList;
                                    
                                    printf("opt_arg_list : arg_list\n"); 
                                }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 238 "b_old.y" /* yacc.c:1646  */
    {   (yyval. node1)= new struct allAttributes;    printf("opt_arg_list : epsilon\n"); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 245 "b_old.y" /* yacc.c:1646  */
    {   
                                    (yyval. node1) = new struct allAttributes; 
                                    (yyval. node1)->parList = (yyvsp[0]. node1)->parList;
                                    struct varParListEntry temp; 
                                    temp.name = (yyvsp[-2]. node1)->name;
                                    temp.eleType=(yyvsp[-2]. node1)->eleType;
                                    temp.type = "simple";
                                    temp.scope = 1;
                                    (yyval. node1)->parList.push_back(temp);   
                                    printf("arg_list : arg COMMA arg_list\n"); 
                
                                }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 257 "b_old.y" /* yacc.c:1646  */
    {  
                                    (yyval. node1) = new struct allAttributes; 
                                    struct varParListEntry temp; 
                                    temp.name = (yyvsp[0]. node1)->name; 
                                    temp.eleType=(yyvsp[0]. node1)->eleType;
                                    temp.scope =1; 
                                    temp.type = "simple";
                                    (yyval. node1)->parList.push_back(temp);  
                                    printf("arg_list : arg\n");
                
                                }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 274 "b_old.y" /* yacc.c:1646  */
    {    (yyval. node1) = new struct allAttributes; 
                                     (yyval. node1)->type = "simple";
                                     (yyval. node1)->scope = 1;
                                     (yyval. node1)->eleType=(yyvsp[-1]. node1)->eleType;
                                     (yyval. node1)->name = (yyvsp[0]. node1)->name;
                                     printf("arg : datatype ID\n");
                                }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 288 "b_old.y" /* yacc.c:1646  */
    {
                int found;   
                struct globalTableEntry *rec;
                
                rec = searchFunc((yyvsp[-1].node1),&found);
                
                
                if(found && rec->alreadyDefined!=1)
                {
                    if((yyvsp[-1].node1)->parList.size() == rec->parList.size())
                    {
                        int i; 
                        for(i=0;i<(yyvsp[-1].node1)->parList.size();i++)
                        {
                            if((yyvsp[-1].node1)->parList[i].eleType != rec->parList[i].eleType)
                            {
                                yyerror("argument type mismatch");
                                rec->eleType = "error";
                                activeFuncPtr = rec;
                                break;
                            }
                        }
                        if(i == (yyvsp[-1].node1)->parList.size())
                        {
                            activeFuncPtr= rec;
                            
                            rec->alreadyDefined=1;
                            currentScope=2;
                            for(int i=0;i<(yyvsp[-1].node1)->parList.size();i++)
                            {
                                //we need to check that the param is not already declared
                                int k;
                                for(k=0; k<i; k++)
                                {
                                    if(rec->parList[k].name==(yyvsp[-1].node1)->parList[i].name)
                                    {
                                        activeFuncPtr = rec;
                                        activeFuncPtr->eleType = "error";
                                        yyerror("parameters already declared");
                                        break;
                                    }
                                }
                                if(k!=i)
                                    break;
                                rec->parList[i].name = (yyvsp[-1].node1)->parList[i].name;
                            
                            }
                            if(activeFuncPtr->eleType!="error")
                            {
                                for(int i=0; i<activeFuncPtr->parList.size(); i++)
                                {
                                    activeFuncPtr->parList[i].offset = (-1)*(activeFuncPtr->parList.size()-i)*4;
                                }
                            }
                        }
                        
                    }
                    else
                    {
                        activeFuncPtr = rec;
                        activeFuncPtr->eleType = "error";
                        yyerror("number of arguments mismatch");
                    }
                }
                else if( rec==NULL )
                {
                    (yyvsp[-1].node1)->alreadyDefined = 1;
                    
                    insertFunc((yyvsp[-1].node1));
                    activeFuncPtr = &symTab.back();
                    for(int i=0; i<activeFuncPtr->parList.size(); i++)
                    {
                        activeFuncPtr->parList[i].offset = (-1)*(activeFuncPtr->parList.size()-i)*4;
                    }
                    currentScope =2;
                }
                else
                {
                    activeFuncPtr = rec;
                    activeFuncPtr->eleType = "error";
                    yyerror("function already defined");
                }
                mainOffset = currentOffset;
                currentOffset = 4;
            }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 373 "b_old.y" /* yacc.c:1646  */
    {   
                                if(activeFuncPtr->eleType!="error")
                                {
                                    // main ka offset back up and restyore 
                                    
                                    
                                    
                                    
                                    (yyval.node1)= new struct allAttributes;
                                    (yyval.node1)->code.push_back("j "+activeFuncPtr->name + "_end");
                                    (yyval.node1)->code.push_back(activeFuncPtr->name+":");
                                    
                                    
                                    (yyval.node1)->code.push_back("move $fp $sp");
                                    (yyval.node1)->code.push_back("sw $ra 0($sp)");
                                    (yyval.node1)->code.push_back("addi $sp, $sp -4");
                                    
                                    
                                    
                                    
                                    (yyval.node1)->code.insert((yyval.node1)->code.end(), (yyvsp[-1].node1)->code.begin(), (yyvsp[-1].node1)->code.end());
                                    
                                    (yyval.node1)->code.push_back(activeFuncPtr->name+"_return:");                     // label to return in between
                                    (yyval.node1)->code.push_back("addi $sp, $fp, -4");
                                    
                                    (yyval.node1)->code.push_back("lw $ra 4($sp)");
                                    int z= 4*(activeFuncPtr->parList.size()) +8;
                                    (yyval.node1)->code.push_back("addi $sp $sp "+to_string(z));
                                    (yyval.node1)->code.push_back("lw $fp 0($sp)");
                                    (yyval.node1)->code.push_back("jr $ra");
                                    
                                    
                                                                                                            // retiurn value wiil be in accumilator
                                    (yyval.node1)->code.push_back(activeFuncPtr->name+"_end:");
                                    
                                    currentScope = 0;
                                    currentOffset = mainOffset;
                                    
                                    
                                    activeFuncPtr->varList.clear();
                                    activeFuncPtr =NULL;
                                }
                                else
                                {
                                    activeFuncPtr->varList.clear();
                                    activeFuncPtr =NULL;
                                    currentScope = 0;
                                    yyerror("errortype function");
                                }
                                printf("func_defn : func_decl BEGIN1 func_stmt end\n");
                            }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 430 "b_old.y" /* yacc.c:1646  */
    {   (yyval.node1)= new struct allAttributes;  (yyval.node1)->code = (yyvsp[-1]. node1)->code; (yyval.node1)->code.insert((yyval.node1)->code.end(), (yyvsp[0].node1)->code.begin(), (yyvsp[0].node1)->code.end());  printf("func_stmt : stmt func_stmt\n");    }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 431 "b_old.y" /* yacc.c:1646  */
    {   (yyval.node1)= new struct allAttributes;  (yyval.node1)->code = (yyvsp[-1].node1)->code; (yyval.node1)->code.push_back("j "+activeFuncPtr->name+"_return"); printf("func_stmt : RETURN rt semi\n"); }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 432 "b_old.y" /* yacc.c:1646  */
    {   (yyval.node1)= new struct allAttributes;   printf("func_stmt : epsilon\n");  }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 439 "b_old.y" /* yacc.c:1646  */
    {  (yyval.node1)= new struct allAttributes;  (yyval.node1)->code = (yyvsp[0]. node1)->code;   printf("rt : expr\n");   }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 440 "b_old.y" /* yacc.c:1646  */
    {   (yyval.node1)= new struct allAttributes;   printf("rt : epsilon\n");   }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 452 "b_old.y" /* yacc.c:1646  */
    {  (yyval.node1) = new struct allAttributes;
                                        (yyval.node1)->code.insert((yyval.node1)->code.end(),(yyvsp[-1]. node1)->code.begin(), (yyvsp[-1]. node1)->code.end() );
                                        (yyval.node1)->code.insert((yyval.node1)->code.end(),(yyvsp[0].node1)->code.begin(), (yyvsp[0].node1)->code.end() );
                                        printf("stmt_list : stmt stmt_list\n"); }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 456 "b_old.y" /* yacc.c:1646  */
    {  
                                        (yyval.node1) = new struct allAttributes;
                                        (yyval.node1)->code.insert((yyval.node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end() );
                                        printf("stmt_list : stmt\n"); }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 467 "b_old.y" /* yacc.c:1646  */
    {
                                                //cout<<"\n\nid scope"<<$1->scope<<endl;
                                                (yyval. node1) = new struct allAttributes;
                                                struct varParListEntry *rec = new struct varParListEntry;
                                                int success;
                                                //cout << $1->name << " " << $4->name;
                                                findEntry((yyvsp[-4]. node1), &success, rec);
                                                //cout<<"\n\nfind id scope"<<rec->scope<<endl;
                                                
                                                if(!success)
                                                {
                                                    yyerror("lhs not declared before use");
                                                }
                                                else
                                                {
                                                    if( (yyvsp[-4]. node1)->type == "array" && (yyvsp[-4]. node1)->eleType != "error" && (yyvsp[-1]. node1)->eleType !="error" )
                                                    {
                                                        //cout<<"type: array ";
                                                        if( (rec->dimList).size() == (yyvsp[-4]. node1)->dimList.size() )
                                                        {
                                                            int i;
                                                            //cout << " dim match dimlist size " <<rec.dimList.size();
                                                            for( i=0; i< rec->dimList.size(); i++)
                                                            {
                                                                //cout<<i<<"th dimension "<<rec.dimList[i]<<" "<<$1->dimList[i]<<"  ";
                                                                if( rec->dimList[i] <= (yyvsp[-4]. node1)->dimList[i] )
                                                                {
                                                                    yyerror("array out of bound");
                                                                    (yyval. node1)->eleType = string("error");
                                                                    
                                                                    (yyvsp[-4]. node1)->eleType = string("error");
                                                                    
                                                                    break;
                                                                }
                                                            }
                                                            if( i == rec->dimList.size() )
                                                            {
                                                                if(coercible(rec->eleType, (yyvsp[-1]. node1)->eleType))
                                                                {
                                                                    if((yyvsp[-4]. node1)->eleType == "bool")
                                                                    {
                                                                        if((yyvsp[-1]. node1)->val > 0)
                                                                            (yyvsp[-4]. node1)->val = 1;
                                                                        else
                                                                            (yyvsp[-4]. node1)->val = 0;
                                                                    }    
                                                                    else
                                                                        (yyvsp[-4]. node1)->val = (yyvsp[-1]. node1)->val;
                                                                    
                                                                    /*  code gen for array    */
                                                                    int dim = 0;
                                                                    int lastDim=1;
                                                                    for(int i=(yyvsp[-4]. node1)->dimList.size()-1; i>=0; i-- )
                                                                    {
                                                                        dim += ((yyvsp[-4]. node1)->dimList[i])*lastDim;
                                                                        lastDim *= rec->dimList[i];
                                                                    }
                                                                    (yyval. node1)->code.insert( (yyval. node1)->code.end(), (yyvsp[-1]. node1)->code.begin(), (yyvsp[-1]. node1)->code.end() );
                                                                    if(activeFuncPtr==NULL)
                                                                    {
                                                                        (yyval. node1)->code.push_back("move $t0, $fp");
                                                                        (yyval. node1)->code.push_back("addi $t0, $t0, " + to_string(-1*( rec->offset+dim*4) ));
                                                                        (yyval. node1)->code.push_back("sw $a0, ($t0)");
                                                                        
                                                                    }
                                                                    else
                                                                    {
                                                                        (yyval. node1)->code.push_back("move $t0, $fp");
                                                                        (yyval. node1)->code.push_back("addi $t0, $t0, " + to_string(-1*(rec->offset+dim*4)) );
                                                                        (yyval. node1)->code.push_back("sw $a0, ($t0)");
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    yyerror("Incompatible assignment");
                                                                }
                                                            }
                                                        }
                                                        else
                                                        {
                                                            yyerror("Dimensions of array mismatch");
                                                        }
                                                    }
                                                    else if((yyvsp[-4]. node1)->type == "simple" && (yyvsp[-4]. node1)->eleType != "error" && (yyvsp[-1]. node1)->eleType !="error")
                                                    {
                                                        //cout << "rec " << $1->eleType << " " << $4->eleType;
                                                        if( coercible(rec->eleType, (yyvsp[-1]. node1)->eleType) )
                                                        {
                                                            if((yyvsp[-4]. node1)->eleType == "bool")
                                                            {
                                                                if((yyvsp[-1]. node1)->val > 0)
                                                                    (yyvsp[-4]. node1)->val = 1;
                                                                else
                                                                    (yyvsp[-4]. node1)->val = 0;
                                                            }    
                                                            else
                                                                (yyvsp[-4]. node1)->val = (yyvsp[-1]. node1)->val;
                                                            /* code gen */
                                                            
                                                            (yyval. node1)->code.insert( (yyval. node1)->code.end(), (yyvsp[-1]. node1)->code.begin(), (yyvsp[-1]. node1)->code.end() );
                                                            if(activeFuncPtr == NULL)
                                                            {
                                                                (yyval. node1)->code.push_back("move $t0, $fp");
                                                                //$$->code.push_back("li $t0, "+to_string(spInitial) );
                                                                (yyval. node1)->code.push_back("addi $t0, $t0, "+ to_string((-1*rec->offset) ) );
                                                                (yyval. node1)->code.push_back("sw $a0, ($t0)");
                                                            }
                                                            else
                                                            {
                                                                if(rec->scope==0)
                                                                {
                                                                    (yyval. node1)->code.push_back("li $t0, "+to_string(spInitial) );
                                                                }
                                                                else
                                                                {
                                                                    (yyval. node1)->code.push_back("move $t0, $fp");
                                                                }
                                                                
                                                                (yyval. node1)->code.push_back("addi $t0, $t0, "+ to_string(-1*rec->offset) );
                                                                (yyval. node1)->code.push_back("sw $a0, ($t0)");
                                                            }
                                                                
                                                                
                                                            //cout<<"value of  "<<$1->name<<" : "<<$1->val;
                                                        }
                                                        else
                                                            yyerror("Incompatible assignment");
                                                    }
                                                }
                                                
                                                
                                                printf("stmt : id_array COLON ASSIGN expr semi\n"); 
                                            }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 600 "b_old.y" /* yacc.c:1646  */
    {   
                                                (yyval. node1) = new struct allAttributes;
                                                (yyval. node1)->code = (yyvsp[-3]. node1)->code;
                                                (yyval. node1)->code.push_back("li $t0, 0");
                                                (yyval. node1)->code.push_back("beq $a0, $t0, target" + to_string(targetCount) );
                                                
                                                
                                                
                                                (yyval. node1)->code.insert((yyval. node1)->code.end(), (yyvsp[-1]. node1)->code.begin(), (yyvsp[-1]. node1)->code.end());
                                                
                                                (yyval. node1)->code.push_back("b target" + to_string(targetCount+1));

                                                (yyval. node1)->code.push_back("target" +to_string(targetCount)+":" );
                                                
                                                (yyval. node1)->code.insert((yyval. node1)->code.end(), (yyvsp[0].node1)->code.begin(), (yyvsp[0].node1)->code.end());
                                                
                                                (yyval. node1)->code.push_back("target" + to_string(targetCount+1) + ":" );
                                                
                                                targetCount+=2;
                                                printf("stmt : IF expr then stmt opt_else\n"); 
                                            }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 621 "b_old.y" /* yacc.c:1646  */
    {
                                                (yyval. node1) = new struct allAttributes;
                                                
                                                (yyval. node1)->code.push_back("target" + to_string(targetCount) + ":");
                                                
                                                
                                                (yyval. node1)->code.insert((yyval. node1)->code.end(), (yyvsp[-2]. node1)->code.begin(), (yyvsp[-2]. node1)->code.end());
                                                (yyval. node1)->code.push_back("li $t0 , 0");
                                                (yyval. node1)->code.push_back("beq $t0, $a0, target" + to_string(targetCount+1) );
                                                
                                                
                                                (yyval. node1)->code.insert((yyval. node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end());
                                                (yyval. node1)->code.push_back("b target" + to_string(targetCount) );
                                                (yyval. node1)->code.push_back("target" + to_string(targetCount+1) + ":");
                                                targetCount+=2;
                                                printf("stmt : WHILE expr do stmt\n"); 
            
                                            }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 639 "b_old.y" /* yacc.c:1646  */
    { currentScope++; }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 639 "b_old.y" /* yacc.c:1646  */
    { currentScope--;    (yyval. node1) = new struct allAttributes; (yyval. node1)->code = (yyvsp[-1].node1)->code;  printf("stmt : BEGIN1  opt_stmt_list end\n"); }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 640 "b_old.y" /* yacc.c:1646  */
    {  (yyval. node1)=new struct allAttributes; (yyval. node1)->code =(yyvsp[-1].node1)->code; printf("stmt : var_decl semi\n"); }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 641 "b_old.y" /* yacc.c:1646  */
    {  
                                                (yyval. node1) = new struct allAttributes;
                                                 (yyval. node1) = (yyvsp[-1]. node1);
                                                 printf("stmt : func_call semi\n");
                                            }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 646 "b_old.y" /* yacc.c:1646  */
    {  printf("stmt : io semi\n"); }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 652 "b_old.y" /* yacc.c:1646  */
    {   printf("then : THEN\n"); }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 653 "b_old.y" /* yacc.c:1646  */
    {  yyerror("then missing ");  }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 663 "b_old.y" /* yacc.c:1646  */
    { (yyval.node1) = new struct allAttributes; (yyval.node1)->code =(yyvsp[0].node1)->code; printf("opt_else : else_stmt\n"); }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 664 "b_old.y" /* yacc.c:1646  */
    {  (yyval.node1) = new struct allAttributes; printf("opt_else : epsilon\n"); }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 671 "b_old.y" /* yacc.c:1646  */
    {   (yyval.node1) = new struct allAttributes;   (yyval.node1)->code = (yyvsp[0]. node1)->code;    printf("else_stmt : ELSE stmt\n"); }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 679 "b_old.y" /* yacc.c:1646  */
    {  
                                int success;
                                if((yyvsp[0]. node1)->type == "epsilon")
                                {
                                    (yyval. node1) = new struct allAttributes;
                                    (yyval. node1)->type = (yyvsp[-1]. node1)->type;
                                    (yyval. node1)->eleType = (yyvsp[-1]. node1)->eleType;
                                    (yyval. node1)->val = (yyvsp[-1]. node1)->val;
                                    (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                }
                                else
                                {
                                    compatibleArithOp((yyvsp[-1]. node1), (yyvsp[0]. node1), &success);
                                    (yyval. node1) = new struct allAttributes;
                                    if(success)
                                    {
                                        
                                        (yyval. node1)->eleType=string("bool");
                                        if((yyvsp[0]. node1)->type=="<=")
                                        {
                                            (yyval. node1)->val = ((yyvsp[-1]. node1)->val <= (yyvsp[0]. node1)->val);
                                            (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                            (yyval. node1)->code.push_back("sw $a0, ($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, -4");
                                            
                                            (yyval. node1)->code.insert( (yyval. node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end() );
                                            (yyval. node1)->code.push_back("lw $t0, 4($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, 4");
                                            (yyval. node1)->code.push_back("ble $t0, $a0, target" + to_string(targetCount));    // $t0 <= $a0
                                            (yyval. node1)->code.push_back("li $a0, 0");
                                            (yyval. node1)->code.push_back("b target" + to_string(targetCount+1));
                                            (yyval. node1)->code.push_back("target" + to_string(targetCount) + ":" );
                                            (yyval. node1)->code.push_back("li $a0, 1");
                                            (yyval. node1)->code.push_back("target"+to_string(targetCount+1) + ":" );        
                                            
                                            targetCount+=2;
                                            //$$->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if((yyvsp[0]. node1)->type==">=")
                                        {    
                                            
                                            (yyval. node1)->val = ((yyvsp[-1]. node1)->val >= (yyvsp[0]. node1)->val);
                                            (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                            (yyval. node1)->code.push_back("sw $a0, ($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, -4");
                                            
                                            (yyval. node1)->code.insert( (yyval. node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end() );
                                            (yyval. node1)->code.push_back("lw $t0, 4($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, 4");
                                            (yyval. node1)->code.push_back("bge $t0, $a0, target" + to_string(targetCount));    // $t0 >= $a0
                                            (yyval. node1)->code.push_back("li $a0, 0");
                                            (yyval. node1)->code.push_back("b target" + to_string(targetCount+1));
                                            (yyval. node1)->code.push_back("target" + to_string(targetCount) + ":" );
                                            (yyval. node1)->code.push_back("li $a0, 1");
                                            (yyval. node1)->code.push_back("target"+to_string(targetCount+1) + ":" );        
                                            
                                            targetCount+=2;
                                            //$$->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if((yyvsp[0]. node1)->type=="==")
                                        {
                                            (yyval. node1)->val = ((yyvsp[-1]. node1)->val == (yyvsp[0]. node1)->val);
                                            (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                            (yyval. node1)->code.push_back("sw $a0, ($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, -4");
                                            
                                            (yyval. node1)->code.insert( (yyval. node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end() );
                                            (yyval. node1)->code.push_back("lw $t0, 4($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, 4");
                                            (yyval. node1)->code.push_back("beq $t0, $a0, target" + to_string(targetCount));    // $t0 <= $a0
                                            (yyval. node1)->code.push_back("li $a0, 0");
                                            (yyval. node1)->code.push_back("b target" + to_string(targetCount+1));
                                            (yyval. node1)->code.push_back("target" + to_string(targetCount) + ":" );
                                            (yyval. node1)->code.push_back("li $a0, 1");
                                            (yyval. node1)->code.push_back("target"+to_string(targetCount+1) + ":" );        
                                            
                                            targetCount+=2;
                                            //$$->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if((yyvsp[0]. node1)->type=="<")
                                        {
                                            (yyval. node1)->val = ((yyvsp[-1]. node1)->val < (yyvsp[0]. node1)->val);
                                            (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                            (yyval. node1)->code.push_back("sw $a0, ($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, -4");
                                            
                                            (yyval. node1)->code.insert( (yyval. node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end() );
                                            (yyval. node1)->code.push_back("lw $t0, 4($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, 4");
                                            (yyval. node1)->code.push_back("blt $t0, $a0, target" + to_string(targetCount));    // $t0 <= $a0
                                            (yyval. node1)->code.push_back("li $a0, 0");
                                            (yyval. node1)->code.push_back("b target" + to_string(targetCount+1));
                                            (yyval. node1)->code.push_back("target" + to_string(targetCount) + ":" );
                                            (yyval. node1)->code.push_back("li $a0, 1");
                                            (yyval. node1)->code.push_back("target"+to_string(targetCount+1) + ":" );        
                                            
                                            targetCount+=2;
                                           // $$->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if((yyvsp[0]. node1)->type==">")
                                        {
                                            (yyval. node1)->val = ((yyvsp[-1]. node1)->val > (yyvsp[0]. node1)->val);
                                            (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                            (yyval. node1)->code.push_back("sw $a0, ($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, -4");
                                            
                                            (yyval. node1)->code.insert( (yyval. node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end() );
                                            (yyval. node1)->code.push_back("lw $t0, 4($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, 4");
                                            (yyval. node1)->code.push_back("bgt $t0, $a0, target" + to_string(targetCount));    // $t0 <= $a0
                                            (yyval. node1)->code.push_back("li $a0, 0");
                                            (yyval. node1)->code.push_back("b target" + to_string(targetCount+1));
                                            (yyval. node1)->code.push_back("target" + to_string(targetCount) + ":" );
                                            (yyval. node1)->code.push_back("li $a0, 1");
                                            (yyval. node1)->code.push_back("target"+to_string(targetCount+1) + ":" );        
                                            
                                            targetCount+=2;
                                            //$$->code.push_back("addi $sp, $sp, 4");
                                        }
                                    }
                                    else
                                    {
                                        (yyval. node1)->eleType = string("error");
                                        yyerror("incompatible operands");
                                    }
                                }
        
                                printf("expr : expr1 rel\n"); }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 807 "b_old.y" /* yacc.c:1646  */
    {
                                (yyval. node1)->code.insert((yyval. node1)->code.end(), (yyvsp[-1]. node1)->code.begin(), (yyvsp[-1]. node1)->code.end());
                                printf("expr : LP expr rp\n"); 
            
                            }
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 818 "b_old.y" /* yacc.c:1646  */
    { 
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->eleType = (yyvsp[0]. node1)->eleType;
                                (yyval. node1)->type = (yyvsp[-1]. node1)->type;              // operator itself; "<="
                                (yyval. node1)->code = (yyvsp[0]. node1)->code;
                                printf("rel : operator expr\n"); 
            
                            }
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 826 "b_old.y" /* yacc.c:1646  */
    {
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->type = string("epsilon");
                                printf("rel : epsilon\n"); 
                    
                            }
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 838 "b_old.y" /* yacc.c:1646  */
    { (yyval. node1) = new struct allAttributes; (yyval. node1)->type = string("<="); printf("operator : LTE\n"); }
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 839 "b_old.y" /* yacc.c:1646  */
    { (yyval. node1) = new struct allAttributes; (yyval. node1)->type = string(">="); printf("operator : GTE\n"); }
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 840 "b_old.y" /* yacc.c:1646  */
    { (yyval. node1) = new struct allAttributes; (yyval. node1)->type = string("=="); printf("operator : EQU\n"); }
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 841 "b_old.y" /* yacc.c:1646  */
    { (yyval. node1) = new struct allAttributes; (yyval. node1)->type = string(">"); printf("operator : GT\n"); }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 842 "b_old.y" /* yacc.c:1646  */
    { (yyval. node1) = new struct allAttributes; (yyval. node1)->type = string("<"); printf("operator : LT\n"); }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 849 "b_old.y" /* yacc.c:1646  */
    {  
        
                                int success;
                                if((yyvsp[0]. node1)->type=="epsilon")
                                {
                                    (yyval. node1) = new struct allAttributes;
                                    (yyval. node1)->type = (yyvsp[-1]. node1)->type;
                                    (yyval. node1)->eleType = (yyvsp[-1]. node1)->eleType;
                                    (yyval. node1)->val = (yyvsp[-1]. node1)->val;
                                    (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                }
                                else
                                {
                                    compatibleArithOp((yyvsp[-1]. node1), (yyvsp[0]. node1), &success);
                                    (yyval. node1) = new struct allAttributes;
                                    if(success)
                                    {
                                        (yyval. node1)->eleType=string("int");
                                        if((yyvsp[0]. node1)->type=="+")
                                        {
                                            (yyval. node1)->val = ((yyvsp[-1]. node1)->val + (yyvsp[0]. node1)->val);
                                            (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                            (yyval. node1)->code.push_back("sw $a0, ($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, -4");
                                            
                                            (yyval. node1)->code.insert( (yyval. node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end() );
                                            (yyval. node1)->code.push_back("lw $t0, 4($sp)");
                                            (yyval. node1)->code.push_back("add $a0, $a0, $t0");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if((yyvsp[0]. node1)->type=="-")
                                        {
                                            (yyval. node1)->val = ((yyvsp[-1]. node1)->val - (yyvsp[0]. node1)->val);
                                            (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                            (yyval. node1)->code.push_back("sw $a0, ($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, -4");
                                            
                                            (yyval. node1)->code.insert( (yyval. node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end() );
                                            (yyval. node1)->code.push_back("lw $t0, 4($sp)");
                                            (yyval. node1)->code.push_back("sub $a0,$a0, $t0");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, 4");
                                        }    
                                    }
                                    else
                                    {
                                        (yyval. node1)->eleType = string("error");
                                        yyerror("incompatible operands");
                                    }
                                }
                                
                                printf("expr1 : expr2 add_sub\n"); 
            
            
                            }
#line 2335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 909 "b_old.y" /* yacc.c:1646  */
    {
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->type = string("+");
                                (yyval. node1)->val = (yyvsp[0]. node1)->val;
                                (yyval. node1)->eleType = (yyvsp[0]. node1)->eleType;
                                if((yyvsp[0]. node1)->eleType != "error")
                                    (yyval. node1)->code =(yyvsp[0]. node1)->code;
                                printf("add_sub : PLUS expr\n"); 
                    
                            }
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 919 "b_old.y" /* yacc.c:1646  */
    {
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->type = string("-");
                                (yyval. node1)->val = (yyvsp[0]. node1)->val;
                                (yyval. node1)->eleType = (yyvsp[0]. node1)->eleType;
                                if((yyvsp[0]. node1)->eleType != "error")
                                    (yyval. node1)->code =(yyvsp[0]. node1)->code;
                                printf("add_sub : MINUS expr\n"); 
                    
                            }
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 929 "b_old.y" /* yacc.c:1646  */
    { 
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->type = string("epsilon");
                                printf("add_sub : epsilon\n"); 
                            }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 940 "b_old.y" /* yacc.c:1646  */
    {
                                int success;
                                if((yyvsp[0]. node1)->type == "epsilon")
                                {
                                    (yyval. node1) = new struct allAttributes;
                                    (yyval. node1)->type = (yyvsp[-1]. node1)->type;
                                    (yyval. node1)->eleType = (yyvsp[-1]. node1)->eleType;
                                    (yyval. node1)->val = (yyvsp[-1]. node1)->val;
                                    (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                }
                                else
                                {
                                    compatibleArithOp((yyvsp[-1]. node1), (yyvsp[0]. node1), &success);
                                    (yyval. node1) = new struct allAttributes;
                                    if(success)
                                    {
                                        
                                        (yyval. node1)->eleType=string("int");
                                        if((yyvsp[0]. node1)->type=="*")
                                        {
                                            (yyval. node1)->val = ((yyvsp[-1]. node1)->val * (yyvsp[0]. node1)->val);
                                            (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                            (yyval. node1)->code.push_back("sw $a0, ($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, -4");
                                            
                                            (yyval. node1)->code.insert( (yyval. node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end() );
                                            (yyval. node1)->code.push_back("lw $t0, 4($sp)");
                                            (yyval. node1)->code.push_back("mult $a0, $t0");
                                            (yyval. node1)->code.push_back("mflo $a0");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if((yyvsp[0]. node1)->type=="/")
                                        {
                                            (yyval. node1)->val = ((yyvsp[-1]. node1)->val / (yyvsp[0]. node1)->val);
                                             (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                            (yyval. node1)->code.push_back("sw $a0, ($sp)");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, -4");
                                            
                                            (yyval. node1)->code.insert( (yyval. node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end() );
                                            (yyval. node1)->code.push_back("lw $t0, 4($sp)");
                                            (yyval. node1)->code.push_back("div $a0, $t0");
                                            (yyval. node1)->code.push_back("mflo $a0");
                                            (yyval. node1)->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if((yyvsp[0]. node1)->type=="epsilon")
                                        {
                                            (yyval. node1)->val = (yyvsp[-1]. node1)->val;
                                            (yyval. node1)->code = (yyvsp[-1]. node1)->code;
                                        }    
                                        
                                    }
                                    else
                                    {
                                        (yyval. node1)->eleType = string("error");
                                        yyerror("incompatible operands");
                                    }
                                }
                                printf("expr2 : expr3 mul_div\n");
                            }
#line 2439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1005 "b_old.y" /* yacc.c:1646  */
    { 
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->type = string("*");
                                (yyval. node1)->val = (yyvsp[0]. node1)->val;
                                (yyval. node1)->eleType = (yyvsp[0]. node1)->eleType;
                                if((yyvsp[0]. node1)->eleType != "error")
                                    (yyval. node1)->code =(yyvsp[0]. node1)->code;
                                printf("mul_div : TIMES expr\n");
                            }
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1014 "b_old.y" /* yacc.c:1646  */
    {
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->type = string("/");
                                (yyval. node1)->val = (yyvsp[0]. node1)->val;
                                (yyval. node1)->eleType = (yyvsp[0]. node1)->eleType;
                                if((yyvsp[0]. node1)->eleType != "error")
                                    (yyval. node1)->code =(yyvsp[0]. node1)->code;
                                printf("mul_div : DIV expr\n"); 
                        
                            }
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1024 "b_old.y" /* yacc.c:1646  */
    {
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->type = string("epsilon");
                                printf("mul_div : epsilon\n");
                            }
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1035 "b_old.y" /* yacc.c:1646  */
    {   
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->eleType = string("bool");
                                (yyval. node1)->val = !((yyvsp[0]. node1)->val);
                                if(coercible("bool", (yyvsp[0]. node1)->type))
                                {
                                    (yyval. node1)->eleType ="bool";
                                    
                                    (yyval. node1)->code.push_back("li $t0, "+ to_string((yyvsp[0]. node1)->val) ) ;
                                    (yyval. node1)->code.push_back("li $t1, 0");
                                    (yyval. node1)->code.push_back("beq $t0, $t1, target"+to_string(targetCount) );
                                    (yyval. node1)->code.push_back("li $a0, 0");
                                    (yyval. node1)->code.push_back("b target"+to_string(targetCount+1));
                                    (yyval. node1)->code.push_back("target" +to_string(targetCount) +":");
                                    (yyval. node1)->code.push_back("li $a0, 1");
                                    (yyval. node1)->code.push_back("target"+to_string(targetCount+1)+":" );
                                    targetCount+=2;
                                }
                                else
                                {
                                    (yyval. node1)->eleType = "error";
                                    yyerror("negation not coercible ");
                                }
                                printf("expr3 : NEGATION expr\n"); 
                
                            }
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1061 "b_old.y" /* yacc.c:1646  */
    {
                                (yyval. node1) = new struct allAttributes;
                                if((yyvsp[0]. node1)->eleType !="error")
                                {
                                    (yyval. node1)->type = (yyvsp[0]. node1)->type;
                                    (yyval. node1)->eleType = (yyvsp[0]. node1)->eleType;
                                    (yyval. node1)->val = (yyvsp[0]. node1)->val;
                                    (yyval. node1)->name = (yyvsp[0]. node1)->name;
                                    for(int i=0;i<(yyvsp[0]. node1)->code.size();i++)
                                        (yyval. node1)->code.push_back((yyvsp[0]. node1)->code[i]); 
                                }
                                else
                                    (yyval. node1)->eleType ="error";
                                    
                                printf("expr3 : term\n");
                            }
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1081 "b_old.y" /* yacc.c:1646  */
    {
                                //cout<<"term -> id_array ";
                                int found;
                                struct varParListEntry rec;     // it can be global entry also but we dont need func table entry fields
                                (yyval. node1) = new struct allAttributes;
                                
                                findEntry((yyvsp[0]. node1), &found, &rec);
                                
                                if( found )
                                {
                                    //cout << "entry found "
                                    (yyvsp[0]. node1)->eleType = rec.eleType;
                                    if( (yyvsp[0]. node1)->type == "array" )
                                    {
                                        //cout<<"type: array ";
                                        if( (rec.dimList).size() == (yyvsp[0]. node1)->dimList.size() )
                                        {
                                            int i;
                                            //cout << " dim match dimlist size " <<rec.dimList.size();
                                            for( i=0; i< rec.dimList.size(); i++)
                                            {
                                                //cout<<i<<"th dimension "<<rec.dimList[i]<<" "<<$1->dimList[i]<<"  ";
                                                if( rec.dimList[i] <= (yyvsp[0]. node1)->dimList[i] )
                                                {
                                                    yyerror("array out of bound");
                                                    (yyval. node1)->eleType = string("error");
                                                    break;
                                                }
                                            }
                                            if( i == rec.dimList.size() )
                                            {
                                                /*  code gen for array    */
                                                int dim = 0;
                                                int lastDim=1;
                                                for(int i=(yyvsp[0]. node1)->dimList.size()-1; i>=0; i-- )
                                                {
                                                    dim += ((yyvsp[0]. node1)->dimList[i])*lastDim;
                                                    lastDim *= rec.dimList[i];
                                                }   
                                                if(activeFuncPtr == NULL)
                                                {
                                                    (yyval. node1)->code.push_back("move $t0, $fp");
                                                    //$$->code.push_back("li $t0, "+to_string(spInitial) );
                                                    (yyval. node1)->code.push_back("addi $t0, $t0, "+to_string(  -1*(rec.offset+dim*4) ) );
                                                    (yyval. node1)->code.push_back("lw $a0, ($t0)");
                                                    
                                                }
                                                else{
                                                    if(rec.scope==0)
                                                    {
                                                        (yyval. node1)->code.push_back("li $t0, "+to_string(spInitial) );
                                                    }
                                                    else
                                                    {
                                                        (yyval. node1)->code.push_back("move $t0, $fp");
                                                    }
                                                    (yyval. node1)->code.push_back("addi $t0, $t0, "+to_string( -1*(rec.offset+dim*4) ) );
                                                    (yyval. node1)->code.push_back("lw $a0, ($t0)");
                                                }
                                                
                                                (yyval. node1)->eleType = (yyvsp[0]. node1)->eleType;
                                                (yyval. node1)->val = (yyvsp[0]. node1)->val;
                                            }
                                        }
                                        else
                                        {
                                            yyerror("array out of bound");
                                            (yyval. node1)->eleType = string("error");
                                            //break;
                                        }
                                    }
                                    else
                                    {
                                        (yyval. node1)->eleType = (yyvsp[0]. node1)->eleType;
                                        (yyval. node1)->val = (yyvsp[0]. node1)->val;
                                        
                                        if(activeFuncPtr == NULL)
                                        {
                                            (yyval. node1)->code.push_back("move $t0, $fp");
                                            //$$->code.push_back("li $t0, "+to_string(spInitial) );
                                            (yyval. node1)->code.push_back("addi $t0, $t0, "+to_string( -1*(rec.offset) ) );
                                            (yyval. node1)->code.push_back("lw $a0, ($t0)");
                                        }
                                        else{
                                            if(rec.scope==0)
                                            {
                                                (yyval. node1)->code.push_back("li $t0, "+to_string(spInitial) );
                                            }
                                            else
                                            {
                                                (yyval. node1)->code.push_back("move $t0, $fp");
                                            }
                                            (yyval. node1)->code.push_back("addi $t0, $t0, "+to_string( -1*rec.offset) );
                                            (yyval. node1)->code.push_back("lw $a0, ($t0)");
                                        }
                                    }
                                }
                                else
                                {
                                    (yyval. node1)->eleType = string("error");
                                    yyerror( (char *)("variabe not declared " + (yyvsp[0]. node1)->name).c_str() );
                                }
                                printf("term : id_array\n");
                            }
#line 2639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1185 "b_old.y" /* yacc.c:1646  */
    { 
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->val=(yyvsp[0]. node1)->val; 
                                (yyval. node1)->eleType = "int";
                                /*  code gen  */
                                (yyval. node1)->code.push_back("li $a0, " + to_string((yyvsp[0]. node1)->val) );
                                
                                printf("term : NUM\n"); 
                
                            }
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1195 "b_old.y" /* yacc.c:1646  */
    {
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->val=1; 
                                (yyval. node1)->eleType = "bool";
                                /*  code gen  */
                                (yyval. node1)->code.push_back("li $a0, 1");
                            }
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1202 "b_old.y" /* yacc.c:1646  */
    {
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->val=0; 
                                (yyval. node1)->eleType = "bool";
                                /*  code gen  */
                                (yyval. node1)->code.push_back("li $a0, 0" );
                            }
#line 2678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1209 "b_old.y" /* yacc.c:1646  */
    {  
                                
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1) = (yyvsp[0]. node1);
                                
                                printf("term : func_call\n");   
                                
                            }
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1217 "b_old.y" /* yacc.c:1646  */
    {  
                                (yyval. node1) = new struct allAttributes;
                                (yyval. node1)->val=(yyvsp[0]. node1)->val; 
                                (yyval. node1)->eleType = "char";
                                printf("term : CHARACTER\n"); 
                                /*  code gen  */
                                (yyval. node1)->code.push_back("li $a0, " + to_string(0) );
                                string s;
                                s.push_back((char)(yyvsp[0]. node1)->val);
                                (yyval. node1)->code.push_back("li $a0, \'" + s +"\'" );
                            }
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1232 "b_old.y" /* yacc.c:1646  */
    {   (yyval.node1) = new struct allAttributes;  (yyval.node1)->code = (yyvsp[0].node1)->code;     printf("opt_stmt_list : stmt_list\n"); }
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1233 "b_old.y" /* yacc.c:1646  */
    {  (yyval.node1) = new struct allAttributes;   printf("opt_stmt_list : epsilon\n"); }
#line 2719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1239 "b_old.y" /* yacc.c:1646  */
    {
                                        (yyval.node1)= new struct allAttributes;
                                        (yyval.node1)->code = (yyvsp[0]. node1)->code;
                                        
                                        patch((yyvsp[0]. node1)->listOfVar, (yyvsp[-1]. node1)->eleType); 
                                        (yyvsp[0]. node1)->eleType="int"; 
                                        printf("var_decl : datatype id_list\n"); 
                                    }
#line 2732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1251 "b_old.y" /* yacc.c:1646  */
    {
                            //cout<<"id_list ->>id_array";
                            //$$ = new struct allAttributes; 
                            int found; 
                            struct varParListEntry rec;
                            
                            findEntry((yyvsp[0]. node1), &found, &rec);
                            
                            if( found && ( (rec.scope == currentScope) || ( rec.type=="function" &&  rec.scope == 1 && currentScope == 2) ) )
                            {
                                
                                string tempError = string("variable already declared ") + (yyvsp[0]. node1)->name; 
                                yyerror ( (char *)(tempError.c_str()) );
                            }
                            else
                            {
                                //cout << "found val " << found;
                                //cout<<"entry scope "<<$1->scope<<endl;
                                if(activeFuncPtr == NULL)
                                {
                                    (yyvsp[0]. node1)->offset = currentOffset;
                                    if((yyvsp[0]. node1)->type=="simple")
                                    {
                                        currentOffset+=4;
                                        (yyvsp[0]. node1)->code.push_back("addi $sp,$sp,-4");
                                    }
                                    else if((yyvsp[0]. node1)->type=="array")
                                    {
                                        int temp=1;
                                        for(int i=0;i<(yyvsp[0]. node1)->dimList.size();i++)
                                        {
                                            temp*=(yyvsp[0]. node1)->dimList[i];
                                            
                                        }
                                        temp*=4;
                                        currentOffset += temp;
                                        (yyvsp[0]. node1)->code.push_back("addi $sp, $sp, "+ to_string(-1*currentOffset) );
                                    }
                                }
                                else
                                {
                                    (yyvsp[0]. node1)->offset = currentOffset;
                                    if((yyvsp[0]. node1)->type=="simple")
                                    {
                                        currentOffset+=4;
                                        (yyvsp[0]. node1)->code.push_back("addi $sp,$sp,-4");
                                    }
                                    else if((yyvsp[0]. node1)->type=="array")
                                    {
                                        int temp=1;
                                        for(int i=0;i<(yyvsp[0]. node1)->dimList.size();i++)
                                        {
                                            temp*=(yyvsp[0]. node1)->dimList[i];
                                            
                                        }
                                        temp*=4;
                                        currentOffset += temp;
                                        (yyvsp[0]. node1)->code.push_back("addi $sp, $sp, "+ to_string(-1*currentOffset) );
                                    }
                                }
                                
                                insertSymTab((yyvsp[0]. node1));
                            }
                        }
#line 2801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1317 "b_old.y" /* yacc.c:1646  */
    { 
                                (yyval. node1) = new struct allAttributes; 
                                
                                (yyval. node1)->code.insert((yyval. node1)->code.end(), (yyvsp[-3]. node1)->code.begin(), (yyvsp[-3]. node1)->code.end());
                                (yyval. node1)->code.insert((yyval. node1)->code.end(), (yyvsp[0]. node1)->code.begin(), (yyvsp[0]. node1)->code.end());
                                
                                (yyvsp[0]. node1)->listOfVar.push_back((yyvsp[-3]. node1)->name);
                                (yyval. node1)->listOfVar =(yyvsp[0]. node1)->listOfVar;   
                                printf("id_list : id_array COMMA id_list \n");
                            }
#line 2816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1327 "b_old.y" /* yacc.c:1646  */
    {
                            
                            int found; 
                            //cout<<"Id_list called\n";
                            (yyval. node1) = new struct allAttributes;
                            (yyval. node1)->listOfVar.push_back((yyvsp[0]. node1)->name);  //in patch list
                            
                            struct varParListEntry rec;
                            findEntry((yyvsp[0]. node1), &found, &rec);
                            if( found && ( (rec.scope == currentScope) || (rec.scope == 1 && currentScope == 2) ) )
                            {
                                
                                string tempError = string("variable already declared ") + (yyvsp[0]. node1)->name; 
                                yyerror ( (char *)(tempError.c_str()) );
                            }
                            else
                            {
                                if(activeFuncPtr == NULL)
                                {
                                    (yyvsp[0]. node1)->offset = currentOffset;
                                    if((yyvsp[0]. node1)->type=="simple")
                                    {
                                        currentOffset+=4;
                                        (yyval. node1)->code.push_back("addi $sp,$sp,-4");
                                    }
                                    else if((yyvsp[0]. node1)->type=="array")
                                    {
                                        int temp=1;
                                        for(int i=0;i<(yyvsp[0]. node1)->dimList.size();i++)
                                        {
                                            temp*=(yyvsp[0]. node1)->dimList[i];
                                            
                                        }
                                        temp*=4;
                                        currentOffset += temp;
                                        (yyval. node1)->code.push_back("addi $sp, $sp, "+ to_string(-1*currentOffset) );
                                    }
                                }
                                else
                                {
                                    (yyvsp[0]. node1)->offset = currentOffset;
                                    if((yyvsp[0]. node1)->type=="simple")
                                    {
                                        currentOffset+=4;
                                        (yyval. node1)->code.push_back("addi $sp,$sp,-4");
                                    }
                                    else if((yyvsp[0]. node1)->type=="array")
                                    {
                                        int temp=1;
                                        for(int i=0;i<(yyvsp[0]. node1)->dimList.size();i++)
                                        {
                                            temp*=(yyvsp[0]. node1)->dimList[i];
                                        }
                                        temp*=4;
                                        currentOffset += temp;
                                        (yyval. node1)->code.push_back("addi $sp, $sp, "+ to_string(-1*currentOffset) );
                                    }
                                }
                                insertSymTab((yyvsp[0]. node1));
                            }
                             printf("id_list : id_array\n"); 
                        }
#line 2883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1394 "b_old.y" /* yacc.c:1646  */
    {
                       //cout<<"ID called\n";
                       //cout << "ID name " << $1->name;
                        (yyval. node1) = new struct allAttributes;
                        //cout<<"after new\n";
                        (yyvsp[0]. node1)->type = string("simple");
                        (yyvsp[0]. node1)->scope = currentScope;
                        //$1->eleType = tempValues.eleType;
                        (yyval. node1)->name = (yyvsp[0]. node1)->name;
                        (yyval. node1)->type = string("simple");
                        (yyval. node1)->scope = currentScope;
                        //$$->eleType = tempValues.eleType;
                        int success;
                        struct varParListEntry temp;
                        findEntry((yyvsp[0]. node1), &success, &temp);
                        (yyvsp[0]. node1)->eleType = temp.eleType;
                        printf("id_array : ID\n");  
                    }
#line 2906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1414 "b_old.y" /* yacc.c:1646  */
    {
                       
                        (yyvsp[0]. node1)->type = string("array");
                        (yyvsp[0]. node1)->scope = currentScope;
                        //$1->eleType = tempValues.eleType;
                        
                    }
#line 2918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1421 "b_old.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-4]. node1)->dimList = (yyvsp[-1].node1)->dimList;
                                    (yyval. node1) = new struct allAttributes;
                                    (yyval. node1)->dimList = (yyvsp[-1].node1)->dimList; 
                                    (yyval. node1)->name = (yyvsp[-4]. node1)->name;
                                    (yyval. node1)->type = string("array");
                                    (yyval. node1)->scope = currentScope;
                                    
                                    //$$->eleType = tempValues.eleType; 
                                    printf("id_array : ID OSB DIMLIST CSB\n"); 
                
                                }
#line 2935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1439 "b_old.y" /* yacc.c:1646  */
    { (yyval.node1) = new struct allAttributes; 
                                            /*$$->code = $1->code;
                                            
                                            $$->code.push_back("li $t0, 4");
                                            $$->code.push_back("mult $t0 $a0");
                                            $$->code.push_back("mflo $a0");
                                            */
                                            
                                            
                                            
                                            
            
                                            (yyval.node1)->dimList.push_back((yyvsp[0]. node1)->val);  printf("DIMLIST : expr\n"); }
#line 2953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1452 "b_old.y" /* yacc.c:1646  */
    { 
            
                                            (yyval.node1) = new struct allAttributes; 
                                            
                                            /*$$->code = $1->code;
                                            
                                            $$->code.push_back("li $t0, 4");
                                            $$->code.push_back("mult $t0 $a0");
                                            $$->code.push_back("mflo $a0");
                                            */
                                            
                                            (yyvsp[0].node1)->dimList.push_back((yyvsp[-2]. node1)->val); 
                                            (yyval.node1)->dimList = (yyvsp[0].node1)->dimList;  printf("DIMLIST : expr COMMA DIMLIST\n"); }
#line 2971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1471 "b_old.y" /* yacc.c:1646  */
    { (yyval. node1) = new struct allAttributes; (yyval. node1)->eleType = string("int"); printf("datatype : INT\n"); }
#line 2977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1472 "b_old.y" /* yacc.c:1646  */
    { (yyval. node1) = new struct allAttributes; (yyval. node1)->eleType = string("bool"); printf("datatype : BOOL\n"); }
#line 2983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1473 "b_old.y" /* yacc.c:1646  */
    { (yyval. node1) = new struct allAttributes; (yyval. node1)->eleType = string("char"); printf("datatype : CHAR\n"); }
#line 2989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1480 "b_old.y" /* yacc.c:1646  */
    {  
                                        int success;
                                        (yyval. node1) = new allAttributes;
                                        struct globalTableEntry *rec;
                                        rec = searchFunc((yyvsp[-3]. node1), &success);
                                        if(success && rec->alreadyDefined==1)       // alreadyDefined =1 means it was defination .
                                        {
                                            if((yyvsp[-1]. node1)->parList.size() == rec->parList.size())
                                            {
                                                int i;
                                                for(i=0;i<(yyvsp[-1]. node1)->parList.size();i++)
                                                {
                                                    if( !coercible((yyvsp[-1]. node1)->parList[i].eleType, rec->parList[i].eleType) )
                                                    {
                                                        yyerror("arguments type mismatch");
                                                        (yyval. node1)->eleType = "error";
                                                        break;
                                                    }
                                                }
                                                if(i==(yyvsp[-1]. node1)->parList.size())
                                                {
                                                    (yyval. node1)->eleType = rec->eleType;     // return type
                                                    /*  code gen  */
                                                    (yyval. node1)->code.push_back("sw $fp 0($sp)");
                                                    (yyval. node1)->code.push_back("addi $sp $sp -4");
                                                    
                                                    
                                                   
                                                   (yyval. node1)->code.insert((yyval. node1)->code.end(), (yyvsp[-1]. node1)->code.begin(), (yyvsp[-1]. node1)->code.end());
                                                    (yyval. node1)->code.push_back("jal "+(yyvsp[-3]. node1)->name);
                                                    
                                                }
                                            }
                                            else{
                                                    yyerror("number of arguments mismatch");
                                                    (yyval. node1)->eleType = "error";
                                            }
                                        }
                                        else{
                                                yyerror("function not defined");
                                                (yyval. node1)->eleType = "error";
                                        }
                                        printf("func_call : ID LP opt_expr_list rp\n"); 
                                
                                    }
#line 3039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1529 "b_old.y" /* yacc.c:1646  */
    {  
                                        (yyval. node1) = new struct allAttributes;
                                        (yyval. node1)->parList = (yyvsp[0]. node1)->parList;
                                        (yyval. node1)->code = (yyvsp[0]. node1)->code;
                                        printf("opt_expr_list : expr_list\n"); 
        
                                    }
#line 3051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1536 "b_old.y" /* yacc.c:1646  */
    {
                                        (yyval. node1) = new struct allAttributes;
                                        printf("opt_expr_list : epsilon\n"); 
                        
                                    }
#line 3061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1545 "b_old.y" /* yacc.c:1646  */
    {  
                                        (yyval. node1) = new struct allAttributes;
                                        (yyval. node1)->parList = (yyvsp[0]. node1)->parList;
                                        struct varParListEntry temp;
                                        temp.eleType = (yyvsp[-2]. node1)->eleType;
                                        (yyval. node1)->parList.push_back(temp);
                                        /*  code gen  */
                                        (yyval. node1)->code = (yyvsp[0]. node1)->code;
                                        (yyval. node1)->code.insert((yyval. node1)->code.end(), (yyvsp[-2]. node1)->code.begin(), (yyvsp[-2]. node1)->code.end());
                                        
                                        (yyval. node1)->code.push_back("sw $a0 0($sp)");
                                        (yyval. node1)->code.push_back("addi $sp $sp -4");
                                        printf("expr_list : expr COMMA expr_list\n"); }
#line 3079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1558 "b_old.y" /* yacc.c:1646  */
    {  
                                        (yyval. node1) = new struct allAttributes;
                                        struct varParListEntry temp;
                                        temp.eleType = (yyvsp[0]. node1)->eleType;
                                        (yyval. node1)->parList.push_back(temp);
                                        (yyval. node1)->code =(yyvsp[0]. node1)->code;
                                        (yyval. node1)->code.push_back("sw $a0 0($sp)");
                                        (yyval. node1)->code.push_back("addi $sp $sp -4");
                                        printf("expr_list : expr\n"); }
#line 3093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1571 "b_old.y" /* yacc.c:1646  */
    {  printf("io : CIN gg ID\n"); }
#line 3099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1574 "b_old.y" /* yacc.c:1646  */
    {   printf("io : COUT ll expr\n"); }
#line 3105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1579 "b_old.y" /* yacc.c:1646  */
    {   printf("gg : GG\n"); }
#line 3111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1580 "b_old.y" /* yacc.c:1646  */
    {  yyerror("stream direction missing ");  }
#line 3117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1587 "b_old.y" /* yacc.c:1646  */
    {   printf("ll : LL\n"); }
#line 3123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1588 "b_old.y" /* yacc.c:1646  */
    {  yyerror("stream direction missing ");  }
#line 3129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1593 "b_old.y" /* yacc.c:1646  */
    {   printf("rp : RP\n"); }
#line 3135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1594 "b_old.y" /* yacc.c:1646  */
    {  yyerror("right parenthesis missing ");  }
#line 3141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1603 "b_old.y" /* yacc.c:1646  */
    {  printf("colon : COLON\n");  }
#line 3147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1604 "b_old.y" /* yacc.c:1646  */
    {  yyerror("colon missing ");  }
#line 3153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1609 "b_old.y" /* yacc.c:1646  */
    {  printf("semi : SEMI\n");  }
#line 3159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1610 "b_old.y" /* yacc.c:1646  */
    {  yyerror("semicolon missing ");  }
#line 3165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1615 "b_old.y" /* yacc.c:1646  */
    {  printf("end : END\n");  }
#line 3171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1616 "b_old.y" /* yacc.c:1646  */
    {  yyerror("end missing ");  }
#line 3177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1622 "b_old.y" /* yacc.c:1646  */
    {  printf("do : DO\n");  }
#line 3183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1623 "b_old.y" /* yacc.c:1646  */
    {  yyerror("do missing ");  }
#line 3189 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3193 "y.tab.c" /* yacc.c:1646  */
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
#line 1653 "b_old.y" /* yacc.c:1906  */


void yyerror(char *s) 
{
    fprintf(stderr, "ERROR: %s at line no. %d\n", s, lineno );
}

struct globalTableEntry *searchFunc(struct allAttributes *entryOld, int *success)
{
    struct allAttributes entry = *entryOld;
    struct globalTableEntry *foundEntry = NULL; //initialize
    
    *success=0;
    for(int i=0; i<symTab.size(); i++)
    {
        if(symTab[i].type=="function")
        {
            if(symTab[i].name==entry.name)
            {
                *success=1;
                
                foundEntry=&symTab[i];
                return foundEntry;
            }
        }
    }
    return foundEntry;
}


// args -> entry to search, success, entry if found
void findEntry(struct allAttributes *entryOld, int *success, struct varParListEntry *foundEntryFinal)
{
    struct allAttributes entry = *entryOld;
    struct varParListEntry *foundEntry = NULL; // initialize
    *success=0;
    //cout << "find entry " << entry.name << "scope: "<<entry.scope <<endl;
    if(activeFuncPtr != NULL)
    {
        //traverse in varList
        for(int i=0; i<activeFuncPtr->varList.size(); i++)
        {
            if( activeFuncPtr->varList[i].name == entry.name && entry.scope >= activeFuncPtr->varList[i].scope )
            {
                if(foundEntry != NULL && foundEntry->scope < activeFuncPtr->varList[i].scope )
                {
                    foundEntry = &activeFuncPtr->varList[i]; 
                }
                else
                    foundEntry = &activeFuncPtr->varList[i]; 
            }
        }
        if(foundEntry!=NULL)
        {
            *success =1;
            *foundEntryFinal = *foundEntry;
            //cout<<"entry found in varlist "<<endl;
            return;
        }
        //traverse in parList
        for(int i=0; i<activeFuncPtr->parList.size(); i++)
        {
            if(activeFuncPtr->parList[i].name==entry.name)
            {
                *success=1;
                foundEntry = &activeFuncPtr->parList[i];
                *foundEntryFinal = *foundEntry;
                //cout << "entry found in paramList\n";
                return;
            }
        }
        
    }
    // search global variable
    //cout << "now search in global table\n";
    for(int i=0; i<symTab.size(); i++)
    {
        if(symTab[i].type != "function")
        {
            //cout << "entry is not func\n";
            if(symTab[i].name == entry.name && symTab[i].scope <= entry.scope )
            {
                if(foundEntry == NULL || (symTab[i].scope  > foundEntry->scope)  )
                {
                    //cout << "names match\n";
                    *success=1;
                    foundEntryFinal->name=symTab[i].name;
                    foundEntryFinal->type=symTab[i].type;
                    foundEntryFinal->eleType=symTab[i].eleType;
                    foundEntryFinal->scope=symTab[i].scope;
                    foundEntryFinal->dimList=symTab[i].dimList;
                    foundEntryFinal->offset = symTab[i].offset;
                    //cout<<"entry found in global"<<endl;
                }
                
            }
        }
    }
    return;
    //cout<<"entry not found"<<endl;
    
}

void compatibleArithOp(struct allAttributes *entry1Old, struct allAttributes *entry2Old, int *success)
{
    *success = 0;
    if(entry1Old->eleType == "error" || entry2Old->eleType == "error")
        return;
    if(entry1Old->eleType == "bool" && entry2Old->eleType == "char")
        return;
    if(entry1Old->eleType == "char" && entry2Old->eleType == "bool")
        return;
    *success=1; 
    return;
}

// to insert par and val
void insertSymTab(struct allAttributes *entryOld)
{
    struct allAttributes entry = *entryOld;
    //cout<<"inserting entry "<< entry.name<<" in symbol table"<<endl;
    
    if(activeFuncPtr == NULL) // insert global var
    {
        struct globalTableEntry newEntry;
        newEntry.name= entry.name;
        newEntry.type = entry.type;
        newEntry.eleType = entry.eleType;
        newEntry.scope = entry.scope;
        newEntry.dimList = entry.dimList;
        newEntry.offset = entry.offset;
        symTab.push_back(newEntry);
        
        //cout<<"entry inserted "<<endl;
        return;
    }   
    struct varParListEntry newEntry;
    
    newEntry.name = entry.name;
    newEntry.type = entry.type;
    newEntry.eleType = entry.eleType;
    newEntry.scope = entry.scope;
    newEntry.dimList = entry.dimList;
    newEntry.offset = entry.offset;
    
    if(entry.scope == 1)
        activeFuncPtr->parList.push_back(newEntry);
    else
        activeFuncPtr->varList.push_back(newEntry);
    //cout<<"entry inserted "<<endl;
}


void patch(vector <string> &entry, string eleType)
{
    if(activeFuncPtr==NULL)
    {
        //check in globalTableEntry
        
        for(int i=0; i<symTab.size();i++)
        {
            for(int j=0;j<entry.size();j++)
            {
                if(symTab[i].name == entry[j])
                {
                    symTab[i].eleType = eleType;
                    break;
                }
            }
        }
    }
    else
    {
        //check in varList of func
        for(int i=0; i<activeFuncPtr->varList.size(); i++)
        {
            for(int j=0; j<entry.size(); j++)
            {
                if(entry[j]==activeFuncPtr->varList[i].name)
                {
                    activeFuncPtr->varList[i].eleType=eleType;
                    break;
                }
            }
        }
        
    }
}

//takes arg as two datatypes and checks if one can be assigned to other
bool coercible(string s1, string s2)
{
    if(s1 == "error" || s2 == "error")
        return 0;
    if((s1 == "bool" && s2 == "char") || (s1 == "char" && s2 == "bool"))
        return 0;
    return 1;
}

//insert funcEntry in the global table
void insertFunc(struct allAttributes *funcEntry1)
{
    struct allAttributes funcEntry =*funcEntry1;
    
    struct globalTableEntry finalFuncEntry;
    
    finalFuncEntry.name = funcEntry.name;
    finalFuncEntry.type = funcEntry.type;
    finalFuncEntry.eleType = funcEntry.eleType;
    finalFuncEntry.scope = 1;
    finalFuncEntry.alreadyDefined = funcEntry.alreadyDefined;
    
    finalFuncEntry.parList = funcEntry.parList;
    symTab.push_back(finalFuncEntry);
}

int main(void) {

    activeFuncPtr = NULL;
    currentOffset=0;
    callFuncPtr = NULL;
    currentScope = 0;
    //tempValues.eleType = "int";
    fp = fopen("codegen.txt", "w+");
    
    fp2 = fopen("symbolTable.txt", "w+");
    fprintf(fp, "main:\n");
    fprintf(fp, "li $sp, 2147479548\n");
    fprintf(fp, "move $fp, $sp\n");
    yyparse();
    fprintf(fp, "li $v0, 10\nsyscall\n");
    
    
    
    /*
    
     struct globalTableEntry
    {
        string name;
        string type;
        string eleType;
        int scope=0;
        vector <struct varParListEntry> parList;
        vector <struct varParListEntry> varList;
        vector <int> dimList;
        int alreadyDefined;
        int offset;
    
    
    */
    
    
    for(int i=0; i<symTab.size(); i++)
    {
        fprintf(fp2, "Entry %d: ", i);
        fprintf(fp2, "   %s %s %s %d", symTab[i].name.c_str(), symTab[i].type.c_str(), symTab[i].eleType.c_str(), symTab[i].scope);
        if(symTab[i].parList.size()==0)
        {
            fprintf(fp2, " NULL ");
        }
        else
        {
            fprintf(fp2, "The parameters are:\n");
            for(int j=0; j<symTab[i].parList.size(); j++)
            {
                fprintf(fp2, "      %s ", symTab[i].parList[j].name.c_str());
            }
        }
        if(symTab[i].varList.size()==0)
        {
            fprintf(fp2, " NULL ");
        }
        else
        {
            fprintf(fp2, "The variables are:\n");
            for(int j=0; j<symTab[i].varList.size(); j++)
            {
                fprintf(fp2, "      %s ", symTab[i].varList[j].name.c_str());
            }
        }
        if(symTab[i].dimList.size()==0)
        {
            fprintf(fp2, " NULL ");
        }
        else
        {
            fprintf(fp2, "The dimensions are:\n");
            for(int j=0; j<symTab[i].dimList.size(); j++)
            {
                fprintf(fp2, "      %d ", symTab[i].dimList[j]);
            }
        }
        fprintf(fp2, "\n");
    }
    
    
    fclose(fp2);
    fclose(fp);
    return 0;
    
    
    
}
