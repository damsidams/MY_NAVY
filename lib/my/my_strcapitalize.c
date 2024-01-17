/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** capitalizes the first letter of each word
*/

static char *strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] >= 65 && str[i] <= 90){
            str[i] = str[i] + 32;
        }
        i++;
    }
    return str;
}

static void condition_check(char *str, int i)
{
    if (str[i + 1] >= 97 && str[i + 1] <= 122){
        str[i + 1] = str[i + 1] - 32;
    }
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    str = strlowcase(str);
    if (str[i] >= 97 && str[i] <= 122){
        str[i] = str[i] - 32;
    }
    while (str[i + 1] != '\0'){
        if (str[i] == ' ' || str[i] == '+' || str[i] == '-'){
            condition_check(str, i);
        }
        i++;
    }
    return str;
}
