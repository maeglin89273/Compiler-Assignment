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
#line 1 "Proj3_B10115018.y" /* yacc.c:339  */

	
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <math.h>
	#include "ExpInfo.h"
	#include "IdTypePair.h"
	#include "SymbolTable.h"
	#include "JASMWriter.h"

	//shortcut macro for raising an error
	#define RAISE_ERROR(m) yyerror(m); YYERROR
	//check the variable name is clash or not
	#define CHECK_CLASH_ERROR(b) if(clashMsg(b)) YYERROR
	#define RAISE_CLASH_ERROR yyerror("variable name clash"); YYERROR
	

	char paramArgTypeMatch(ArgNode * argsA, ArgNode * argsB);

	char clashMsg(VarRow * varPtr);
		
	int tolerateNumType(int typeA, int typeB);

	ExpInfo biOptorMathWrap(ExpInfo leftOp, ExpInfo rightOp, int operator);
	ExpInfo doMath(ExpInfo a, ExpInfo b, ExpInfo c, int operator);
	void writeMathJASM(int operator);

	ExpInfo cmpWrap (ExpInfo leftOp, ExpInfo rightOp, int operator);
	ExpInfo doCompare(ExpInfo a, ExpInfo b, ExpInfo c, int operator);
	void writeCmpJASM(int operator);

	VarRow * varInsert(char * id, ExpInfo info);

	void prt(char * msg);

#line 103 "y.tab.c" /* yacc.c:339  */

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
    COMMA = 258,
    COLON = 259,
    SEMI = 260,
    L_PARENT = 261,
    R_PARENT = 262,
    L_SQ_BKT = 263,
    R_SQ_BKT = 264,
    L_BKT = 265,
    R_BKT = 266,
    ASSIGN_OP = 267,
    CMP_ADD = 268,
    CMP_MINUS = 269,
    CMP_MULTI = 270,
    CMP_DIV = 271,
    IDFY = 272,
    CONST_INT = 273,
    CONST_REAL = 274,
    CONST_STR = 275,
    OR = 276,
    AND = 277,
    NOT = 278,
    LESS = 279,
    LESS_EQ = 280,
    GREAT = 281,
    GREAT_EQ = 282,
    EQ = 283,
    NOT_EQ = 284,
    PLUS = 285,
    MINUS = 286,
    MULTI = 287,
    DIV = 288,
    MOD = 289,
    INCR = 290,
    DECR = 291,
    XCR = 292,
    UMINUS = 293,
    RET_OP = 294,
    K_BREAK = 295,
    K_CASE = 296,
    K_CLASS = 297,
    K_CONTINUE = 298,
    K_DEFAULT = 299,
    K_DO = 300,
    K_ELSE = 301,
    K_ENUM = 302,
    K_FALSE = 303,
    K_FOR = 304,
    K_FUNC = 305,
    K_IF = 306,
    K_IMPORT = 307,
    K_IN = 308,
    K_INIT = 309,
    K_LET = 310,
    K_NIL = 311,
    K_PRINT = 312,
    K_PRINTLN = 313,
    K_PUBLIC = 314,
    K_RETURN = 315,
    K_SELF = 316,
    K_STATIC = 317,
    K_STRUCT = 318,
    K_SWITCH = 319,
    K_TRUE = 320,
    K_VAR = 321,
    K_WHERE = 322,
    K_WHILE = 323,
    K_VOID = 324,
    K_READ = 325,
    TYP_STR = 326,
    TYP_INT = 327,
    TYP_BOOL = 328,
    TYP_FLOAT = 329,
    TYP_DOUBLE = 330
  };
#endif
/* Tokens.  */
#define COMMA 258
#define COLON 259
#define SEMI 260
#define L_PARENT 261
#define R_PARENT 262
#define L_SQ_BKT 263
#define R_SQ_BKT 264
#define L_BKT 265
#define R_BKT 266
#define ASSIGN_OP 267
#define CMP_ADD 268
#define CMP_MINUS 269
#define CMP_MULTI 270
#define CMP_DIV 271
#define IDFY 272
#define CONST_INT 273
#define CONST_REAL 274
#define CONST_STR 275
#define OR 276
#define AND 277
#define NOT 278
#define LESS 279
#define LESS_EQ 280
#define GREAT 281
#define GREAT_EQ 282
#define EQ 283
#define NOT_EQ 284
#define PLUS 285
#define MINUS 286
#define MULTI 287
#define DIV 288
#define MOD 289
#define INCR 290
#define DECR 291
#define XCR 292
#define UMINUS 293
#define RET_OP 294
#define K_BREAK 295
#define K_CASE 296
#define K_CLASS 297
#define K_CONTINUE 298
#define K_DEFAULT 299
#define K_DO 300
#define K_ELSE 301
#define K_ENUM 302
#define K_FALSE 303
#define K_FOR 304
#define K_FUNC 305
#define K_IF 306
#define K_IMPORT 307
#define K_IN 308
#define K_INIT 309
#define K_LET 310
#define K_NIL 311
#define K_PRINT 312
#define K_PRINTLN 313
#define K_PUBLIC 314
#define K_RETURN 315
#define K_SELF 316
#define K_STATIC 317
#define K_STRUCT 318
#define K_SWITCH 319
#define K_TRUE 320
#define K_VAR 321
#define K_WHERE 322
#define K_WHILE 323
#define K_VOID 324
#define K_READ 325
#define TYP_STR 326
#define TYP_INT 327
#define TYP_BOOL 328
#define TYP_FLOAT 329
#define TYP_DOUBLE 330

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 38 "Proj3_B10115018.y" /* yacc.c:355  */

	int intVal;
	double realVal;
	char * strVal;
	char * varId;
	VarRow * varPtr;
	IdTypePair itPair;
	FuncInfo funcVal;
	ExpInfo expInfo;

