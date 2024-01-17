/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** Side functions to do what the flag should do
*/

#include "my.h"

int is_inf(double nb)
{
    double MaxValue = 1.7976931348623157E+308;

    if (nb >= MaxValue * 10)
        return 1;
    return 0;
}

static void print_nb_base(int nb, int *nb_char_print, int base)
{
    char res;
    char array[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    if (nb / base > 0)
        print_nb_base(nb / base, nb_char_print, base);
    res = array[nb % base];
    my_putchar(res);
    *nb_char_print += 1;
}

static int my_put_nbr_base_capa(int nb, int base)
{
    int nb_char_print = 0;

    print_nb_base(nb, &nb_char_print, base);
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

static int flag_a_float(double nb)
{
    int nb_of_char = 0;
    int int_part = (int)nb;
    double temp = 0;

    if (int_part == nb)
        return my_put_nbr_base(nb, 16);
    nb_of_char += my_put_nbr_base(int_part, 16);
    my_putchar('.');
    nb -= int_part;
    nb *= nb_digits(nb_of_char, int_part);
    int_part = (int)nb;
    if ((int)temp % 10 > 4)
        int_part += 1;
    while (int_part % 10 == 0)
        int_part /= 10;
    nb_of_char += my_put_nbr_base(int_part, 16);
    return nb_of_char + 1;
}

static int flag_a_printer(float nb, char pos, int base)
{
    int nb_of_char = 0;

    nb_of_char = flag_a_float(nb);
    my_putchar('p');
    my_putchar(pos);
    my_put_nbr(base);
    return nb_of_char;
}

int flag_a(double nb)
{
    int base = 0;
    char pos = '+';
    int is_it_neg = 0;

    nb = is_neg(nb, &is_it_neg);
    if (nb == 0)
        return my_putstr("0x0p+0") + is_it_neg;
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
    return my_putstr("0x") + flag_a_printer(nb, pos, base) + 4 + is_it_neg;
}

static int flag_aa_float(double nb)
{
    int nb_of_char = 0;
    int int_part = (int)nb;
    double temp = 0;

    if (int_part == nb)
        return my_put_nbr_base_capa(nb, 16);
    nb_of_char += my_put_nbr_base_capa(int_part, 16);
    my_putchar('.');
    nb -= int_part;
    nb *= nb_digits(nb_of_char, int_part);
    int_part = (int)nb;
    if ((int)temp % 10 > 4)
        int_part += 1;
    while (int_part % 10 == 0)
        int_part /= 10;
    nb_of_char += my_put_nbr_base_capa(int_part, 16);
    return nb_of_char + 1;
}

static int flag_aa_printer(float nb, char pos, int base)
{
    int nb_of_char = 0;

    nb_of_char = flag_aa_float(nb);
    my_putchar('P');
    my_putchar(pos);
    my_put_nbr(base);
    return nb_of_char;
}

int flag_aa(double nb)
{
    int base = 0;
    char pos = '+';
    int is_it_neg = 0;

    nb = is_neg(nb, &is_it_neg);
    if (nb == 0)
        return my_putstr("0X0P+0") + is_it_neg;
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
    return my_putstr("0X") + flag_aa_printer(nb, pos, base) + 4 + is_it_neg;
}
