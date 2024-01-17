/*
** EPITECH PROJECT, 2024
** file
** File description:
** files function managements
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "func.h"

static int lines_nb(char *path)
{
    char *buffer = NULL;
    size_t buffer_size = 0;
    __ssize_t line_size;
    FILE *my_file = fopen(path, "r");
    int res = 0;

    if (!my_file)
        return 84;
    line_size = getline(&buffer, &buffer_size, my_file);
    while (line_size >= 0) {
        res ++;
        line_size = getline(&buffer, &buffer_size, my_file);
    }
    free(buffer);
    buffer = NULL;
    fclose(my_file);
    return res;
}

static int store_data(char *path, char **temp)
{
    char *buffer = NULL;
    size_t buffer_size = 0;
    __ssize_t line_size;
    FILE *my_file = fopen(path, "r");
    int index = 0;

    if (!my_file)
        return 84;
    line_size = getline(&buffer, &buffer_size, my_file);
    while (line_size >= 0) {
        (temp)[index] = my_strdup(buffer);
        index++;
        line_size = getline(&buffer, &buffer_size, my_file);
    }
    free(buffer);
    buffer = NULL;
    fclose(my_file);
    return 0;
}

static int read_data(char **data, char **map)
{
    char *separators[] = {":", "\n", NULL};
    char **temp;
    int return_value = 0;

    for (int i = 0; data[i] != NULL; i++) {
        temp = my_str_to_custom_array(data[i], separators);
        return_value = get_boat(map, temp);
    }
    return return_value;
}

int load_file(char *path)
{
    int lines_num = 0;
    char **temp;
    int return_value = 0;
    char **map;

    map = map_creator();
    lines_num = lines_nb(path);
    temp = malloc(sizeof(char *) * (lines_num + 1));
    temp[lines_num] = NULL;
    store_data(path, temp);
    if (!valid_boat(temp))
        return 84;
    return_value = read_data(temp, map);
    return return_value;
}
