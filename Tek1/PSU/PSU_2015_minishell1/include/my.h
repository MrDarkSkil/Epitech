/*
** my.h for my.h in /home/hubert_1/rendu/Piscine_C_J09/ex_02
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Thu Oct  8 14:25:19 2015 leo hubert
** Last update Sun Jan 24 18:06:42 2016 Léo Hubert
*/

#ifndef MY_
#define MY_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

typedef struct s_list
{
  int	first;
  char	*key;
  char	*str;
  struct s_list *prev;
  struct s_list *next;
}	t_list;

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
int	chek_flags(va_list ap, char arg);
char	*my_getenv(char **env, char *path);
char	*get_next_line(const int fd);
char	**get_env(t_list *list);
char	*get_path(t_list *list, char *command);
char	*custom_path(char *str, char *command);
char	**get_env_bis(t_list *list);
char	*my_fusionstr(char *str, char *str2);
t_list 	*add_list(t_list *list, char *str, char *key);
int	show_list(t_list *list);
int	check_path(char *check);
int	init_command(char *arg, t_list *list);
t_list	*init_env(char **env);
int	size_list(t_list *list);
int	exec_command(char	*path,
		     char	**command,
		     char	**env);
char	*search_list(t_list *list, char *search);
int	my_cd(t_list *list, char **command);
int	my_exit(t_list *list, char **command);
int	my_unset(t_list *list, char **command);
int	my_set(t_list *list, char **command);
int	check_command(char **command, t_list *list);
t_list	*delete_maillon(t_list *list);
int	my_cd_moin(t_list *list);
char	*my_cd_bis(t_list *list, char **command, char *pwd);
int	countword(char *str, char caract);
int	current(char *str, char caract);
char	**my_str_to_wordtab(char *str, char caract);
int	local_exec(t_list *list, char **command);
void	sigproc();
void	my_puterror(char c);
int	my_error(char *com, char *str);

#endif
