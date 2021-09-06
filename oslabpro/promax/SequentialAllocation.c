#include <stdio.h>
int main() {
	int n, i, j, blocklengths[20], startingblocks[20], temp[20], c[20][20];
	printf("Enter no.of files:");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Enter no. of blocks occupied by File %d.\t", i + 1);
		scanf("%d", &blocklengths[i]);
		printf("Enter the starting block of File %d. \t", i + 1);
		scanf("%d", &startingblocks[i]);
		temp[i] = startingblocks[i];
		for (j = 0; j < blocklengths[i]; j++)
			c[i][j] = startingblocks[i]++;
	}
	printf("Filename\tStart block\tLength\n");
	for (i = 0; i < n; i++)
		printf("%d\t  %d \t%d\n", i + 1, temp[i], blocklengths[i]);	
	return 0;
}
