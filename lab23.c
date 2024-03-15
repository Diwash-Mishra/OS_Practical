//program to implement indexed file allocation technique
#include <stdio.h>
#include <conio.h>

int f[50], inde[50], n;

int main() {
    int i, j, p, c;

    system("cls");

    for (i = 0; i < 50; i++)
        f[i] = 0;

x:
    printf("Enter index block: ");
    scanf("%d", &p);

    if (f[p] == 0) {
        f[p] = 1;
        printf("Enter number of files on index: ");
        scanf("%d", &n);
    } else {
        printf("Block already allocated.\n");
        goto x;
    }

    for (i = 0; i < n; i++) {
        printf("Enter block for file %d: ", i + 1);
        scanf("%d", &inde[i]);
    }

    for (i = 0; i < n; i++) {
        if (f[inde[i]] == 1) {
            printf("Block already allocated.\n");
            goto x;
        }
    }

    for (j = 0; j < n; j++)
        f[inde[j]] = 1;

    printf("\nAllocated.\n");
    printf("File indexed:\n");
    for (i = 0; i < n; i++)
        printf("%d -> %d: %d\n", p, inde[i], f[inde[i]]);

    printf("Enter 1 to enter more files and 0 to exit: ");
    scanf("%d", &c);

    if (c == 1)
        goto x;

    getch();
    return 0;
}
/*
Input/Output
Enter index block: 17
Enter number of files on index: 5
Enter block for file 1: 4
Enter block for file 2: 8
Enter block for file 3: 29
Enter block for file 4: 19
Enter block for file 5: 25

Allocated.
File indexed:
17 -> 4: 1
17 -> 8: 1
17 -> 29: 1
17 -> 19: 1
17 -> 25: 1
Enter 1 to enter more files and 0 to exit:

Conclusion:
Based on this output, the program seems to correctly allocate blocks for the index 
and files. Each file block associated with the index is marked as allocated (1), 
indicating that it is in use. The program also checks if the blocks are already 
allocated and prompts the user accordingly.
*/
