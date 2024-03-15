//implementation of FIFO page replacement algorithem
#include <stdio.h>

int main() {
    int i = 0, j = 0, k = 0, i1 = 0, m, n, rs[30], flag = 1, p[30];

    // Use system("cls") for Windows and system("clear") for Unix-like systems
    system("cls");

    printf("FIFO page replacement algorithm. .. \n");
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");

    while (1) {
        scanf("%d", &rs[i]);
        if (rs[i] == 0)
            break;
        i++;
    }

    m = i;

    for (j = 0; j < n; j++)
        p[j] = 0;

    for (i = 0; i < m; i++) {
        flag = 1;
        
        for (j = 0; j < n; j++) {
            if (p[j] == rs[i]) {
                printf("Data already in page...\n");
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            p[i1] = rs[i];
            i1++;
            k++;

            if (i1 == n)
                i1 = 0;

            for (j = 0; j < n; j++) {
                printf("\nPage %d: %d", j + 1, p[j]);
                if (p[j] == rs[i])
                    printf("*");
            }

            printf("\n\n");
        }
    }

    printf("Total number of page faults = %d\n", k);

    return 0;
}
/*
(note: string ma 0 lekhesi algorithem end hunxa yo program ma)

Input/Output

FIFO page replacement algorithm. ..
Enter the number of frames: 3
Enter the reference string: 1 2 3 4 1 2 5 1 2 3 4 5 0

Page 1: 1*
Page 2: 0
Page 3: 0


Page 1: 1
Page 2: 2*
Page 3: 0


Page 1: 1
Page 2: 2
Page 3: 3*


Page 1: 4*
Page 2: 2
Page 3: 3


Page 1: 4
Page 2: 1*
Page 3: 3


Page 1: 4
Page 2: 1
Page 3: 2*


Page 1: 5*
Page 2: 1
Page 3: 2

Data already in page...
Data already in page...

Page 1: 5
Page 2: 3*
Page 3: 2


Page 1: 5
Page 2: 3
Page 3: 4*

Data already in page...
Total number of page faults = 9
*/