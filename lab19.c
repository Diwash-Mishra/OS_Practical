//program to organize the file using single level directory
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm, count, i, j, mid, cir_x;
    char fname[10][20];

    printf("Enter the number of files: ");
    scanf("%d", &count);

    initgraph(&gd, &gm, "C:/Turboc3/BGI");

    if (graphresult() != 0) {
        printf("Graphics initialization failed. Exiting...\n");
        return 1;
    }

    cleardevice();
    setbkcolor(GREEN);

    if (count > 0) {
        printf("Enter file names:\n");

        for (i = 0; i < count; i++) {
            printf("File %d: ", i + 1);
            scanf("%s", fname[i]);
        }

        mid = 640 / count;
        cir_x = mid / 3;

        for (j = 0; j < count; j++, cir_x += mid) {
            line(320, 150, cir_x, 250);
            fillellipse(cir_x, 250, 30, 30);
            outtextxy(cir_x, 250, fname[j]);
        }
    }

    getch();
    closegraph();

    return 0;
}
/*
Input/Output:
Enter the number of files:2
interface change into green and
Enter file names:
File 1: 23
file 2: 31
after this figure will come with 2 circle connecting each other starting from one point
 first one is far and second one is close to the starting point of line.
*/