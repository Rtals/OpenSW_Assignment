#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file1 name] ... \n", argv[0]);
        exit(0);
    }
    int num_files = argc - 1;
    int* fd_list = (int*)malloc(sizeof(int) * num_files);

    for (int i = 0; i < num_files; i++) {
        fd_list[i] = open(argv[i + 1], O_RDONLY);
        if (fd_list[i] == -1) {
            perror(argv[i + 1]);
        }
        else {
            printf("Opened successfully: %s\n", argv[i + 1]);
        }
    }

    for (int i = 0; i < num_files; i++) {
        if (fd_list[i] != -1) {
            close(fd_list[i]);
            printf("Closed successfully: %s\n", argv[i + 1]);
        }
    }

    free(fd_list);
    return 0;
}