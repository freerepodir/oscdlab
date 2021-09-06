#include <stdio.h>
int main() {
    int capacity, nprocesses, i, memory, total_stored;
    printf("Enter the memory capacity: ");
    scanf("%d", &capacity);
    printf("Enter the number of processes: ");
    scanf("%d", &nprocesses);
    for (i = 0; i < nprocesses; i++) {
        printf("\nEnter the memory required for process%d: ", i + 1);
        scanf("%d", &memory);
        total_stored += memory;
        if (memory <= capacity) {
            if (total_stored == capacity) {
                printf("Memory Full\n");
            }
            printf("memory allocated for process%d is %d\n", i + 1, capacity);
            printf("remaining memory: %d\n", capacity - memory);
            capacity -= memory;
        }
        else {
            printf("memory not allocated.\n");
        }
        printf("external fragmentation for this process is:%d \n", capacity);
    }
    return 0;
}
