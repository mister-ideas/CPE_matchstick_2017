##
## EPITECH PROJECT, 2017
## matchstick
## File description:
## Makefile
##

SRC_DIR=	src

SRC=		$(SRC_DIR)/matchstick.c	\
		$(SRC_DIR)/display.c	\
		$(SRC_DIR)/player.c	\
		$(SRC_DIR)/ia.c

OBJ=		$(SRC:.c=.o)

CFLAGS= 	-W -Wall -fno-builtin -g3

CPPFLAGS =	-I include

LFLAGS=		-L lib/my/ -l my

NAME=		matchstick

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/src/
		gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean:
		make clean -C lib/src/
		rm -f $(OBJ)

fclean: 	clean
		make fclean -C lib/src/
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
