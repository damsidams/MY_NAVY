/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** function that returns the square root
*/

static int computeall(int nb)
{
    int result = 0;
    int tmp = 0;

    while (tmp != nb){
        result = result + 1;
        tmp = result * result;
    }
    return result;
}

int my_compute_square_root(int nb)
{
    int nbsave = nb;
    int odd = 1;

    while (nbsave > 0){
        nbsave = nbsave - odd;
        odd = odd + 2;
    }
    if (nbsave != 0){
        return 0;
    }
    return computeall(nb);
}
