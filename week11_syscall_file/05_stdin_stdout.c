#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 128

int main(int argc, char* argv[]) {
    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        exit(0);
    }
    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;

    while (1) {
        if (read_result == 0) {
            printf("Detected EOF (Ctrl + D)\n");
            printf("Terminating read loop...\n");
            break;
        }
        else if (read_result == -1) {
            perror("read error\n");
            exit(0);
        }
        read_result = read(0, readStr, BUF_SIZE);
        write(1, readStr, read_result);
    }

    free(readStr);
    return 0;
}