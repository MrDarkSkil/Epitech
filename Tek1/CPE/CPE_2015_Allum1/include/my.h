/*
** my.h for Allum1 in /home/hubert_i/CPE_2015_Allum1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Feb 19 01:49:36 2016 Léo Hubert
** Last update Fri Feb 19 01:53:27 2016 Léo Hubert
*/


#ifndef MY_
#define MY_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


typedef struct s_allum
{
  int	first;
  int	etage;
  int	nb_allum;
  int	binary;
  struct s_allum *prev;
  struct s_allum *next;
}	t_allum;

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
int     my_putnbr_base_size(size_t nbr, char *base);
t_allum		*init_allum1(int etage);
t_allum		*add_etage(t_allum	*allum,
			  int		nb_allum,
			   int		etage);
int		getline_allum(t_allum *allum);
int		getmatches(t_allum *allum, int line);
void		remove_matches(t_allum	*allum,
			       int	line,
			       int	matches);
void		display_playerturn(int	matches,
				   int	line);
int		count_allum(t_allum	*allum);
void		display_allum1_part2(t_allum	*allum,
				     int	width,
				     int	etage);
void		display_allum1(t_allum	*allum);
int		check_game(t_allum *allum, int player);
int		total_matches(t_allum *allum);
int		remove_IA(t_allum *allum);
int		IA(t_allum *allum);
int		my_strchar(char *str, char to_find);
long		determine_power(char* str, int base);
int		my_getnbr_base(char *str, char *base);

#endif
