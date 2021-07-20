#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int isDigit(char temp[])
{
  int i = 0;
  while (temp[i] != '\0')
  {
    if (temp[i] < 48 || temp[i] > 57)
    {
      return 0;
    }
    i++;
  }
  return 2;
}

int analyze(char token[])
{
  const char *keywords[] = {
      "auto", "break", "case", "char", "continue", "do", "default", "const",
      "double", "else", "enum", "extern", "for", "if", "goto", "float",
      "int", "long", "register", "return", "signed", "static", "sizeof", "short",
      "struct", "switch", "typedef", "union", "void", "while", "volatile", "unsigned"};

  const char *operators[] = {"+", "-", "*", "/", "%%", "++", "--", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "&", "|", "^", "<<", ">>", "=", "+=", "-=", "*=", "/=", "%%=", "sizeof", "&", "*", "?", "->"};
  int i = 0;

  for (i = 0; i < 32; i++)
  {
    if (strcmp(keywords[i], token) == 0)
    {
      return 1;
    }
  }

  return isDigit(token);

  for (i = 0; i < sizeof(operators) / sizeof(operators[0]); i++)
  {
    if (strcmp(operators[i], token) == 0)
    {
      return 3;
    }
  }
  return 0;
}

int main()
{

  char line[MAX] = "";
  char new_line[MAX] = "";
  int i = 0, index = 0;
  FILE *file = fopen("program.txt", "r");

  while (fgets(line, MAX, file))
  {
    for (i = 0; i < strlen(line) - 1; i++)
    {
      if (line[i] == ';')
        new_line[index++] = ' ';
      else if (line[i] != '{' && line[i] != '}' && line[i] != '(' && line[i] != ')')
        new_line[index++] = line[i];
    }
  }

  char *token = strtok(new_line, " ");
  while (token != NULL)
  {
    printf("%s\t - ", token);
    int flag = analyze(token);

    switch (flag)
    {
    case 1:
      printf("Keyword \n");
      break;
    case 2:
      printf("Number \n");
      break;
    case 3:
      printf("Operator \n");
      break;
    default:
      printf("Identifier\n");
      break;
    }

    token = strtok(NULL, " ");
  }

  return 0;
}