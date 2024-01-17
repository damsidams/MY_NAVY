/*
** EPITECH PROJECT, 2023
** PRINTF
** File description:
** Initializes pointers functions for the printf
*/

#include <stdarg.h>
#include "my.h"

int print_float(va_list list, char char_flag, int bp, int ap)
{
    int nb_of_char = 0;
    double arg = va_arg(list, double);
    char flag = 'f';
    int (*f_char[])(double, char, int) =
    {
        flag_zero, flag_plus, flag_blank, flag_hashtag, flag_minus_int,
        flag_minus_double
    };

    if (choose_cflag(char_flag, flag) >= 0)
        nb_of_char += f_char[choose_cflag(char_flag, flag)](arg, flag, bp);
    if (char_flag == '-')
        return nb_of_char;
    return flag_f(arg) + nb_of_char;
}

int print_ffloat(va_list list, char char_flag, int bp, int ap)
{
    int nb_of_char = 0;
    double arg = va_arg(list, double);
    char flag = 'F';
    int (*f_char[])(double, char, int) =
    {
        flag_zero, flag_plus, flag_blank, flag_hashtag, flag_minus_int,
        flag_minus_double
    };

    if (choose_cflag(char_flag, flag) >= 0)
        nb_of_char += f_char[choose_cflag(char_flag, flag)](arg, flag, bp);
    if (char_flag == '-')
        return nb_of_char;
    return nb_of_char + flag_ff(arg);
}

int print_float_e(va_list list, char char_flag, int bp, int ap)
{
    int nb_of_char = 0;
    double arg = va_arg(list, double);
    char flag = 'e';
    int (*f_char[])(double, char, int) =
    {
        flag_zero, flag_plus, flag_blank, flag_hashtag, flag_minus_int,
        flag_minus_double
    };

    if (choose_cflag(char_flag, flag) >= 0)
        nb_of_char += f_char[choose_cflag(char_flag, flag)](arg, flag, bp);
    if (char_flag == '-')
        return nb_of_char;
    return nb_of_char + flag_e(arg);
}

int print_ffloat_ee(va_list list, char char_flag, int bp, int ap)
{
    int nb_of_char = 0;
    double arg = va_arg(list, double);
    char flag = 'E';
    int (*f_char[])(double, char, int) =
    {
        flag_zero, flag_plus, flag_blank, flag_hashtag, flag_minus_int,
        flag_minus_double
    };

    if (choose_cflag(char_flag, flag) >= 0)
        nb_of_char += f_char[choose_cflag(char_flag, flag)](arg, flag, bp);
    if (char_flag == '-')
        return nb_of_char;
    return nb_of_char + flag_ee(arg);
}

int print_int(va_list list, char char_flag, int bp, int ap)
{
    int nchar = 0;
    int arg = va_arg(list, int);
    char flag = 'd';
    int (*f_char[])(double, char, int) =
    {
        flag_zero, flag_plus, flag_blank, flag_hashtag, flag_minus_int,
        flag_minus_double
    };

    if (choose_cflag(char_flag, flag) >= 0) {
        if (char_flag == '-')
            return f_char[choose_cflag(char_flag, flag)](arg, flag, bp);
        nchar += f_char[choose_cflag(char_flag, flag)]((double)arg, flag, bp);
    }
    return nchar + my_put_nbr(arg);
}
