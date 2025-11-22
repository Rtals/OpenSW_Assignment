#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 32

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [source file] [destination file1] [destination file2] ... \n", argv[0]);
        exit(0);
    }

    // open source file (read only)
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror(argv[1]);
    }

    // open dest files (write only)
    int num_files = argc - 2;
    int* dest_fd_list = (int*)malloc(sizeof(int) * num_files);
    for (int i = 0; i < num_files; i++) {
        dest_fd_list[i] = open(argv[i + 2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    }

    // read from source and write destination & stdout
    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;
    while (1) {
        read_result = read(src_fd, readStr, BUF_SIZE);
        
        if (read_result == 0) {
            printf("program end...\n");
            break;
        }
        else if (read_result == -1) {
            perror("read error\n");
            exit(0);
        }

        write(1, readStr, read_result);
        for (int i = 0; i < num_files; i++) {
            write(dest_fd_list[i], readStr, read_result);
        }
    }

    // close all files
    close(src_fd);
    for (int i = 0 ; i < num_files; i++) {
        close(dest_fd_list[i]);
    }

    free(readStr);
    free(dest_fd_list);
    return 0;
}