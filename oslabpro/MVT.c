#include <stdio.h>

void main()
{
	int m = 0, m1 = 0, m2 = 0, p, count = 0, i;
	printf("Enter the total memory capacity.\n");
	scanf("%d", &m);
	printf("Enter the total number of processes.\n");
	scanf("%d", &p);
	for (i = 0; i < p; i++)
	{
		printf("Enter the size required to process %d.\n", i + 1);
		scanf("%d", &m1);
		count = count + m1;
		if (m1 <= m)
		{
			if (count == m)
				printf("%d fully occupied. No further memory remaining.\n");
			printf("Memory allocated for process %d is: %d \n", i + 1, m);
			m2 = m - m1;
			printf("Remaining memory is: %d\n", m2);
			m = m2;
		}
		else
		{
			printf("Memory has not been allocated to this process as it exceeds the capacity (%d).\n", m);
		}

		printf("External fragmentation for this process is: %d \n\n", m2);
	}
}
