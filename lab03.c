//Lab3: process creation using fork();
#include <stdio.h>
#include <unistd.h> // for fork()

int main() {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        // Error occurred
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("This is the child process. PID: %d\n", getpid());
    } else {
        // Parent process
        printf("This is the parent process. PID: %d\n", getpid());
        printf("Child process PID: %d\n", pid);
    }

    return 0;
}
/*
Output:
This is the parent process. PID: 70
Child process PID: 74


...Program finished with exit code 0
Press ENTER to exit console.
*/
