//Program for implementation of SJF scheduling algorithem
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int pid;
    int btime;
    int wtime;
} sp;

int main()
{
    int i, j, n, tbm = 0, towtwtime = 0, totttime;
    sp *p, t;

    printf("\n SJF Scheduling..\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    p = (sp*)malloc(n * sizeof(sp));

    printf("\nEnter the burst time:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
        p[i].wtime = 0;
    }

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (p[i].btime > p[j].btime)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }

    printf("\nProcess Scheduling\n");
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        towtwtime += p[i].wtime = tbm;
        tbm += p[i].btime;
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].btime, p[i].wtime, p[i].wtime + p[i].btime);
    }

    totttime = tbm + towtwtime;
    printf("\nTotal Waiting Time: %d", towtwtime);
    printf("\nAverage Waiting Time: %f", (float)towtwtime / n);
    printf("\nTotal Turnaround Time: %d", totttime);
    printf("\nAverage Turnaround Time: %f", (float)totttime / n);

    free(p); // Don't forget to free the allocated memory

    return 0;
}
