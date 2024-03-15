//Program for implementation of the procuder consumer problem using semaphore
#include<stdio.h>
#include<stdlib.h>

struct Semaphore {
    int mutex;
    int full;
    int empty;
    int x;
};

void producer(struct Semaphore *sem);
void consumer(struct Semaphore *sem);
int wait(int s);
int signal(int s);

int main() {
    struct Semaphore sem = {1, 0, 3, 0};
    int n;

    printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");

    while (1) {
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if ((sem.mutex == 1) && (sem.empty != 0))
                    producer(&sem);
                else
                    printf("BUFFER IS FULL\n");
                break;

            case 2:
                if ((sem.mutex == 1) && (sem.full != 0))
                    consumer(&sem);
                else
                    printf("BUFFER IS EMPTY\n");
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer(struct Semaphore *sem) {
    sem->mutex = wait(sem->mutex);
    sem->full = signal(sem->full);
    sem->empty = wait(sem->empty);
    sem->x++;
    printf("\nproducer produces the item %d\n", sem->x);
    sem->mutex = signal(sem->mutex);
}

void consumer(struct Semaphore *sem) {
    sem->mutex = wait(sem->mutex);
    sem->full = wait(sem->full);
    sem->empty = signal(sem->empty);
    printf("\nconsumer consumes item %d\n", sem->x);
    sem->x--;
    sem->mutex = signal(sem->mutex);
}
