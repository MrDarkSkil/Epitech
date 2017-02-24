##
## Makefile for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
## 
## Made by Eric DESCHODT
## Login   <descho_e@epitech.net>
## 
## Started on  Mon Mar  7 13:18:01 2016 Eric DESCHODT
## Last update Sun Mar 27 17:51:23 2016 Léo Hubert
##

NAME		=		corewar

LIB             =       -L/home/${USER}/.froot/lib/ -llapin     \
                        -L/usr/local/lib                        \
                        -lsfml-audio                            \
                        -lsfml-graphics                         \
                        -lsfml-window                           \
                        -lsfml-system                           \
                        -lstdc++ -ldl                           \
                        -lm

SRC		=		src/main.c		\
				src/start_vm.c		\
				src/utils.c		\
				src/op.c		\
				src/living.c		\
				src/load_instru.c	\
				src/parsing.c		\
				src/parsing2.c		\
				src/utils_list.c	\
				src/list_champ.c	\
				src/list_champ2.c	\
				src/pop_list.c		\
				src/add_list.c		\
				src/kill_champ.c	\
				src/zjump.c		\
				src/sti.c		\
				src/syntax.c		\
				src/syntax2.c		\
				src/syntaxe4.c		\
				src/syntax3.c		\
				src/add.c		\
				src/ldi.c		\
				src/lldi.c		\
				src/or.c		\
				src/xor.c		\
				src/check_id.c		\
				src/and.c		\
				src/sub.c		\
				src/ld.c		\
				src/forking.c		\
				src/create_champ.c	\
				src/movingPC.c		\
				src/init_board.c	\
				src/st.c		\
				src/lld.c		\
				src/aff.c		\
				src/my_strdup.c		\
				src/debug.c		\
				src/usage.c		\
				src/winning.c

SRC		+=		src/loop.c		\
				src/check_ko.c		\
				src/print_names.c	\
				src/printboardgraph.c	\
				src/startgame.c		\
				src/free_tex.c

SRC		+=		../menu/src/main.c		\
				../menu/src/init_menu.c		\
				../menu/src/button_options.c	\
				../menu/src/button.c		\
				../menu/src/load_screen.c 	\
				../menu/src/load_textures.c 	\
				../menu/src/pages.c		\
				../menu/src/click_handler.c 	\
				../menu/src/click_handler2.c 	\
				../menu/src/tekfonctions.c
OBJ		=		$(SRC:.c=.o)

CFLAGS		+=		-W -Wall -Wextra -ansi -pedantic
CFLAGS		+=		-Werror
CFLAGS		+=		-I../include
CFLAGS		+=		-I/home/${USER}/.froot/include/


LFLAGS		=		-lmy -L../lib

all		:		$(NAME)

$(NAME)		:		$(OBJ)
				cc -o $(NAME) $(OBJ) $(LFLAGS) $(LIB)

clean		:
				rm -rf $(OBJ)

fclean		:		clean
				rm -rf $(NAME)

re		:		fclean all

.PHONY		:		all clean fclean re
