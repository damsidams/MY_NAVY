/*
** EPITECH PROJECT, 2023
** my_isnneg
** File description:
** show if the nb passed as parameter is negative or positive
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    my_putchar('\n');
    return 0;
}
