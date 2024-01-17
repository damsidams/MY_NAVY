/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** returns 1 if the string only contains alphabetical characters 0 if else
*/

static int is_low(char const *str, int i)
{
    if (str[i] >= 97 && str[i] <= 122){
        return 1;
    }
    return 0;
}

static int is_maj(char const *str, int i)
{
    if (str[i] >= 65 && str[i] <= 90){
        return 1;
    }
    return 0;
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (is_low(str, i) != 1 && is_maj(str, i) != 1){
            return 0;
        }
        i++;
    }
    return 1;
}
