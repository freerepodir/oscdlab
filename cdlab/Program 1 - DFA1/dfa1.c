// DFA that accepts strings which have 011 as a substring
#include <stdio.h>
int main()
{
  int n, i, input[100];
  printf("Enter the length of the input: ");
  scanf("%d", &n);
  printf("Enter the input: ");
  for (i = 0; i < n; i++)
    scanf("%1d", &input[i]);
  int state = 0;
  i = 0;
  do
  {
    switch (state)
    {
    case 0:
      if (input[i] == 0)
        state = 1;
      else
        state = 0;
      break;
    case 1:
      if (input[i] == 0)
        state = 0;
      else
        state = 2;
      break;
    case 2:
      if (input[i] == 0)
        state = 0;
      else
        state = 3;
      break;
    }
    i++;
  } while (i < n);
  if (state == 3)
    printf("Input accepted.\n");
  else
    printf("Input rejected.\n");
}