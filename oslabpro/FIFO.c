#include <stdio.h>
int main()
{
  int i, j, index = 0, flag, nframes, npages, frames[100], pages[100], faults = 0;
  printf("Enter the number of frames: ");
  scanf("%d", &nframes);
  printf("Enter the number of pages: ");
  scanf("%d", &npages);
  printf("Enter the sequence of pages: ");
  for (i = 0; i < npages; i++)
    scanf("%d", &pages[i]);
  for (i = 0; i < nframes; i++)
    frames[i] = -1;
  for (i = 0; i < nframes; i++)
    printf("Frame %d\t", i + 1);
  printf("\n");
  for (i = 0; i < npages; i++)
  {
    flag = 0;
    for (j = 0; j < nframes; j++)
    {
      if (frames[j] == pages[i])
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
    {
      if (index < nframes)
      {
        frames[index++] = pages[i];
        faults++;
      }
      else
      {
        index = 0;
        frames[index++] = pages[i];
        faults++;
      }
    }
    for (j = 0; j < nframes; j++)
      printf("%d\t", frames[j]);
    printf("\n");
  }
  printf("The total number of page faults is: %d\n", faults);
  return 0;
}