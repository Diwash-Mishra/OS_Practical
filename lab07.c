//Program for implementation of FCFS scheduling algorithem
#include<stdio.h>
#include<stdlib.h>

struct fcfs {
    int pid;
    int btime;
    int wtime;
    int ttime;
} p[10];

int main() {
    int i, n;
    int tbm=0, totwtime = 0, totttime = 0;

    printf("\nFCFS Scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter burst time of process %d: ", p[i].pid);
        scanf("%d", &p[i].btime);
    }

    p[0].wtime = 0;
    p[0].ttime = p[0].btime;
    totttime += p[0].ttime;

    for (i = 1; i < n; i++) {
        p[i].wtime = p[i - 1].wtime + p[i - 1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
        totttime += p[i].ttime;
        totwtime += p[i].wtime;
    }
    
     printf("\n process\tbursttime\twaiting time\tturnaround time\n");
    for (i = 0; i < n; i++) {
        tbm += p[i].btime;
        printf("\n%d\t\t%d", p[i].pid, p[i].btime);
        printf("\t\t%d\t\t%d", p[i].wtime, p[i].wtime + p[i].btime);
    }
    printf("\nTotal Waiting Time: %d", totwtime);
    printf("\nAverage Waiting Time: %f", (float)totwtime / n);
    printf("\nTotal Turnaround Time: %d", totttime);
    printf("\nAverage Turnaround Time: %f", (float)totttime / n);

    return 0;
}
