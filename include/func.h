/*
** EPITECH PROJECT, 2023
** func
** File description:
** prototype of func used in the project
*/
#include <stdarg.h>

#ifndef MY_FUNC_H
    #define MY_FUNC_H
int load_file(char *path, char ***map);
int valid_boat(char **temp);
int get_boat(char **map, char **temp);
char **map_creator(void);
void receive_pid(char **map);
int send_pid(int pid, char **map);
void struct_init(void);
void print_map(char **map);
void print_ennemy_map(char **map);
int alive(char **map);
int get_y(char *str);
int get_x(char *str);
char *int_to_binary(int i);
void receive_attack(char **map, int ennemy_pid);
void attack(int pid, char **map, char **ennemy_map);
void receive_sig1(int sig);
void receive_sig2(int sig);
char get_x_char(int i);
int send(int pid, char *binnary);
int receive_ennemy_status(void);
void send_my_status(char **map, int ennemy_pid);
typedef struct signals_s {
    int value;
    int nb_bit;
}signals_t;
extern signals_t *my_signals;
#endif /* MY_FUNC_H */
