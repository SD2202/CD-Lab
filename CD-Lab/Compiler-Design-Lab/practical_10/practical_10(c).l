%{
#include<stdio.h>

int line = 1;
%}

%%

^      { printf("%d ", line++); }
.*\n   { printf("%s", yytext); }

%%

int main()
{
    yyin = fopen("input.txt","r");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}