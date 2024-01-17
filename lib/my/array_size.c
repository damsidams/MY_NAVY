/*
** EPITECH PROJECT, 2024
** array_size
** File description:
** return array size
*/

#include <stdlib.h>

int array_size(char **array)
{
    int res = 0;

    while (array[res] != NULL)
        res++;
    return res;
}
