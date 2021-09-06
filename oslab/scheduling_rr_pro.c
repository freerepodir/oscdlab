#include <stdio.h>
int main()
{
    int burst_time[10], turn_around_time[10], waiting_time[10], remaining_time[10];
    int n, i, j, timeslice, max_burst_time, gantt_pointer = 0;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }
    printf("\nEnter the time slice: ");
    scanf("%d", &timeslice);

    max_burst_time = burst_time[0];
    for (i = 0; i < n; i++)
    {
        if (max_burst_time < burst_time[i])
            max_burst_time = burst_time[i];
    }

    for (j = 0; j < (max_burst_time / timeslice) + 1; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (remaining_time[i] != 0)
            {
                if (remaining_time[i] <= timeslice)
                {
                    turn_around_time[i] = gantt_pointer + remaining_time[i];
                    gantt_pointer += remaining_time[i];
                    remaining_time[i] = 0;
                }
                else
                {
                    remaining_time[i] -= timeslice;
                    gantt_pointer += timeslice;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        waiting_time[i] = turn_around_time[i] - burst_time[i];
        avg_tat += turn_around_time[i];
        avg_wt += waiting_time[i];
    }
    printf("\nThe Average Turnaround time is -- %f", avg_tat * 1.0 / n);
    printf("\nThe Average Waiting time is -- %f ", avg_wt * 1.0 / n);
    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
        printf("\t%d \t %d \t\t %d \t\t %d \n", i + 1, burst_time[i], waiting_time[i], turn_around_time[i]);

    return 0;
}
