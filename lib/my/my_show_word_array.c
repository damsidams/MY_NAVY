/*
** EPITECH PROJECT, 2023
** my_show_word_array.c
** File description:
** display content of an array
*/

#include "my.h"
#include "stdio.h"
#include <unistd.h>

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != NULL; i++){
        write(1, tab[i], my_strlen(tab[i]));
        my_putchar('\n');
    }
    return 0;
}
