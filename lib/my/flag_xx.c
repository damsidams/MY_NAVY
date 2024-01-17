/*
** EPITECH PROJECT, 2023
** flag_x
** File description:
** convert to hexadecmal
*/

#include "my.h"

static void print_part2(unsigned int i)
{
    switch (i){
    case 13:
        my_putchar('D');
        break;
    case 14:
        my_putchar('E');
        break;
    case 15:
        my_putchar('F');
        break;
    default:
        my_put_nbr(i);
    }
}

static void print_part1(unsigned int i)
{
    switch (i){
    case 10:
        my_putchar('A');
        break;
    case 11:
        my_putchar('B');
        break;
    case 12:
        my_putchar('C');
        break;
    }
    if (i > 12 || i < 10)
        print_part2(i);
}

unsigned int flag_xx(unsigned int i)
{
    unsigned int rest = 0;
    unsigned int quot = 0;
    unsigned int count = 0;
    unsigned int nbr = 0;
    unsigned int digits[32];

    if (i == 0){
        my_put_nbr(i);
        return 1;
    }
    while (i > 0){
        digits[nbr] = i % 16;
        i = i / 16;
        nbr += 1;
    }
    for (int j = nbr - 1; j >= 0; j--){
        print_part1(digits[j]);
    }
    return nbr;
}