#line 304 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 319 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  216

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    81,    84,    87,    88,    89,    92,    93,
      96,    97,    98,   101,   102,   105,   115,   121,   136,   145,
     150,   158,   168,   184,   192,   197,   204,   218,   224,   225,
     226,   229,   229,   249,   252,   257,   261,   270,   271,   281,
     282,   285,   285,   293,   294,   297,   298,   299,   302,   303,
     304,   305,   306,   313,   320,   328,   336,   344,   352,   358,
     371,   376,   389,   395,   414,   421,   433,   433,   434,   434,
     437,   444,   454,   455,   456,   457,   458,   463,   468,   469,
     473,   476,   485,   495,   505,   508,   515,   520,   525,   534,
     537,   540,   543,   546,   549,   554,   557,   569,   570,   573,
     576,   579,   582,   589,   594,   599,   607,   611,   615,   619,
     625,   643,   652,   655,   660,   664,   669,   669,   679,   688,
     688,   696,   696,   704,   704,   704,   714
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA", "COLON", "SEMI", "L_PARENT",
  "R_PARENT", "L_SQ_BKT", "R_SQ_BKT", "L_BKT", "R_BKT", "ASSIGN_OP",
  "CMP_ADD", "CMP_MINUS", "CMP_MULTI", "CMP_DIV", "IDFY", "CONST_INT",
  "CONST_REAL", "CONST_STR", "OR", "AND", "NOT", "LESS", "LESS_EQ",
  "GREAT", "GREAT_EQ", "EQ", "NOT_EQ", "PLUS", "MINUS", "MULTI", "DIV",
  "MOD", "INCR", "DECR", "XCR", "UMINUS", "RET_OP", "K_BREAK", "K_CASE",
  "K_CLASS", "K_CONTINUE", "K_DEFAULT", "K_DO", "K_ELSE", "K_ENUM",
  "K_FALSE", "K_FOR", "K_FUNC", "K_IF", "K_IMPORT", "K_IN", "K_INIT",
  "K_LET", "K_NIL", "K_PRINT", "K_PRINTLN", "K_PUBLIC", "K_RETURN",
  "K_SELF", "K_STATIC", "K_STRUCT", "K_SWITCH", "K_TRUE", "K_VAR",
  "K_WHERE", "K_WHILE", "K_VOID", "K_READ", "TYP_STR", "TYP_INT",
  "TYP_BOOL", "TYP_FLOAT", "TYP_DOUBLE", "$accept", "swift", "$@1",
  "func_content", "var_const_decls", "var_const_decl", "g_var_const_decls",
  "g_var_const_decl", "const_decl", "g_var_decl", "l_var_decl", "id_itype",
  "func_decls", "func_decl", "$@2", "args", "args_list", "ret_itype",
  "pmt_itype", "stmts", "$@3", "stmt", "asgn_stmt", "id_or_elmt_lref",
  "id_or_elmt_rref", "id_or_elmt_num_lrref", "arr_elmt", "print_stmt",
  "$@4", "$@5", "ret_stmt", "exp", "bool_exp", "cmp_exp", "num_exp",
  "xcr_exp", "func_invo", "val_func_invo", "params", "params_list",
  "const_exp", "$@6", "int_exp", "if_else_stmt", "$@7", "if_stmt", "$@8",
  "while_stmt", "$@9", "$@10", "empty", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330
};
# endif

#define YYPACT_NINF -152

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-152)))

