
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_eof = 0,
     T_and = 258,
     T_char = 259,
     T_div = 260,
     T_do = 261,
     T_else = 262,
     T_fun = 263,
     T_if = 264,
     T_int = 265,
     T_mod = 266,
     T_not = 267,
     T_nothing = 268,
     T_or = 269,
     T_ref = 270,
     T_return = 271,
     T_then = 272,
     T_var = 273,
     T_while = 274,
     T_writeInteger = 275,
     T_writeChar = 276,
     T_writeString = 277,
     T_id = 278,
     T_const_int = 279,
     T_const_char = 280,
     T_const_string = 281,
     T_geq = 282,
     T_leq = 283,
     T_assign = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 15 "parser/parser.y"
   
   AST *program;
   int num;
   char *id;
   char op;
   char *const_char;
   char *const_str;
   Expr *expr;
   Stmt *stmt;
   Cond *cond; 
   Block *stmt_list;
   Func_def *func_def;
   Local_def_gen *local_def_gen;
   Header *header;
   Fpar_def_gen *fpar_def_gen;
   Fpar_def *fpar_def;
   Comma_id_gen *comma_id_gen;
   Type_gen *type_gen;
   Typos typos;
   Type *type;
   Ret_type *ret_type;
   Fpar_type *fpar_type;
   Local_def *local_def;
   Func_decl *func_decl;
   Var_def *var_def;
   Func_call_stmt *func_call_stmt;
   Func_call_expr *func_call_expr;
   Comma_expr_gen *comma_expr_gen;
   L_value *l_value;
   Expr *expr_high;
   Cond *cond_high;
 



/* Line 1676 of yacc.c  */
#line 118 "parser/parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


