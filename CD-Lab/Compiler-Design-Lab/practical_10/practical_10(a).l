%{
#include<stdio.h>
%}

%%

[0-9]+      { printf("Number: %s\n", yytext); }

.|\n        ;

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