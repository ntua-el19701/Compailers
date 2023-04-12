%{

#include <stdio.h>
#define T_eof     0
#define T_and     1000
#define T_char    1001
#define T_div     1002
#define T_do      1003
#define T_else    1004
#define T_fun     1005
#define T_if      1006
#define T_int     1007
#define T_mod     1008
#define T_not     1009
#define T_nothing 1010
#define T_or      1011
#define T_ref     1012
#define T_return  1013
#define T_then    1014
#define T_var     1015
#define T_while   1016

#define T_name      1017
#define T_const_int 1018
#define T_const_char 1019
#define T_const_string 1020
#define T_compare 1021
#define T_assign  1022
#define T_writeInteger 1023
#define T_writeChar 1024
#define T_writeString 1025
#define T_readInteger 1026
#define T_readChar 1027
#define T_readString 1028
#define T_array_char 1029
#define T_array_int 1029



int lineno = 1;




%}

L [a-z,A-Z]
D [0-9]
W [ \t\n\r]

%x COMMENT
%option noyywrap

%%

"char"\[{D}*\]  {return T_array_char; }
"int"\[{D}*\]   {return T_array_int; }
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
"writeInteger"  {return T_writeInteger; }
"writeChar"     {return T_writeChar; }
"writeString"   {return T_writeString; }
"readInteger"   {return T_readInteger; }
"readChar"      {return T_readChar; }
"readString"    {return T_readString; }

'([^'\\]|\\([nrtr0\\\\'\"]|x[0-9a-fA-F]{2}))' {return T_const_char; } //for constant characters ('a')
[\=\+\-\*\#\(\)\{\}\[\]\,\;\:]  { return yytext[0]; }  
\>\=|\<\= {return T_compare;} 

\<\-                  {return T_assign;} 
\>|\<                 {return T_compare;}
{L}({L}|{D}|_)*       { return T_name; } //for variables
{D}+                  { return T_const_int; }        // constant integers 
\"[^"]+\"             {return T_const_string; }   // constant strings

"$"[^\n\$]([^\n])*\n  {/* single line comments*/ ++lineno;}

"$$"                  {BEGIN(COMMENT);} 
<COMMENT>"$$"         {BEGIN(INITIAL);}
<COMMENT>\n           {lineno++;}
<COMMENT>[^\n"$$"]*   {/*nothing*/}
<COMMENT><<EOF>>      { fprintf(stderr, "Unfinished comment at EOF\n"); exit(1); }



\n      {  ++lineno;}
{W}+    { /* return nothing */ }


.       { fprintf(stderr, "Illegal character %c at line %d\n", yytext[0], lineno); exit(42); }

%%

int main() {
  int token;
  do {
    token = yylex();
    
    printf("token = %d, lexeme = \"%s\"\n", token, yytext);
  } while(token != T_eof);
  return 0;
}
