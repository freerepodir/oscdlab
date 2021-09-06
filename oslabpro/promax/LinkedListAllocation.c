#include <stdio.h>
struct file {
	char name[10];
	int start, size, block[10];
} f[10];
int main() {
	int i, j, n;
	printf("Enter the number of files.");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("\nFor file %d, enter", i + 1);
		printf("\n\tName of the File : \t");
		scanf("%s", &f[i].name);
		printf("\tStarting Block : \t");
		scanf("%d", &f[i].start);
		f[i].block[0] = f[i].start;
		printf("\tNumber of Blocks : \t");
		scanf("%d", &f[i].size);
		printf("\tBlock Numbers : \t");
		for (j = 1; j <= f[i].size; j++)
			scanf("%d", &f[i].block[j]);
	}
	printf("\n\nFile\tStart\tSize\tBlock\n");
	for (i = 0; i < n; i++) {
		printf("%s\t%d\t%d\t", f[i].name, f[i].start, f[i].size);
		for (j = 1; j <= f[i].size - 1; j++)
			printf("%d--->", f[i].block[j]);
		printf("%d", f[i].block[j]);
		printf("\n");
	}
	return 0;
}
