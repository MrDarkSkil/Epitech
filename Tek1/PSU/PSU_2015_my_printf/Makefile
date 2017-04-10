##
## Makefile<PSU_2015_my_printf> for Makefile in /home/hubert_i/rendu/101pong
## 
## Made by leo hubert
## Login   <hubert_i@epitech.net>
## 
## Started on  Fri Nov 13 01:56:31 2015 leo hubert
## Last update Mon Nov 16 14:18:56 2015 leo hubert
##

CC	= cc

RM	= rm -rf

ARRC	= ar rc

CFLAGS	+= -W -Wextra -Werror -Wall

RANLIB	= ranlib

NAME	= libmy.a

SRCS	=	./lib/my/my_getnbr.c		\
		./lib/my/my_putchar.c		\
		./lib/my/my_printf.c		\
		./lib/my/my_put_nbr.c		\
		./lib/my/fonction_printf.c	\
		./lib/my/my_putnbr_unsigned.c	\
		./lib/my/my_putstr.c		\
		./lib/my/my_strlen.c		\
		./lib/my/my_putnbr_base.c	\
		./lib/my/my_putnbr_base_size.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARRC) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	$(RM) $(OBJS) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
