#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX 100
int identifier(char str1[])
{
char keywords[32][10] = {
"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","while","volatile"};
char operators[32][10] = {
"+","-","*","/","%","++","--","==","!=",">","<",">=","<=","&&",
"||","!","&","|","^","<<",">>","=","+=","-=","*=","/=","%=",
"sizeof","&","*","?","->"};
int i, flag = 0;
for(i=0; i<32; i++)
{
if (strcmp(str1,keywords[i])==0)
flag=1;
}
if(flag==0)
{
for(i=0;i<32;i++)
{
if(strcmp(str1,operators[i])==0)
flag  = -1;
}
}
return flag;
}
void tokenizer()
{
char line[MAX] = "";
char new_line[MAX] = "";
int line_count = 0, index = 0;
FILE *file = fopen("fu.txt", "r");
while (fgets(line, MAX, file))
{
line_count++;
for(int i=0; i<strlen(line)-1; i++)
{
if(line[i]==';')
new_line[index++] = ' ';
else if(line[i]!='{'&&line[i]!='}'&&line[i]!='('&&line[i]!=')')
new_line[index++] = line[i]; 
}  	
}
char* token = strtok(new_line, " ");
while (token != NULL) 
{
printf("%s : ", token);
int flag = identifier(token);
switch(flag)
{
case 1:
printf("Keyword \n");
break;
case -1:
printf("Operator \n");
break;
case 0:
printf("Identifier \n");
break;	
} 
token = strtok(NULL, " ");     
}
}


void main()
{
tokenizer();
}
