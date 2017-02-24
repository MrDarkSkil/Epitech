/*
** tetris.h for tetris.h in /home/roig_a/rendu/PSU_2015_tetris
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Thu Feb 25 17:48:48 2016 Antoine Roig
** Last update Sun Mar 20 14:27:22 2016 Antoine Roig
*/

#ifndef _TETRIS_H_
# define _TETRIS_H_

# define _POSIX_SOURCE
# define _XOPEN_SOURCE
# define _GNU_SOURCE

# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <ncurses.h>
# include <time.h>
# include <dirent.h>
# include <fcntl.h>
# include <string.h>

typedef	struct	s_tetri
{
  int			rx;
  int			ry;
  char			*name;
  int			width;
  int			height;
  int			color;
  char			***tetriminos;
}		t_tetri;

typedef struct		s_list
{
  t_tetri		*tetri;
  char			*n;
  struct s_list		*next;
  struct s_list		*prev;
}	 t_list;

typedef struct		s_dlist
{
  t_list		*begin;
  t_list		*end;
  int			size;
}	t_dlist;

typedef struct	s_tetris
{
  int		position;
  int		pos_x;
  int		pos_y;
  char		*name;
  int		width;
  int		height;
  int		color;
  char		***tetriminos;
}	t_tetris;

typedef struct	s_windows
{
  WINDOW	*tetris;
  WINDOW	*scores;
  WINDOW	*next;
}	t_windows;

typedef	struct	s_var
{
  int	j;
  int	i;
  int	x_ref;
  int	y_ref;
}		t_var;

typedef	struct	s_l_c
{
  int	l;
  int	c;
}		t_l_c;

typedef struct s_options
{
  int		*tab_key;
  int		key_left;
  int		key_right;
  int		key_turn;
  int		key_drop;
  int		key_quit;
  int		key_pause;
  int		map_row;
  int		map_col;
  int		level;
  int		without_next;
  int		debug;
  int		down;
  int		scores;
  int		high;
  int		lines;
  char		*binary;
  t_windows	*windows;
  t_tetris	*next;
  t_tetris	*current;
  t_dlist	*tetriminos;
  char		**map;
}	t_options;

void			*xmalloc(int);
t_dlist			*new_list(t_dlist*);
void			show_list(t_options *);
void			clear_list(t_dlist *list);
void			rev_list(t_dlist * list);
void			add_list_end(t_dlist *, t_tetri *tetri);
t_list			*pop_list_begin(t_dlist *);
t_list			*pop_list_end(t_dlist *);
t_dlist			*load_tetriminos(t_dlist *list);
char			*parsing1(char *content, char **width,
				  char **height, char **color);
char			**make_substi(char **, int, int);
t_tetri	*load_tetri2(t_tetri * tetri, int l, int c, char *color);
t_tetri	*load_tetri(t_tetri *tetri, int rx, int ry, char *name);
void	load_tetri_loop(t_dlist *list, struct stat buffer, DIR *repository);
int	active_debug(t_options	*options,
		     char	*flag);
int     my_strncmp(char *s1, char *s2, int nb);
int	my_getnbr(char *str);
int	my_putchar(char c);
int	my_put_nbr(int nbr);
int	my_strlen(char * str);
char    *my_strcat(char *dest, char *src);
int	my_putstr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strcmp_2(char *s1, char *s2);
int     my_show_wordtab(char **tab);
void	init_options(t_options	*options, char **av);
int	show_help();
int	debug(t_options	*options);
void	debug_tetriminos(t_options *options);
int	count_tetriminos(t_options *options);
char	*take_after(char *str, char c);
char	*take_begin(char *str, char c);
int	change_level(t_options	*options,
		     char	*flag);
int	change_map(t_options	*options,
		   char		*flag);
int	without_next(t_options	*options,
		     char	*flag);
int	key_left(t_options	*options,
		 char		*flag);
int	key_right(t_options	*options,
		  char		*flag);
int	key_turn(t_options	*options,
		 char		*flag);
int	key_drop(t_options	*options,
		 char		*flag);
int	key_quit(t_options	*options,
		 char		*flag);
int	key_pause(t_options	*options,
		  char		*flags);
int	check_keys(t_options	*options,
		   char		*flag);
char	*parce_flag(char *str);
int	check_flags(t_options	*options,
		    int		ac,
		    char	**av);
int	display(t_options *options);
int	my_is_num(char *str);
int	my_search_to_str(char *str, char to_search);
int	init_map(t_options *options);
int	put_in_map(t_options *options);
void	press_any_key();
char	**make_tetri2(char *content, char **tetrimino, int i, int c);
int	check_file(char	*str);
t_dlist	*parsing(t_dlist *list, char *content, char *name);
char	***malloc_tab(int l, int c);
char	***first_dim(char ***tab, int l, int c, char**);
char	***last_dim(char ***tab, int l, int c);
int	check_tab(int *tab);
void    my_putchar_file(char c, int fd);
int     my_put_nbr_file(int nb, int fd);
void    load_title_color();
void    title_bis(int x, int y);
void    title1(int x, int y);
void    title(int x, int y);
void    display_tetris(t_options *options);
void    display_map(t_options *options);
void    load_color();
void            display_next(t_options *options);
void            choose_next(t_options *options);
void	get_time(int sec, t_options *options);
int	check_colision_down(t_options *options);
int	drop_tetris(t_options *options);
int	check_colision_left(t_options *options);
int	check_colision_right(t_options *options);
void	display_score(t_options *options);
int	check_if_in_map(t_options *options);
int	check_windows(t_options	*options);
int	options_down(t_options *options);
int	check_if_col(t_options *options);
void	down_map(t_options *options, int y);
void	delete_line(t_options *options, int y);
void	check_game(t_options *options);
void	drop(t_options *);
void	colision_rotate(t_options *);
void	colision_right(t_options *);
void	colision_left(t_options *);
void    init_display(t_options *options);
void    option_down(t_options *options);
void    simple_aff(t_options *options);
void    end_game(t_options *options);
#endif /* TETRIS_ */
