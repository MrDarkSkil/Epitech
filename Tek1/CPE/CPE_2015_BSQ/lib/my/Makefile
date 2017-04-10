##
## Makefile for Make in /home/jabbar_y/rendu/PSU_2015_my_printf_bootstrap
## 
## Made by Jabbari Yassir
## Login   <jabbar_y@epitech.net>
## 
## Started on  Mon Nov  2 14:30:26 2015 Jabbari Yassir
## Last update Thu Dec 17 23:50:04 2015 leo hubert
##

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
		my_printf.c			\
		my_putnbr_base_size.c		\
		my_putnbr_unsigned.c		\
		my_swap.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARRC) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
