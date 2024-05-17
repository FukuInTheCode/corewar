/*
** EPITECH PROJECT, 2024
** display_help.c
** File description:
** function for open a .txt and display the help
*/

#include "my.h"
#include <fcntl.h>
#include <sys/stat.h>

int open_help(char const *path)
{
    int fd = open(path, O_RDONLY);
    size_t ret = 0;
    struct stat file_info;
    char *buffer;

    if (fd == -1 || stat(path, &file_info) == -1)
        return 84;
    buffer = malloc(file_info.st_size);
    if (buffer == NULL)
        return 84;
    ret = read(fd, buffer, file_info.st_size) == -1;
    if (ret)
        return 84;
    write(1, buffer, file_info.st_size);
    close(fd);
    free(buffer);
    return 1;
}

int display_help(int argc, char **argv, char const *path)
{
    if (argc == 2 && argv[1] != NULL && argv[1][0] == '-'
        && argv[1][1] == 'h' && argv[1][2] == '\0')
        return open_help(path);
    return 0;
}