#define YYTABLE_NINF -106

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -54,    15,    27,    13,   -41,  -152,  -152,  -152,  -152,     7,
      56,    22,    47,  -152,    72,  -152,    24,  -152,  -152,    36,
    -152,  -152,  -152,   213,  -152,   115,   248,  -152,  -152,  -152,
    -152,  -152,     4,  -152,  -152,   213,   154,  -152,  -152,   213,
     114,   114,  -152,   102,  -152,   260,  -152,  -152,  -152,   132,
    -152,   140,   153,   143,  -152,  -152,     4,  -152,   147,   166,
    -152,  -152,   161,    57,   162,  -152,  -152,  -152,  -152,  -152,
     130,  -152,  -152,   198,  -152,   233,  -152,  -152,   308,  -152,
     131,  -152,   331,   321,    31,     4,   213,  -152,   170,  -152,
    -152,  -152,  -152,  -152,   213,   213,   213,   213,  -152,   183,
    -152,   181,   187,  -152,   233,     4,     4,  -152,   188,   170,
    -152,  -152,   248,     4,   213,   213,   213,   213,   185,   233,
     190,    -4,    44,   295,   121,   341,  -152,   331,   351,   233,
     233,   213,   213,   213,   213,   213,   213,  -152,  -152,   192,
     197,  -152,   199,   138,   138,  -152,  -152,   172,   140,   123,
    -152,  -152,   233,  -152,  -152,   260,   260,   260,   260,  -152,
    -152,  -152,  -152,  -152,   179,  -152,   260,   260,   260,   260,
     260,   260,  -152,     4,  -152,    30,  -152,   204,   129,   248,
    -152,  -152,  -152,  -152,  -152,   210,   211,   214,   248,  -152,
    -152,    52,   215,   248,   208,   217,   219,  -152,  -152,  -152,
    -152,  -152,   224,   122,   112,  -152,  -152,   229,  -152,     4,
     213,     4,  -152,   200,  -152,  -152
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     126,     0,     0,     0,   126,    11,    13,    14,    12,     0,
       0,    21,    20,     1,     0,    10,     2,    29,    30,     0,
     116,   116,   116,     0,   116,     0,   126,    28,    39,    40,
      27,    16,     0,    15,    18,     0,    61,   103,   104,     0,
       0,     0,   102,     0,    62,   118,    97,   111,   105,     0,
      17,   126,    63,     0,    66,    68,    71,   123,     0,    41,
      43,    45,     0,     0,    64,    46,    48,    58,    52,    49,
      50,    51,    44,     0,    76,     0,    87,    86,    74,   117,
      72,    84,    73,    78,     0,   126,     0,    96,    63,   107,
      64,   109,   106,   108,     0,     0,     0,     0,    19,     0,
      36,     0,    33,    34,     0,     0,     0,    70,     0,    61,
      47,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,     0,     0,   105,    85,    81,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,    95,   115,     0,
     112,   113,     0,   100,   101,    98,    99,     0,     0,     0,
      67,    69,     0,    42,    53,    54,    55,    56,    57,   119,
      77,    75,    80,    79,    83,    82,    89,    90,    91,    92,
      93,    94,   110,     0,    65,     0,    35,     0,     0,   126,
     114,    37,    31,    38,   121,     0,    41,     0,   126,   124,
     120,   126,    41,   126,     0,     0,   126,     6,     8,     9,
       7,   122,    41,    26,    25,    32,     5,    41,   125,     0,
       0,     0,    23,     0,    22,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,  -152,  -152,  -152,    45,  -152,   238,  -150,  -152,
    -152,    -2,  -152,   231,  -152,  -152,  -152,  -152,    78,  -151,
    -152,   145,  -152,  -152,   -25,    17,   -11,  -152,  -152,  -152,
    -152,    34,   108,  -152,   -19,   -21,    10,    50,  -152,  -152,
      62,  -152,   -78,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
       2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    26,   195,   196,   197,     4,     5,     6,     7,
     199,    10,    16,    17,   187,   101,   102,   182,    30,    59,
     112,    60,    61,    62,    42,    43,    44,    65,   105,   106,
      66,    79,    80,    81,    82,    46,    47,    48,   139,   140,
      31,    32,    49,    69,   179,    70,   188,    71,   108,   193,
      72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,     1,     8,   161,    45,    67,    18,    78,   142,    14,
      73,    19,     2,    13,     1,    64,    84,   -85,   -85,    20,
      87,    36,    37,    38,    74,     2,    19,    75,   186,    90,
      90,    78,     9,   110,    22,    39,    68,   192,   137,    40,
      41,   198,   202,    63,    11,   207,   198,   111,   121,   100,
     125,   162,    76,   103,   123,    23,   127,    89,    91,    24,
      78,    94,    95,    96,    97,   129,   130,    45,    21,    77,
     114,   115,   116,   117,    14,   143,   144,   145,   146,   125,
      78,    78,    83,    33,    34,   127,    50,   141,    78,    25,
     107,    67,    92,    93,   125,   155,   156,   157,   158,   181,
     123,    64,    28,    29,   125,   125,    83,     1,    28,    29,
     127,   127,   166,   167,   168,   169,   170,   171,   194,   138,
     210,    51,    68,   124,   211,   128,    19,   125,   163,    63,
     177,    88,   213,   127,   209,    83,   185,    92,    93,   150,
     151,    98,   -88,   -88,   129,   130,   176,   154,    78,   104,
     129,   130,   129,   130,   128,    83,    83,    99,    67,    85,
      85,    86,    86,    83,   109,   -59,    -3,    67,    64,   128,
      96,    97,    67,   113,   -60,    67,   118,    64,    86,   128,
     128,   122,    64,   126,    78,    64,    78,    19,   147,    68,
     148,    45,   204,   200,   152,   159,    63,   160,    68,   172,
     173,   130,   128,    68,   119,    63,    68,   180,   174,   215,
      63,   175,   149,    63,   184,    36,    37,    38,   120,    35,
     189,    75,   190,    83,   191,   203,   201,   122,   205,    39,
      36,    37,    38,    40,    41,   208,    52,   164,   165,   119,
      -4,   206,    15,   212,    39,   214,    76,    27,    40,    41,
      36,    37,    38,   183,    40,    41,    75,   153,     0,    83,
     178,    83,     0,    77,    39,    52,     0,     0,    40,    41,
      53,     0,     0,     0,     1,     0,    54,    55,     0,    56,
       0,    76,     0,    40,    41,   194,     0,    57,     0,    58,
      94,    95,    96,    97,     0,     0,     0,     0,    77,    53,
       0,     0,   137,     0,     0,    54,    55,     0,    56,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    58,   131,
     132,   133,   134,   135,   136,    94,    95,    96,    97,   -85,
     -85,     0,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,   -88,   -88,     0,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,   131,   132,   133,   134,   135,
     136,    94,    95,    96,    97,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105
};

