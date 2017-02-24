/*
** display2.c for display2.c in /home/roig_a/rendu/PSU_2015_tetris
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sat Mar 19 19:01:27 2016 Antoine Roig
** Last update Sat Mar 19 19:02:31 2016 Antoine Roig
*/

#include "tetris.h"

void	display_tetris(t_options *options)
{
  char	**tetrimino;
  int	y;
  int	x;

  y = 0;
  tetrimino = options->current->tetriminos[options->current->position];
  wattron(options->windows->tetris, COLOR_PAIR(options->current->color));
  while (y < options->current->height)
    {
      x = 0;
      while (x < options->current->width)
	{
	  if (!(tetrimino[y][x] == ' '))
	    mvwprintw(options->windows->tetris, options->current->pos_y + y,
		      options->current->pos_x + x, "%c", '*');
	  x++;
	}
      y++;
    }
  wattroff(options->windows->tetris, COLOR_PAIR(options->next->color));
  wrefresh(options->windows->tetris);
}

void	display_map(t_options *options)
{
  int	x;
  int	y;

  y = 0;
  while (y < options->map_row)
    {
      x = 0;
      while (x < options->map_col)
	{
	  if (options->map[y][x] != '0')
	    {
	      wattron(options->windows->tetris, COLOR_PAIR(options->map[y][x]));
	      mvwprintw(options->windows->tetris, y + 1, x + 1, "%c", '*');
	      wattroff(options->windows->tetris, COLOR_PAIR(options->map[y][x]));
	    }
	  else
	    mvwprintw(options->windows->tetris, y + 1, x + 1, "%c", ' ');
	  x++;
	}
      y++;
    }
}

void	load_color()
{
  start_color();
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void		display_next(t_options *options)
{
  char		**tetrimino;
  int		y;
  int		x;

  y = 0;
  tetrimino = options->next->tetriminos[options->next->position];
  wattron(options->windows->next, COLOR_PAIR(options->next->color));
  while (y < options->next->height)
    {
      x = 0;
      while (x < options->next->width)
	{
	  if (tetrimino[y][x] == ' ')
	    mvwprintw(options->windows->next, y + 1, x + 2, "%c", ' ');
	  else
	    mvwprintw(options->windows->next, y + 1, x + 2, "%c", '*');
	  x++;
	}
      y++;
    }
  wattroff(options->windows->next, COLOR_PAIR(options->next->color));
  wrefresh(options->windows->next);
}

void		choose_next(t_options *options)
{
  t_list	*tmp;
  int		i;
  int		next;

  i = -1;
  options->next = xmalloc(sizeof(t_tetris));
  srand(time(NULL));
  tmp = options->tetriminos->begin;
  next = rand() % options->tetriminos->size;
  while (++i < next)
    tmp = tmp->next;
  options->next->position = rand() % 4;
  options->next->name = tmp->tetri->name;
  options->next->color = tmp->tetri->color;
  options->next->width = tmp->tetri->width;
  options->next->height = tmp->tetri->height;
  options->next->tetriminos = tmp->tetri->tetriminos;
  options->next->pos_x = (options->map_col / 2) - (tmp->tetri->width / 2);
  options->next->pos_y = 1;
}
