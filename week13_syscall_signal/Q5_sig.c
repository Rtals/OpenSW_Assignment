#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

struct two_double
{
    double a;
    double b;
} data;
struct two_double data;

void sigint_handler(int _signo)
{
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main()
{
    struct sigaction sa_sigalrm;
    struct two_double zeros = {0.0, 0.0};
    struct two_double ones = {1.0, 1.0};

    sa_sigalrm.sa_handler = sigint_handler;
    sigemptyset(&sa_sigalrm.sa_mask);
    sa_sigalrm.sa_flags = 0;
    if (sigaction(SIGALRM, &sa_sigalrm, NULL) == -1)
    {
        perror("sigaction error: ");
        exit(0);
    }

    // signal mask ...
    sigset_t block_set;
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGALRM);

    alarm(1);

    while (1)
    {
        sigprocmask(SIG_BLOCK, &block_set, NULL);
        data = zeros;
        sigprocmask(SIG_UNBLOCK, &block_set, NULL);

        sigprocmask(SIG_BLOCK, &block_set, NULL);
        data = ones;
        sigprocmask(SIG_UNBLOCK, &block_set, NULL);
    }

    return 0;
}