static const yytype_int16 yycheck[] =
{
       2,    55,     0,     7,    23,    26,     4,    32,    86,    50,
       6,     4,    66,     0,    55,    26,    35,    21,    22,    12,
      39,    17,    18,    19,    20,    66,     4,    23,   179,    40,
      41,    56,    17,    58,    12,    31,    26,   188,     7,    35,
      36,   191,   193,    26,    17,   196,   196,    58,    73,    51,
      75,     7,    48,    51,    73,     8,    75,    40,    41,    12,
      85,    30,    31,    32,    33,    21,    22,    86,    12,    65,
      13,    14,    15,    16,    50,    94,    95,    96,    97,   104,
     105,   106,    32,    21,    22,   104,    24,    85,   113,    17,
      56,   112,    35,    36,   119,   114,   115,   116,   117,    69,
     119,   112,    72,    73,   129,   130,    56,    55,    72,    73,
     129,   130,   131,   132,   133,   134,   135,   136,    66,    85,
       8,     6,   112,    73,    12,    75,     4,   152,     7,   112,
       7,    17,   210,   152,    12,    85,     7,    35,    36,   105,
     106,     9,    21,    22,    21,    22,   148,   113,   173,     6,
      21,    22,    21,    22,   104,   105,   106,    17,   179,     6,
       6,     8,     8,   113,    17,    12,     0,   188,   179,   119,
      32,    33,   193,    12,    12,   196,    46,   188,     8,   129,
     130,    73,   193,    75,   209,   196,   211,     4,     7,   179,
       3,   210,   194,   191,     6,    10,   179,     7,   188,     7,
       3,    22,   152,   193,     6,   188,   196,   173,     9,     9,
     193,    39,   104,   196,    10,    17,    18,    19,    20,     6,
      10,    23,    11,   173,    10,    17,    11,   119,    11,    31,
      17,    18,    19,    35,    36,    11,    17,   129,   130,     6,
      11,   196,     4,   209,    31,   211,    48,    16,    35,    36,
      17,    18,    19,   175,    35,    36,    23,   112,    -1,   209,
     152,   211,    -1,    65,    31,    17,    -1,    -1,    35,    36,
      51,    -1,    -1,    -1,    55,    -1,    57,    58,    -1,    60,
      -1,    48,    -1,    35,    36,    66,    -1,    68,    -1,    70,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    65,    51,
      -1,    -1,     7,    -1,    -1,    57,    58,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    21,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    66,    77,    82,    83,    84,    85,   126,    17,
      87,    17,    87,     0,    50,    83,    88,    89,   126,     4,
      12,    12,    12,     8,    12,    17,    78,    89,    72,    73,
      94,   116,   117,   116,   116,     6,    17,    18,    19,    31,
      35,    36,   100,   101,   102,   110,   111,   112,   113,   118,
     116,     6,    17,    51,    57,    58,    60,    68,    70,    95,
      97,    98,    99,   101,   102,   103,   106,   111,   112,   119,
     121,   123,   126,     6,    20,    23,    48,    65,   100,   107,
     108,   109,   110,   113,   110,     6,     8,   110,    17,   101,
     102,   101,    35,    36,    30,    31,    32,    33,     9,    17,
      87,    91,    92,   126,     6,   104,   105,   107,   124,    17,
     100,   102,    96,    12,    13,    14,    15,    16,    46,     6,
      20,   100,   108,   110,   113,   100,   108,   110,   113,    21,
      22,    24,    25,    26,    27,    28,    29,     7,   107,   114,
     115,   126,   118,   110,   110,   110,   110,     7,     3,   108,
     107,   107,     6,    97,   107,   110,   110,   110,   110,    10,
       7,     7,     7,     7,   108,   108,   110,   110,   110,   110,
     110,   110,     7,     3,     9,    39,    87,     7,   108,   120,
     107,    69,    93,    94,    10,     7,    95,    90,   122,    10,
      11,    10,    95,   125,    66,    79,    80,    81,    84,    86,
     126,    11,    95,    17,    87,    11,    81,    95,    11,    12,
       8,    12,   107,   118,   107,     9
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    78,    77,    79,    80,    80,    80,    81,    81,
      82,    82,    82,    83,    83,    84,    84,    85,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    87,    88,    88,
      88,    90,    89,    91,    91,    92,    92,    93,    93,    94,
      94,    96,    95,    95,    95,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    98,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   104,   103,   105,   103,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   109,   109,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   111,   111,   111,   111,
     112,   113,   114,   114,   115,   115,   117,   116,   118,   120,
     119,   122,   121,   124,   125,   123,   126
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     2,     2,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     4,     4,     4,     4,     5,
       2,     2,     4,     4,     5,     2,     2,     3,     2,     1,
       1,     0,    11,     1,     1,     3,     1,     1,     1,     1,
       1,     0,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     0,     3,     0,     3,
       2,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       3,     2,     3,     3,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     2,     2,     2,     2,
       4,     1,     1,     1,     3,     1,     0,     2,     1,     0,
       6,     0,     8,     0,     0,     9,     0
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
#line 81 "Proj3_B10115018.y" /* yacc.c:1646  */
    {startWriteMainMethod();}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 81 "Proj3_B10115018.y" /* yacc.c:1646  */
    {endWriteMainMethod();}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 105 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if(typeCompatible((yyvsp[-2].itPair).type, (yyvsp[0].expInfo).type)) {

				ExpInfo info;
				info = convertNumType((yyvsp[0].expInfo), (yyvsp[-2].itPair).type);
				CHECK_CLASH_ERROR(insertPrimitive((yyvsp[-2].itPair).id, info));
			} else {
				RAISE_ERROR("the types are not compatible");
			}
		}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 115 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			enableWriter(1);
			CHECK_CLASH_ERROR(insertPrimitive((yyvsp[-2].varId), (yyvsp[0].expInfo)));
		}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 121 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if(typeCompatible((yyvsp[-2].itPair).type, (yyvsp[0].expInfo).type)) {
				ExpInfo info;
				info = convertNumType((yyvsp[0].expInfo), (yyvsp[-2].itPair).type);

				VarRow * insertResult = varInsert((yyvsp[-2].itPair).id, info);
				if (!insertResult) {
					RAISE_ERROR("variable name clash");
				} else {
					globalIVarDeclaration((yyvsp[-2].itPair).id, info.constVal.intVal);
				}
			} else {
				RAISE_ERROR("the types are not compatible");		
			}
		}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 136 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			VarRow * insertResult = varInsert((yyvsp[-2].varId), (yyvsp[0].expInfo));
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			} else {
				globalIVarDeclaration((yyvsp[-2].varId), (yyvsp[0].expInfo).constVal.intVal);
				
			}
		}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 145 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			//notice the array size here, it may be changed in the future
			// CHECK_CLASH_ERROR(insertArray($2.id, $2.type, 0));
			RAISE_ERROR("sorry, arrays are not supported yet!");
		}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 150 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			VarRow * insertResult = insertNotInitPrimitive((yyvsp[0].itPair).id, (yyvsp[0].itPair).type);
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			} else {
				globalIVarDeclarationNotInit((yyvsp[0].itPair).id);
			}
		}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 158 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			VarRow * insertResult = insertNotInitPrimitive((yyvsp[0].varId), INT_T);
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			} else {
				globalIVarDeclarationNotInit((yyvsp[0].varId));
			}
		}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 168 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if(typeCompatible((yyvsp[-2].itPair).type, (yyvsp[0].expInfo).type)) {
				ExpInfo info;
				info = convertNumType((yyvsp[0].expInfo), (yyvsp[-2].itPair).type);

				VarRow * insertResult = varInsert((yyvsp[-2].itPair).id, info);
				if (!insertResult) {
					RAISE_ERROR("variable name clash");
				} else {
					iVarStore(insertResult);
				}

			} else {
				RAISE_ERROR("the types are not compatible");		
			}
		}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 184 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			VarRow * insertResult = varInsert((yyvsp[-2].varId), (yyvsp[0].expInfo));
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			} else {
				iVarStore(insertResult);
			}
		}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 192 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			//notice the array size here, it may be changed in the future
			// CHECK_CLASH_ERROR(insertArray($2.id, $2.type, 0));
			RAISE_ERROR("sorry, arrays are not supported yet!");
		}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 197 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			VarRow * insertResult = insertNotInitPrimitive((yyvsp[0].itPair).id, (yyvsp[0].itPair).type);
			
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			}
		}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 204 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			VarRow * insertResult = insertNotInitPrimitive((yyvsp[0].varId), INT_T);
			
			if (!insertResult) {
				RAISE_ERROR("variable name clash");
			}
		}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 218 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.itPair).id = (yyvsp[-2].varId);
			(yyval.itPair).type = (yyvsp[0].intVal);
		}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 229 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			FuncInfo func = (yyvsp[-3].funcVal);
			func.retType = (yyvsp[0].intVal);
			VarRow * funcVar = insertFunc((yyvsp[-5].varId), func);
			if(funcVar) {
				startWriteFunction(funcVar);
				newScope(func);

			} else {
				RAISE_ERROR("function name clash");
			}
		}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 240 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if (dumpCurrentScope()) {
				endWriteFunction();
			} else {
				RAISE_ERROR("The function has no proper return statement");
			}
		}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 249 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.funcVal) = (yyvsp[0].funcVal);
		}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 252 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.funcVal).args = (yyval.funcVal).lastArg = NULL;
		}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 257 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.funcVal) = (yyvsp[-2].funcVal);
			(yyval.funcVal).lastArg = catArgs((yyval.funcVal).lastArg, (yyvsp[0].itPair).id, (yyvsp[0].itPair).type);
		}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 261 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.funcVal).lastArg = (yyval.funcVal).args = catArgs(NULL, (yyvsp[0].itPair).id, (yyvsp[0].itPair).type);	 
		}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 270 "Proj3_B10115018.y" /* yacc.c:1646  */
    {(yyval.intVal) = VOID_T;}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 271 "Proj3_B10115018.y" /* yacc.c:1646  */
    {(yyval.intVal) = (yyvsp[0].intVal);}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 281 "Proj3_B10115018.y" /* yacc.c:1646  */
    {(yyval.intVal) = INT_T;}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 282 "Proj3_B10115018.y" /* yacc.c:1646  */
    {(yyval.intVal) = BOOL_T;}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 285 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			// if there is a statement under a return, raise an error
			if(hasReturned()) {
				RAISE_ERROR("the following statements are unreachable");
			} else {
				jnewline();
			}
		}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 299 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			RAISE_ERROR("not support read keyword yet");
		}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 303 "Proj3_B10115018.y" /* yacc.c:1646  */
    {endWriteElse();}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 304 "Proj3_B10115018.y" /* yacc.c:1646  */
    {endWriteIf();}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 306 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].expInfo).type != K_VOID) {
				stackPop();
			}
		}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 313 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if (typeCompatible((yyvsp[-2].varPtr)->type, (yyvsp[0].expInfo).type)) {
				iVarStore((yyvsp[-2].varPtr));
			} else {
				RAISE_ERROR("variable type is incampatible");
			}
		}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 320 "Proj3_B10115018.y" /* yacc.c:1646  */
    {			
			if (typeCompatible((yyvsp[-2].varPtr)->type, (yyvsp[0].expInfo).type)) {
				stackAdd();
				iVarStore((yyvsp[-2].varPtr));
			} else {
				RAISE_ERROR("variable type is incampatible");
			}
		}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 328 "Proj3_B10115018.y" /* yacc.c:1646  */
    {			
			if (typeCompatible((yyvsp[-2].varPtr)->type, (yyvsp[0].expInfo).type)) {
				stackSub();
				iVarStore((yyvsp[-2].varPtr));
			} else {
				RAISE_ERROR("variable type is incampatible");
			}
		}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 336 "Proj3_B10115018.y" /* yacc.c:1646  */
    {			
			if (typeCompatible((yyvsp[-2].varPtr)->type, (yyvsp[0].expInfo).type)) {
				stackMul();
				iVarStore((yyvsp[-2].varPtr));
			} else {
				RAISE_ERROR("variable type is incampatible");
			}
		}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 344 "Proj3_B10115018.y" /* yacc.c:1646  */
    {			
			if (typeCompatible((yyvsp[-2].varPtr)->type, (yyvsp[0].expInfo).type)) {
				stackDiv();
				iVarStore((yyvsp[-2].varPtr));
			} else {
				RAISE_ERROR("variable type is incampatible");
			}
		}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 352 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			stackPop();
		}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 358 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			VarRow * var = lookup((yyvsp[0].varId));
			if (var) {
				if(var->isConst) {
					RAISE_ERROR("cannot assign to the constant variable");
				} else {			
					var->isInit = 1;
					(yyval.varPtr) = var;
				}
			} else {
				RAISE_ERROR("cannot find the variable");
			}
		}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 371 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			// $$ = $1;
		}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 376 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			VarRow * var = lookup((yyvsp[0].varId));
			if (var && var->isInit) {
				(yyval.expInfo) = primitiveVarExpMapping(var);
				if ((yyval.expInfo).isConst) {
					iConstPush((yyval.expInfo).constVal.intVal);
				} else {
					iVarLoad(var);
				}
			} else {
				RAISE_ERROR("cannot find the variable or it is not init");
			}
		}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 389 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			// $$ = $1;
		}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 395 "Proj3_B10115018.y" /* yacc.c:1646  */
    {	
			VarRow * var = lookup((yyvsp[0].varId));
			if (var) {
				if(var->isConst) {
					RAISE_ERROR("cannot assign to the constant variable");

				} else if (!var->isInit) {
					RAISE_ERROR("the variable is not init");

				} else if (!checkNumber(var->type)) {
					RAISE_ERROR("variable is not a number");

				} else {
					(yyval.varPtr) = var;
				}
			} else {
				RAISE_ERROR("cannot find the variable");
			}
		}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 414 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			// $$ = $1;
		}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 421 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			/*VarRow * var = lookup($1);
			if (var) {
				$$.type = var->content.arrVal.type;
				$$.isConst = 0;
			} else {
				RAISE_ERROR("cannot find the variable");
			}*/
			RAISE_ERROR("sorry, arrays are not supported yet!");
		}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 433 "Proj3_B10115018.y" /* yacc.c:1646  */
    {startPrint();}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 433 "Proj3_B10115018.y" /* yacc.c:1646  */
    {endAsPrint((yyvsp[0].expInfo).type);}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 434 "Proj3_B10115018.y" /* yacc.c:1646  */
    {startPrint();}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 434 "Proj3_B10115018.y" /* yacc.c:1646  */
    {endAsPrintln((yyvsp[0].expInfo).type);}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 437 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if (setReturn((yyvsp[0].expInfo).type)) {
				writeIReturn();
			} else {
				RAISE_ERROR("return type is not match");
			}
		}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 444 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if (setReturn(VOID_T)) {
				writeReturn();
			} else {
				RAISE_ERROR("return type is not match");
			}
		}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 454 "Proj3_B10115018.y" /* yacc.c:1646  */
    {(yyval.expInfo) = (yyvsp[0].expInfo);}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 455 "Proj3_B10115018.y" /* yacc.c:1646  */
    {(yyval.expInfo) = (yyvsp[0].expInfo);}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 456 "Proj3_B10115018.y" /* yacc.c:1646  */
    {(yyval.expInfo) = (yyvsp[0].expInfo);}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 457 "Proj3_B10115018.y" /* yacc.c:1646  */
    {(yyval.expInfo) = (yyvsp[-1].expInfo);}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 458 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = createConstExp(STR_T);
			(yyval.expInfo).constVal.strVal = (yyvsp[0].strVal);
			strConstPush((yyvsp[0].strVal));
		}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 463 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = createConstExp(STR_T);
			(yyval.expInfo).constVal.strVal = (yyvsp[-1].strVal);
			strConstPush((yyvsp[-1].strVal));
		}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 468 "Proj3_B10115018.y" /* yacc.c:1646  */
    {(yyval.expInfo) = (yyvsp[0].expInfo);}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 469 "Proj3_B10115018.y" /* yacc.c:1646  */
    {(yyval.expInfo) = (yyvsp[-1].expInfo);}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 473 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = (yyvsp[-1].expInfo);
		}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 476 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = (yyvsp[0].expInfo);

			if ((yyval.expInfo).isConst) {
				(yyval.expInfo).constVal.intVal = !(yyval.expInfo).constVal.intVal;
			} else {
				stackNot();
			}
		}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 485 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo).isConst = isBothConst((yyvsp[-2].expInfo), (yyvsp[0].expInfo));
			(yyval.expInfo).type = BOOL_T;

			if ((yyval.expInfo).isConst) {
				(yyval.expInfo).constVal.intVal = (yyvsp[-2].expInfo).constVal.intVal && (yyvsp[0].expInfo).constVal.intVal;
			} else {
				stackAnd();
			}
		}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 495 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo).isConst = isBothConst((yyvsp[-2].expInfo), (yyvsp[0].expInfo));
			(yyval.expInfo).type = BOOL_T;

			if ((yyval.expInfo).isConst) {
				(yyval.expInfo).constVal.intVal = (yyvsp[-2].expInfo).constVal.intVal || (yyvsp[0].expInfo).constVal.intVal;
			} else {
				stackOr();
			}
		}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 505 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = (yyvsp[0].expInfo);
		}
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 508 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if (checkExpBool((yyvsp[0].expInfo))) {
				(yyval.expInfo) = (yyvsp[0].expInfo);
			} else {
				RAISE_ERROR("expression is not a boolean");
			}
		}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 515 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = createConstExp(BOOL_T);
			(yyval.expInfo).constVal.intVal = 1;
			pushTrue();
		}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 520 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = createConstExp(BOOL_T);
			(yyval.expInfo).constVal.intVal = 0;
			pushFalse();
		}
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 525 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if (checkExpBool((yyvsp[0].expInfo))) {
				(yyval.expInfo) = (yyvsp[0].expInfo);
			} else {
				RAISE_ERROR("expression is not a boolean");
			}
		}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 534 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = cmpWrap((yyvsp[-2].expInfo), (yyvsp[0].expInfo), LESS);
		}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 537 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = cmpWrap((yyvsp[-2].expInfo), (yyvsp[0].expInfo), LESS_EQ);
		}
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 540 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = cmpWrap((yyvsp[-2].expInfo), (yyvsp[0].expInfo), GREAT);
		}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 543 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = cmpWrap((yyvsp[-2].expInfo), (yyvsp[0].expInfo), GREAT_EQ);
		}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 546 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = cmpWrap((yyvsp[-2].expInfo), (yyvsp[0].expInfo), EQ);
		}
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 549 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = cmpWrap((yyvsp[-2].expInfo), (yyvsp[0].expInfo), NOT_EQ);
		}
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 554 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = (yyvsp[-1].expInfo);
		}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 557 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = (yyvsp[0].expInfo);
			if ((yyval.expInfo).isConst)	{
				if ((yyval.expInfo).type == INT_T) {
					(yyval.expInfo).constVal.intVal = -(yyval.expInfo).constVal.intVal;
				} else {
					(yyval.expInfo).constVal.realVal = -(yyval.expInfo).constVal.realVal;
				}
			} else {
				stackNeg();
			}
		}
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 569 "Proj3_B10115018.y" /* yacc.c:1646  */
    {(yyval.expInfo) = (yyvsp[0].expInfo);}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 570 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = biOptorMathWrap((yyvsp[-2].expInfo), (yyvsp[0].expInfo), MULTI);
		}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 573 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = biOptorMathWrap((yyvsp[-2].expInfo), (yyvsp[0].expInfo), DIV);
		}
