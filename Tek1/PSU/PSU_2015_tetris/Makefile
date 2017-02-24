##
## Makefile for Makefile in /home/roig_a/rendu/PSU_2015_tetris
## 
## Made by Antoine Roig
## Login   <roig_a@epitech.net>
## 
## Started on  Thu Feb 25 17:05:29 2016 Antoine Roig
## Last update Sun Mar 20 14:16:38 2016 Antoine Roig
##

NAME 	=	tetris

CFLAGS 	+=	-W -Wall -ansi -pedantic
CFLAGS	+=	-Iincludes -lncurses

LIB	=	sources/lib/my_strcmp.c			\
		sources/lib/my_put_nbr.c		\
	   	sources/lib/my_get_nbr.c		\
	   	sources/lib/my_is_num.c			\
	   	sources/lib/my_takestr.c		\
	   	sources/lib/my_str_to_search.c		\
		sources/lib/my_putchar.c		

DISPLAY	=	sources/display/display.c		\
		sources/display/display2.c		\
		sources/display/display_3.c		\
		sources/display/display_4.c		\
		sources/display/display_5.c		\
		sources/display/display_6.c		\
		sources/display/display_utils.c		\
		sources/display/display_colision.c	\
		sources/display/display_title.c

SRC 	=	$(LIB)					\
		$(DISPLAY)				\
		sources/my_utils.c			\
		sources/main.c				\
		sources/change_options.c		\
		sources/change_options_bis.c		\
		sources/init_tetris.c			\
		sources/debug.c				\
		sources/debug2.c			\
		sources/check_flags.c			\
		sources/check_tab.c			\
		sources/load_tetriminos.c		\
		sources/load_tetriminos2.c		\
		sources/tri_dimensions.c		\
		sources/make_substi.c			\
		sources/link-list/add_list.c		\
		sources/link-list/pop_list.c		\
		sources/link-list/utils_list.c

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"
YELLOW  =	"\033[1;33m"
FINISH  =       "\033[5;1;35m"

CC	=	gcc

OBJ 	= 	$(SRC:.c=.o)

all:		$(NAME)

clean:
		@rm -f $(OBJ) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(OBJ) $(DEFAULT)

fclean:		clean
		@rm -f $(NAME) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(NAME) $(DEFAULT)

re:		fclean all

## Compilation -----------------------------------------------------------------

$(NAME):
		@$(CC) $(SRC) -o $(NAME) $(CFLAGS) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(OBJ) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nCompilation Succesfully of "$(NAME) $(DEFAULT)

.PHONY: 	all clean fclean re
