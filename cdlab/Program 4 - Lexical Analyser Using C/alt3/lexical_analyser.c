#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool isDelimeter(char ch)
{
if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || ch == '(' ||ch == ')' || ch =='[' ||  ch == '[' || ch == ']' || ch == '{' || ch == '}')
return (true);
return (false);
}
bool isOperator(char ch)
{
if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=')
return (true);
return (false);
}
bool isKeyword(char* str)
{
if (!strcmp(str,"for") || !strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") || !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
return (true);
return (false);
}
void main(){
FILE *ptr;
char c,tok[100];
int n=0,i;
ptr=fopen("ip.txt","r");
c=fgetc(ptr);
while(c!=EOF){
if(!isDelimeter(c)){
tok[n]=c;
n++;
}
else{
tok[n]='\0';
if(n!=0){
if(isKeyword(tok)){
printf("%s is a keyword.\n",tok);
}
else{
printf("%s is a identifier.\n",tok);
}
if(isOperator(c)){
printf("%c is a operator.\n",c);
}
}
n=0;
}
c=fgetc(ptr);
}
fclose(ptr);
}
