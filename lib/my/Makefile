##
## EPITECH PROJECT, 2023
## makefile
## File description:
## my first make file
##

SRC	=	my_is_prime.c	\
		my_strcat.c	\
		my_strncat.c	\
		my_putchar.c	\
		my_strcmp.c	\
		my_strncmp.c	\
		my_put_nbr.c	\
		my_strcpy.c	\
		my_strncpy.c	\
		my_char_isalpha.c	\
		my_putstr.c	\
		my_str_isalpha.c	\
		my_strstr.c	\
		my_char_isnum.c	\
		my_revstr.c	\
		my_str_islower.c	\
		my_str_to_word_array.c	\
		my_str_to_line_array.c	\
		my_compute_power_rec.c	\
		my_showmem.c	\
		my_str_isnum.c	\
		my_strupcase.c	\
		my_compute_square_root.c	\
		my_showstr.c	\
		my_str_isprintable.c	\
		my_swap.c	\
		my_find_prime_sup.c	\
		my_show_word_array.c	\
		my_str_isupper.c	\
		my_getnbr.c	\
		my_sort_int_array.c	\
		my_strlen.c	\
		my_isneg.c	\
		my_strcapitalize.c	\
		my_strlowcase.c	\
		my_getoperator.c	\
		my_getnbr_ez.c	\
		my_printf.c     \
		flag_funcs.c	\
		flag_funcs2.c	\
		flag_funcs3.c	\
		flag_funcs4.c	\
		flag_x.c	\
		flag_xx.c	\
		pointer_to_func_1.c	\
		pointer_to_func_2.c	\
		pointer_to_func_3.c	\
		pointer_to_func_4.c	\
		flag_char.c	\
        flag_char2.c	\
		which_identifier.c	\
		average.c	\
		my_strdup.c	\
		my_get_nbr_size.c \
		int_to_str.c \
		my_str_to_custom_array.c	\
		array_size.c	\
		int_lenght.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

LIB	=	./

LIBNAME	=	my.h

CFLAGS	=

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(LIBNAME) ../../include/
	$(clean)
	$(fclean)

re: fclean all

debug: CFLAGS += -g3
debug:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(LIBNAME) ../../include/
	$(clean)
	$(fclean)
