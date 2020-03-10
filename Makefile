##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/bsq.c	\
		src/main_loop.c	\
		src/pos_square.c	\

TESTS	=	src/bsq.c	\
		src/main_loop.c	\
		src/pos_square.c	\
		tests/test_my_bsq.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	=	-W -Wall -I include/

UNITFLAGS	=	-lcriterion --coverage

EXECTESTS	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

tests_run:
	$(CC) -o $(EXECTESTS) $(TESTS) $(CFLAGS) $(UNITFLAGS)
	./$(EXECTESTS) && gcovr --branches --exclude tests

clean:
	rm -f *~
	rm -f $(OBJ)
	rm -f *gc*

fclean:	clean
	rm -f $(NAME)
	rm -f $(EXECTESTS)

re:	fclean all

.PHONY:	all clean fclean re
