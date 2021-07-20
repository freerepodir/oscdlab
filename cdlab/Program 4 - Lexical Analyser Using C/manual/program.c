#include <stdio.h>
#include <conio.h>
#include <string.h>

FILE * fp;
static char ch;
char keyword[8][10] = { "int", " main", "printf", "float", "if", "else", "break", "char" };
char brace[10] = { '(', ')', '{', '}', '[', ']' };
char oper[10] = { '+', '-', '*', '/', '%', '<', '>', '=' };
char sym[10] = { '.', ',', ';', ':', '|', '#', '"' };
char identifier[32];
char number[10];
int i;
void scantoken();
void main()
{
	fp = fopen("input.txt", "r");
	ch = getc(fp);
	printf("\ntoken-----------lexeme\n");
	while (!feof(fp))
	{
		scantoken();
	}

	fclose(fp);
}

void scantoken()
{
	int j;
	for (i = 0; i < 10; i++)
	{
		if (brace[i] == ch)
		{
			printf("Brace----%c\n", ch);
			ch = getc(fp);
		}
	}

	for (i = 0; i < 10; i++)
	{
		if (oper[i] == ch)
		{
			printf("operator----%c\n", ch);
			ch = getc(fp);
		}
	}

	for (i = 0; i < 10; i++)
	{
		if (sym[i] == ch)
		{
			printf("Symbol----%c\n", ch);
			ch = getc(fp);
		}
	}

	if (isalpha(ch))
	{
		identifier[0] = ch;
		identifier[1] = '\0';
		j = 1;
		ch = getc(fp);
		while (isalnum(ch))
		{
			identifier[j++] = ch;
			ch = getc(fp);
		}

		identifier[j] = '\0';
		if (key() == 1)
		{
			printf("keyword------%s\n", identifier);
		}
		else
		{
			printf("identifier-----%s\n", identifier);
		}
	}
	else if(isdigit(ch))
	{
		number[0] = ch;
		j = 1;
		ch = getc(fp);
		while (isdigit(ch))
		{
			number[j++] = ch;
			ch = getc(fp);
		}

		identifier[j] = '\0';
		printf("number----%s\n", number);
	}
	else if(isspace(ch))
	{
		ch = getc(fp);
	}
}

int key()
{
	int flag = 0;
	for (i = 0; i < 8; i++)
	{
		if (strcmp(keyword[i], identifier) == 0)
		{
			flag = 1;
			break;
		}
	}

	return flag;
}
