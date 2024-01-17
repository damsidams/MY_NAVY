/*
** EPITECH PROJECT, 2023
** my
** File description:
** got all prototype of my lib
*/

#include <stdarg.h>

#ifndef MY_H
    #define MY_H
int my_printf(const char *format, ...);
int my_put_nbr(int nb);
int my_put_nbr_base(int nb, int base);
int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int flag_f(double nb);
int flag_ff(double nb);
int flag_s(char *str);
int flag_e(double nb);
int flag_ee(double nb);
unsigned int flag_o(unsigned int i);
unsigned int flag_u(unsigned int nb);
unsigned int flag_x(unsigned int i);
unsigned int flag_xx(unsigned int i);
int nb_size(int nb, int nb_char_print);
int flag_g(double nb);
int flag_gg(double nb);
void flag_n(int *i, int nb);
unsigned int flag_p(int *i);
int flag_a(double nb);
int flag_aa(double nb);
double is_neg(double nb, int *nb_of_char);
int is_inf(double nb);
int flag_zero(double nb, char flag, int size);
int flag_hashtag(double nb, char flag, int size);
int flag_plus(double nb, char flag, int size);
int flag_blank(double nb, char flag, int size);
int flag_minus_int(double nb, char flag, int size);
int flag_minus_double(double nb, char flag, int size);
int choose_cflag(char char_flag, char normal_flag);
int my_char_isnum(char const c);
int average(double nb, int *int_part, int *dec_part, int precision);
int my_char_isalpha(char const c);
int my_char_isalpha(char const c);
int my_char_isnum(char const c);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar_error(char c);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char **my_str_to_word_array(char const *str);
int my_show_word_array(char *const *tab);
char my_getoperator(char const *str);
int my_getnbr_ez(char const *str);
char *my_strdup(const char *str);
char **my_str_to_line_array(char const *str);
int my_get_nbr_size(float i);
char *int_to_str(int nb);
char **my_str_to_custom_array(char const *str, char **separators);
int array_size(char **array);
int int_lenght(int i);
#endif /* MY_H */
