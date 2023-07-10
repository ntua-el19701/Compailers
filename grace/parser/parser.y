%{
#include <cstdio>
#include <iostream>
#include "../lexer/lexer.hpp"
#include "../ast/ast.hpp"

#include <string>
using namespace std;


extern int lineno;
SymbolTable st;
%}

%union{   
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
 
}


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
%token T_writeInteger "writeInteger"
%token T_writeChar    "writeChar"
%token T_writeString  "writeString"



%token<id>  T_id             
%token<num> T_const_int "const_int"
%token<const_char> T_const_char 
%token<const_str> T_const_string 
%token T_geq ">="
%token T_leq "<="
%token T_assign "<-"


%nonassoc '=' '#' '>' '<' "<=" ">=" 
%nonassoc "not"
%left "and"
%left "or"
%left '+' '-'
%left '*' "div" "mod" 



%expect 1 //if then else


%type<program> program
%type<stmt> stmt
%type<expr> expr
%type<cond> cond
%type<stmt_list> stmt_list 
%type<stmt_list> block
%type<func_def> func_def
%type<local_def_gen> local_def_gen
%type<header> header
%type<fpar_def_gen> fpar_def_gen
%type<fpar_def> fpar_def
%type<comma_id_gen> comma_id_gen
%type<type> type
%type<typos> data_type
%type<type_gen> type_gen
%type<ret_type> ret_type 
%type<fpar_type> fpar_type 
%type<local_def> local_def
%type<func_decl> func_decl
%type<var_def> var_def
%type<func_call_stmt> func_call_stmt 
%type<func_call_expr> func_call_expr 
%type<comma_expr_gen> comma_expr_gen
%type<l_value> l_value
%type<expr_high> expr_high
%type<cond_high> cond_high


%%

program:
        func_def                                                    {  std::cout << *$1;}
        ;

func_def:       
        header local_def_gen block                                  { $1->sem(); $$ = new Func_def($1, $2, $3);  st.closeScope();}
        ;

local_def_gen:                                          
        /*nothing*/                                                 { $$ = nullptr; }
        | local_def local_def_gen                                   { $$ = new Local_def_gen($1, $2); }
        ;
        
header: 
        T_fun T_id '(' ')' ':' ret_type                             { $$ = new Header($2, nullptr, nullptr, $6); }
        | T_fun T_id '(' fpar_def fpar_def_gen ')' ':' ret_type     { $$ = new Header($2, $4, $5, $8); } 
        ;
        
fpar_def_gen:                                                       
        /*nothing*/                                                 { $$ = nullptr; }
        | ';' fpar_def fpar_def_gen                                 { $$ = new Fpar_def_gen($2, $3); }
        ;

fpar_def:
        T_ref T_id comma_id_gen ':' fpar_type                       { $$ = new Fpar_def(true, $2, $3, $5); }
        | T_id comma_id_gen ':' fpar_type                           { $$ = new Fpar_def(false, $1, $2, $4); }
        ;

comma_id_gen: 
        /*nothing*/                                                 { $$ = nullptr; }
        | ',' T_id comma_id_gen                                     { $$ = new Comma_id_gen($2, $3); }
        ;

data_type: 
        T_int                                                       { $$ =  TYPE_int; }
        | T_char                                                    { $$ =  TYPE_char; }
        ;

type:
        data_type type_gen                                          { $$ = new Type($1, $2); }
        ;

type_gen:
        /*nothing*/                                                 { $$ = nullptr; }
        | '[' T_const_int ']' type_gen                              { $$ = new Type_gen($2, $4); } //array?
        ;

ret_type:                                                          
        data_type                                                   { $$ = new Ret_type($1); }
        | T_nothing                                                 { $$ = new Ret_type(TYPE_nothing); }
        ;

fpar_type:
        data_type '[' ']' type_gen                                  { $$ = new Fpar_type($1, $4, 1); }
        | data_type type_gen                                        { $$ = new Fpar_type($1, $2, 0); }
        ;

local_def:                                                          
        func_def                                                    { $$ = new Local_def($1, nullptr, nullptr); }                                 
        | func_decl                                                 { $$ = new Local_def(nullptr, $1, nullptr); }
        | var_def                                                   { $$ = new Local_def(nullptr, nullptr, $1); }
        ;

func_decl: 
        header ';'                                                  { $$ = new Func_decl($1); }
        ;

var_def: 
        T_var T_id comma_id_gen ':' type ';'                        { $$ = new Var_def($2, $3, $5); }
        ;

