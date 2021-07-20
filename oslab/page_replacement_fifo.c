#include<stdio.h>
#include<conio.h>

int main() {
  int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;
  printf("Enter the number of pages.\n");
  scanf("%d", & n);
  printf("Enter the number of frames.\n");
  scanf("%d", & f);
  for (i = 0; i < f; i++)
    m[i] = -1;
  printf("Enter the pages.\n");
  for (i = 0; i < n; i++)
    scanf("%d", & rs[i]);
  printf("\n");
  for (i = 0; i < n; i++) {
    for (k = 0; k < f; k++) {
      if (m[k] == rs[i])
        break;

    }
    if (k == f) {
      m[count++] = rs[i];
      pf++;
    }
    for (j = 0; j < f; j++)
      printf("\t%d", m[j]);
    printf("\n");
    if (count == f)
      count = 0;

  }
  printf("\nTotal number of page faults : %d", pf);
  return 0;
}
