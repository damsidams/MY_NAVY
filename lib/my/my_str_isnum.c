/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** returns 1 if the string only contains digits and 0 otherwise
*/

static int is_digit(char const *str, int i)
{
    if (str[i] >= 48 && str[i] <= 57){
        return 1;
    }
    return 0;
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (is_digit(str, i) != 1){
            return 0;
        }
        i++;
    }
    return 1;
}
