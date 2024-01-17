/*
** EPITECH PROJECT, 2024
** signals
** File description:
** all signals related function
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "func.h"
#include <unistd.h>
#include <signal.h>

void struct_init(void)
{
    my_signals = malloc(sizeof(signals_t));
    my_signals->nb_bit = 0;
    my_signals->value = 0;
}

static void receive_sig1(int sig)
{
    my_signals->value = my_signals->value << 1;
    my_signals->value = my_signals->value | 1;
    my_signals->nb_bit = my_signals->nb_bit + 1;
}

static void receive_sig2(int sig)
{
    my_signals->value = my_signals->value << 1;
    my_signals->nb_bit = my_signals->nb_bit + 1;
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

int send_pid(int pid, char **map)
{
    int my_pid = getpid();
    char *my_pid_binary = int_to_binary(my_pid);
    int index = 0;
    char **ennemy_map = map_creator();

    my_printf("my_pid: %d\n", my_pid);
    while (index != 32) {
        if (my_pid_binary[index] == '1' && kill(pid, SIGUSR1) != 0)
            return 84;
        if (my_pid_binary[index] == '0' && kill(pid, SIGUSR2) != 0)
            return 84;
        index++;
        usleep(10);
    }
    my_printf("\nsuccessfully connected to enemy\n");
    print_map(map);
    print_ennemy_map(ennemy_map);
    while (1);
    return 0;
}

void receive_pid(char **map)
{
    int bin_received = 0;
    char **ennemy_map;

    ennemy_map = map_creator();
    my_printf("my_pid: %d\n", getpid());
    my_printf("\nwaiting for enemy connection...\n", getpid());
    if (signal(SIGUSR1, receive_sig1))
        bin_received++;
    if (signal(SIGUSR2, receive_sig2))
        bin_received++;
    while (my_signals->nb_bit != 32);
    my_printf("\nenemy connected\n");
    my_signals->nb_bit = 0;
    print_map(map);
    print_ennemy_map(ennemy_map);
    while (1);
}
