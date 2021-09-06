#include <stdio.h>
int main() {
	int i, n, bursttimes[100];
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter the burst times of the processes: ");
	for(i = 0; i < n; i++)
		scanf("%d", &bursttimes[i]);
	int cummulative = 0, TAtimes[100], waitingtimes[100];
	for(i = 0; i < n; i++) {
		cummulative += bursttimes[i];
		TAtimes[i] = cummulative;
	}
	for(i = 0; i < n; i++)
		waitingtimes[i] = TAtimes[i] - bursttimes[i];
	int TATsum = 0, WTsum = 0;
	for(i = 0; i < n; i++) {
		TATsum += TAtimes[i];
		WTsum += waitingtimes[i];
	}
	printf("Process\tBT\tTAT\tWT\n");
	for(i = 0; i < n; i++) 
		printf("P%d\t%d\t%d\t%d\n", i, bursttimes[i], TAtimes[i], waitingtimes[i]);
	printf("Average Turnaround Time = %.2f\n", (float)TATsum / n);
	printf("Average Waiting Time = %.2f\n", (float)WTsum / n);
	return 0;
}
