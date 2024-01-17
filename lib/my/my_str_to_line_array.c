/*
** EPITECH PROJECT, 2023
** my_str_to_word
** File description:
** function that splits a string into words
*/

#include <stdlib.h>
#include "my.h"

static int check_condition(char const *str, int i)
{
    if (str[i] == '\n'){
        return 1;
    }
    return 0;
}

static void add_word(char const *str, char *result, int start, int end)
{
    int i = 0;

    while (start < end){
        result[i] = str[start];
        start++;
        i++;
    }
    result[i] = 0;
}

static void all_funk
(int *word_nb, char ***result, char const *str, int word_lenght)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (*word_nb == 0 && word_lenght != 0 && check_condition(str, i) == 1){
            (*result)[*word_nb] = malloc(sizeof(char) * (word_lenght + 1));
            add_word(str, (*result)[*word_nb], i - word_lenght, i);
            word_lenght = 0;
            (*word_nb)++;
        }
        if (word_lenght != 0 && check_condition(str, i) == 1){
            (*result)[*word_nb] = malloc(sizeof(char) * (word_lenght + 1));
            add_word(str, (*result)[*word_nb], i - word_lenght + 1, i);
            word_lenght = 0;
            (*word_nb)++;
        }
        if (word_lenght != 0 && str[i + 1] == '\0'){
            (*result)[*word_nb] = malloc(sizeof(char) * (word_lenght + 1));
            add_word(str, (*result)[*word_nb], i - (word_lenght - 1), i + 1);
        }
        word_lenght++;
    }
}

char **my_str_to_line_array(char const *str)
{
    int word_nb = 0;
    int word_lenght = 0;
    char **result = malloc(sizeof(char *) * my_strlen(str));

    if (str[0] == '\0'){
        result[0] = 0;
        return result;
    }
    all_funk(&word_nb, &result, str, word_lenght);
    result[word_nb] = 0;
    return result;
}
