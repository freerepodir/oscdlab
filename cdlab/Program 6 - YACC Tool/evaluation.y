%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%token NUMBER ID

%left '+' '-'
%left '*' '/'
%%
E : T        {
                printf("Result = %d\n", $$);
                return 0;
            }
 
T :
    T '+' T { $$ = $1 + $3; }
    | T '-' T { $$ = $1 - $3; }
    | T '*' T { $$ = $1 * $3; }
    | T '/' T { $$ = $1 / $3; }
  

    | '(' T ')' { $$ = $2; }
    | NUMBER { $$ = $1; }
    | ID { $$ = $1; };
%%

int main(){
	
	printf("enter the expression\n");
	yyparse();
	printf("\n valid");
	return 0;
}

yyerror(){
 printf("\n invalid");
}
