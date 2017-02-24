/*
** my.h for my.h in /home/hubert_1/rendu/Piscine_C_J09/ex_02
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Thu Oct  8 14:25:19 2015 leo hubert
** Last update Tue Apr 12 18:17:40 2016 Léo Hubert
*/

#ifndef MY_
# define MY_

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include "get_next_line.h"

typedef struct s_env
{
  int	first;
  char	*key;
  char	*str;
  struct s_env *prev;
  struct s_env *next;
}	t_env;

typedef struct		s_commands
{
  char			**command;
  char			*arg;
  int			first;
  struct s_commands	*next;
  struct s_commands	*prev;
}			t_commands;

typedef struct	s_data
{
  t_env		*env;
  t_commands	*commands;
}		t_data;

typedef struct	s_bin
{
  char		*path;
  char		**env;
  char		**commands;
  char		*file;
  char		**command;
  pid_t		pid;
  int		fd;
}		t_bin;

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
char	**get_env(t_env *env);
char	*get_path(t_env *env, char *command);
char	*custom_path(char *str, char *command);
char	**get_env_bis(t_env *env);
char	*my_fusionstr(char *str, char *str2);
t_env 	*add_env(t_env *env, char *str, char *key);
int	show_env(t_env *env);
int	check_path(char *check);
int	init_command(t_data *data);
t_env	*init_env(char **env);
int	size_env(t_env *env);
int	exec_command(t_data *data);
char	*search_env(t_env *env, char *search);
int	my_cd(t_env *env, char **command);
int	my_exit(t_env *env, char **command);
int	my_unset(t_env *env, char **command);
int	my_set(t_env *env, char **command);
int	check_command(char **command, t_env *env);
t_env	*delete_maillon(t_env *env);
int	my_cd_moin(t_env *env);
char	*my_cd_bis(t_env *env, char **command, char *pwd);
int	countword(char *str, char caract);
int	current(char *str, char caract);
char	**my_str_to_wordtab(char *str, char caract);
int	local_exec(t_env *env, char **command);
void	sigproc();
void	my_puterror(char c);
int	my_error(char *com, char *str);
char	*my_strdup(char *src);
void	free_env(t_env *env);
int	init_commands(t_data *data, char *args);
int     exec_commands(t_data *data);
void	free_commands(t_commands *commands);
int	exec_commandpipe2(char **commands, int fd[2], t_env *env_list, char **env);
int	exec_commandpipe1(char **commands, int fd[2], t_env *env_list, char **env);
int	exec_commandpipe(t_data *data);
int	exec_commandredirect2(t_data *data);
int	exec_commandredirect(t_data *data);
#endif
