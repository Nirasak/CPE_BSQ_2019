/*
** EPITECH PROJECT, 2019
** pos_square.c
** File description:
** pos square
*/

#include "my.h"

void pos_square(int *tab, int i, int max[2])
{
    if (tab[i] > max[0]) {
        max[0] = tab[i];
        max[1] = i;
    }
}
