##
## Makefile for Makefile in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
## 
## Made by Léo Hubert
## Login   <hubert_i@epitech.net>
## 
## Started on  Sun Jan 17 19:54:18 2016 Léo Hubert
## Last update Tue Jan 26 19:08:30 2016 Léo Hubert
##

CFLAGS	+=	-llapin -L$(LD_LIBRARY_PATH) -I$(C_INCLUDE_PATH)
CFLAGS 	+= 	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm
CFLAGS	+=	-W -Wall -Werror -ansi -pedantic
CFLAGS	+=	-I./include/
LIB  	=	-lmy -L./lib/

CC	=	gcc

NAME    =	demo

SRC	=	main.c			\
		image.c			\
		tekfonctions.c		\
		tekfonctions_bis.c

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"
YELLOW  =	"\033[1;33m"
FINISH  =       "\033[5;1;35m"

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

clean:
		@rm -f $(OBJ) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(OBJ) $(DEFAULT)

fclean:		clean
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
		@$(CC) $(OBJ) $ $(CFLAGS) -o $(NAME) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(OBJ) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nCompilation Succesfully of "$(NAME) $(DEFAULT)
		@paplay include/sound/end.ogg &

%.o:		%.c
		@$(CC) $^ -c $(CFLAGS) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $^ $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $^ $(DEFAULT)

.PHONY: 	all encore clean fclean re
