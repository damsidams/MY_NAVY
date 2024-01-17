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
typedef struct signals_s {
    int value;
    int nb_bit;
}signals_t;
extern signals_t *my_signals;
#endif /* MY_FUNC_H */
