#include <stdio.h>

void main()
{
	int i, j, n, b[10], p[10], w[10], t[10], pr[10];
	float tw = 0, tt = 0, avgw, avgt, temp1, temp2, temp3;
	printf("Enter the number of processes.\n");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("\n\n\tEnter Process ID.\t");
		scanf("%d", &p[i]);
		printf("\tEnter Burst Time.\t");
		scanf("%d", &b[i]);
		printf("\tEnter Priority.\t");
		scanf("%d", &pr[i]);
	}

	for (i = 1; i <= n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (pr[i] >= pr[j])
			{
				temp1 = b[i];
				b[i] = b[j];
				b[j] = temp1;
				temp2 = p[i];
				p[i] = p[j];
				p[j] = temp2;
				temp3 = pr[i];
				pr[i] = pr[j];
				pr[j] = temp3;
			}
		}
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
	printf("pid \t bt \t wt \t pr \t tat \n");
	for (i = 1; i <= n; i++)
	{
		printf("p[%d]\t %d\t %d\t %d\t %d\n", p[i], b[i], w[i], pr[i], t[i]);
	}

	printf("Average Waiting Time is %f\n Average Turnaround Time is %f", avgw, avgt);
}
