/*
** EPITECH PROJECT, 2019
** bsq.c
** File description:
** bsq
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "my.h"

int count_lines(char *str, int *i)
{
    int count = 0;

    for (; str[*i] >= '0' && str[*i] <= '9'; *i = *i + 1)
        count = count * 10 + str[*i] - 48;
    if (str[*i] != '\n')
        return (-1);
    *i = *i + 1;
    return (count);
}

char *open_file(char *file, struct stat *sb)
{
    int fd = open(file, O_RDONLY);
    int size = 0;
    char *str = NULL;

    if (fd == -1 || stat(file, sb) == -1)
        return (NULL);
    size = sb->st_size;
    str = malloc(sizeof(char) * (size + 1));
    if (str == NULL)
        return (NULL);
    if (read(fd, str, size) == -1)
        return (NULL);
    str[size] = '\0';
    return (str);
}

int bsq(char *file)
{
    struct stat sb;
    char *str = open_file(file, &sb);
    char *save_map = str;
    int nb_lines = 0;
    int i = 0;

    if (str == NULL)
        return (84);
    nb_lines = count_lines(str, &i);
    str = str + i;
    if (nb_lines == -1)
        return (84);
    if (main_loop(str, sb.st_size - i, nb_lines) == -1)
        return (84);
    free(save_map);
    return (0);
}
