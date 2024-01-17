/*
** EPITECH PROJECT, 2024
** int_lenght
** File description:
** return lenght of an int
*/

int int_lenght(int i)
{
    int res = 0;
    int temp = i;

    while (temp > 0) {
        temp = temp / 10;
        res++;
    }
    return res;
}
