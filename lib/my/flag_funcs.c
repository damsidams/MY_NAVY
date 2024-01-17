/*
** EPITECH PROJECT, 2023
** MY_PTINTF
** File description:
** Side functions to do what the flag should do
*/

#include "my.h"

static double is_neg_here(double nb, int *nb_of_char)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        *nb_of_char += 1;
    }
    return nb;
}

static double flag_f_assist(double nb, int *nb_of_char)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        *nb_of_char += 1;
    }
    return nb;
}

int flag_f(double nb)
{
    int nb_of_char = 0;
    int int_part = (int)nb;
    double temp = 0;

    nb = flag_f_assist(nb, &nb_of_char);
    if (is_inf(nb))
        return my_putstr("inf") + nb_of_char;
    int_part = (int)nb;
    if (int_part == nb)
        return my_put_nbr(nb) + my_putstr(".000000") + nb_of_char;
    nb_of_char += my_put_nbr(int_part);
    nb -= int_part;
    nb *= 1000000;
    temp = nb * 10;
    int_part = (int)nb;
    if ((int)temp % 10 > 4)
        int_part += 1;
    my_putchar('.');
    nb_of_char += my_put_nbr(int_part);
    return nb_of_char + 1;
}

int flag_s(char *str)
{
    return my_putstr(str);
}

static int flag_e_printer(double nb, char pos, int base)
{
    int nb_of_char = 0;

    nb_of_char = flag_f(nb);
    my_putchar('e');
    my_putchar(pos);
    if (base < 10)
        my_putchar('0');
    my_put_nbr(base);
    return nb_of_char;
}

int flag_e(double nb)
{
    int base = 0;
    char pos = '+';
    int is_it_neg = 0;

    nb = is_neg_here(nb, &is_it_neg);
    if (is_inf(nb))
        return my_putstr("inf") + is_it_neg;
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

    nb_of_char = flag_f(nb);
    my_putchar('E');
    my_putchar(pos);
    if (base < 10)
        my_putchar('0');
    my_put_nbr(base);
    return nb_of_char;
}

int flag_ee(double nb)
{
    int base = 0;
    char pos = '+';
    int is_it_neg = 0;

    nb = is_neg_here(nb, &is_it_neg);
    if (is_inf(nb))
        return my_putstr("INF") + is_it_neg;
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

int flag_ff(double nb)
{
    int nb_of_char = 0;
    int int_part = (int)nb;
    double temp = 0;

    nb = flag_f_assist(nb, &nb_of_char);
    if (is_inf(nb))
        return my_putstr("INF") + nb_of_char;
    int_part = (int)nb;
    if (int_part == nb)
        return my_put_nbr(nb) + my_putstr(".000000") + nb_of_char;
    nb_of_char += my_put_nbr(int_part);
    nb -= int_part;
    nb *= 1000000;
    temp = nb * 10;
    int_part = (int)nb;
    if ((int)temp % 10 > 4)
        int_part += 1;
    my_putchar('.');
    nb_of_char += my_put_nbr(int_part);
    return nb_of_char + 1;
}
