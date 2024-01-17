/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** returns 1 if the number is prime and 0 if not
*/
#include <stdio.h>
int my_is_prime(int nb)
{
    int div = 2;
    int res = 0;

    if (nb <= 1){
        return 0;
    }
    while (div < nb){
        res = nb % div;
        if (res == 0){
            return 0;
        }
        div++;
    }
    return 1;
}
