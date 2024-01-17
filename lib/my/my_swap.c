/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** swap the content of two int using memory adress
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int save = *a;

    *a = *b;
    *b = save;
}
