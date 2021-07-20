#include <stdio.h>

int main()
{
	int n, m[20], i, j, sb[20], s[20], b[20][20], x;
	printf("Enter the number of files.\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("\nFor File %d, enter the following.\n",i+1);
		printf("\t Starting Block, Size of File :");
		scanf("%d%d", &sb[i], &s[i]);
		printf("\t Number of blocks occupied :");
		scanf("%d", &m[i]);
		printf("\t Blocks :");
		for (j = 0; j < m[i]; j++)
			scanf("%d", &b[i][j]);
	}

	printf("\nFile\t Index\t Length\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t%d\t%d\n", i + 1, sb[i], m[i]);
	}
	
	return 0;
}
