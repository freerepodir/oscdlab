%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token ID
%left '+'
%left '*'
%%
E:E'+'E|E'*'E|'('E')'|ID
%%

int main(){

    printf("enter the expression\n");
    yyparse();
    printf("\n valid");
    return 0;
}

yyerror(){
    printf("\n invalid");
    exit(0);
}
