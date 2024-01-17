/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** display a string
*/

#include "my.h"

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar_error(str[i]);
        i++;
    }
    return 0;
}
