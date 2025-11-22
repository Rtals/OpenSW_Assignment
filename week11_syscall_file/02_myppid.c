#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t my_pid = getpid();
    pid_t parent_pid = getppid();

    printf("pid: %lu\n", (unsigned long)my_pid);
    printf("ppid: %lu\n", (unsigned long)parent_pid);
    
    return 0;
}