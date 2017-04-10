##
## Makefile for Mafefile in /home/hubert_i/rendu/PSU_2015_my_printf
##
## Made by leo hubert
## Login   <hubert_i@epitech.net>
##
## Started on  Wed Nov  4 09:57:56 2015 leo hubert
## Last update Fri Dec 18 18:07:38 2015 leo hubert
##

CFLAGS  +=      -W -Wextra -Werror -Wall
CFLAGS  +=      -I./include/

NAME    =	bsq

SRC	= 	main.c		\
		bsq.c		\
		scare.c		\
		error.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cc $(OBJ) -o $(NAME) -lm -lmy -L./lib/

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)
		rm -f $(OBJ)

re:		fclean all

.PHONY: 	all clean fclean re
