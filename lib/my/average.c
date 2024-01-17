/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** Get the average of the decimal with the given precision
*/

int average(double nb, int *int_part, int *dec_part, int precision)
{
    int temp = 0;

    nb *= precision;
    temp = nb * 10;
    *dec_part = (int)nb;
    if ((int)temp % 10 > 4) {
        temp = *dec_part;
        *dec_part += 1;
    }
    if (*dec_part / precision > temp / precision) {
        if (*int_part >= 0) {
            *int_part += 1;
        } else
            *int_part -= 1;
        return 1;
    }
    return 0;
}
