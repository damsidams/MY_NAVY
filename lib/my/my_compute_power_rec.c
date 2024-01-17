/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** recursive function that returns the first argument raised to the power p
*/

int my_compute_power_rec(int nb, int p)
{
    int result = nb;

    if (p == 0){
        return 1;
    }
    if (p < 0){
        return 0;
    }
    if (p > 1){
        p--;
        result = result * my_compute_power_rec(nb, p);
    }
    return result;
}
