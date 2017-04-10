##
## Makefile for PSU_2016_malloc in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_malloc
##
## Made by Leo HUBERT
## Login   <leo.hubert@epitech.eu>
##
## Started on  Mon Jan 23 21:45:33 2017 Leo HUBERT
## Last update Fri Feb  3 12:34:53 2017 Yassir
##

CFLAGS	+=	-W -Wall -Werror -Wextra -fPIC -shared
CFLAGS  +=	-I../include

CC	=	gcc

NAME_LIB    =	../libmy_malloc.so

SRC	=	malloc.c	\
		heap_functions.c \
		show_memory.c	\

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"
YELLOW  =	"\033[1;33m"
FINISH  =       "\033[5;1;35m"

OBJ	=	$(SRC:.c=.o)

all:		$(NAME_LIB)

clean:
		@rm -f $(OBJ) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(OBJ) $(DEFAULT)

fclean:		clean
		@rm -f $(NAME_LIB) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(NAME_LIB) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(NAME_LIB) $(DEFAULT)

re:		fclean all


## Sound ----------------------------------------------------------------------

encore:
		@paplay ../include/sound/encore.ogg
blague:
		@paplay ../include/sound/humour.ogg &

## Compilation -----------------------------------------------------------------

$(NAME_LIB):	$(OBJ)
		@$(CC) $(OBJ) $(CFLAGS) -o $(NAME_LIB) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(OBJ) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nCompilation Succesfully of "$(NAME_LIB) $(DEFAULT)
		#@paplay ../include/sound/end.ogg &

%.o:		%.c
		@$(CC) -c $^ -o $@ $(CFLAGS) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $^ $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $^ $(DEFAULT)

.PHONY: 	all encore clean fclean re
