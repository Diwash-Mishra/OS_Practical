//program for sequential file for processing the students information
#include <stdio.h>

typedef struct {
    int sno;
    char name[25];
    int m1, m2, m3;
} STD;

void display(FILE *);
int search(FILE *, int);

void main() {
    int i, n, sno_key, opn;
    FILE *fp;
    STD s;

    printf("How many records ? ");
    scanf("%d", &n);

    fp = fopen("stud.dat", "w");
    for (i = 0; i < n; i++) {
        printf("Enter the student information %d (sno, Name, M1, M2, M3): ", i + 1);
        scanf("%d%s%d%d%d", &s.sno, s.name, &s.m1, &s.m2, &s.m3);
        fwrite(&s, sizeof(s), 1, fp);
    }
    fclose(fp);

    fp = fopen("stud.dat", "r+");
    do {
        printf("1-DISPLAY\n2.SEARCH\n3.EXIT\nYOUR OPTION: ");
        scanf("%d", &opn);
        switch (opn) {
            case 1:
                printf("\nStudent Records in the file\n");
                display(fp);
                break;
            case 2:
                printf("Enter sno of the student to be searched: ");
                scanf("%d", &sno_key);
                if (search(fp, sno_key)) {
                    // No need to print the record here, it will be printed in search function
                    printf("Success!! Record found in the file\n");
                } else
                    printf("Failure!! Record %d not found\n", sno_key);
                break;
            case 3:
                printf("Exit !! press key");
                getchar(); // Consume the newline character left in the input buffer
                break;
            default:
                printf("Invalid option!!! Try again!!\n");
                break;
        }
    } while (opn != 3);
    fclose(fp);
}

void display(FILE *fp) {
    STD s;
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp))
        printf("%d\t%s\t%d\t%d\t%d\n", s.sno, s.name, s.m1, s.m2, s.m3);
}

int search(FILE *fp, int sno_key) {
    STD s;
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.sno == sno_key) {
            printf("%d\t%s\t%d\t%d\t%d\n", s.sno, s.name, s.m1, s.m2, s.m3);
            return 1;
        }
    }
    return 0;
}
