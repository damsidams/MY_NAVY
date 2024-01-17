/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** Initialize pointer functions for the printf (flag : s, c, %)
*/

#include <stdarg.h>
#include "my.h"
#include "p_function.h"

int print_string(va_list list, char char_flag, int bp, int ap)
{
    int nb_of_char = 0;
    char *arg = va_arg(list, char *);

    if (char_flag == '-') {
        nb_of_char += my_putstr(arg);
        for (int i = my_strlen(arg); i < bp; i++)
            nb_of_char += my_putchar(' ');
        return nb_of_char;
    }
    return my_putstr(arg);
}

int print_char(va_list list, char char_flag, int bp, int ap)
{
    int nb_of_char = 0;
    char arg = va_arg(list, int);

    if (char_flag == '-') {
        nb_of_char += my_putchar(arg);
        for (int i = 1; i < bp; i++)
            nb_of_char += my_putchar(' ');
        return nb_of_char;
    }
    return my_putchar(arg);
}

int print_percent(va_list list, char char_flag, int bp, int ap)
{
    return my_putchar('%');
}

int print_thegflag(va_list list, char char_flag, int bp, int ap)
{
    int nb_of_char = 0;
    double arg = va_arg(list, double);
    char flag = 'g';
    int (*f_char[])(double, char, int) =
    {
        flag_zero, flag_plus, flag_blank, flag_hashtag, flag_minus_int,
        flag_minus_double
    };

    if (choose_cflag(char_flag, flag) >= 0)
        nb_of_char += f_char[choose_cflag(char_flag, flag)](arg, flag, bp);
    if (char_flag == '-')
        return nb_of_char;
    return nb_of_char + flag_g(arg);
}

int print_theggflag(va_list list, char char_flag, int bp, int ap)
{
    int nb_of_char = 0;
    double arg = va_arg(list, double);
    char flag = 'G';
    int (*f_char[])(double, char, int) =
    {
        flag_zero, flag_plus, flag_blank, flag_hashtag, flag_minus_int,
        flag_minus_double
    };

    if (choose_cflag(char_flag, flag) >= 0)
        nb_of_char += f_char[choose_cflag(char_flag, flag)](arg, flag, bp);
    if (char_flag == '-')
        return nb_of_char;
    return nb_of_char + flag_gg(arg);
}
