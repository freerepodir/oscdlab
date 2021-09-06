#include <stdio.h>

int main()
{
	int m, p, s, p1;
	int m1[4], i, f, f1 = 0, f2 = 0, fra1, fra2, s1, pos;
	printf("Enter the total size of the memory.\n");
	scanf("%d", &m);
	printf("Enter the number of partitions.\n");
	scanf("%d", &p);
	s = m / p;
	printf("\nThe memory can be divided into partitions of %d units each.\n", s);
	printf("Enter the number of processes.\n");
	scanf("%d", &p1);
	pos = m;
	for (i = 0; i < p1; i++)
	{
		if (pos < s)
		{
			printf("\nThere is no further memory for Process %d.", i + 1);
			m1[i] = 0;
			break;
		}
		else
		{
			printf("\nEnter the memory requirement for process %d.\n", i + 1);
			scanf("%d", &m1[i]);
			if (m1[i] <= s)
			{
				printf("Process is allocated in partition %d.\n", i + 1);
				fra1 = s - m1[i];
				printf("Internal fragmentation for process is %d.\n", fra1);
				f1 = f1 + fra1;
				pos = pos - s;
			}
			else
			{
				printf("Process not allocated in partition %d.\n", i + 1);
				s1 = m1[i];
				while (s1 > s)
				{
					s1 = s1 - s;
					pos = pos - s;
				}

				pos = pos - s;
				fra2 = s - s1;
				f2 = f2 + fra2;
				printf("External Fragmentation for this process is %d.\n", fra2);
			}
		}
	}

	printf("\nProcess\tAllocated Memory");
	for (i = 0; i < p1; i++)
		printf("\n%5d\t%5d", i + 1, m1[i]);
	f = f1 + f2;
	printf("\nTotal Fragmentation is:%d", f);
	return 0;
}
