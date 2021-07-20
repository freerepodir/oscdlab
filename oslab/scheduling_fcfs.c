#include <stdio.h>

void main()
{
	int i, j, n, b[10], p[10], w[10], t[10];
	float tw = 0, tt = 0, avgw, avgt;
	printf("Enter the number of processes.\n");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("\n\nEnter Process ID.\t");
		scanf("%d", &p[i]);
		printf("Enter Burst Time.\t");
		scanf("%d", &b[i]);
	}

	b[0] = 0, w[0] = 0;
	for (i = 1; i <= n; i++)
	{
		w[i] = w[i - 1] + b[i - 1];
		tw = tw + w[i];
		t[i] = w[i] + b[i];
		tt = tt + t[i];
	}

	avgw = tw / n;
	avgt = tt / n;
	printf("pid \t bt \t wt \t tat \n");
	for (i = 1; i <= n; i++)
	{
		printf("p[%d]\t %d\t %d\t %d\n", i, b[i], w[i], t[i]);
	}

	printf("Average waiting time is %f\n Average turn around time is %f", avgw, avgt);
}
