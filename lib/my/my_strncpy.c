/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** function that copies n characters from a string into another
*/

static int strlenght(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return i;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n){
        dest[i] = src[i];
        i++;
    }
    if (strlenght(dest) < n){
        dest[i] = '\0';
    }
    return dest;
}
