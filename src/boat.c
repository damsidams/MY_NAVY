/*
** EPITECH PROJECT, 2024
** boat
** File description:
** all boat related function
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static void point_or_space(char **map, int i, int k)
{
    if (k % 2 == 0)
        map[i][k] = '.';
    else
        map[i][k] = ' ';
}

char **map_creator(void)
{
    char **map = malloc(sizeof(char *) * 9);

    map[8] = NULL;
    for (int i = 0; i != 8; i++) {
        map[i] = malloc(sizeof(char) * 16);
        map[i][15] = '\0';
        for (int k = 0; k != 15; k++)
            point_or_space(map, i, k);
    }
    return map;
}

int get_x(char *str)
{
    switch (str[0]) {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    case 'E':
        return 4;
    case 'F':
        return 5;
    case 'G':
        return 6;
    case 'H':
        return 7;
    default:
        return 84;
    }
}

int get_y(char *str)
{
    switch (str[1]) {
    case '1':
        return 0;
    case '2':
        return 1;
    case '3':
        return 2;
    case '4':
        return 3;
    case '5':
        return 4;
    case '6':
        return 5;
    case '7':
        return 6;
    case '8':
        return 7;
    default:
        return 84;
    }
}

static int lenght_check(int a, int b, int lenght)
{
    if (a - b != lenght - 1)
        return 0;
    return 1;
}

static int boat_check(int start_x, int start_y, int end_x, int end_y)
{
    if ((start_x != end_x && start_y != end_y) || start_x > 7 || start_y > 7 ||
        end_x > 7 || end_y > 7)
        return 0;
    return 1;
}

static void add_coo(int *coordinate, int a, int b, char *str)
{
    coordinate[a] = get_x(str);
    coordinate[b] = get_y(str);
}

static void load_boat(char **map, int *coordinate)
{
    if (coordinate[1] == coordinate[3]) {
        for (int y = coordinate[2]; y != coordinate[4] + 1; y++)
        map[y][coordinate[1] * 2] = (coordinate[0] + '0');
    }
    if (coordinate[2] == coordinate[4])
        for (int x = coordinate[1]; x != coordinate[3] + 1; x++)
        map[coordinate[2]][x * 2] = (coordinate[0] + '0');
}

int get_boat(char **map, char **temp)
{
    int *coordinate = malloc(sizeof(int) * 6);

    for (int i = 0; temp[i] != NULL; i++) {
        if (i == 0)
            coordinate[0] = my_getnbr(temp[i]);
        if (i == 1)
            add_coo(coordinate, 1, 2, temp[i]);
        if (i == 2)
            add_coo(coordinate, 3, 4, temp[i]);
    }
    if (!boat_check
        (coordinate[1], coordinate[2], coordinate[3], coordinate[4]))
        return 84;
    if ((!lenght_check(coordinate[3], coordinate[1], coordinate[0]) &&
        !lenght_check(coordinate[4], coordinate[2], coordinate[0])))
        return 84;
    load_boat(map, coordinate);
    return 0;
}

int valid_boat(char **temp)
{
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;

    if (array_size(temp) != 4)
        return 0;
    for (int i = 0; temp[i] != NULL; i++) {
        if (my_getnbr(temp[i]) == 2)
            two += 1;
        if (my_getnbr(temp[i]) == 3)
            three += 1;
        if (my_getnbr(temp[i]) == 4)
            four += 1;
        if (my_getnbr(temp[i]) == 5)
            five += 1;
    }
    if (two == 0 || three == 0 || four == 0 || five == 0)
        return 0;
    return 1;
}
