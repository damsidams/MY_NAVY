/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** File to run the flag characters
*/

int choose_cflag(char char_flag, char normal_flag)
{
    char *flags = "0+ #-";
    int i = 0;

    while (flags[i] && flags[i] != char_flag)
        i++;
    if (flags[i] == '\0')
        return -1;
    if (i <= 3)
        return i;
    if (normal_flag == 'd' || normal_flag == 'i')
        return i;
    return i + 1;
}

int flag_zero(double nb, char flag, int size)
{
    return 0;
}
