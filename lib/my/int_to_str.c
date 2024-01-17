/*
** EPITECH PROJECT, 2023
** MY PUT NBR
** File description:
** transform an in given as param and return str
*/

#include "my.h"
#include <stdlib.h>

static int nb_lenght(int i)
{
    int res = 0;

    while (i % 10 > 10) {
        res++;
        i = i % 10;
    }
    return res;
}

static void print_nb(int nb, int *nb_char_print, char **res)
{
    char temp;
    char str[2];

    temp = (nb % 10) + '0';
    str[0] = temp;
    str[1] = '\0';
    *res = my_strcat(*res, str);
    *nb_char_print += 1;
    if (nb / 10 > 0)
        print_nb(nb / 10, nb_char_print, res);
}

char *int_to_str(int nb)
{
    int nb_char_print = 0;
    char *res;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        nb_char_print ++;
    }
    res = malloc(sizeof(char) * (nb_lenght(nb) + nb_char_print + 1));
    res[nb_lenght(nb) + nb_char_print] = '\0';
    print_nb(nb, &nb_char_print, &res);
    my_revstr(res);
    return res;
}
