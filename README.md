# get_next_line Documentation

## Overview
The `get_next_line` function is a project at 42 School designed to read a line from a file descriptor. It is capable of handling multiple file descriptors and is particularly useful for parsing files line by line.

## EXAMPLE
To execute the project, compile the source files, provide the path to the desired text file as a command-line argument, and run the resulting executable. For example: `./your_executable ./example.txt`.

```c
#include "get_next_line.h"
#include <stdio.h>


int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line: %s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
