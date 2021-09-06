#include <stdio.h>
#define MAX 50
int main()
{
	int page[MAX], i, n, f, ps, off, pno;
	printf("Enter the number of pages in the memory.\n");
	scanf("%d", &n);
	printf("Enter page size.\n");
	scanf("%d", &ps);
	printf("Enter no of frames.\n");
	scanf("%d", &f);
	for (i = 0; i < n; i++)
		page[i] = -1;
	printf("\nEnter the page table.");
	printf("\nEnter frame no as -1 if that page is not present in any frame.\n\n");
	printf("\nPage Number\tFrame Number\n");
	for (i = 0; i < n; i++)
	{
		printf("\n%d\t\t", i);
		scanf("%d", &page[i]);
	}

	printf("\n\nEnter the logical address ( page number and offset ).");
	scanf("%d%d", &pno, &off);
	if (page[pno] == -1)
		printf("\n\nThe required page is not available in any frame.");
	else
		printf("\n\nPhysical Address (Frame Number and Offset) : %d|%d", page[pno], off);

	return 1;
}