#line 2383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 576 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = biOptorMathWrap((yyvsp[-2].expInfo), (yyvsp[0].expInfo), PLUS);
		}
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 579 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = biOptorMathWrap((yyvsp[-2].expInfo), (yyvsp[0].expInfo), MINUS);
		}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 582 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if (checkExpNumber((yyvsp[0].expInfo))) {
				(yyval.expInfo) = (yyvsp[0].expInfo);
			} else {
				RAISE_ERROR("expression is not a number");
			}
		}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 589 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = createConstExp(INT_T);
			(yyval.expInfo).constVal.intVal = (yyvsp[0].intVal);
			iConstPush((yyvsp[0].intVal));
		}
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 594 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			// $$ = createConstExp(DOUBLE_T);
			// $$.constVal.realVal = $1;
			RAISE_ERROR("sorry, not support real number yet");
		}
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 599 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if (checkExpNumber((yyvsp[0].expInfo))) {
				(yyval.expInfo) = (yyvsp[0].expInfo);
			} else {
				RAISE_ERROR("expression is not a number");
			}
		}
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 607 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = primitiveVarExpMapping((yyvsp[-1].varPtr));
			iVarPosIncr((yyvsp[-1].varPtr));
		}
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 611 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = primitiveVarExpMapping((yyvsp[0].varPtr));
			iVarPreIncr((yyvsp[0].varPtr));
		}
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 615 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = primitiveVarExpMapping((yyvsp[-1].varPtr));
			iVarPosDecr((yyvsp[-1].varPtr));
		}
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 619 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.expInfo) = primitiveVarExpMapping((yyvsp[0].varPtr));
			iVarPreDecr((yyvsp[0].varPtr));
		}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 625 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			VarRow * funcVar = lookup((yyvsp[-3].varId));
			if (!funcVar) {
				RAISE_ERROR("cannot find function");
			} else if (funcVar->type != FUNC_T) {
				RAISE_ERROR("this variable is not a function");
			} else if (!paramArgTypeMatch(funcVar->content.funcVal.args, (yyvsp[-1].funcVal).args)) {
				RAISE_ERROR("the parameter types or length are not matched");
			}

			(yyval.expInfo).type = funcVar->content.funcVal.retType;
			(yyval.expInfo).isConst = 0;

			stackFuncInvok(funcVar);
			
		}
