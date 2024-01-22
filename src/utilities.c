/*
** EPITECH PROJECT, 2024
** utilities
** File description:
** contnain all functions that are used multiple times
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "func.h"
#include <unistd.h>
#include <signal.h>

char get_x_char(int i)
{
    switch (i) {
    case 0:
        return 'A';
    case 1:
        return 'B';
    case 2:
        return 'C';
    case 3:
        return 'D';
    case 4:
        return 'E';
    case 5:
        return 'F';
    case 6:
        return 'G';
    case 7:
        return 'H';
    default:
        return 'J';
    }
}

char *int_to_binary(int i)
{
    int temp = i;
    int index = 31;
    char *res = malloc(sizeof(char) * 33);

    res[32] = '\0';
    while (temp > 0) {
        res[index] = ((temp % 2) + '0');
        temp = temp / 2;
        index--;
    }
    for (int i = 0; i <= index; i++)
        res[i] = '0';
    return res;
}

void send_my_status(char **map, int ennemy_pid)
{
    if (alive(map))
        send(ennemy_pid, int_to_binary(1));
    else
        send(ennemy_pid, int_to_binary(0));
}

int send(int pid, char *binnary)
{
    for (int i = 0; i != 32; i++) {
        if (binnary[i] == '1' && kill(pid, SIGUSR1) != 0)
            return 84;
        if (binnary[i] == '0' && kill(pid, SIGUSR2) != 0)
            return 84;
        usleep(200);
    }
    return 0;
}

static int is_boat(char s)
{
    if (s != '.' && s != 'x' && s != ' ' && s != '.' && s != 'o')
        return 1;
    return 0;
}

int alive(char **map)
{
    int flag = 0;

    signal(SIGUSR1, receive_sig1);
    signal(SIGUSR2, receive_sig2);
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            flag += is_boat(map[i][j]);
        }
    }
    if (flag != 0)
        return 1;
    return 0;
}
