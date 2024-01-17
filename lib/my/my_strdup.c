/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** duplicate a string
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *str)
{
    int lenght = my_strlen(str);
    char *result = malloc(sizeof(char) * (lenght + 100));

    result[lenght] = '\0';
    for (int i = 0; str[i] != '\0'; i++) {
        result[i] = str[i];
    }
    return result;
}
