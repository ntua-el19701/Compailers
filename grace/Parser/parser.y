%{
#include <cstdio>
#include "lexer.hpp"

%}

%token T_eof     0
%token T_and     "and"
%token T_char    "char"
%token T_div     "div"
%token T_do      "do"
%token T_else    "else"
%token T_fun     "fun"
%token T_if      "if"
%token T_int     "int"
%token T_mod     "mod"
%token T_not     "not"
%token T_nothing "nothing" 
%token T_or      "or"
%token T_ref     "ref"
%token T_return  "return"
%token T_then    "then"
%token T_var     "var"
%token T_while   "while"

%token T_id    
%token T_const_int "const_int"
%token T_const_char 
%token T_const_string 
%token T_geq ">="
%token T_leq "<="
%token T_assign "<-"



%left '+' '-'
%left '*' "div" "mod" 
%nonassoc '=' '#' '>' '<' "<=" ">=" 
%nonassoc "not"
%left "and"
%left "or"


%expect 1 //if then else




%%

program:
        func_def
        ;

func_def: 
        header local_def_gen block
        ;

local_def_gen: 
        /*nothing*/
        | local_def local_def_gen
        ;
        
header: 
        T_fun T_id '(' ')' ':' ret_type
        | T_fun T_id '(' fpar_def fpar_def_gen ')' ':' ret_type 
        ;
        
fpar_def_gen: 
        /*nothing*/
        | ';' fpar_def fpar_def_gen
        ;

fpar_def:
        T_ref T_id comma_id_gen ':' fpar_type
        | T_id comma_id_gen ':' fpar_type
        ;

comma_id_gen: 
        /*nothing*/
        | ',' T_id comma_id_gen
        ;

data_type: 
        T_int
        | T_char
        ;

type:
        data_type type_gen
        ;

type_gen:
        /*nothing*/
        | '[' T_const_int ']' type_gen
        ;

ret_type:
        data_type
        | T_nothing
        ;

fpar_type:
        data_type '[' ']' type_gen
        | data_type type_gen
        ;

local_def:
        func_def
        | func_decl
        | var_def
        ;

func_decl: 
        header ';' 
        ;

var_def: 
        T_var T_id comma_id_gen ':' type ';'
        ;

stmt: 
        ';'
        | l_value T_assign expr ';' 
        | block
        | func_call ';'
        | T_if cond T_then stmt 
        | T_if cond T_then stmt T_else stmt
        | T_while cond T_do stmt 
        | T_return ';'
        | T_return expr ';'
        ;

block: '{' stmt_list '}'
        ;

stmt_list: 
        /*nothing*/
        | stmt stmt_list
        ;

func_call: 
        T_id '(' ')'
        | T_id '(' expr comma_expr_gen ')'
        ;

comma_expr_gen: 
        /*nothing*/
        | ',' expr comma_expr_gen
        ;

l_value:       
        T_id
        | T_const_string
        | l_value '[' expr ']'
        ;

expr: 
        T_const_int
        | T_const_char
        | l_value
        | expr_high
        | func_call
        | expr '+' expr
        | expr '-' expr
        | expr '*' expr 
        | expr T_div expr
        | expr T_mod expr
        ;

expr_high: 
        '(' expr ')'
        | '+' expr
        | '-' expr
        ;

cond:
        cond_high
        | cond T_and cond
        | cond T_or cond
        | expr '=' expr
        | expr '#' expr
        | expr '>' expr
        | expr '<' expr
        | expr T_geq expr
        | expr T_leq expr
        ;

cond_high: 
        '(' cond ')'
        | T_not cond
        ;





%%

int main() {
  int result = yyparse();
  if (result == 0) printf("Success.\n");
  return result;

}