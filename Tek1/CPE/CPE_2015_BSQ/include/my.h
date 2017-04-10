/*
** my.h for my.h in /home/hubert_1/rendu/Piscine_C_J09/ex_02
** 
** Made by leo hubert
** Login   <hubert_1@epitech.net>
** 
** Started on  Thu Oct  8 14:25:19 2015 leo hubert
** Last update Fri Dec 18 18:13:05 2015 leo hubert
*/

#ifndef _MY_
#define _MY_


#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

typedef	struct	s_bsq
{
  int	nb_lines;
  int	size_line;
  char	**tab;
}	t_bsq;

typedef	struct	s_pos
{
  int	cur_x;
  int	cur_y;
  int	max_x;
  int	max_y;
  int	size;
}	t_pos;

typedef	struct	s_scare
{
  int	haut_x;
  int	haut_y;
  int	bas_x;
  int	bas_y;
  int	size;
}	t_scare;

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
void	usage();
int	open_file(const char *str);
int	error_openfile();
char	*putnbr_line(char *buffer, t_bsq *bsq);
int	get_octe(const char *dest);
int	open_file(const char *dest);
void	usage();
int	error_openfile();
int	not_filemap();
int	my_putin_tab(char *buffer, t_bsq *bsq);
int	my_bsq(t_bsq *bsq, t_scare *scare);
int	make_scare(t_bsq *bsq, t_scare *scare);
int	search_scare(t_bsq *bsq, t_pos *pos, t_scare *scare);
int	my_show_bsq(t_bsq *bsq);
int	save_scare(t_scare *scare, t_pos *pos, int size);

#endif
