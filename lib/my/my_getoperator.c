/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** returns a number, sent to the function as a string
*/

char my_getoperator(char const *str)
{
    for (int count = 0; str[count] != '\0'; count++){
        if (str[count] == '%'){
            return '%';
        }
        if (str[count] == '+'){
            return '+';
        }
        if (str[count] == '-'){
            return '-';
        }
        if (str[count] == '*'){
            return '*';
        }
        if (str[count] == '/'){
            return '/';
        }
    }
    return 0;
}