stmt: 
        ';'                                                         { $$ = nullptr; }
        | l_value T_assign expr ';'                                 { $$ = new Assign($1, $3); }
        | block                                                     { $$ = $1; }   
        | func_call_stmt ';'                                        { $$ = $1; }
        | T_if cond T_then stmt                                     { $$ = new If($2, $4, nullptr); }    
        | T_if cond T_then stmt T_else stmt                         { $$ = new If($2, $4, $6); }
        | T_while cond T_do stmt                                    { $$ = new While($2, $4); }
        | T_return ';'                                              { $$ = new Return(nullptr); }
        | T_return expr ';'                                         { $$ = new Return($2); }
        | T_writeInteger '(' T_id ')' ';'                           { $$ = new Write_Integer($3, -1); }
        | T_writeInteger '(' T_const_int ')' ';'                    { $$ = new Write_Integer(nullptr, $3); }
        | T_writeChar '(' T_id ')' ';'                              { $$ = new Write_Char($3); }
        | T_writeString '(' T_id ')' ';'                            { $$ = new Write_String($3,nullptr,0); }
        | T_writeString '(' T_const_string ')' ';'                  { $$ = new Write_String(nullptr,$3,1); }

        ;

block: '{' stmt_list '}'                                            { $$ = $2;  }                             
        ;

stmt_list: 
        /*nothing*/                                                 { $$ = new Block(); }
        | stmt_list stmt                                            { $1->append_stmt($2); }
        ;

func_call_stmt:      
        T_id '(' ')'                                                { $$ = new Func_call_stmt($1, nullptr, nullptr); }
        | T_id '(' expr comma_expr_gen ')'                          { $$ = new Func_call_stmt($1, $3, $4); }
        ;

func_call_expr:      
        T_id '(' ')'                                                { $$ = new Func_call_expr($1, nullptr, nullptr); }
        | T_id '(' expr comma_expr_gen ')'                          { $$ = new Func_call_expr($1, $3, $4); }
        ;


comma_expr_gen: 
        /*nothing*/                                                 { $$ = nullptr; }
        | ',' expr comma_expr_gen                                   { $$ = new Comma_expr_gen($2, $3); }
        ;

l_value:       
        T_id                                                        { $$ = new L_value(nullptr,nullptr,$1,nullptr,1); }    
        | T_const_string                                            { $$ = new L_value(nullptr, nullptr, nullptr, $1,2); }
        | l_value '[' expr ']'                                      { $$ = new L_value($1, $3,nullptr, nullptr,3 ); }
        ;

expr: 
        T_const_int                                                 { $$ = new IntConst($1); }
        | T_const_char                                              { $$ = new Const_char($1); }
        | l_value                                                   { $$ = $1; }
        | expr_high                                                 { $$ = $1; }
        | func_call_expr                                            { $$ = $1; }
        | expr '+' expr                                             { $$ = new BinOp($1,"+",$3); }
        | expr '-' expr                                             { $$ = new BinOp($1,"-",$3); } 
        | expr '*' expr                                             { $$ = new BinOp($1,"*",$3); }
        | expr T_div expr                                           { $$ = new BinOp($1,"/",$3); }
        | expr T_mod expr                                           { $$ = new BinOp($1,"%",$3); }
        ;

expr_high: 
        '(' expr ')'                                                { $$ = $2; }
        | '+' expr                                                  { $$ = new UnOp('+', $2); }     
        | '-' expr                                                  { $$ = new UnOp('-', $2); }
        ;

cond:
        cond_high                                                   { $$ = $1; }
        | cond T_and cond                                           { $$ = new Cond($1, "&&", $3); }
        | cond T_or cond                                            { $$ = new Cond($1, "||", $3); }
        | expr '=' expr                                             { $$ = new Compare($1, "=", $3); }
        | expr '#' expr                                             { $$ = new Compare($1, "#", $3); }
        | expr '>' expr                                             { $$ = new Compare($1, ">", $3); }
        | expr '<' expr                                             { $$ = new Compare($1, "<", $3); }
        | expr T_geq expr                                           { $$ = new Compare($1, ">=", $3); }
        | expr T_leq expr                                           { $$ = new Compare($1, "<=", $3); }
        ;

cond_high: 
        '(' cond ')'                                                { $$ = $2; }
        | T_not cond                                                { $$ = new Cond($2,"!",nullptr); }
        ;





%%

int main() {
  int result = yyparse();
  if (result == 0) printf("Success.\n");
  return result;

}