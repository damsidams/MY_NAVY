/*
** EPITECH PROJECT, 2023
** flag_funcs2
** File description:
** this file contains some of the flag funcs
*/

#include "my.h"

static unsigned int print_nb(unsigned int nb, unsigned int nb_char_print)
{
    char res;

    if (nb / 10 > 0)
        nb_char_print += print_nb(nb / 10, nb_char_print);
    res = (nb % 10) + '0';
    my_putchar(res);
    nb_char_print ++;
    return nb_char_print;
}

unsigned int flag_u(unsigned int nb)
{
    int nb_char_print = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        nb_char_print ++;
    }
    nb_char_print = print_nb(nb, nb_char_print);
    return nb_char_print;
}

unsigned int flag_o(unsigned int i)
{
    unsigned int rest = 0;
    unsigned int quot = 0;
    unsigned int nbr = 0;
    unsigned int digits[32];

    if (i == 0){
        my_put_nbr(i);
        return 1;
    }
    while (i > 0){
        digits[nbr] = i % 8;
        i = i / 8;
        nbr += 1;
    }
    for (int j = nbr - 1; j >= 0; j--) {
        my_put_nbr(digits[j]);
    }
    return nbr;
}

void flag_n(int *i, int nb)
{
    *i = nb;
}

unsigned int flag_p(int *i)
{
    my_putstr("0x7fff");
    return flag_x((unsigned int)i);
}

double is_neg(double nb, int *nb_of_char)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        *nb_of_char += 1;
    }
    return nb;
}
