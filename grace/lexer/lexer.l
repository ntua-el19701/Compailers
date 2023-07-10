%{

#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "../ast/ast.hpp"
#include "lexer.hpp"
#include "../parser/parser.hpp"
#define T_eof     0


int lineno = 1;



%}

L [a-z|A-Z]
D [0-9]
W [ \t\n\r]

%x COMMENT
%option noyywrap

%%


"and"           { return T_and; }
"char"          { return T_char; }
"div"           { return T_div; }
"do"            { return T_do; }
"else"          { return T_else; }
"fun"           { return T_fun; }
"if"            { return T_if; }
"int"           { return T_int; }
"mod"           { return T_mod; }
"not"           { return T_not; }
"nothing"       { return T_nothing; }
"or"            { return T_or; }
"ref"           { return T_ref; }
"return"        { return T_return; }
"then"          { return T_then; }
"var"           { return T_var; }
"while"         { return T_while; }
"writeInteger"  { return T_writeInteger; }
"writeChar"     { return T_writeChar; }
"writeString"   { return T_writeString; }



'([^'\\]|\\([nrtr0\\\\'\"]|x[0-9a-fA-F]{2}))' { yylval.const_char = yytext; return T_const_char; } //for constant characters ('a')
[\=\+\-\*\#\(\)\{\}\[\]\,\;\:\>\<]            { yylval.op = yytext[0]; return yytext[0]; }  
\>\= {return T_geq;} 
\<\= {return T_leq;} 

\<\-                  {return T_assign;} 

{L}({L}|{D}|_)*       { yylval.id = strdup(yytext); return T_id; } //for variables
{D}+                  { yylval.num = atoi(yytext); return T_const_int; }        // constant integers 


\"(\\.|[^"\\\n])*\"   { yylval.const_str = strdup(yytext); return T_const_string; } // for const string
"$"[^\n\$]([^\n])*\n  {/* single line comments*/ ++lineno;}

"$$"                  {BEGIN(COMMENT);} 
<COMMENT>"$$"         {BEGIN(INITIAL);}
<COMMENT>\n           {lineno++;}
<COMMENT>[^\n"$$"]*   {/*nothing*/}
<COMMENT><<EOF>>      { fprintf(stderr, "Unfinished comment at EOF\n"); exit(1); }


\n    { /* increment line number for each newline character */ lineno ++;}

{W}+    { /* return nothing */ }


.       {  fprintf(stderr, "Illegal character %c at line %d\n", yytext[0], lineno); exit(42); }

%%

  void yyerror(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(1);
  }
/*
int main() {
  int token;
  do {
    token = yylex();
    
    printf("token = %d, lexeme = \"%s\"\n", token, yytext);
  } while(token != T_eof);
  return 0;
  }*/
  

  


