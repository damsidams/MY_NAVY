/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** Contains all the needed function by flag g and flag G and the
** function itself
*/

#include "my.h"

int nb_size(int nb, int nb_char_print)
{
    if (nb < 0) {
        nb *= -1;
        nb_char_print ++;
    }
    if (nb / 10 > 0)
        nb_char_print += nb_size(nb / 10, nb_char_print);
    nb_char_print ++;
    return nb_char_print;
}

static int nb_digits(int nb_of_char, int int_part)
{
    int nb_of_digits = 1000000;
    int i = 0;

    if (int_part == 0)
        nb_of_digits *= 10;
    while (i < nb_of_char) {
        nb_of_digits /= 10;
        i ++;
    }
    return nb_of_digits;
}

static int flag_f_no_print_zero(double nb)
{
    int nb_of_char = 0;
    int int_part = (int)nb;
    double temp = 0;

    if (int_part == nb)
        return my_put_nbr(nb);
    nb_of_char += my_put_nbr(int_part);
    my_putchar('.');
    nb -= int_part;
    nb *= nb_digits(nb_of_char, int_part);
    temp = nb * 10;
    int_part = (int)nb;
    if ((int)temp % 10 > 4)
        int_part += 1;
    while (int_part % 10 == 0)
        int_part /= 10;
    nb_of_char += my_put_nbr(int_part);
    return nb_of_char + 1;
}

static int flag_e_printer(double nb, char pos, int base)
{
    int nb_of_char = 0;

    nb_of_char = flag_f_no_print_zero(nb);
    my_putchar('e');
    my_putchar(pos);
    if (base < 10)
        my_putchar('0');
    my_put_nbr(base);
    return nb_of_char;
}

static int flag_e_for_g(double nb)
{
    int base = 0;
    char pos = '+';
    int is_it_neg = 0;

    nb = is_neg(nb, &is_it_neg);
    while (nb > 10) {
        nb /= 10;
        base ++;
    }
    while (nb < 1) {
        pos = '-';
        nb *= 10;
        base ++;
    }
    return flag_e_printer(nb, pos, base) + 4 + is_it_neg;
}

static int flag_ee_printer(double nb, char pos, int base)
{
    int nb_of_char = 0;

    nb_of_char = flag_f_no_print_zero(nb);
    my_putchar('E');
    my_putchar(pos);
    if (base < 10)
        my_putchar('0');
    my_put_nbr(base);
    return nb_of_char;
}

static int flag_ee_for_gg(double nb)
{
    int base = 0;
    char pos = '+';
    int is_it_neg = 0;

    nb = is_neg(nb, &is_it_neg);
    while (nb > 10) {
        nb /= 10;
        base ++;
    }
    while (nb < 1) {
        pos = '-';
        nb *= 10;
        base ++;
    }
    return flag_ee_printer(nb, pos, base) + 4 + is_it_neg;
}

int flag_g(double nb)
{
    int nb_of_char = 0;

    if (nb < 0) {
        my_putchar('-');
        nb_of_char ++;
        nb *= -1;
    }
    if (is_inf(nb))
        return my_putstr("inf") + nb_of_char;
    if (nb_size((int)nb, 0) <= 6)
        return flag_f_no_print_zero(nb) + nb_of_char;
    return flag_e_for_g(nb) + nb_of_char;
}

int flag_gg(double nb)
{
    int nb_of_char = 0;

    if (nb < 0) {
        my_putchar('-');
        nb_of_char ++;
        nb *= -1;
    }
    if (is_inf(nb))
        return my_putstr("INF") + nb_of_char;
    if (nb_size((int)nb, 0) <= 6)
        return flag_f_no_print_zero(nb) + nb_of_char;
    return flag_ee_for_gg(nb) + nb_of_char;
}
