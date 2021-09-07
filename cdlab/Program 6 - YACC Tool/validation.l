%{

#include "y.tab.h"

%}

%%
[a-zA-Z][a-zA-Z]* return ID;

. return yytext[0];
\n return 0;
%%

int yywrap(){
return 1;
}
