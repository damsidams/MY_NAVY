/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
**  get smallest prime number that is greater than, or equal to parameter
*/

static int isprime(int nb)
{
    int div = 2;
    int res = 0;

    if (nb <= 1){
        return 0;
    }
    while (div < nb){
        res = nb % div;
        if (res == 0){
            return 0;
        }
        div++;
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    while (!isprime(nb)){
        nb++;
    }
    return nb;
}
