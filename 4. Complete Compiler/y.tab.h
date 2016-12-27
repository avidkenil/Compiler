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
#line 86 "b_old.y" /* yacc.c:1909  */

    struct allAttributes *node1;


#line 141 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
