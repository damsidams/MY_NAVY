/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** Initialize pointer functions for the printf
*/

#include <stdarg.h>
#include "my.h"

int print_n(va_list list, char char_flag, int bp, int ap)
{
    return 0;
}

int print_a(va_list list, char char_flag, int bp, int ap)
{
    int nb_of_char = 0;
    double arg = va_arg(list, double);
    char flag = 'a';
    int (*f_char[])(double, char, int) =
    {
        flag_zero, flag_plus, flag_blank, flag_hashtag, flag_minus_int,
        flag_minus_double
    };

    if (choose_cflag(char_flag, flag) >= 0)
        nb_of_char += f_char[choose_cflag(char_flag, flag)](arg, flag, bp);
    if (char_flag == '-')
        return nb_of_char;
    return nb_of_char + flag_a(arg);
}

int print_aa(va_list list, char char_flag, int bp, int ap)
{
    int nb_of_char = 0;
    double arg = va_arg(list, double);
    char flag = 'A';
    int (*f_char[])(double, char, int) =
    {
        flag_zero, flag_plus, flag_blank, flag_hashtag, flag_minus_int,
        flag_minus_double
    };

    if (choose_cflag(char_flag, flag) >= 0)
        nb_of_char += f_char[choose_cflag(char_flag, flag)](arg, flag, bp);
    if (char_flag == '-')
        return nb_of_char;
    return nb_of_char + flag_aa(arg);
}