#line 2500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 643 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].expInfo).type == K_VOID) {
				RAISE_ERROR("void function cannot be a expression");
			} else {
				(yyval.expInfo) = (yyvsp[0].expInfo);
			}
		}
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 652 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.funcVal) = (yyvsp[0].funcVal);
		}
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 655 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.funcVal).args = (yyval.funcVal).lastArg = NULL;
		}
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 660 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.funcVal) = (yyvsp[-2].funcVal);
			(yyval.funcVal).lastArg = catArgs((yyval.funcVal).lastArg, NULL, (yyvsp[0].expInfo).type);
		}
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 664 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			(yyval.funcVal).lastArg = (yyval.funcVal).args = catArgs(NULL, NULL, (yyvsp[0].expInfo).type);
		}
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 669 "Proj3_B10115018.y" /* yacc.c:1646  */
    {enableWriter(0);}
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 669 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			enableWriter(1);
			if (!(yyvsp[0].expInfo).isConst) {
				RAISE_ERROR("not a const expression");
			} else {
				(yyval.expInfo) = (yyvsp[0].expInfo);
			}
		}
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 679 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].expInfo).type != INT_T) {
				RAISE_ERROR("not a int expression");
			} else {
				(yyval.expInfo) = (yyvsp[0].expInfo);
			}
		}
