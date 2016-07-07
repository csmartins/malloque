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
#line 1 "trabalho.y" /* yacc.c:339  */

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <list>

using namespace std;

struct Type {
  string name;
  int s;  // array size when attribute is an array.
  int s2; // 
  
  Type() {}
  Type( string name ) {
    this->name = name;
    this->s = 0;
    this->s2 = 0;
  }
};

struct Attribute {
  string v;  // Value
  Type   t;  // type
  string c;  // code
  list<Attribute> l; // List of related attributes.
  string d;  // variable declaration
  
  Attribute() {}  // automatic inicialization to empty ""
  Attribute( string v, string t = "", string c = "" ) {
    this->v = v;
    this->t.name = t;
    this->c = c;
  }
};

struct Function {
    string name;
    Type returnType; // "void" for void
    list<Attribute> parameterList;
    
    Function() { }
    
    Function(string name, Type returnType, list<Attribute> parameterList) {
        this->name = name;
        this->returnType = returnType;
        this->parameterList = parameterList;
    }
    
    Function(const Function &f) {
        this->name = f.name;
        this->returnType = f.returnType;
        this->parameterList = f.parameterList;
    }
};

typedef map< string, Type > TS;
TS ts;
TS tsl;

typedef map<string, Function> TF;
TF tf;

string activePipe; 
string activePipeStep; 

const int MAX_STR = 256;

void error(string msg);

string toStr( int n );
int parseInt( string s );
string trimId(string id);

string generateTemp(Type type);
string generateLabel( string cmd );
string generateTempDeclaration();
void resetTempVariables();
void initOperatorResultTable();
Type resultType( Type a, string op, Type b );
string getFormatStringForType(const Type &t);

void generateBinaryOperatorCode( Attribute* SS, const Attribute& S1, const Attribute& S2, const Attribute& S3 );
void generateUnaryOperatorCode(Attribute* SS, const Attribute& S1, const Attribute& S2);

void generateIfCodeWithElse( Attribute* SS, const Attribute& expr, const Attribute& cmdThen, const Attribute& cmdElse );
void generateIfCodeWithoutElse( Attribute* SS, const Attribute& expr, const Attribute& cmdThen );
void generateForCode( Attribute* SS, const Attribute& initial, const Attribute& condition, const Attribute& step, Attribute& cmd );
void generateWhileCode( Attribute* SS, const Attribute& expr, Attribute& cmd);
void generateDoWhileCode( Attribute* SS, Attribute& cmd, const Attribute& expr);
void generateSwitchCode(Attribute* SS, const Attribute& expr , Attribute& cases, const Attribute& defaultCase);
void generateCaseCode(Attribute* SS, const Attribute& intCase, Attribute& caseCode);
void generateFunctionCallWithParametersCode(Attribute* SS, const Attribute& id, const Attribute& params);
void generateFunctionCallWithoutParametersCode(Attribute* SS, const Attribute& id);

void generateAssignmentCode( Attribute* SS, Attribute& lvalue, const Attribute& rvalue );
void generateOutputCode(Attribute *SS, const Attribute &exp);
void generateInputCode(Attribute *SS, const Attribute &id);

void generateArrayCode(Attribute *SS, const Attribute& arrSize);
void generateBidimensionalArrayCode(Attribute *SS, const Attribute& arrSize1, const Attribute& arrSize2);

void insertVarTS( TS&, string nameVar, Type type );
bool searchVarTS( TS&, string nameVar, Type* type );
bool searchVar( string nameVar, Type* type );

void insertFuncTF(TF&, Function *f);
bool searchFuncTF(TF&, string nameFunc, Function* function);

void generateFunctionHeader(Attribute *SS,
                                 const Attribute& type,
                                 const Attribute& id,
                                 const Attribute& paramDecList);

void generateVarDeclaration( Attribute* SS, const Attribute& type, const Attribute& id );
void generateFunctionDeclaration(Attribute *SS,
                                 const Attribute& header,
                                 const Attribute& cmd);

void resetTempParameterList();
void addParamToParameterList(Attribute* SS, const Attribute& type, const Attribute& id);

void replaceBreakLabel(Attribute& block, string realLabel);

void generatePipeCode(Attribute* SS, const Attribute& start, const Attribute& end, const Attribute& pipes, const Attribute& consume);
void generateArrayPipeCode(Attribute* SS, const Attribute& id, const Attribute& pipes, const Attribute& consume);
void generateFilterCode( Attribute* SS, const Attribute& cond );
void generateFirstNCode( Attribute* SS, const Attribute& cond );

#define YYSTYPE Attribute

int yylex();
int yyparse();
void yyerror(const char *);

#line 204 "y.tab.c" /* yacc.c:339  */

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
    _CTE_INT = 258,
    _CTE_CHAR = 259,
    _CTE_DOUBLE = 260,
    _CTE_FLOAT = 261,
    _CTE_BOOL = 262,
    _CTE_STRING = 263,
    _ID = 264,
    _IF = 265,
    _THEN = 266,
    _ELSE = 267,
    _RETURN = 268,
    _FOR = 269,
    _WHILE = 270,
    _DO = 271,
    _SWITCH = 272,
    _CASE = 273,
    _DEFAULT = 274,
    _BREAK = 275,
    _FILTER = 276,
    _FIRST_N = 277,
    _FOR_EACH = 278,
    _LAST_N = 279,
    _SORT = 280,
    _RANGE = 281,
    _2PTS = 282,
    _PIPE = 283,
    _X = 284,
    _INT = 285,
    _CHAR = 286,
    _BOOL = 287,
    _DOUBLE = 288,
    _FLOAT = 289,
    _STRING = 290,
    _CMD_OUT = 291,
    _CMD_IN = 292,
    _CMD_VAR = 293,
    _FUNCTION = 294,
    _BEGIN = 295,
    _END = 296,
    _OPR_ATR = 297,
    _OPR_NOT = 298,
    _OPR_LESS_EQUAL = 299,
    _OPR_GREATER_EQUAL = 300,
    _OPR_COMP = 301,
    _OPR_AND = 302,
    _OPR_OR = 303,
    _OPR_DIF = 304
  };
