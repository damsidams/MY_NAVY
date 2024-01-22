/*
** EPITECH PROJECT, 2024
** utilities_two
** File description:
** same as utilities one
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "func.h"
#include <unistd.h>
#include <signal.h>

void struct_init(void)
{
    my_signals = malloc(sizeof(signals_t));
    my_signals->nb_bit = 0;
    my_signals->value = 0;
}

void receive_sig1(int sig)
{
    my_signals->value = my_signals->value << 1;
    my_signals->value = my_signals->value | 1;
    my_signals->nb_bit = my_signals->nb_bit + 1;
}

void receive_sig2(int sig)
{
    my_signals->value = my_signals->value << 1;
    my_signals->nb_bit = my_signals->nb_bit + 1;
}
