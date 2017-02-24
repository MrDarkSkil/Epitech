##
## Makefile for Make in /home/jabbar_y/rendu/PSU_2015_my_printf_bootstrap
## 
## Made by Jabbari Yassir
## Login   <jabbar_y@epitech.net>
## 
## Started on  Mon Nov  2 14:30:26 2015 Jabbari Yassir
## Last update Tue Jan 19 17:00:37 2016 Léo Hubert
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;30m"
RED	=	"\033[5;31m"
YELLLOW	=	"\033[1;33m"
FINISH	=	"\033[5;1;35m"

CC	= cc

RM	= rm -rf

ARRC	= ar rc

CFLAGS	+= -W -Wextra -Werror -Wall

RANLIB = ranlib

NAME	= ../libmy.a

SRCS	= 	my_find_prime_sup.c		\
		my_getnbr.c			\
		my_isneg.c			\
		my_is_prime.c			\
		my_power_rec.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_showmem.c			\
		my_sort_int_tab.c		\
		my_square_root.c		\
		my_strcapitalize.c		\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_str_isalpha.c		\
		my_str_islower.c		\
		my_str_isnum.c			\
		my_str_isprintable.c		\
		my_str_isupper.c		\
		my_strlen.c			\
		my_strlcat.c			\
		my_strlowcase.c			\
		my_strncat.c			\
		my_strncmp.c			\
		my_strncpy.c			\
		my_strstr.c			\
		my_strupcase.c			\
		my_putnbr_bin.c			\
		sum_stdarg.c			\
		disp_stdarg.c			\
		my_putnbr_base.c		\
		my_putnbr_base_size.c		\
		my_putnbr_unsigned.c  		\
		get_next_line.c			\
		my_swap.c

OBJS	= $(SRCS:.c=.o)

all: 		$(NAME)

clean:
		@$(RM) $(OBJS) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(OBJS) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(OBJS) $(DEFAULT)

fclean: 	clean
		@$(RM) $(NAME) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(NAME) $(DEFAULT)

re: 		fclean all

## Compilation lib --------------------------------------------------------------

$(NAME):	$(OBJS)
		@$(ARRC) $(NAME) $(OBJS) && \
		$(ECHO) $(GREEN) "[OK] Ar" $(TEAL) $(OBJS) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] Ar" $(TEAL) $(OBJS) $(DEFAULT)
		@$(RANLIB) $(NAME) && \
		$(ECHO) $(GREEN) "[OK] Ranlib" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] Ranlib" $(TEAL) $(NAME) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nLib compilation finish"$(DEFAULT)

%.o:		%.c
		@$(CC) $(CFLAGS) -c -o $@ $^ && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) lib/my/$^ $(DEFAULT) || \
		$(ECHO) $(GREEN) "[ERROR] gcc" $(TEAL) lib/my/$^ $(DEFAULT)

.PHONY: 	all clean fclean re
