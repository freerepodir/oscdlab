
%{
#include<stdio.h>
int keywords = 0, identifiers = 0, numbers = 0, operators = 0;
%}
%%
"int"|"void" {printf("keyword"); keywords++;}
"auto"|"break"|"case"|"char"|"continue"|"do"|"default"|"const"|"double"|"else"|"enum"|"extern"|"for"|"if"|"goto"|"float"|"int"|"long"|"register"|"return"|"signed"|"static"|"sizeof"|"short"|"struct"|"switch"|"typedef"|"union"|"void"|"while"|"volatile"|"unsigned" {printf("keyword"); keywords++;}
"+"|"-"|"*"|"/"|"++"|"--"|"="|"=="|"!"|"&"|"^" {printf("operator"); operators++}
[a-zA-Z][a-zA-Z]*[0-9]* {printf("identifier"); identifiers++;}
[0-9] {printf("Numbers"); numbers++}
%%

int main(){
    yyin = fopen("program.txt", "r");
    yylex();
    printf("Keywords: %d\n", keywords);
    printf("Identifiers: %d\n", identifiers);
    printf("Operators: %d\n", operators);
    printf("Numbers: %d\n", numbers);
}
int yywrap(){
    return 1;
}
