/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** function that reverses a string
*/

static int lenght(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return i;
}

char *my_revstr(char *str)
{
    int start = 0;
    int end = lenght(str) - 1;
    char save;

    while (start < end){
        save = str[start];
        str[start] = str[end];
        str[end] = save;
        start++;
        end--;
    }
    return str;
}
