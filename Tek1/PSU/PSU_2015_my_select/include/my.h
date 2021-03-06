/*
** my.h for my.h in /home/hubert_1/rendu/Piscine_C_J09/ex_02
** 
** Made by leo hubert
** Login   <hubert_1@epitech.net>
** 
** Started on  Thu Oct  8 14:25:19 2015 leo hubert
** Last update Sat Dec 12 22:18:22 2015 leo hubert
*/

#ifndef MY_
#define MY_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my_select.h"

int	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int     my_putnbr_unsigned(unsigned int nb);
int	my_put_nbr_base(int nb, char *str);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	sum_stdarg(int i, int nb, ...);
int	disp_stdarg(char *s, ...);
int	my_putnbr_bin(int nb);
int	my_putnbr_base(int nbr, char *base);
int	my_is_printable_char(char *str);
int     my_printf(char *arg, ...);
int     my_putnbr_base_size(size_t nbr, char *base);
int     chek_flag(char flag, va_list ap);
int     my_printf_p(size_t pointer);
int     my_printf_x(int arg, int type);
int     my_printf_S(char *str);
t_list	*add_list_bis(t_list *newelem);
int	my_select_show(t_list *list, int argc);
t_list	*key_action(t_list *list, int key);
t_list	*my_select_init(int argc, char **argv);
t_list	*add_list(t_list *list, char *str);
t_list	*add_list_bis(t_list *newelem);
int	show_list(t_list *list);
int	color_select(t_list *list);
t_list	*up_buttom(t_list *list);
t_list	*down_buttom(t_list *list);
t_list	*delete_target(t_list *list);
t_list	*enter_buttom(t_list *list);
t_list	*select_target(t_list *list);
int	usage();

#endif
