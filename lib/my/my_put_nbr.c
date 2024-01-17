/*
** EPITECH PROJECT, 2023
** MY PUT NBR
** File description:
** write an nbr given as a parameter and return the nb of char printed
*/

#include "my.h"

static void print_nb(int nb, int *nb_char_print)
{
    char res;

    if (nb / 10 > 0)
        print_nb(nb / 10, nb_char_print);
    res = (nb % 10) + '0';
    my_putchar(res);
    *nb_char_print += 1;
}

int my_put_nbr(int nb)
{
    int nb_char_print = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        nb_char_print ++;
    }
    print_nb(nb, &nb_char_print);
    return nb_char_print;
}

static void print_nb_base(int nb, int *nb_char_print, int base)
{
    char res;
    char array[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    if (nb / base > 0)
        print_nb(nb / base, nb_char_print);
    res = array[nb % base];
    my_putchar(res);
    *nb_char_print += 1;
}

int my_put_nbr_base(int nb, int base)
{
    int nb_char_print = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        nb_char_print ++;
    }
    print_nb_base(nb, &nb_char_print, base);
    return nb_char_print;
}
