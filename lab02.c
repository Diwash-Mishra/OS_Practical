//system call for write
#include <stdio.h>
#include <unistd.h>

int main() {
    char ch[20] = "hello dmc";
    write(1, ch, 20); 
    return 0;
}
/*
Output
hello dmc

...Program finished with exit code 0
Press ENTER to exit console.
*/

//system call for read
#include <stdio.h>
#include <unistd.h>

int main() {
    char ch[20];  // Array to store the read data
    ssize_t bytes_read; // Variable to store the number of bytes read

    bytes_read = read(0, ch, 20); // Read from standard input (file descriptor 0) into ch

    if (bytes_read == -1) {
        perror("Read error");
        return 1; // Return error code if read fails
    }

    // Print what has been read
    printf("Read %zd bytes: %s\n", bytes_read, ch);
    
    return 0;
}
/*
Output:
diwash
Read 7 bytes: diwash



...Program finished with exit code 0
Press ENTER to exit console.
*/