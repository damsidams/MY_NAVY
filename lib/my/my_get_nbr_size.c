/*
** EPITECH PROJECT, 2023
** my_get_nbr_size
** File description:
** get size in terms of nb of int
*/

int my_get_nbr_size(float i)
{
    int res = 0;

    while (i >= 1) {
        i = i / 10;
        res++;
    }
    return res + 1;
}
