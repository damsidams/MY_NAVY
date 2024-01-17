/*
** EPITECH PROJECT, 2024
** game
** File description:
** all game related func
*/

#include "my.h"
#include "func.h"
#include <stdio.h>

void print_map(char **map)
{
    my_printf("\nmy navy:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; map[i] != NULL; i++) {
        my_printf("%d|%s\n",i+1, map[i]);
    }
}

void print_ennemy_map(char **map)
{
    my_printf("\nenemy navy:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; map[i] != NULL; i++) {
        my_printf("%d|%s\n",i+1, map[i]);
    }
}
