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
     ASSIGNOP = 258,
     MULOP = 259,
     ADDOP = 260,
     INCOP = 261,
     RELOP = 262,
     NOT = 263,
     OR = 264,
     AND = 265,
     FLT_LITERAL = 266,
     INT_LITERAL = 267,
     STR_LITERAL = 268,
     STREAMIN = 269,
     STREAMOUT = 270,
     ID = 271,
     CIN = 272,
     COUT = 273,
     ELSE = 274,
     ENDL = 275,
     FLOAT = 276,
     IF = 277,
     INT = 278,
     RETURN = 279,
     WHILE = 280
   };
#endif
/* Tokens.  */
#define ASSIGNOP 258
#define MULOP 259
#define ADDOP 260
#define INCOP 261
#define RELOP 262
#define NOT 263
#define OR 264
#define AND 265
#define FLT_LITERAL 266
#define INT_LITERAL 267
#define STR_LITERAL 268
#define STREAMIN 269
#define STREAMOUT 270
#define ID 271
#define CIN 272
#define COUT 273
#define ELSE 274
#define ENDL 275
#define FLOAT 276
#define IF 277
#define INT 278
#define RETURN 279
#define WHILE 280




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 10 "skarse.y"
{
    double d;
    char* str;
    struct SymTabNode* s;
    int fn;
}
/* Line 1529 of yacc.c.  */
#line 106 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
