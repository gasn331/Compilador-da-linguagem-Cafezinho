/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 32 "./fonte/cafezinho.y" /* yacc.c:1909  */

        int lineno;
        char *string;
        node* node_type;

#line 104 "cafezinho.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CAFEZINHO_TAB_H_INCLUDED  */
