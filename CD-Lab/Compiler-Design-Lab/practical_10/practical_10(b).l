%{
#include<stdio.h>
%}

%%

\<[^>]*\>      { printf("HTML Tag: %s\n", yytext); }

.|\n           ;

%%

int main()
{
    yyin = fopen("input.html","r");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}