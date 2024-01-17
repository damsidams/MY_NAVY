/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** Initialize pointer functions for the printf
*/

#include <stdarg.h>
#include "my.h"

int print_octal(va_list list, char char_flag, int bp, int ap)
{
    unsigned int arg = va_arg(list, unsigned int);
    int nb_of_char = 0;

    if (char_flag == '#')
        nb_of_char = flag_hashtag((double)arg, 'o', bp);
    if (char_flag == '-') {
        nb_of_char += flag_o(arg);
        for (int i = nb_of_char; i < bp; i++)
            nb_of_char += my_putchar(' ');
        return nb_of_char;
    }
    return flag_o(arg);
}

int print_unsigned(va_list list, char char_flag, int bp, int ap)
{
    unsigned int arg = va_arg(list, unsigned int);
    int nb_of_char = 0;

    if (char_flag == '-') {
        nb_of_char += flag_u(arg);
        for (int i = nb_of_char; i < bp; i++)
            nb_of_char += my_putchar(' ');
        return nb_of_char;
    }
    return flag_u(arg);
}

int print_hex(va_list list, char char_flag, int bp, int ap)
{
    unsigned int arg = va_arg(list, unsigned int);
    int nb_of_char = 0;

    if (char_flag == '#')
        nb_of_char = flag_hashtag((double)arg, 'x', bp);
    if (char_flag == '-') {
        nb_of_char += flag_x(arg);
        for (int i = nb_of_char; i < bp; i++)
            nb_of_char += my_putchar(' ');
        return nb_of_char;
    }
    return flag_x(arg);
}

int print_hexx(va_list list, char char_flag, int bp, int ap)
{
    unsigned int arg = va_arg(list, unsigned int);
    int nb_of_char = 0;

    if (char_flag == '#')
        nb_of_char = flag_hashtag((double)arg, 'X', bp);
    if (char_flag == '-') {
        nb_of_char += flag_xx(arg);
        for (int i = nb_of_char; i < bp; i++)
            nb_of_char += my_putchar(' ');
        return nb_of_char;
    }
    return flag_xx(arg);
}

int print_pointer(va_list list, char char_flag, int bp, int ap)
{
    return flag_p(va_arg(list, int *));
}
