/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** Reproduce the behavior of the strstr function
*/

static int compare_string(char *str, const char *str2)
{
    int count = 0;

    while (str2[count] != '\0'){
        if (str[count] != str2[count]){
            return 0;
        }
        count ++;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] == to_find[0] && compare_string(str + i, to_find) == 1){
            return str + i;
        }
        i++;
    }
    return 0;
}
