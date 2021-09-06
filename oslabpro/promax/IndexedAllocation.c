#include <stdio.h>
int main() {
	int n, i, j, blocklengths[20], startingblocks[20], blocks[20][20];
	printf("Enter the number of files.\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("\nFor File %d, enter the following.\n", i + 1);
		printf("\t Starting Block:");
		scanf("%d", &startingblocks[i]);
		printf("\t Number of blocks occupied :");
		scanf("%d", &blocklengths[i]);
		printf("\t Blocks :");
		for (j = 0; j < blocklengths[i]; j++)
			scanf("%d", &blocks[i][j]);
	}
	printf("\nFile\t Index\t Length\n");
	for (i = 0; i < n; i++)
		printf("%d\t%d\t%d\n", i + 1, startingblocks[i], blocklengths[i]);
	return 0;
}
