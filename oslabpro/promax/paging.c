#include <stdio.h>
int main() {
	int pages[50], i, n, frames, offset, pagenumber;
	printf("Enter the number of pages in the memory.\n");
	scanf("%d", &n);
	printf("Enter number of frames.\n");
	scanf("%d", &frames);
	for (i = 0; i < n; i++)
		pages[i] = -1;
	printf("\nEnter the page table.");
	printf("\nEnter frame number as -1 if that page is not present in any frame.\n\n");
	printf("\nPage Number\tFrame Number\n");
	for (i = 0; i < n; i++) {
		printf("\n%d\t\t", i);
		scanf("%d", &pages[i]);
	}
	printf("\n\nEnter the logical address (page number and offset).");
	scanf("%d%d", &pagenumber, &offset);
	if (pages[pagenumber] == -1)
		printf("\n\nThe required page is not available in any frame.");
	else
		printf("\n\nPhysical Address (frame number and offset): %d|%d", pages[pagenumber], offset);
	return 0;
}
