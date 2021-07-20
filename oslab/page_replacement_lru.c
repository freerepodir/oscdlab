#include<stdio.h>
#include<conio.h>

int main() {
  int i, j, k, min, rs[25], m[10], count[10], flag[25], n, f, pf = 0, next = 1;
  printf("Enter the number of pages.\n");
  scanf("%d", &n);
  printf("Enter the number of frames.\n");
  scanf("%d", &f);
  for (i = 0; i < f; i++) {
    count[i] = 0;
    m[i] = -1;
  }
  printf("Enter the pages.\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &rs[i]);
    flag[i] = 0;
  }
  
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < f; j++) {
      if (m[j] == rs[i]) {
        flag[i] = 1;
        count[j] = next;
        next++;
      }
    }
    if (flag[i] == 0) {
      if (i < f) {
        m[i] = rs[i];
        count[i] = next;
        next++;
      } else {
        min = 0;
        for (j = 1; j < f; j++)
          if (count[min] > count[j])
            min = j;
        m[min] = rs[i];
        count[min] = next;
        next++;
      }
      pf++;
    }
    for (j = 0; j < f; j++)
      printf("%d\t", m[j]);
    printf("\n");
  }
  printf("\nTotal number of page faults : %d", pf);
  return 0;
}
