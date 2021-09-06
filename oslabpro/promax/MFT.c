#include <stdio.h>
int main() {
	int i, memorysize, blocksize, processes, extfragmentation, intfragmentation, totalintfragmentation = 0, numblocks;
	int processsize[10], count = 0;
	printf("Enter the size of the memory: ");
	scanf("%d", &memorysize);
	printf("Enter the size of each block of memory: ");
	scanf("%d", &blocksize);
	printf("Enter the number of processes: ");
	scanf("%d", &processes);
	numblocks = memorysize / blocksize;
	extfragmentation = memorysize - (blocksize * numblocks);
	printf("The number of blocks available in the memory = %d.\n", numblocks);
	for(i = 0; i < processes; i++) {
		printf("Enter the size of process %d: ", i + 1);
		scanf("%d", &processsize[i]);
	}
	printf("Process:\tMemory Required:\tAllocated:\tInternal Fragmentation:\n");
	for(i = 0; i < processes && count < numblocks; i++) {
		printf("%d\t\t%d\t\t", i + 1, processsize[i]);
		if(processsize[i] > blocksize) {
			printf("NO\t\t---\n");	
		} else {
			intfragmentation = blocksize - processsize[i];
			totalintfragmentation += intfragmentation;
			printf("YES\t\t%d\n", intfragmentation);
			count++;
		}
	}
	if(i < processes)
		printf("Memory full. The rest of the processes cannot be accomodated.\n");
	printf("Internal Fragmentation = %d\n", totalintfragmentation);
	printf("External Fragmentation = %d\n", extfragmentation);
	return 0;
}
