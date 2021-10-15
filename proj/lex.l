%{
#include "gram.tab.hpp"
%}

%option yylineno
%option noyywrap

%%
[a-z][a-zA-Z0-9]*	{cout << "lexindif\n";return indificator;}
[A-Z][a-zA-Z0-9]*	{cout << "lexname\n";return argname;}

"("	{cout << "lex ls\n";return ls;}
")"	{cout << "lex rs\n";return rs;}
"."	{cout << "lex point\n"; return point;}
","	{cout << "lex comma\n"; return comma;}
";"	{cout << "lex semicolon\n"; return semicolon;}

":-"	{cout << "lex :-"; return ravno;}

[ \t\n]+ {}
<<EOF>>  {return 0;}

. {cout << "char err = " << *yytext << endl;}
%%
