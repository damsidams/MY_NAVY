/*
** EPITECH PROJECT, 2024
** game
** File description:
** all game related func
*/

#include "my.h"
#include "func.h"
#include <stdio.h>
#include <signal.h>
#include <signal.h>
#include <unistd.h>

void print_map(char **map)
{
    my_printf("\nmy navy:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; map[i] != NULL; i++)
        my_printf("%d|%s\n", i + 1, map[i]);
}

void print_ennemy_map(char **map)
{
    my_printf("\nenemy navy:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; map[i] != NULL; i++)
        my_printf("%d|%s\n", i + 1, map[i]);
}

void missed_or_hit(int x, int y, char **map, int ennemy_pid)
{
    char x_char = get_x_char(x);
    char y_char = ((y + 1) + '0');

    if (map[y][x * 2] != '.') {
        my_printf("\nresult: %c%c:hit\n", x_char, y_char);
        send(ennemy_pid, int_to_binary(1));
        map[y][x * 2] = 'x';
    } else {
        my_printf("\nresult: %c%c:missed\n", x_char, y_char);
        send(ennemy_pid, int_to_binary(0));
        map[y][x * 2] = 'o';
    }
}

static void get_attack_respons(int x, int y, char **ennemy_map)
{
    int flag = 0;
    char x_char = get_x_char(x);
    char y_char = ((y + 1) + '0');

    while (my_signals->nb_bit != 32);
    flag = my_signals->value;
    my_signals->nb_bit = 0;
    my_signals->value = 0;
    if (flag) {
        my_printf("\nresult: %c%c:hit\n", x_char, y_char);
        ennemy_map[y][x * 2] = 'x';
    }
    if (!flag) {
        my_printf("\nresult: %c%c:missed\n", x_char, y_char);
        ennemy_map[y][x * 2] = 'o';
    }
}

static void send_attack(int pid, char *input, char **ennemy_map)
{
    int x = 0;
    int y = 0;
    char *x_binnary;
    char *y_binnary;

    x = get_x(input);
    y = get_y(input);
    x_binnary = int_to_binary(x);
    y_binnary = int_to_binary(y);
    send(pid, x_binnary);
    send(pid, y_binnary);
    get_attack_respons(x, y, ennemy_map);
}

static int check_validity(__ssize_t line_size, char *buffer)
{
    if (line_size != 0)
        buffer[line_size - 1] = '\0';
    if (line_size != 0 && my_strlen(buffer) != 2) {
        my_printf("\nwrong position\n", buffer);
        my_printf("\nattack: ");
        return 0;
    }
    if (line_size != 0 && my_strlen(buffer) == 2 &&
        (get_x(buffer) == 84 || get_y(buffer) == 84)) {
        my_printf("\nwrong position\n", buffer);
        my_printf("\nattack: ");
        return 0;
    }
    return 1;
}

int attack(int pid, char **map, char **ennemy_map)
{
    char *buffer = NULL;
    size_t buffer_size = 0;
    __ssize_t line_size = 0;

    my_printf("\nattack: ");
    while (line_size == 0) {
        line_size = getline(&buffer, &buffer_size, stdin);
        if (line_size == -1)
            return 1;
        line_size = check_validity(line_size, buffer);
    }
    send_attack(pid, buffer, ennemy_map);
    return 0;
}

void receive_attack(char **map, int ennemy_pid)
{
    int x = 0;
    int y = 0;

    signal(SIGUSR1, receive_sig1);
    signal(SIGUSR2, receive_sig2);
    my_printf("\nwaiting for enemy's attack...\n");
    my_signals->nb_bit = 0;
    my_signals->value = 0;
    while (my_signals->nb_bit != 32);
    x = my_signals->value;
    my_signals->nb_bit = 0;
    my_signals->value = 0;
    while (my_signals->nb_bit != 32);
    y = my_signals->value;
    my_signals->nb_bit = 0;
    my_signals->value = 0;
    missed_or_hit(x, y, map, ennemy_pid);
}