#endif
/* Tokens.  */
#define _CTE_INT 258
#define _CTE_CHAR 259
#define _CTE_DOUBLE 260
#define _CTE_FLOAT 261
#define _CTE_BOOL 262
#define _CTE_STRING 263
#define _ID 264
#define _IF 265
#define _THEN 266
#define _ELSE 267
#define _RETURN 268
#define _FOR 269
#define _WHILE 270
#define _DO 271
#define _SWITCH 272
#define _CASE 273
#define _DEFAULT 274
#define _BREAK 275
#define _FILTER 276
#define _FIRST_N 277
#define _FOR_EACH 278
#define _LAST_N 279
#define _SORT 280
#define _RANGE 281
#define _2PTS 282
#define _PIPE 283
#define _X 284
#define _INT 285
#define _CHAR 286
#define _BOOL 287
#define _DOUBLE 288
#define _FLOAT 289
#define _STRING 290
#define _CMD_OUT 291
#define _CMD_IN 292
#define _CMD_VAR 293
#define _FUNCTION 294
#define _BEGIN 295
#define _END 296
#define _OPR_ATR 297
#define _OPR_NOT 298
#define _OPR_LESS_EQUAL 299
#define _OPR_GREATER_EQUAL 300
#define _OPR_COMP 301
#define _OPR_AND 302
#define _OPR_OR 303
#define _OPR_DIF 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 350 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   530

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    56,     2,     2,
      60,    61,    54,    52,    62,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,    57,
      50,     2,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,    64,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   152,   152,   158,   163,   168,   170,   173,   174,   175,
     176,   177,   178,   181,   185,   198,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   231,   232,   242,   253,   256,   259,   262,   265,   268,
     272,   275,   278,   283,   292,   293,   296,   297,   298,   299,
     302,   305,   312,   315,   318,   321,   324,   327,   328,   331,
     336,   343,   348,   356,   362,   363,   366,   371,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   395,   396,   399,   402,   408,   416,   421,
     424,   428,   433,   436,   441,   442,   445,   449,   452,   455,
     458,   461,   462,   465,   468,   471,   474,   477,   478,   481,
     484,   485
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_CTE_INT", "_CTE_CHAR", "_CTE_DOUBLE",
  "_CTE_FLOAT", "_CTE_BOOL", "_CTE_STRING", "_ID", "_IF", "_THEN", "_ELSE",
  "_RETURN", "_FOR", "_WHILE", "_DO", "_SWITCH", "_CASE", "_DEFAULT",
  "_BREAK", "_FILTER", "_FIRST_N", "_FOR_EACH", "_LAST_N", "_SORT",
  "_RANGE", "_2PTS", "_PIPE", "_X", "_INT", "_CHAR", "_BOOL", "_DOUBLE",
  "_FLOAT", "_STRING", "_CMD_OUT", "_CMD_IN", "_CMD_VAR", "_FUNCTION",
  "_BEGIN", "_END", "_OPR_ATR", "_OPR_NOT", "_OPR_LESS_EQUAL",
  "_OPR_GREATER_EQUAL", "_OPR_COMP", "_OPR_AND", "_OPR_OR", "_OPR_DIF",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "'['", "']'",
  "'('", "')'", "','", "'{'", "'}'", "':'", "$accept", "S1", "S", "TYPE",
  "ID", "E", "F", "PIPE", "PIPE_ARRAY", "PIPES", "PIPE_FUNCTION",
  "CONSUME", "INIT_PIPE", "FILTER", "FOR_EACH", "FIRST_N", "LAST_N",
  "SORT", "FUNC", "PARAMS", "FUNC_HEADER", "FUNC_DECL", "PARAM_DEC_LIST",
  "PARAM_DEC", "C", "CMD", "RETURN", "VAR", "VAR_DEC", "VAR_GLOB",
  "VAR_GLOB_DEC", "ARR", "VAR_INIC", "ATR", "OUT", "IN", "IF", "WHILE",
  "DO_WHILE", "FOR", "SWITCH", "SWITCH_CASES", "CASE", "DEFAULT_CASE", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      60,    62,    43,    45,    42,    47,    37,    59,    91,    93,
      40,    41,    44,   123,   125,    58
};
# endif

#define YYPACT_NINF -158

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-158)))

#define YYTABLE_NINF -44

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-44)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,    64,    -1,     5,   -14,   -28,  -158,   -39,  -158,  -158,
    -158,  -158,  -158,  -158,    30,   -19,    36,  -158,  -158,   -35,
     244,  -158,    30,   -10,  -158,  -158,    64,    -6,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,   -18,    84,    84,     1,    84,
      39,    42,    48,    51,  -158,    84,   101,    64,   244,    84,
    -158,    84,    72,   420,  -158,    58,    88,  -158,   244,    53,
      61,   -13,    62,    65,    66,  -158,  -158,    67,  -158,  -158,
    -158,   118,   116,    69,    70,    64,    84,    77,   -44,  -158,
     261,   448,   101,   186,   244,    84,  -158,    84,   448,    68,
    -158,   119,    90,   461,   288,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,  -158,
    -158,    79,   110,  -158,  -158,  -158,  -158,   119,  -158,  -158,
    -158,  -158,    75,  -158,  -158,    64,    74,   324,  -158,   448,
      -2,   244,    72,    82,  -158,    99,   306,   275,   -22,  -158,
    -158,  -158,  -158,   448,   461,   461,   461,   474,   474,   461,
     461,   461,    -3,    -3,  -158,  -158,  -158,    85,    91,    94,
     100,    88,  -158,  -158,  -158,  -158,   102,  -158,  -158,  -158,
     104,   133,  -158,   105,  -158,    84,   136,    84,   142,   124,
      84,    84,  -158,    84,    84,    84,    84,  -158,   244,   156,
    -158,    84,   448,   244,   434,    84,   148,   448,   108,   448,
     340,   356,   372,   388,   111,   112,   404,  -158,   101,   448,
     166,    89,  -158,    88,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,   113,   107,   114,  -158,   134,   110,   244,   244,   244,
    -158,  -158,  -158,  -158,  -158
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     0,     5,     0,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     1,     3,     0,
      84,     6,     0,    92,    91,    93,    65,     0,     4,    34,
      37,    35,    36,    38,    39,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,    84,     0,
      82,     0,    33,     0,    30,     0,     0,    31,    84,     0,
       0,     0,     0,     0,     0,    74,    77,     0,    76,    75,
      90,     0,     0,     0,    64,    65,     0,     0,    13,    33,
       0,    85,     0,     0,    84,     0,    81,     0,    99,    13,
     100,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      80,    44,     0,    83,    63,    79,    70,     0,    71,    72,
      73,    78,     0,    67,    62,     0,     0,     0,    58,    60,
       0,     0,     0,     0,   103,     0,     0,     0,    97,    87,
      89,    68,    40,    98,    23,    24,    25,    27,    28,    26,
      21,    22,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,    46,    47,    48,    49,     0,    42,    50,    86,
      94,     0,    61,    14,    57,     0,   101,     0,     0,     0,
       0,     0,    88,     0,     0,     0,     0,    45,    84,     0,
      66,     0,    59,     0,     0,     0,     0,    51,     0,    96,
       0,     0,     0,     0,     0,     0,     0,   102,     0,   104,
       0,   111,   107,     0,    52,    54,    55,    56,    53,    95,
      15,     0,     0,     0,   108,     0,     0,     0,    84,    84,
     106,    41,   105,   109,   110
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,  -158,    11,   -20,   -30,  -158,  -158,  -158,  -157,
    -158,   -50,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,   173,   103,  -158,   -81,   -47,  -158,  -158,    63,   179,
     162,   -74,  -158,   -79,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,   -26,  -158
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    72,    79,    53,    54,    55,    56,   112,
     161,   167,   198,   162,   168,   163,   164,   165,    57,   130,
       5,     6,    73,    74,    58,    59,    60,    61,   139,     7,
      24,    25,   182,    62,    63,    64,    65,    66,    67,    68,
      69,   211,   212,   225
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    92,   134,   133,   187,    17,    80,    81,    15,    83,
     -43,   113,    14,    16,    76,    88,    77,   140,    21,    93,
     181,    94,    28,    22,     1,     2,    90,    22,    52,     8,
       9,    10,    11,    12,    13,    20,    71,   135,    52,    23,
      76,    26,    77,   140,   116,    27,   127,   129,    71,   117,
     176,   106,   107,   108,    75,   136,   226,   137,    91,   174,
     175,    82,   132,    52,    52,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    84,
      29,    30,    31,    32,    33,    34,    78,    29,    30,    31,
      32,    33,    34,    78,     8,     9,    10,    11,    12,    13,
     157,   158,    85,   159,   160,    86,    44,   210,   223,    87,
      89,    52,   207,    44,    95,   110,   111,   114,   115,   118,
      49,   122,   119,   120,   121,   123,    76,    49,   138,   221,
     124,   141,   125,   166,   170,   172,   171,    51,   128,   177,
     178,   204,   190,   183,    51,   192,   232,   194,   193,   184,
     197,   199,   185,   200,   201,   202,   203,   195,   186,   205,
     188,   206,   189,   191,   196,   209,   210,   213,    52,   222,
     218,   219,   228,    52,   227,   230,   231,    18,   126,   229,
     169,   233,   234,    19,    70,   224,     0,     0,   132,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,    37,
      38,    39,    40,    41,     0,     0,    42,    52,    52,    52,
       0,     0,    43,     0,     0,    44,     0,     0,     0,     0,
       0,     0,    45,    46,    47,     0,    48,     0,     0,    49,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    50,     0,     0,    51,    29,    30,    31,
      32,    33,    34,    35,    36,     0,     0,    37,    38,    39,
      40,    41,     0,     0,    42,     0,     0,     0,     0,     0,
      43,     0,   131,    44,     0,     0,     0,     0,     0,     0,
      45,    46,    47,     0,    48,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,   180,     0,    51,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,     0,   142,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,     0,   179,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,   173,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   214,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,   215,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,   216,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,   217,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,   220,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   208,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   -44,   -44,   -44,     0,     0,
     -44,   -44,   -44,   104,   105,   106,   107,   108,    96,    97,
      98,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108
};

