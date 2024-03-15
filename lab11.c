//Program for implementation algorithem for deadlock detection
#include<stdio.h>

static int mark[20];
int i, j, np, nr;

int main() {
    int alloc[10][10], request[10][10], avail[10], r[10], w[10];

    printf("\nEnter the number of processes: ");
    scanf("%d", &np);

    printf("\nEnter the number of resources: ");
    scanf("%d", &nr);

    for (i = 0; i < nr; i++) {
        printf("\nTotal amount of resource R %d:", i + 1);
        scanf("%d", &r[i]);
    }

    printf("\nEnter the request matrix:\n");
    for (i = 0; i < np; i++)
        for (j = 0; j < nr; j++)
            scanf("%d", &request[i][j]);

    printf("\nEnter the allocation matrix:\n");
    for (i = 0; i < np; i++)
        for (j = 0; j < nr; j++)
            scanf("%d", &alloc[i][j]);

    for (j = 0; j < nr; j++) {
        avail[j] = r[j];
        for (i = 0; i < np; i++) {
            avail[j] -= alloc[i][j];
        }
    }

    for (i = 0; i < np; i++) {
        int count = 0;
        for (j = 0; j < nr; j++) {
            if (alloc[i][j] == 0)
                count++;
            else
                break;
        }
        if (count == nr)
            mark[i] = 1;
    }

    for (i = 0; i < np; i++) {
        int canbeprocessed = 0;
        if (mark[i] != 1) {
            for (j = 0; j < nr; j++) {
                if (request[i][j] <= avail[j])
                    canbeprocessed = 1;
                else {
                    canbeprocessed = 0;
                    break;
                }
            }
            if (canbeprocessed) {
                mark[i] = 1;
                for (j = 0; j < nr; j++)
                    avail[j] += alloc[i][j];
            }
        }
    }

    int deadlock = 0;
    for (i = 0; i < np; i++)
        if (mark[i] != 1)
            deadlock = 1;

    if (deadlock)
        printf("\nDeadlock detected\n");
    else
        printf("\nNo Deadlock possible\n");

    return 0;
}

/*
input/output
Enter the number of processes: 4

Enter the number of resources: 5

Total amount of resource R 1:2

Total amount of resource R 2:1

Total amount of resource R 3:1

Total amount of resource R 4:2

Total amount of resource R 5:1

Enter the request matrix:
0 1 0 0 1
0 0 1 0 1
0 0 0 0 1
1 0 1 0 1

Enter the allocation matrix:
1 0 1 1 0
1 1 0 0 0
0 0 0 1 0
0 0 0 0 0

Deadlock detected
*/