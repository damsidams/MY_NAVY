/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** puthcar
*/
#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
