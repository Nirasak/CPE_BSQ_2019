/*
** EPITECH PROJECT, 2019
** main_loop.c
** File description:
** main loop
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *prep_str(char *str, int *max, int nb_cols)
{
    int i = max[1];

    for (int lines = max[0] - 1; lines >= 0; lines--)
        for (int cols = max[0] - 1; cols >= 0; cols--)
            str[i - (lines * nb_cols) - cols] = 'x';
    return (str);
}

int check_char(int *tab, int i, int nb_cols, int max[2])
{
    int a = tab[i - 1];
    int b = tab[i - nb_cols];
    int c = tab[i - nb_cols - 1];

    if (tab[i] == -1)
        return (-1);
    if (a <= b && a <= c)
        tab[i] = a + 1;
    else if (b < a && b < c)
        tab[i] = b + 1;
    else
        tab[i] = c + 1;
    pos_square(tab, i, max);
    return (0);
}

char *algo(char *str, int *tab)
{
    int i = 0;
    int nb_cols = 1;
    int max[2] = {0, 0};

    for (; tab[i] != -1; i++) {
        pos_square(tab, i, max);
        nb_cols++;
    }
    i++;
    for (; tab[i] != -2; i++) {
        if ((i + 1) % nb_cols == 0 && tab[i] != -1)
            return (NULL);
        if (i % nb_cols != 0 && (i + 1) % nb_cols != 0 && tab[i] != 0)
            if (check_char(tab, i, nb_cols, max) == -1)
                return (NULL);
        pos_square(tab, i, max);
    }
    return (prep_str(str, max, nb_cols));
}

int *prep_tab(char *str, int i, int size, int nb_lines)
{
    int *tab = malloc(sizeof(int) * (size + 1));

    if (tab == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++) {
        if (str[i] == '.')
            tab[i] = 1;
        if (str[i] == 'o')
            tab[i] = 0;
        if (str[i] == '\n') {
            nb_lines--;
            tab[i] = -1;
        }
        if (str[i] != '.' && str[i] != 'o' && str[i] != '\n')
            return (NULL);
    }
    if (nb_lines != 0)
        return (NULL);
    tab[i] = -2;
    return (tab);
}

int main_loop(char *str, int size, int nb_lines)
{
    int *tab = prep_tab(str, 0, size, nb_lines);

    if (tab == NULL)
        return (-1);
    str = algo(str, tab);
    if (str == NULL)
        return (-1);
    write(1, str, size);
    free(tab);
    return (0);
}
