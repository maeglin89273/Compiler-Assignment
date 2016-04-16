/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 38 "Proj3_B10115018.y" /* yacc.c:1909  */

	int intVal;
	double realVal;
	char * strVal;
	char * varId;
	VarRow * varPtr;
	IdTypePair itPair;
	FuncInfo funcVal;
	ExpInfo expInfo;

#line 215 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
