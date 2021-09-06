  
%{
#include<stdio.h>
%}
%%
"int"|"void" {printf("Keyword");}
"auto"|"break"|"case"|"char"|"continue"|"do"|"default"|"const"|"double"|"else"|"enum"|"extern"|"for"|"if"|"goto"|"float"|"int"|"long"|"register"|"return"|"signed"|"static"|"sizeof"|"short"|"struct"|"switch"|"typedef"|"union"|"void"|"while"|"volatile"|"unsigned" {printf("keyword");}
[a-zA-Z][a-zA-Z]*[0-9]* {printf("identifier");}
[0-9] {printf("Numbers");}
%%

int main(){
    yyin = fopen("program.txt", "r");
    yylex();
}
int yywrap(){
    return 1;
}
