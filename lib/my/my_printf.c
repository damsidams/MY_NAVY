/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** reproduce basic printf behavior
*/

#include <stdarg.h>
#include "my.h"
#include "p_function.h"

static void print_noflag(char c)
{
    my_putchar('%');
    my_putchar(c);
}

static int cases
(char c, va_list list, char identifier, int *precisions)
{
    int (*functions[])
        (va_list list, char identifier, int precisions1, int precisions2) =
        {
            print_int, print_string,
            print_char, print_percent, print_int,
            print_octal, print_unsigned, print_hex,
            print_hexx, print_float, print_ffloat,
            print_float_e, print_ffloat_ee, print_thegflag,
            print_theggflag, print_n, print_pointer,
            print_a, print_aa};
    char *base = "dsc%iouxXfFeEgGnpaA";

    for (int i = 0; base[i] != '\0'; i++){
        if (base[i] == c){
            return functions[i]
                (list, identifier, precisions[0], precisions[1]);
        }
    }
    print_noflag(c);
    return 2;
}

static int precisions
(const char *c, va_list list, int *counter, char identifier)
{
    int res[2];
    int flag_count = 0;

    while (my_char_isnum(*c) == 1){
        res[0] = res[0] * 10 + (*c - '0');
        c++;
        flag_count++;
    }
    if (*c == '.'){
        c++;
        flag_count++;
    }
    while (my_char_isnum(*c) == 1){
        res[1] = res[1] + ((float)(*c - '0'));
        c++;
        flag_count++;
    }
    *counter = *counter + cases(*c, list, identifier, res);
    return flag_count;
}

static int format_identifiers
(const char *c, va_list list, int *counter)
{
    char *base = "-0+ #";
    int flag_count = 0;

    for (int i = 0; base[i] != '\0'; i++){
        if (base[i] == *c){
            c++;
            flag_count = 1 + precisions(c, list, counter, base[i]);
            return flag_count;
        }
    }
    flag_count = precisions(c, list, counter, 0);
    return flag_count;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int counter = 0;
    char next_letter = *(format + 1);
    int flag_count = 1;

    va_start(list, format);
    while (*format){
        next_letter = (*format) + 1;
        if (*format == '%' && next_letter != '\0'){
            format++;
            flag_count += format_identifiers(format, list, &counter);
        } else
            counter += my_putchar(*format);
        if (*format != '\0')
            format += flag_count;
        flag_count = 1;
    }
    va_end(list);
    return counter;
}