static const yytype_int16 yycheck[] =
{
      20,    48,    83,    82,   161,     0,    36,    37,     9,    39,
      28,    58,     1,     2,    58,    45,    60,    91,    57,    49,
      42,    51,    57,    62,    38,    39,    46,    62,    48,    30,
      31,    32,    33,    34,    35,    63,    58,    84,    58,     9,
      58,    60,    60,   117,    57,     9,    76,    77,    58,    62,
     131,    54,    55,    56,    60,    85,   213,    87,    47,    61,
      62,    60,    82,    83,    84,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    40,
       3,     4,     5,     6,     7,     8,     9,     3,     4,     5,
       6,     7,     8,     9,    30,    31,    32,    33,    34,    35,
      21,    22,    60,    24,    25,    57,    29,    18,    19,    58,
       9,   131,   193,    29,    42,    57,    28,    64,    57,    57,
      43,     3,    57,    57,    57,     9,    58,    43,     9,   208,
      61,    41,    62,    23,    59,    61,   125,    60,    61,    57,
      41,   188,     9,    58,    60,   175,   227,   177,    12,    58,
     180,   181,    58,   183,   184,   185,   186,    15,    58,     3,
      58,   191,    58,    58,    40,   195,    18,    59,   188,     3,
      59,    59,    65,   193,    61,    41,   226,     4,    75,    65,
     117,   228,   229,     4,    22,   211,    -1,    -1,   208,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    20,   227,   228,   229,
      -1,    -1,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    15,
      16,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    11,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    27,    -1,    60,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    59,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    59,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    59,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    59,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    59,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    59,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    44,    45,    46,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    44,    45,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,    67,    68,    86,    87,    95,    30,    31,
      32,    33,    34,    35,    69,     9,    69,     0,    87,    95,
      63,    57,    62,     9,    96,    97,    60,     9,    57,     3,
       4,     5,     6,     7,     8,     9,    10,    13,    14,    15,
      16,    17,    20,    26,    29,    36,    37,    38,    40,    43,
      57,    60,    70,    71,    72,    73,    74,    84,    90,    91,
      92,    93,    99,   100,   101,   102,   103,   104,   105,   106,
      96,    58,    69,    88,    89,    60,    58,    60,     9,    70,
      71,    71,    60,    71,    40,    60,    57,    58,    71,     9,
      70,    69,    91,    71,    71,    42,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      57,    28,    75,    91,    64,    57,    57,    62,    57,    57,
      57,    57,     3,     9,    61,    62,    88,    71,    61,    71,
      85,    11,    70,    99,    90,    91,    71,    71,     9,    94,
      97,    41,    61,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    21,    22,    24,
      25,    76,    79,    81,    82,    83,    23,    77,    80,    94,
      59,    69,    61,    59,    61,    62,    90,    57,    41,    61,
      27,    42,    98,    58,    58,    58,    58,    75,    58,    58,
       9,    58,    71,    12,    71,    15,    40,    71,    78,    71,
      71,    71,    71,    71,    91,     3,    71,    90,    57,    71,
      18,   107,   108,    59,    59,    59,    59,    59,    59,    59,
      59,    99,     3,    19,   108,   109,    75,    61,    65,    65,
      41,    77,    90,    91,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    74,    75,    75,    76,    76,    76,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    84,    85,
      85,    86,    86,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    97,    97,    98,    98,    99,   100,
     101,   102,   102,   103,   104,   105,   106,   107,   107,   108,
     109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     7,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     8,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     3,     3,
       1,     6,     5,     4,     1,     0,     4,     2,     3,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     2,     0,     2,     3,     3,     2,     1,
       3,     3,     1,     1,     4,     7,     2,     0,     3,     2,
       2,     4,     6,     3,     6,     9,     8,     1,     2,     4,
       3,     0
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
#line 152 "trabalho.y" /* yacc.c:1646  */
    { cout << "#include <stdio.h>\n"
               "#include <stdlib.h>\n"
               "#include <string.h>\n\n"
            << (yyvsp[0]).d << (yyvsp[0]).c << endl << "int main() {\nprincipal();\nreturn 0;\n}"; }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 158 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute();
                  (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; 
                  (yyval).d = (yyvsp[-1]).d;
                }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 163 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute();
                     (yyval).c = (yyvsp[-2]).c; 
                     (yyval).d = (yyvsp[-2]).d + (yyvsp[-1]).d;
                   }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 168 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 170 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 181 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute();
           (yyval).v = (yyvsp[0]).v;
           searchVar((yyvsp[0]).v, &((yyval).t));
         }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 185 "trabalho.y" /* yacc.c:1646  */
    { Type idType;
                     searchVar((yyvsp[-3]).v, &idType);
                     
                     if ((yyvsp[-1]).t.name == "int") {
                         (yyval) = Attribute();
                         (yyval).c = (yyvsp[-1]).c;
                         (yyval).t.name = idType.name;
                         (yyval).v = (yyvsp[-3]).v + "[" + (yyvsp[-1]).v + "]";
                     } else {
                         error("Tipo do indice do array " + (yyvsp[-3]).v + " deve ser um int. Tipo encontrado: " + (yyvsp[-1]).t.name);
                     }
                     
                   }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 198 "trabalho.y" /* yacc.c:1646  */
    { Type idType;
                               Type typeInt = Type("int");
                               Attribute indexTemp1 = generateTemp(typeInt);
                               Attribute indexTemp2 = generateTemp(typeInt);
                               
                               searchVar((yyvsp[-6]).v, &idType);
                               (yyval) = Attribute();
                               //cout << toStr(idType.s2) << endl;
                               (yyval).c = (yyvsp[-4]).c + (yyvsp[-1]).c +
                                      indexTemp1.v + " = " + toStr(idType.s2) + " * " + (yyvsp[-4]).v + ";\n" + 
                                      indexTemp2.v + " = " + indexTemp1.v + " + " + (yyvsp[-1]).v + ";\n";
                               (yyval).t.name = idType.name;
                               (yyval).v = (yyvsp[-6]).v + "[" + indexTemp2.v + "]";
                             }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 214 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 215 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 216 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 217 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 218 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 219 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 220 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 221 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 222 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 223 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 224 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 225 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 226 "trabalho.y" /* yacc.c:1646  */
    { generateBinaryOperatorCode( &(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 227 "trabalho.y" /* yacc.c:1646  */
    {generateUnaryOperatorCode(&(yyval), (yyvsp[-1]), (yyvsp[0]));}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 233 "trabalho.y" /* yacc.c:1646  */
    { if( activePipe != "" ){
        (yyval) = Attribute(); 
        (yyval).v = "x_" + activePipe;
        (yyval).t = Type(activePipe);
    }
      else
        error( "Variavel 'x' so pode ser usada dentro de pipe" );
      //cout << $$.c << " " << $$.t.name << " " << $$.v << endl;
    }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 243 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);
	    if ((yyval).v.find("[", 0) != string::npos) {
		    Type idType;
    		searchVar(trimId((yyval).v), &idType);
    		Attribute valueTemp = generateTemp(idType);
    
    		(yyval).c += valueTemp.v + " = " + (yyval).v + ";\n";
    		(yyval).v = valueTemp.v;
	    }
      }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 254 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Type( "int" ); }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 257 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Type( "double" ); }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 260 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Type( "float" ); }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 263 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Type( "char" ); }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 266 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Type( "bool" ); }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 269 "trabalho.y" /* yacc.c:1646  */
    {  (yyval).v = (yyvsp[0]).v; 
       (yyval).t = Type( "string" ); }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 272 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 275 "trabalho.y" /* yacc.c:1646  */
    {
                                                       generatePipeCode(&(yyval), (yyvsp[-5]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0]).c);
                                                       }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 278 "trabalho.y" /* yacc.c:1646  */
    {
                            generateArrayPipeCode(&(yyval), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
                         }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 284 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);
               Type idType;
               searchVar((yyvsp[0]).v, &idType);
               activePipe = idType.name;
               activePipeStep = generateLabel( "pipe" ); 
             }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 292 "trabalho.y" /* yacc.c:1646  */
    {(yyval) = Attribute();}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 293 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; (yyval).d = (yyvsp[-1]).d + (yyvsp[0]).d;}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 302 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 305 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);
                activePipe =  (yyvsp[0]).t.name;
                //cout << activePipe << endl;
	            activePipeStep = generateLabel( "pipe" ); 
              }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 312 "trabalho.y" /* yacc.c:1646  */
    { generateFilterCode( &(yyval), (yyvsp[-1]) );}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 315 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c; }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 318 "trabalho.y" /* yacc.c:1646  */
    {generateFirstNCode(&(yyval), (yyvsp[-1]));}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 327 "trabalho.y" /* yacc.c:1646  */
    { generateFunctionCallWithParametersCode(&(yyval), (yyvsp[-3]), (yyvsp[-1])); }
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 328 "trabalho.y" /* yacc.c:1646  */
    { generateFunctionCallWithoutParametersCode(&(yyval), (yyvsp[-2])); }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 332 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]);
              (yyval).c = (yyval).c + (yyvsp[0]).c;
              (yyval).l.push_back((yyvsp[0]));
            }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 337 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute();
              (yyval).c = (yyvsp[0]).c;
              (yyval).l.push_back((yyvsp[0]));
            }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 344 "trabalho.y" /* yacc.c:1646  */
    {
                    generateFunctionHeader(&(yyval), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]));
                }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 349 "trabalho.y" /* yacc.c:1646  */
    {
                    Attribute v = Attribute();
                    v.t.name = "void";
                    generateFunctionHeader(&(yyval), v, (yyvsp[-3]), (yyvsp[-1]));
                }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 357 "trabalho.y" /* yacc.c:1646  */
    {
                    generateFunctionDeclaration(&(yyval), (yyvsp[-3]), (yyvsp[-1]));
                }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 362 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 363 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute(); }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 367 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-3]);
                                    addParamToParameterList(&(yyval), (yyvsp[-1]), (yyvsp[0]));
                                    (yyval).v += ", " + (yyvsp[-1]).t.name + " " + (yyvsp[0]).v;
                                  }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 372 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute();
                      addParamToParameterList(&(yyval), (yyvsp[-1]), (yyvsp[0]));
                      (yyval).v = (yyvsp[-1]).t.name + " " + (yyvsp[0]).v;
                    }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 378 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute(); (yyval).c = (yyvsp[-1]).c; (yyval).d = (yyvsp[-1]).d; }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 379 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + (yyvsp[-1]).v + ";\n" ; }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 391 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute(); (yyval).c = "goto BREAK_LABEL;\n"; }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 395 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute(); (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; (yyval).d = (yyvsp[-1]).d + (yyvsp[0]).d; }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 396 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute(); }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 399 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute(); (yyval).c = (yyvsp[0]).c + "return " + (yyvsp[0]).v + ";"; }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 402 "trabalho.y" /* yacc.c:1646  */
    { (yyvsp[0]).t.name = (yyvsp[-2]).t.name;
                        insertVarTS(tsl, trimId((yyvsp[0]).v), (yyvsp[0]).t);
                        generateVarDeclaration(&(yyval), (yyvsp[-2]), (yyvsp[0]));
                        (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c;
                      }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 408 "trabalho.y" /* yacc.c:1646  */
    { (yyvsp[0]).t.name = (yyvsp[-1]).t.name;
                              insertVarTS(tsl, trimId((yyvsp[0]).v), (yyvsp[0]).t);
                              generateVarDeclaration(&(yyval), (yyvsp[-1]), (yyvsp[0]));
                              (yyval).t = (yyvsp[-1]).t;
                              (yyval).c = (yyvsp[0]).c;
                            }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 416 "trabalho.y" /* yacc.c:1646  */
    {(yyval) = Attribute();
                        (yyval).v = (yyvsp[-1]).v;
                        if((yyvsp[0]).v != "")
                            (yyval).c = (yyvsp[0]).c + (yyvsp[-1]).v + " = " + (yyvsp[0]).v + ";\n";
                        }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 424 "trabalho.y" /* yacc.c:1646  */
    { insertVarTS(ts, (yyvsp[0]).v, (yyvsp[-2]).t);
                                       generateVarDeclaration(&(yyval), (yyvsp[-2]), (yyvsp[0]));
                                     }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 428 "trabalho.y" /* yacc.c:1646  */
    { insertVarTS(ts, (yyvsp[0]).v, (yyvsp[-1]).t);
                                   generateVarDeclaration(&(yyval), (yyvsp[-1]), (yyvsp[0]));
                                 }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 433 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute();
                     (yyval).v = (yyvsp[0]).v;
                    }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 436 "trabalho.y" /* yacc.c:1646  */
    {(yyval) = Attribute();
                    (yyval).v = (yyvsp[0]).v;
                    }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 441 "trabalho.y" /* yacc.c:1646  */
    {generateArrayCode(&(yyval), (yyvsp[-1]));}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 442 "trabalho.y" /* yacc.c:1646  */
    { generateBidimensionalArrayCode(&(yyval), (yyvsp[-4]), (yyvsp[-1])); }
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 445 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute();
                        (yyval).v = (yyvsp[0]).v;
                        (yyval).c = (yyvsp[0]).c;
                      }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 449 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Attribute(); }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 452 "trabalho.y" /* yacc.c:1646  */
    { generateAssignmentCode( &(yyval), (yyvsp[-2]), (yyvsp[0]) ); }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 455 "trabalho.y" /* yacc.c:1646  */
    { generateOutputCode(&(yyval), (yyvsp[0]));}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 458 "trabalho.y" /* yacc.c:1646  */
    { generateInputCode(&(yyval), (yyvsp[0])); }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 461 "trabalho.y" /* yacc.c:1646  */
    { generateIfCodeWithoutElse( &(yyval), (yyvsp[-2]), (yyvsp[0]) ); }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 462 "trabalho.y" /* yacc.c:1646  */
    { generateIfCodeWithElse( &(yyval), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]) ); }
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 465 "trabalho.y" /* yacc.c:1646  */
    { generateWhileCode(&(yyval), (yyvsp[-1]), (yyvsp[0])); }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 468 "trabalho.y" /* yacc.c:1646  */
    { generateDoWhileCode( &(yyval), (yyvsp[-3]), (yyvsp[0]) ); }
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 471 "trabalho.y" /* yacc.c:1646  */
    { generateForCode(&(yyval), (yyvsp[-6]), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 474 "trabalho.y" /* yacc.c:1646  */
    {generateSwitchCode(&(yyval), (yyvsp[-5]) , (yyvsp[-2]), (yyvsp[-1]));}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 477 "trabalho.y" /* yacc.c:1646  */
    {(yyval).l.push_front((yyvsp[0])); (yyval).c = (yyvsp[0]).c;}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 478 "trabalho.y" /* yacc.c:1646  */
    { (yyval).l.push_front((yyvsp[0])); (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c;}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 481 "trabalho.y" /* yacc.c:1646  */
    {generateCaseCode(&(yyval), (yyvsp[-2]), (yyvsp[0]));}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 484 "trabalho.y" /* yacc.c:1646  */
    {(yyval).c = (yyvsp[0]).c;}
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2263 "y.tab.c" /* yacc.c:1646  */
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
#line 488 "trabalho.y" /* yacc.c:1906  */

int nline = 1;

map<string,int> n_var_temp;
map<string,Type> operatorResult;
map<string,int> label;

#include "lex.yy.c"

int yyparse();

string toStr( int n ) {
  char buf[1024] = "";
  
  sprintf( buf, "%d", n );
  
  return buf;
}

int parseInt( string s ) {
  int buf;
  
  sscanf( s.c_str() , "%d", &buf );
  
  return buf;
}

string trimId(string id) {
    int bracketPos = id.find_first_of("[");
    
    if (bracketPos == string::npos)
        return id;
    else
        return id.substr(0, bracketPos);
}


string generateLabel( string cmd ) {
  return "L_" + cmd +"_" + toStr( ++label[cmd] );
}

void yyerror( const char* st )
{
  puts( st );
    printf( "Linha: %d\nPerto de: '%s'\n", nline, yytext );
}

void error(string msg) {
    yyerror(msg.c_str());
}

void initOperatorResultTable() {
  operatorResult["string+string"] = Type( "string" );
  operatorResult["string+int"] = Type( "string" );
  
  operatorResult["int+int"] = Type( "int" );
  operatorResult["int-int"] = Type( "int" );
  operatorResult["int*int"] = Type( "int" );
  operatorResult["int%int"] = Type( "int" );
  operatorResult["int/int"] = Type( "int" );
  
  operatorResult["double+double"] = Type( "double" );
  operatorResult["double-double"] = Type( "double" );
  operatorResult["double*double"] = Type( "double" );
  operatorResult["double/double"] = Type( "double" );
  
  operatorResult["float+float"] = Type( "float" );
  operatorResult["float-float"] = Type( "float" );
  operatorResult["float*float"] = Type( "float" );
  operatorResult["float/float"] = Type( "float" );
  
  operatorResult["int==int"] = Type( "bool" );
  operatorResult["char==char"] = Type("bool");
  operatorResult["string==string"] = Type("bool");
  operatorResult["float==float"] = Type("bool");
  operatorResult["double==double"] = Type("bool");
  operatorResult["bool==bool"] = Type("bool");
  
  operatorResult["int!=int"] = Type( "bool" );
  operatorResult["char!=char"] = Type("bool");
  operatorResult["string!=string"] = Type("bool");
  operatorResult["float!=float"] = Type("bool");
  operatorResult["double!=double"] = Type("bool");
  operatorResult["bool!=bool"] = Type("bool");
  
  operatorResult["int<int"] = Type( "bool" );
  operatorResult["int>int"] = Type( "bool" );
  operatorResult["int>=int"] = Type( "bool" );
  operatorResult["int<=int"] = Type( "bool" );
  
  operatorResult["double<double"] = Type( "bool" );
  operatorResult["double>double"] = Type( "bool" );
  operatorResult["double>=double"] = Type( "bool" );
  operatorResult["double<=double"] = Type( "bool" );
  
  operatorResult["float<float"] = Type( "bool" );
  operatorResult["float>float"] = Type( "bool" );
  operatorResult["float>=float"] = Type( "bool" );
  operatorResult["float<=float"] = Type( "bool" );
  
  operatorResult["bool&&bool"] = Type( "bool" );
  operatorResult["bool||bool"] = Type( "bool" );
  operatorResult["!bool"] = Type( "bool" );
  
  operatorResult["double+int"] = Type( "double" );
  operatorResult["int+double"] = Type( "double" );
  operatorResult["double-int"] = Type( "double" );
  operatorResult["int-double"] = Type( "double" );
  operatorResult["double*int"] = Type( "double" );
  operatorResult["int*double"] = Type( "double" );
  operatorResult["double/int"] = Type( "double" );
  operatorResult["int/double"] = Type( "double" );
  
  operatorResult["float+int"] = Type( "float" );
  operatorResult["int+float"] = Type( "float" );
  operatorResult["float-int"] = Type( "float" );
  operatorResult["int-float"] = Type( "float" );
  operatorResult["float*int"] = Type( "float" );
  operatorResult["int*float"] = Type( "float" );
  operatorResult["float/int"] = Type( "float" );
  operatorResult["int/float"] = Type( "float" );
  
  operatorResult["double+float"] = Type( "double" );
  operatorResult["float+double"] = Type( "double" );
  operatorResult["double-float"] = Type( "double" );
  operatorResult["float-double"] = Type( "double" );
  operatorResult["double*float"] = Type( "double" );
  operatorResult["float*double"] = Type( "double" );
  operatorResult["double/float"] = Type( "double" );
  operatorResult["float/double"] = Type( "double" );
}

Type resultType( Type a, string op, Type b ) {
  if( operatorResult.find( a.name + op + b.name ) == operatorResult.end() )
    error( "Operacao nao permitida: " + a.name + op + b.name );

  return operatorResult[a.name + op + b.name];
}

string getFormatStringForType(const Type &t) {
    if (t.name == "int")
        return "%d";
    else if (t.name == "double")
        return "%lf";
    else if (t.name == "float")
        return "%f";
    else if (t.name == "char")
        return "%c";
    else if (t.name == "string")
        return "%s";
    else // bool
        return "%s";
}

string generateTempDeclaration() {
  string c;
  
  for( int i = 0; i < n_var_temp["bool"]; i++ )
    c += "  int temp_bool_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["int"]; i++ )
    c += "  int temp_int_" + toStr( i + 1 ) + ";\n";

    for( int i = 0; i < n_var_temp["char"]; i++ )
    c += "  char temp_char_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["double"]; i++ )
    c += "  double temp_double_" + toStr( i + 1 ) + ";\n";

    for( int i = 0; i < n_var_temp["float"]; i++ )
    c += "  float temp_float_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["string"]; i++ )
    c += "  char temp_string_" + toStr( i + 1 ) + "[" + toStr( MAX_STR )+ "];\n";
    
  return c;  
}

void resetTempVariables() {
  n_var_temp["bool"] = 0;
  n_var_temp["int"] = 0;
  n_var_temp["char"] = 0;
  n_var_temp["double"] = 0;
  n_var_temp["float"] = 0;
  n_var_temp["string"] = 0;
}

void generateVarDeclaration( Attribute* SS, const Attribute& type, const Attribute& id ) 
{
  SS->v = "";
  SS->t = type.t;
  if( type.t.name == "string" ) {
    SS->d = SS->d + "char " + id.v + "["+ toStr( MAX_STR ) +"];\n";   
  } else if ( type.t.name == "bool" ) {
    SS->d = SS->d + "int " + id.v + ";\n";
  } else {
    SS->d = SS->d + type.t.name + " " + id.v + ";\n";
  }
}

void generateArrayCode(Attribute *SS, const Attribute& arrSize)
{
    SS->v = SS->v + "[" + arrSize.v + "]";
    SS->t.s = parseInt(arrSize.v);
}

void generateBidimensionalArrayCode(Attribute *SS, const Attribute& arrSize1, const Attribute& arrSize2)
{
    int arrSize = parseInt(arrSize1.v) * parseInt(arrSize2.v);
    SS->v = SS->v + "[" + toStr(arrSize) + "]";
    SS->t.s = parseInt(arrSize1.v);
    SS->t.s2 = parseInt(arrSize2.v);
}

string generateTemp(Type type) {
  return "temp_" + type.name + "_" + toStr( ++n_var_temp[type.name] );
}

void generateUnaryOperatorCode(Attribute* SS, const Attribute& S1, const Attribute& S2){
    SS->t = Type("bool");
    SS->v = generateTemp(SS->t);
    
    if(S2.t.name == "bool")
    {
        SS->c = S2.c + SS->v + "=" + "!" + S2.v + ";\n";
        
    }
    else
        error("O operador '!' só pode ser usado com um bool. Tipo esperado: 'parada', encontrado: " + S2.t.name);
}

void generateBinaryOperatorCode( Attribute* SS, const Attribute& S1, const Attribute& S2, const Attribute& S3 ) {
  SS->t = resultType( S1.t, S2.v, S3.t );
  SS->v = generateTemp( SS->t );
  
  Attribute secondOperand = Attribute();
  secondOperand.v = S3.v;
  secondOperand.t = S3.t;
  
  string castCode;
  
  if (S1.t.name == "string" && S2.v == "+" && S3.t.name == "int") {
    secondOperand.v = generateTemp(S1.t);
    secondOperand.t = S1.t;
    castCode = "\nsprintf(" + secondOperand.v + ", \"%d\", " + S3.v + ");";
  }

  if( SS->t.name == "string" ) {
    // Falta o operador de comparação para string
    SS->c = S1.c + S3.c + castCode + 
            "\n  strncpy( " + SS->v + ", " + S1.v + ", " + 
                        toStr( MAX_STR - 1 ) + " );\n" +
            "  strncat( " + SS->v + ", " + secondOperand.v + ", " + 
                        toStr( MAX_STR - 1 ) + " );\n" +
            "  " + SS->v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n\n";    
  }
  else
    SS->c = S1.c + S3.c + castCode +
            "  " + SS->v + " = " + S1.v + " " + S2.v + " " + secondOperand.v + ";\n";
            
  SS->d = S1.v;
}

void insertVarTS(TS& ts, string nameVar, Type type) {
    if(!searchVarTS(ts, nameVar, &type))
        ts[nameVar] = type;
    else
        error("Variavel ja declarada: " + nameVar);
}

bool searchVarTS(TS& table, string nameVar, Type* type) {
    if(table.find(nameVar) != table.end()) {
        *type = table[nameVar];
        return true;
    }
    else
        return false;
}

bool searchVar(string nameVar, Type *type) {
    if (searchVarTS(tsl, nameVar, type))
        return true;
    else
        return searchVarTS(ts, nameVar, type);
}

void insertFuncTF(TF&, Function *f) {
    if(!searchFuncTF(tf, f->name, f))
        tf[f->name] = *f;
    else
        error("Funcao ja declarada: " + f->name);
}

bool searchFuncTF(TF&, string nameFunc, Function* func) {
    if(tf.find(nameFunc) != tf.end()) {
        *func = tf[nameFunc];
        return true;
    }
    else
        return false;
}

void addParamToParameterList(Attribute* SS, const Attribute& type, const Attribute& id) {
    Attribute param = Attribute();
    param.t = type.t;
    param.v = id.v;
    SS->l.push_front(param);
    
    insertVarTS(tsl, id.v, type.t);
}

void generateFunctionHeader(Attribute *SS,
                                 const Attribute& type,
                                 const Attribute& id,
                                 const Attribute& paramDecList) {
                                 
                    Function f = Function(id.v, type.t , paramDecList.l);
                    insertFuncTF(tf, &f);
                    
                    *SS = Attribute();
                    
                    string typeName;
                     if( type.t.name == "string" ) {
                        typeName = "char*";
                    } else {
                         typeName = type.t.name;
                    }
                    
                    SS->c = typeName + " " + id.v + "(" + paramDecList.v + ") ";
}

void generateFunctionDeclaration(Attribute *SS,
                                 const Attribute& header,
                                 const Attribute& cmd) {
                    *SS = Attribute();
                    
                    SS->c = header.c
                            + "{ \n"
                            + generateTempDeclaration()
                            + cmd.d
                            + cmd.c
                            + "\n}\n\n";
                            
                    tsl.clear();
                    resetTempVariables();
}

void generateIfCodeWithElse( Attribute* SS, const Attribute& expr, const Attribute& cmdThen, const Attribute& cmdElse ) {
  string ifTrue = generateLabel( "if_true" ),
         ifFalse = generateLabel( "if_false" ),
         ifEnd = generateLabel( "if_end" );
      
  *SS = Attribute();
  SS->c = expr.c + 
          "  if( " + expr.v + " ) goto " + ifTrue + ";\n" +
          "  goto " + ifFalse + ";\n" +
          "  " + ifTrue + ":\n" + cmdThen.c +
          "  goto " + ifEnd + ";\n" +
          "  " + ifFalse + ":\n" + cmdElse.c +
          "  " + ifEnd + ":;\n";
}

void generateIfCodeWithoutElse( Attribute* SS, const Attribute& expr, const Attribute& cmdThen ) {
  string ifTrue = generateLabel( "if_true" ),
         ifEnd = generateLabel( "if_end" );
      
  *SS = Attribute();
  SS->c = expr.c + 
          "  if( " + expr.v + " ) goto " + ifTrue + ";\n" +
          "  goto " + ifEnd + ";\n" + 
          "  " + ifTrue + ":\n" + 
          "    " + cmdThen.c +
          "  goto " + ifEnd + ";\n" +
          "  " + ifEnd + ":;\n";
    
}

void generateForCode( Attribute* SS, const Attribute& initial, const Attribute& condition, const Attribute& step, Attribute& cmd) {
  string forCond = generateLabel( "for_cond" ),
         forEnd = generateLabel( "for_end" );
  string valueNotCond = generateTemp( Type("bool"));
  
  replaceBreakLabel(cmd, forEnd);
  *SS = Attribute();
  
  if( condition.t.name != "bool" )
    error( "A expressão de teste deve ser booleana: " + condition.t.name ); 
  

  SS->c = initial.c + forCond + ":\n" + condition.c +
          "  " + valueNotCond + " = !" + condition.v + ";\n" +
          "  if( " + valueNotCond + " ) goto " + forEnd + ";\n" +
          cmd.c +
          step.c +
          "  goto " + forCond + ";\n" + 
          forEnd + ":;\n";
}

void generatePipeCode(Attribute* SS, const Attribute& start, const Attribute& end, const Attribute& pipes, const Attribute& consume){
    Type pipeType = Type(activePipe);
    
    Attribute initial, cond, step, cmd, varPipe;
    
    initial = Attribute(); 
    cond = Attribute(); 
    step = Attribute(); 
    cmd = Attribute();
    *SS = Attribute();
    varPipe = Attribute();
    
    varPipe.v = "x_" + activePipe;
    varPipe.t = pipeType;
    
    insertVarTS(tsl, varPipe.v, activePipe);

    generateVarDeclaration(&initial, varPipe, varPipe);
    initial.c = varPipe.v + " = " + start.v + ";\n";

    cond.t.name = "bool";
    cond.v = generateTemp(Type("bool"));
    cond.c = "  " + cond.v + " = " + "x_" + activePipe + " <= " + end.v + ";\n";
    
    step.c = activePipeStep + ":\n" + "  x_" + activePipe + " = x_" + activePipe + " + 1;\n";
    
    cmd.c = pipes.c + consume.v;
    
    generateForCode(SS, initial, cond, step, cmd);

    SS->d += initial.d;

    activePipe = "";
}

void generateFirstNCode( Attribute* SS, const Attribute& n ){
    Attribute initial, cond, step, cmd, var;
    
    *SS = Attribute();
    SS->v = generateTemp(Type("int"));
    
    initial = Attribute(); 
    cond = Attribute(); 
    step = Attribute(); 
    cmd = Attribute();
    var = Attribute();
    
    var.v = SS->v;
    var.t = Type("int");
    
    insertVarTS(tsl, SS->v, Type("int"));

    generateVarDeclaration(&initial, var, var);
    
    //cout << initial.d << endl;
    
    cond.t.name = "bool";
    cond.v = generateTemp(Type("bool"));
    cond.c = "  " + cond.v + " = " + SS->v + " <= " + n.v + ";\n";
    
    step.c = activePipeStep + ":\n" + "  " + SS->v + " = " + SS->v + " + 1;\n";
    
    generateForCode(SS, initial, cond, step, cmd);

    SS->d += initial.d;
}

void generateArrayPipeCode(Attribute* SS, const Attribute& id, const Attribute& pipes, const Attribute& consume) {
    Type pipeType = Type(activePipe);
    Type idType;
    searchVar(id.v, &idType);
    
    Attribute initial, cond, step, cmd, varPipe, arrayIndex;
    
    initial = Attribute(); 
    cond = Attribute(); 
    step = Attribute(); 
    cmd = Attribute();
    *SS = Attribute();
    varPipe = Attribute();
    arrayIndex = Attribute();
    
    varPipe.v = "x_" + activePipe;
    varPipe.t = pipeType;

    arrayIndex.v = "pipe_arrayIndex";
    arrayIndex.t = Type("int");
    
    insertVarTS(tsl, varPipe.v, activePipe);
    insertVarTS(tsl, arrayIndex.v, arrayIndex.t);

    generateVarDeclaration(&initial, varPipe, varPipe);
    generateVarDeclaration(&initial, arrayIndex, arrayIndex);

    initial.c = arrayIndex.v + " = 0;\n";

    cond.t.name = "bool";
    cond.v = generateTemp(Type("bool"));
    cond.c = "  " + cond.v + " = " + arrayIndex.v + " < " + toStr(idType.s) + ";\n";
    
    step.c = activePipeStep + ":\n" + arrayIndex.v + " = " + arrayIndex.v + " + 1;\n";
    
    cmd.c = varPipe.v + " = " + id.v + "[" + arrayIndex.v + "];\n" +
	    pipes.c + consume.c;
    
    generateForCode(SS, initial, cond, step, cmd);

    SS->d += initial.d;

    activePipe = "";
}



void generateFilterCode( Attribute* SS, const Attribute& cond ){
    *SS = Attribute();
    SS->v = generateTemp( Type( "bool" ) );
    
    SS->c = cond.c 
            + "  " 
            + SS->v 
            + " = !" 
            + cond.v 
            + ";\n" 
            + "  if( " + SS->v + " ) goto " 
            + activePipeStep 
            + ";\n";
    
    SS->d = cond.d;
}


void generateWhileCode( Attribute* SS, const Attribute& expr, Attribute& cmd) {
    string whileTest = generateLabel( "while_test" ),
           whileBody = generateLabel( "while_body" ),
           whileEnd = generateLabel( "while_end" );
    
    replaceBreakLabel(cmd, whileEnd);
    *SS = Attribute();
    
    SS->c = whileTest + ":\n" + expr.c + "if (" + expr.v + 
         ") goto " + whileBody + ";\ngoto " + whileEnd +
         ";\n" + whileBody + ":\n" + cmd.c + "goto " + whileTest +
         ";\n" + whileEnd + ":;\n";
}

void generateSwitchCode(Attribute* SS, const Attribute& expr , Attribute& cases, const Attribute& defaultCase)
{
    *SS = Attribute();
    string caseDefault = generateLabel("default");
    string fimSwitch = generateLabel("fimSwitch");

    replaceBreakLabel(cases, fimSwitch);
    
    for(list<Attribute>::const_iterator i = cases.l.begin(); i != cases.l.end(); i++)
    {
        SS->c = SS->c + "  if( " + expr.v + " == " + (i->c).substr(6, 1) + " ) goto " + (i->c).substr(0, 9) + ";\n";
    }
        SS->c = SS->c + "  goto " + caseDefault + ";\n";

    
    SS->c = SS->c + cases.c;
    
    SS->c = SS->c + caseDefault + ":\n" + "    "  + defaultCase.c; 
    
    SS->c = SS->c + fimSwitch + ":;\n";
}

void generateCaseCode(Attribute* SS, const Attribute& intCase, Attribute& caseCode)
{
    string labelCase = generateLabel( "case" + intCase.v );
    
    *SS = Attribute();
    
    SS->c = SS->c + labelCase + ":\n" + caseCode.c;
}

void generateDoWhileCode( Attribute* SS, Attribute& cmd, const Attribute& expr) {
    string doBody = generateLabel( "do_body" ),
           doEnd = generateLabel( "do_end" );
    
    replaceBreakLabel(cmd, doEnd);
    *SS = Attribute();
    
    SS->c = doBody + ":\n" + cmd.c + expr.c +
	    "if (" + expr.v + ") goto " + doBody + ";\n" +
	    "goto " + doEnd + ";\n";
}

void generateAssignmentCode( Attribute* SS, Attribute& lvalue, const Attribute& rvalue ) {
  Type lvalueType;
  string lvalueId = trimId(lvalue.v);
  
  if( searchVar( lvalueId, &lvalueType ) ) {
    if( lvalueType.name == rvalue.t.name ) {
      if( lvalueType.name == "string" ) {
        SS->c = lvalue.c + rvalue.c + 
                "  strncpy( " + lvalue.v + ", " + rvalue.v + ", " + 
                            toStr( MAX_STR - 1 ) + " );\n" +
                "  " + lvalue.v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n";
      } else {
        SS->c = lvalue.c + rvalue.c + 
                "  " + lvalue.v + " = " + rvalue.v + ";\n"; 
      }
    }
    else
      error( "Expressao " + rvalue.t.name + 
            " nao pode ser atribuida a variavel " +
            lvalue.t.name );
  } 
  else {
    error( "Variavel nao declarada: " + lvalueId );
  }
}

void generateOutputCode(Attribute *SS, const Attribute &exp) {
    *SS = Attribute();
    SS->c = exp.c + 
        "printf(\"" +
        getFormatStringForType(exp.t) +
        "\\n\", " +
        exp.v + 
        ");\n";
}

void generateInputCode(Attribute *SS, const Attribute &id) {
    *SS = Attribute();
    Type idType;
    
    if (searchVar( id.v, &idType)) {
        SS->c = "scanf(\"" +
            getFormatStringForType(idType) +
            "\", &" +
            id.v + 
            ");";
    } else {
        error("Variavel nao declarada: " + id.v);
    }
}

void generateFunctionCallWithParametersCode(Attribute* SS, const Attribute& id, const Attribute& params) {
    Function func;
    
    if (!searchFuncTF(tf, id.v, &func)) {
        error("Funcao nao declarada: " + id.v);
    }
       
    if (func.parameterList.size() != params.l.size()) {
        error( "Funcao " + id.v + " espera " + toStr(func.parameterList.size()) + " parametros e recebeu " + toStr(params.l.size()) );
    }
    
    list<Attribute>::const_iterator passedParam = params.l.begin();
    list<Attribute>::const_iterator expectedParam = func.parameterList.begin();
    int paramCount = 1;
    string paramListCode;
    
    while (passedParam != params.l.end()) {
        if (passedParam->t.name != expectedParam->t.name) {
            error("Tipo incompativel no parametro " + toStr(paramCount) +
                  " da funcao " + id.v + ": esperava " + expectedParam->t.name +
                  ", encontrou " + passedParam->t.name);
        }
        
        paramListCode += passedParam->v;
        if (paramCount < params.l.size()) paramListCode += ", ";
        
        SS->c += passedParam->c;
        
        passedParam++;
        expectedParam++;
        paramCount++;
    }
    
    SS->t = func.returnType;
    SS->v = id.v + "(" + paramListCode + ")";
}

void generateFunctionCallWithoutParametersCode(Attribute* SS, const Attribute& id) {
    Function func;
    
    if (!searchFuncTF(tf, id.v, &func)) {
        error("Funcao nao declarada: " + id.v);
    }
       
    if (func.parameterList.size() != 0) {
        error( "Funcao " + id.v + " espera " + toStr(func.parameterList.size()) + " parametros e recebeu 0" );
    }
    
    SS->t = func.returnType;
    SS->v = id.v + "()";
}

void replaceAll(string& str, const string& oldStr, const string& newStr) {
  size_t pos = 0;
  while((pos = str.find(oldStr, pos)) != string::npos) {
     str.replace(pos, oldStr.length(), newStr);
     pos += newStr.length();
  }
}

void replaceBreakLabel(Attribute& block, string realLabel) {
	replaceAll(block.c, "BREAK_LABEL", realLabel);
}

int main( int argc, char* argv[] ) {
  initOperatorResultTable();
  yyparse();
}
