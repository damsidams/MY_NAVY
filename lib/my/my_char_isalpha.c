/*
** EPITECH PROJECT, 2023
** my_char_isalpha
** File description:
** check wether a char is part of the alphabet
*/

static int is_low(char const c)
{
    if (c >= 97 && c <= 122){
        return 1;
    }
    return 0;
}

static int is_maj(char const c)
{
    if (c >= 65 && c <= 90){
        return 1;
    }
    return 0;
}

int my_char_isalpha(char const c)
{
    if (is_low(c) != 1 && is_maj(c) != 1){
        return 0;
    }
    return 1;
}
