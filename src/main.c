/*
** EPITECH PROJECT, 2024
** main
** File description:
** main of my_navy
*/

#include "my.h"
#include "func.h"

signals_t *my_signals;

static void print_h(void)
{
    my_printf("USAGE\n    ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n    ");
    my_printf
    ("first_player_pid: only for the 2nd player. pid of the first player.\n");
    my_printf
    ("    navy_positions: file representing the positions of the ships.\n");
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0 &&
        my_strlen(argv[1]) == 2) {
        print_h();
        return 0;
    }
    if (argc == 2) {
        if (load_file(argv[1]) != 0)
            return 84;
        struct_init();
        print_pid();
        return 0;
    }
    if (argc == 3) {
        if (load_file(argv[2]) != 0)
            return 84;
        struct_init();
        return send_pid(my_getnbr(argv[1]));
    }
    return 84;
}
