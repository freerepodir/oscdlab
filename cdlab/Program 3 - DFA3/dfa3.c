// DFA for a string of length atmost 3
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
      state = 1;
      break;
    case 1:
      state = 2;
      break;
    case 2:
      state = 3;
      break;
    case 3:
      state = 4;
      break;
    case 4:
      state = 4;
      break;
    }
    i++;
  } while (i < n);
  if (state != 4)
    printf("Input accepted.\n");
  else
    printf("Input rejected.\n");
  return 0;
}