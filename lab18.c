////implementation of optimal page replacement
#include <stdio.h>

int main() {
    int f, p;
    int pages[50], frame[10], hit = 0, count[50], time[50];
    int i, j, page, flag, futureIndex, maxFuture;

    printf("Enter no of frames: ");
    scanf("%d", &f);

    if (f <= 0 || f > 10) {
        printf("Invalid number of frames. Exiting...\n");
        return 1;
    }

    printf("Enter no of pages: ");
    scanf("%d", &p);

    if (p <= 0 || p > 50) {
        printf("Invalid number of pages. Exiting...\n");
        return 1;
    }

    for (i = 0; i < f; i++) {
        frame[i] = -1;
    }

    for (i = 0; i < 50; i++) {
        count[i] = 0;
    }

    printf("Enter page numbers:\n");

    for (i = 0; i < p; i++) {
        scanf("%d", &pages[i]);

        if (pages[i] < 0 || pages[i] >= 50) {
            printf("Invalid page number. Exiting...\n");
            return 1;
        }
    }

    printf("\n");

    for (i = 0; i < p; i++) {
        count[pages[i]]++;
        flag = 1;

        for (j = 0; j < f; j++) {
            if (frame[j] == -1 || frame[j] == pages[i]) {
                if (frame[j] != -1) {
                    hit++;
                }
                flag = 0;
                frame[j] = pages[i];
                break;
            }
        }

        if (flag) {
            maxFuture = -1;

            for (j = 0; j < f; j++) {
                futureIndex = -1;

                for (int k = i + 1; k < p; k++) {
                    if (pages[k] == frame[j]) {
                        futureIndex = k;
                        break;
                    }
                }

                if (futureIndex == -1) {
                    maxFuture = j;
                    break;
                }

                if (futureIndex > maxFuture) {
                    maxFuture = futureIndex;
                }
            }

            frame[maxFuture] = pages[i];
        }

        for (j = 0; j < f; j++) {
            printf("%d ", frame[j]);
        }

        printf("\n");
    }

    printf("Page hit = %d\n", hit);

    return 0;
}
