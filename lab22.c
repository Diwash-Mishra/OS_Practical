//program to implement linked file allocation technique for processing the employee details.
#include <stdio.h>
#include <conio.h>
#include <string.h>

struct record {
    char empname[20];
    int age;
    float salary;
};

typedef struct record person;

int main() {
    person employee;
    int i, n, rec, result;
    FILE *fp, *people;

    printf("How many records: ");
    scanf("%d", &n);

    fp = fopen("PEOPLE.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter the employee information (EmpName, Age, Salary): ");
        scanf("%s %d %f", employee.empname, &employee.age, &employee.salary);
        fwrite(&employee, sizeof(person), 1, fp);
    }
    fclose(fp);

    people = fopen("PEOPLE.txt", "r");
    if (people == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Which record do you want to read from file? ");
    scanf("%d", &rec);
    while (rec >= 0) {
        fseek(people, rec * sizeof(person), SEEK_SET);
        result = fread(&employee, sizeof(person), 1, people);
        if (result == 1) {
            printf("\nRECORD %d\n", rec);
            printf("Given name: %s\n", employee.empname);
            printf("Age: %d years\n", employee.age);
            printf("Current salary: $%.2f\n\n", employee.salary);
        } else {
            printf("\nRECORD %d not found !\n\n", rec);
        }
        printf("Which record do you want (0 to %d): ", n - 1);
        scanf("%d", &rec);
    }

    fclose(people);
    getch();
    return 0;
}
