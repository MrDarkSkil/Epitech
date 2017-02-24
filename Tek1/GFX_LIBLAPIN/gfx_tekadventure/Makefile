##
## Makefile for makefile in /home/hubert_i/rendu/2015/INFO/gfx_tekadventure
## 
## Made by Léo Hubert
## Login   <hubert_i@epitech.net>
## 
## Started on  Thu Apr 14 13:53:38 2016 Léo Hubert
## Last update Sun Apr 17 18:51:37 2016 Loic Lopez
##

CFLAGS	+=	-llapin -L$(LD_LIBRARY_PATH) -I$(C_INCLUDE_PATH)
CFLAGS 	+= 	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm
CFLAGS	+=	-W -Wall -g
CFLAGS	+=	-Werror
CFLAGS	+=	-I./include/

CC	=	gcc

NAME    =	gfx_tekadventure

LIB	=	src/lib/my_getnbr.c		\
		src/lib/my_putstr.c		\

SRCS	=	$(LIB)				\
		src/main.c			\
		src/contribute_scene3.c		\
		src/contribute_main.c		\
		src/contribute_scene1.c		\
		src/keys_and_menu.c		\
		src/list.c			\
		src/loadTextures.c		\
		src/screens.c			\
		src/loadSprites.c		\
		src/loadSounds.c		\
		src/tekfonctions.c		\
		src/tekfonctions_bis.c

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"
YELLOW  =	"\033[1;33m"
FINISH  =       "\033[5;1;35m"

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

clean:
		@rm -f $(OBJS) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(OBJS) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(OBJS) $(DEFAULT)

fclean:		clean
		@rm -f $(NAME) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(NAME) $(DEFAULT)

re:		fclean all


## Sound ----------------------------------------------------------------------

encore:
		@paplay include/sound/encore.ogg
blague:
		@paplay include/sound/humour.ogg &

## Compilation -----------------------------------------------------------------

$(NAME):	$(OBJS)
		@$(CC) $(OBJS) $(CFLAGS) -o $(NAME) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(OBJS) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(OBJS) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nCompilation Succesfully of "$(NAME) $(DEFAULT)
#		@paplay include/sound/end.ogg &

%.o:		%.c
		@$(CC) $^ -c -o $@  $(CFLAGS) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $^ $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $^ $(DEFAULT)

.PHONY: 	all encore clean fclean re