#line 2576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 688 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			enterElseBlock();
			startWriteElse();
		}
#line 2585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 692 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			leaveBlock();
		}
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 696 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			enterIfBlock();
			startWriteIf();
		}
#line 2602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 700 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			leaveBlock();
		}
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 704 "Proj3_B10115018.y" /* yacc.c:1646  */
    {startWriteWhile();}
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 704 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			enterLoopBlock();
			writeWhileEval();
		}
#line 2625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 707 "Proj3_B10115018.y" /* yacc.c:1646  */
    {
			leaveBlock();
			endWriteWhile();
		}
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2638 "y.tab.c" /* yacc.c:1646  */
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
#line 716 "Proj3_B10115018.y" /* yacc.c:1906  */


char clashMsg(VarRow * varPtr) {
	if (varPtr == NULL) {
		yyerror("variable name clash");
		return 1;
	}
	return 0;
}

char paramArgTypeMatch(ArgNode * argsA, ArgNode * argsB) {
	for (;argsA != NULL && argsB != NULL;) {
		if (!typeCompatible(argsA->type, argsB->type)) {
			return 0;
		}
		argsA = argsA->next;
		argsB = argsB->next;
	}

	if (argsA != argsB ) {
		return 0;
	}

	return 1;
}

ExpInfo convertNumType(ExpInfo exp, int numType) {	
	if (exp.type != numType) {
		if (numType != INT_T && exp.type == INT_T) {
			exp.constVal.realVal = exp.constVal.intVal;
		}
		exp.type = numType;	
	}
	
	return exp;
}

