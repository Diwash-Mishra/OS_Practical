//implementation of memory allocation methods for fixed partion using Best fit
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define max 25

int main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest;
    static int bf[max], ff[max];

    system("cls");

    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of files:");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d:", i + 1);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d:", i + 1);
        scanf("%d", &f[i]);
    }

    for (i = 0; i < nf; i++) {
        lowest = INT_MAX;
        temp = 0;
        ff[i] = 0;
        for (j = 0; j < nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0 && lowest > temp) {
                    ff[i] = j + 1;  // Block numbering starts from 1
                    lowest = temp;
                }
            }
        }
        frag[i] = lowest;
        if (ff[i] != 0) {
            bf[ff[i] - 1] = 1;  // Mark the block as allocated
        }
    }

    printf("\nFile No\tFile Size \tBlock No\tBlock Size\tFragment");
    for (i = 0; i < nf; i++) {
        if (ff[i] != 0) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, f[i], ff[i], b[ff[i] - 1], frag[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated\t\t--\t\t--", i + 1, f[i]);
        }
    }

    getchar();
    return 0;
}
