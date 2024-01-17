/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** Flag characters +, # and ' '
*/

#include "my.h"

int flag_hashtag(double nb, char flag, int size)
{
    int nb_of_char = 0;

    switch (flag) {
    case 'o':
        nb_of_char = my_putchar('0');
        break;
    case 'x':
        nb_of_char = my_putstr("0x");
        break;
    case 'X':
        nb_of_char = my_putstr("0X");
        break;
    }
    return nb_of_char;
}

int flag_plus(double nb, char flag, int size)
{
    if (nb > 0)
        return my_putchar('+');
    return 0;
}

int flag_blank(double nb, char flag, int size)
{
    if (nb > 0)
        return my_putchar(' ');
    return 0;
}
