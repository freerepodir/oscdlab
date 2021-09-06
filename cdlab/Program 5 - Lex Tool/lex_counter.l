%{
#include<stdio.h>
int lines=0,words=0,sl=0,cl=0,num=0,spl_chr=0,tot=0;
%}
%%
\n {lines++, words++;}
[\t ' '] {words++;}
[A-Z] {cl++;}
[a-z] {sl++;}
[0-9] {num++;}
. {spl_chr++;}
%%
int main()
{
yyin=fopen("ex.txt","r");
yylex();
tot=sl+cl+num+spl_chr;
printf("total no. of symbols :%d\n", tot);
printf("no. of Lines:%d\n", lines);
printf("no. of words:%d\n", words);
printf("no. of lower case letters:%d\n", sl);
printf("no. of upper case letters:%d\n", cl);
printf("no. of special characters:%d\n", spl_chr);
printf(" no. of digits:%d\n", num);
return 0;
}
int yywrap()
{
return 1;
}
