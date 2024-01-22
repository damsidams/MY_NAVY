##
## EPITECH PROJECT, 2023
## makefile
## File description:
## my first make file
##

NAME	=	my_navy

SRC	=	src/main.c	\
		src/file.c	\
		src/boat.c	\
		src/signals.c	\
		src/game.c	\
		src/utilities.c	\
		src/utilities_two.c	\

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=

CFLAGS = -I./include/ -L./lib/my/ -lmy -Wall -Wextra

TEST_NAME	=	unit_tests

TEST_DIR	=	../tests/test_cat.c

CRITERION_FLAG	=	--coverage -lcriterion

FLAGS	=	$(CRITERION_FLAG) $(CFLAGS) $(LDFLAGS)

MAKE	=	make

all:    $(NAME)

tests_run:	$(OBJ)
	gcc -o $(TEST_NAME) cat.c $(TEST_DIR) $(FLAGS)
	./$(TEST_NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

$(NAME): $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

debug: CFLAGS += -g3
debug: clean $(OBJ)
		make -C lib/my/ debug
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
