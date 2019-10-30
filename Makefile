##
## EPITECH PROJECT, 2019
## MUL_my_defender_2018
## File description:
## makefile
##

CC	= gcc -g

RM	= rm -f

NAME	= navy

LIB =   my_getnbr.c \
        my_putchar.c    \
        my_putstr.c \
        my_putnbr.c \
        my_strcmp.c \
        my_strlen.c

SRC	=   map.c   \
        load_map.c  \
        kill_it.c   \
        state_machine.c \
        client_utils.c  \
        display_map.c   \
        main.c  \
        play.c  \
        recieve_signal.c    \
        send_signal.c   \
        server_utils.c

OBJ	= $(addprefix source/,$(SRC:.c=.o))

JBO = $(addprefix lib/,$(LIB:.c=.o))

CFLAGS	= -W -Wextra -Wall -I include/

$(NAME): $(OBJ) $(JBO)
	$(CC) $(OBJ) $(JBO) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
