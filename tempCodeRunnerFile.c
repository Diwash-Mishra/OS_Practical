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
