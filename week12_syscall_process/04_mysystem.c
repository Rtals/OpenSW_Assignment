#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(char* command) {
    // assignment (fork, exec 사용) (system 메뉴얼 참고)
    pid_t child_pid;
    child_pid = fork();
    if (child_pid == 0) {
        execl("/bin/sh", "sh", "-c", command, NULL);
    }
    else {
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
    }
    return 0;
}

int main() {
    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good Bye~\n");

    return 0;
}