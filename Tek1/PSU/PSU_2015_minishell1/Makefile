##
## Makefile for Mafefile in /home/hubert_i/rendu/PSU_2015_my_printf
##
## Made by leo hubert
## Login   <hubert_i@epitech.net>
##
## Started on  Wed Nov  4 09:57:56 2015 leo hubert
## Last update Sun Jan 24 18:05:30 2016 Léo Hubert
##

LIB  	=	-lm -lmy -L./lib/
CFLAGS  +=      -W -Wextra -Werror -Wall -pedantic
CFLAGS  +=      -I./include/

CC	=	gcc

NAME    =	mysh

SRC	=	env.c			\
		minishell.c		\
		linked_list.c		\
		str_to_wordtab.c	\
		command.c		\
		command_bis.c		\
		cd.c			\
		error.c			\
		main.c

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"
YELLOW  =	"\033[1;33m"
FINISH  =       "\033[5;1;35m"

OBJ	=	$(SRC:.c=.o)

all:		makelib $(NAME)

clean:
		@make clean -C lib/my/ && \
		$(ECHO) $(GREEN) "[OK]" $(YELLOW) "make clean lib" $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR]" $(YELLOW) "make clean lib" $(DEFAULT)
		@rm -f $(OBJ) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(OBJ) $(DEFAULT)

fclean:		clean
		@make fclean -C lib/my/ && \
		$(ECHO) $(GREEN) "[OK]" $(YELLOW) "make fclean lib" $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR]" $(YELLOW) "make flcean lib" $(DEFAULT)
		@rm -f $(NAME) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(NAME) $(DEFAULT)

re:		encore fclean all

## Sound ----------------------------------------------------------------------

encore:
		@paplay include/sound/encore.ogg &
blague:
		@paplay include/sound/humour.ogg &

## Compilation -----------------------------------------------------------------

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME) $(LIB) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(OBJ) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nCompilation Succesfully of "$(NAME) $(DEFAULT)
		@paplay include/sound/end.ogg &

%.o:		%.c
		@$(CC) $(CFLAGS) -c $^ && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $^ $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $^ $(DEFAULT)

makelib:
		@make -C lib/my/


.PHONY: 	all clean fclean re encore blague makelib
