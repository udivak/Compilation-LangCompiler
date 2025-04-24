/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AND = 258,
     OR = 259,
     NOT = 260,
     BOOL = 261,
     TRUE = 262,
     FALSE = 263,
     DEF = 264,
     MAIN = 265,
     IF = 266,
     ELSE = 267,
     ELIF = 268,
     WHILE = 269,
     FOR = 270,
     DO = 271,
     VAR = 272,
     BEGIN_TOKEN = 273,
     CALL = 274,
     END = 275,
     RETURN = 276,
     RETURNS = 277,
     NULL_T = 278,
     REAL = 279,
     STRING = 280,
     TYPE = 281,
     CHAR = 282,
     INT = 283,
     INT_LITERAL = 284,
     REAL_LITERAL = 285,
     INT_PTR = 286,
     CHAR_PTR = 287,
     REAL_PTR = 288,
     ID = 289,
     STRING_LITERAL = 290,
     CHAR_LITERAL = 291,
     EQ = 292,
     NEQ = 293,
     GE = 294,
     LE = 295,
     GT = 296,
     LT = 297,
     SEMICOLON = 298,
     COMMA = 299,
     LPAREN = 300,
     RPAREN = 301,
     LBRACKET = 302,
     RBRACKET = 303,
     LBRACE = 304,
     RBRACE = 305,
     COLON = 306,
     LOWER_THAN_ELSE = 307
   };
#endif
/* Tokens.  */
#define AND 258
#define OR 259
#define NOT 260
#define BOOL 261
#define TRUE 262
#define FALSE 263
#define DEF 264
#define MAIN 265
#define IF 266
#define ELSE 267
#define ELIF 268
#define WHILE 269
#define FOR 270
#define DO 271
#define VAR 272
#define BEGIN_TOKEN 273
#define CALL 274
#define END 275
#define RETURN 276
#define RETURNS 277
#define NULL_T 278
#define REAL 279
#define STRING 280
#define TYPE 281
#define CHAR 282
#define INT 283
#define INT_LITERAL 284
#define REAL_LITERAL 285
#define INT_PTR 286
#define CHAR_PTR 287
#define REAL_PTR 288
#define ID 289
#define STRING_LITERAL 290
#define CHAR_LITERAL 291
#define EQ 292
#define NEQ 293
#define GE 294
#define LE 295
#define GT 296
#define LT 297
#define SEMICOLON 298
#define COMMA 299
#define LPAREN 300
#define RPAREN 301
#define LBRACKET 302
#define RBRACKET 303
#define LBRACE 304
#define RBRACE 305
#define COLON 306
#define LOWER_THAN_ELSE 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "parser.y"
{
    int intVal;
    float realVal;
    char charVal;
    char* stringVal;
    node* node;
}
/* Line 1529 of yacc.c.  */
#line 161 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

