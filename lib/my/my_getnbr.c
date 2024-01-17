/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** returns a number, sent to the function as a string
*/

#include "my.h"

static int negcheck(char const *str, int *count, int *neg)
{
    if (str[*count] == '-' && (str[*count + 1] > 47 && str[*count + 1] < 58)) {
            if (*neg == 0){
                *neg = 1;
                *count = *count + 1;
            }
    }
    return 0;
}

static int size_result(char const *str, int count, int *result, int *detected)
{
    if (str[count] > 47 && str[count] < 58){
        *result = *result * 10 + (str[count] - '0');
        *detected = 1;
    }
    if ((str[count + 1] > '9' || str[count + 1] < '0') && *detected == 1){
        *detected = 2;
    }
    return 0;
}

static int toolong(int *result, int neg, int *detected)
{
    if (neg == 1 || neg == 2) {
        *result = *result * -1;
    }
    if (*detected == 42){
        *result = 0;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int count = 0;
    int result = 0;
    int neg = 0;
    int detected = 0;

    while (str[count] != '\0'){
        negcheck(str, &count, &neg);
        if (result > result * 10 + (str[count] - '0') && neg == 0){
            detected = 42;
        }
        size_result(str, count, &result, &detected);
        if (detected == 2){
            toolong(&result, neg, &detected);
            return result;
        }
        count++;
    }
    toolong(&result, neg, &detected);
    return result;
}
