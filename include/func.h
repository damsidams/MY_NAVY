/*
** EPITECH PROJECT, 2023
** func
** File description:
** prototype of func used in the project
*/
#include <stdarg.h>

#ifndef MY_FUNC_H
    #define MY_FUNC_H
int load_file(char *path);
int valid_boat(char **temp);
int get_boat(char **map, char **temp);
char **map_creator(void);
void print_pid(void);
int send_pid(int pid);
void struct_init(void);
typedef struct signals_s {
    int value;
    int nb_bit;
}signals_t;
extern signals_t *my_signals;
#endif /* MY_FUNC_H */
