/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** Header file for all the function pointers
*/

#include <stdarg.h>

#ifndef P_FUNCTION_H
    #define P_FUNCTION_H
int print_string(va_list list, char char_flag, int bp, int ap);
int print_char(va_list list, char char_flag, int bp, int ap);
int print_percent(va_list list, char char_flag, int bp, int ap);
int print_octal(va_list list, char char_flag, int bp, int ap);
int print_unsigned(va_list list, char char_flag, int bp, int ap);
int print_hex(va_list list, char char_flag, int bp, int ap);
int print_hexx(va_list list, char char_flag, int bp, int ap);
int print_float(va_list list, char char_flag, int bp, int ap);
int print_ffloat(va_list list, char char_flag, int bp, int ap);
int print_float_e(va_list list, char char_flag, int bp, int ap);
int print_ffloat_ee(va_list list, char char_flag, int bp, int ap);
int print_int(va_list list, char char_flag, int bp, int ap);
int print_thegflag(va_list list, char char_flag, int bp, int ap);
int print_theggflag(va_list list, char char_flag, int bp, int ap);
int print_n(va_list list, char char_flag, int bp, int ap);
int print_pointer(va_list list, char char_flag, int bp, int ap);
int print_a(va_list list, char char_flag, int bp, int ap);
int print_aa(va_list list, char char_flag, int bp, int ap);
#endif /* P_FUNCTION_H */
