##
## Makefile for Mafefile in /home/hubert_i/rendu/PSU_2015_my_printf
##
## Made by leo hubert
## Login   <hubert_i@epitech.net>
##
## Started on  Wed Nov  4 09:57:56 2015 leo hubert
## Last update Fri Feb  5 15:25:18 2016 Léo Hubert
##

CFLAGS  +=      -W -Wextra -Werror -Wall -ansi -pedantic
CFLAGS  +=      -I./include/ --std=c99 -D_POSIX_C_SOURCE=199309L -D_BSD_SOURCE=199309L

CC	=	gcc

NAME_CLIENT    	=	client/client
NAME_SERVEUR    =	server/server

SRC_CLIENT	= 	client/src/client.c	\
			lib/my_putstr.c		\
			lib/my_getnbr.c		\
			lib/my_put_nbr.c	\
			lib/my_putchar.c	\
			lib/my_strlen.c		\
			lib/my_putnbr_base.c

SRC_SERVEUR	= 	server/src/server.c	\
			lib/my_putstr.c		\
			lib/my_getnbr.c		\
			lib/my_putnbr_base.c	\
			lib/my_putchar.c	\
			lib/my_revstr.c		\
			lib/my_strlen.c		\
			lib/my_put_nbr.c	\
			lib/my_putnbr_bin.c

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"
YELLOW  =	"\033[1;33m"
FINISH  =       "\033[5;1;35m"

all:		$(NAME_CLIENT) $(NAME_SERVEUR)

clean:
		@rm -rf $(NAME_CLIENT) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(NAME_CLIENT) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(NAME_CLIENT) $(DEFAULT)
		@rm -rf $(NAME_SERVEUR) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(NAME_SERVEUR) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(NAME_SERVEUR) $(DEFAULT)

fclean:		clean

re:		fclean all

## Sound ----------------------------------------------------------------------

encore:
		@paplay include/sound/encore.ogg
blague:
		@paplay include/sound/humour.ogg &

## Compilation -----------------------------------------------------------------

$(NAME_CLIENT):
			@$(CC) $(SRC_CLIENT) -o $(NAME_CLIENT) $(CFLAGS)&& \
			$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(SRC_CLIENT) $(DEFAULT) || \
			$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(SRC_CLINET) $(DEFAULT)

$(NAME_SERVEUR):
			@$(CC) $(SRC_SERVEUR) -o $(NAME_SERVEUR) $(CFLAGS)&& \
			$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(SRC_SERVEUR) $(DEFAULT) || \
			$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(SRC_SERVEUR) $(DEFAULT)
			@$(ECHO) $(FINISH) "\nCompilation Succesfully of Minitalk" $(DEFAULT)
			@paplay include/sound/end.ogg &

.PHONY: 	all clean fclean re encore blague
