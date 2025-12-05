#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    sigset_t block_set, pending_set;

    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);

    // 순서1: SIGINT signal blocking 설정
    sigprocmask(SIG_BLOCK, &block_set, NULL);

    // 순서2: 5초간 sleep
    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");
    sleep(5);

    // 순서3: SIGINT signal pending 확인
    sigpending(&pending_set);

    if (sigismember(&pending_set, SIGINT))
    {
        printf("\nSIGINT is pending\n");
    }
    else
    {
        printf("\nSIGINT is not pending\n");
    }

    return 0;
}