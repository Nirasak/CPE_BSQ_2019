/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main bsq
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    return (bsq(av[1]));
}
