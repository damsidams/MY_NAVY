/*
** EPITECH PROJECT, 2023
** my_sort_word_array
** File description:
** sort word by ascii order
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static void swap(char ***tab, int i, int j)
{
    char *save = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen((*tab)[i]) + 1));
    char *tmp2 = malloc(sizeof(char) * (my_strlen((*tab)[j]) + 1));

    my_strcpy(tmp, (*tab)[i]);
    my_strcpy(tmp2, (*tab)[j]);
    my_strlowcase(tmp);
    my_strlowcase(tmp2);
    if (my_strcmp(tmp, tmp2) > 0) {
        save = (*tab)[i];
        (*tab)[i] = (*tab)[j];
        (*tab)[j] = save;
    }
}

int my_sort_word_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = i + 1; tab[j] != NULL; j++) {
            swap(&tab, i, j);
        }
    }
    return 0;
}
