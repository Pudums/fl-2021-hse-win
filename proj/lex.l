%{
#include "gram.tab.hpp"

%}

%option yylineno
%option noyywrap

%%
[a-z][a-zA-Z0-9]*	{yylval.name_ = new string(yytext);return indificator;}
[A-Z][a-zA-Z0-9]*	{yylval.name_ = new string(yytext);return argname;}

"("	{return ls;}
")"	{return rs;}
"."	{return point;}
","	{return comma;}
";"	{return semicolon;}
"?" {return question;}

":-"	{return ravno;}

[ \t\n]+ {}
<<EOF>>  {return 0;}

. {cout << "char err = " << *yytext << endl;}
%%