ExpInfo biOptorMathWrap(ExpInfo leftOp, ExpInfo rightOp, int operator) {
	ExpInfo output;
	output.isConst = isBothConst(leftOp, rightOp);
	output.type = tolerateNumType(leftOp.type, rightOp.type);

	if (output.isConst) {
		output = doMath(output, leftOp, rightOp, operator);
	}
	writeMathJASM(operator);

	return output;
}

ExpInfo doMath(ExpInfo a, ExpInfo b, ExpInfo c, int operator) {
	if (a.type == INT_T) {
		int op1 = b.constVal.intVal;
		int op2 = c.constVal.intVal;
		switch(operator) {
			case MULTI:
				a.constVal.intVal = op1 * op2;
				break;
			case DIV:
				a.constVal.intVal = op1 / op2;
				break;
			case MOD:
				a.constVal.intVal = op1 % op2;
				break;
			case PLUS:
				a.constVal.intVal = op1 + op2;
				break;
			case MINUS:
				a.constVal.intVal = op1 - op2;
		}
	} else {
		double op1 = b.type == INT_T? b.constVal.intVal: b.constVal.realVal;
		double op2 = c.type == INT_T? c.constVal.intVal: c.constVal.realVal;
		switch(operator) {
			case MULTI:
				a.constVal.realVal = op1 * op2;
				break;
			case DIV:
				a.constVal.realVal = op1 / op2;
				break;
			case MOD:
				a.constVal.realVal = fmod(op1, op2);
				break;
			case PLUS:
				a.constVal.realVal = op1 + op2;
				break;
			case MINUS:
				a.constVal.realVal = op1 - op2;
		}
	}

	return a;
}

void writeMathJASM(int operator) {
	switch(operator) {
		case MULTI:
			stackMul();
			break;
		case DIV:
			stackDiv();
			break;
		case MOD:
			stackRem();
			break;
		case PLUS:
			stackAdd();
			break;
		case MINUS:
			stackSub();
	}
}

ExpInfo cmpWrap(ExpInfo leftOp, ExpInfo rightOp, int operator) {
	ExpInfo output;
	output.isConst = isBothConst(leftOp, rightOp);
	output.type = BOOL_T;

	if (output.isConst) {
		output = doCompare(output, leftOp, rightOp, operator);
	}
	writeCmpJASM(operator);

	return output;
}

ExpInfo doCompare(ExpInfo a, ExpInfo b, ExpInfo c, int operator) {
	double op1 = b.type == INT_T? b.constVal.intVal: b.constVal.realVal;
	double op2 = c.type == INT_T? c.constVal.intVal: c.constVal.realVal;

	switch(operator) {
		case LESS:
			a.constVal.intVal = op1 < op2;
			break;
		case LESS_EQ:
			a.constVal.intVal = op1 <= op2;
			break;
		case GREAT:
			a.constVal.intVal = op1 > op2;
			break;
		case GREAT_EQ:
			a.constVal.intVal = op1 >= op2;
			break;
		case EQ:
			a.constVal.intVal = op1 == op2;
			break;
		case NOT_EQ:
			a.constVal.intVal = op1 != op2;
	}
	return a;
}

void writeCmpJASM(int operator) {
	switch(operator) {
		case LESS:
			stackLess();
			break;
		case LESS_EQ:
			stackLessEq();
			break;
		case GREAT:
			stackGreat();
			break;
		case GREAT_EQ:
			stackGreatEq();
			break;
		case EQ:
			stackEq();
			break;
		case NOT_EQ:
			stackNotEq();
	}
}

VarRow * varInsert(char * id, ExpInfo info) {
	char isExpConst = info.isConst;
	info.isConst = 0;
	VarRow * insertResult = insertPrimitive(id, info);
	
	return insertResult;
}


void prt(char * msg) {
	fprintf(stdout, "\t\t\t%s\n", msg);
}

yyerror(char * msg) {
	fprintf(stderr, "\nsyntax error: %s\n", msg);
}

main(int c, char * args[]) {
	
	prepareJASM(args[1]);
	createSymbolTable();
	int result = yyparse();
	freeSymbolTable();
	closeJASM(result);
	return result;
}
