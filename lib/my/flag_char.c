/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** Definition of the flag characters
*/

#include "my.h"

static int nb_size_float(double nb)
{
    int nb_of_char = 0;
    int int_part = (int)nb;

    if (nb < 0) {
        nb_of_char += my_strlen("-");
        nb *= -1;
    }
    if (is_inf(nb))
        return my_strlen("size") + nb_of_char;
    int_part = (int)nb;
    if (int_part == nb)
        return nb_size(nb, 0) + my_strlen(".000000") + nb_of_char;
    nb_of_char += nb_size(int_part, 0);
    nb -= int_part;
    nb *= 1000000;
    int_part = (int)nb;
    nb_of_char += nb_size(int_part, 0);
    return nb_of_char + my_strlen(".");
}

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

int flag_minus_int(double nb, char flag, int size)
{
    int nb_of_char = 0;
    int size_word = nb_size(nb, 0);

    if (size_word >= size)
        return my_put_nbr(nb);
    nb_of_char = my_put_nbr(nb);
    for (int i = size_word; i < size; i++)
        nb_of_char += my_putchar(' ');
    return nb_of_char;
}

int flag_minus_double(double nb, char flag, int size)
{
    int nb_of_char = 0;
    int size_word = nb_size_float(nb);

    if (size_word >= size)
        return flag_f(nb);
    nb_of_char = flag_f(nb);
    for (int i = size_word; i < size; i++) {
        nb_of_char += my_putchar(' ');
    }
    return nb_of_char;
}
