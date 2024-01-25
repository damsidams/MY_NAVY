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

static void print_maps(char **map, char **ennemy_map)
{
    print_map(map);
    print_ennemy_map(ennemy_map);
}

static int connect_to_ennemy(int my_pid, int ennemy_pid, char *my_pid_binary)
{
    signal(SIGUSR1, receive_sig1);
    signal(SIGUSR2, receive_sig2);
    my_printf("my_pid: %d\n", my_pid);
    if (send(ennemy_pid, my_pid_binary) == 84)
        return 84;
    my_printf("\nsuccessfully connected to enemy\n");
    return 0;
}

static int receive_ennemy_pid(void)
{
    int ennemy_pid = 0;

    while (my_signals->nb_bit != 32);
    ennemy_pid = my_signals->value;
    my_signals->nb_bit = 0;
    my_signals->value = 0;
    return ennemy_pid;
}

static int gameloop_sender(char **map, char **ennemy_map, int ennemy_pid)
{
    int ennemy_alive = 1;

    while (alive(map) && ennemy_alive) {
        print_maps(map, ennemy_map);
        receive_attack(map, ennemy_pid);
        send_my_status(map, ennemy_pid);
        if (!alive(map))
            break;
        if (attack(ennemy_pid, map, ennemy_map))
            break;
        ennemy_alive = receive_ennemy_status();
    }
    if (!alive(map))
        return 0;
    if (!ennemy_alive)
        return 1;
    return 84;
}

int send_pid(int pid, char **map)
{
    int my_pid = getpid();
    int ennemy_pid = 0;
    char *my_pid_binary = int_to_binary(my_pid);
    char **ennemy_map = map_creator();
    int endgame = 0;

    if (connect_to_ennemy(my_pid, pid, my_pid_binary) == 84)
        return 84;
    ennemy_pid = receive_ennemy_pid();
    endgame = gameloop_sender(map, ennemy_map, ennemy_pid);
    if (endgame != 84) {
        print_map(map);
        print_ennemy_map(ennemy_map);
        if (!endgame)
            my_printf("\nEnemy won\n");
        if (endgame)
            my_printf("\nI won\n");
    }
    return 0;
}

static int game_init_receiver(void)
{
    int ennemy_pid = 0;

    my_printf("my_pid: %d\n", getpid());
    my_printf("\nwaiting for enemy connection...\n", getpid());
    signal(SIGUSR1, receive_sig1);
    signal(SIGUSR2, receive_sig2);
    while (my_signals->nb_bit != 32);
    my_printf("\nenemy connected\n");
    ennemy_pid = my_signals->value;
    my_signals->nb_bit = 0;
    my_signals->value = 0;
    send(ennemy_pid, int_to_binary(getpid()));
    return ennemy_pid;
}

int receive_ennemy_status(void)
{
    int ennemy_flag = 0;

    while (my_signals->nb_bit != 32);
    ennemy_flag = my_signals->value;
    my_signals->nb_bit = 0;
    my_signals->value = 0;
    return ennemy_flag;
}

static void print_end(char **map, char **ennemy_map, int ennemy_alive)
{
    print_map(map);
    print_ennemy_map(ennemy_map);
    if (!alive(map))
        my_printf("\nEnemy won\n");
    if (!ennemy_alive)
        my_printf("\nI won\n");
}

static void map_pid_init(char ***ennemy_map, int *ennemy_pid)
{
    *ennemy_map = map_creator();
    *ennemy_pid = game_init_receiver();
}

void receive_pid(char **map)
{
    char **ennemy_map;
    int ennemy_pid = 0;
    int ennemy_alive = 1;
    int flag = 0;

    map_pid_init(&ennemy_map, &ennemy_pid);
    while (alive(map) && ennemy_alive) {
        print_maps(map, ennemy_map);
        if (attack(ennemy_pid, map, ennemy_map)) {
            flag = 1;
            break;
        }
        ennemy_alive = receive_ennemy_status();
        if (!ennemy_alive)
            break;
        receive_attack(map, ennemy_pid);
        send_my_status(map, ennemy_pid);
    }
    if (flag != 1)
        print_end(map, ennemy_map, ennemy_alive);
}
