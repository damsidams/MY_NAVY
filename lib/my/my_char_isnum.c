/*
** EPITECH PROJECT, 2023
** my_char_isnum
** File description:
** check wether a char is a digit or not
*/

int my_char_isnum(char const c)
{
    if (c >= 48 && c <= 57){
        return 1;
    }
    return 0;
}
