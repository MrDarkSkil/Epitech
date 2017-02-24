/*
** display_4.c for display_4.c in /home/roig_a/rendu/PSU_2015_tetris
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sat Mar 19 19:08:20 2016 Antoine Roig
** Last update Sat Mar 19 19:23:00 2016 Antoine Roig
*/

#include "tetris.h"

int	check_if_in_map(t_options *options)
{
  char	**tetrimino;
  int	y;
  int	x;
  int	ret;

  y = 0;
  ret = 0;
  tetrimino = options->current->tetriminos[options->current->position];
  while (y < options->current->height)
    {
      x = -1;
      while (++x < options->current->width)
	{
	  if (tetrimino[y][x] == ' ')
	    {
	      if (!(options->current->pos_y + y - 1 >= 0 && options->current->pos_y
		   + y - 1 <= options->map_row - 1
		    && options->current->pos_x + x - 1  >= 0 &&
		    options->current->pos_x + x - 1 <= options->map_col - 1))
		ret = 1;
	    }
	}
      y++;
    }
  return (ret);
}

int	check_windows(t_options	*options)
{
  int	i;

  i = 0;
  (options->map_row + 2 > LINES) ? i = 1 :
    (options->map_col + 28 + options->next->width + options->next->width
    + 5 > COLS) ? i = 1 :
    (20 > LINES) ? i = 1 :
    (1);
  if (i == 1)
    return (-1);
  return (0);
}

int	check_if_col(t_options *options)
{
  char		**tetrimino;
  int		y;
  int		x;

  y = 0;
  tetrimino = options->current->tetriminos[options->current->position];
  while (y < options->current->height)
    {
      x = 0;
      while (x < options->current->width)
	{
	  if (tetrimino[y][x] != ' ')
	    {
	      if (options->map[options->current->pos_y + y - 1]
		  [options->current->pos_x + x - 1] != '0')
		return (1);
	    }
	  x++;
	}
      y++;
    }
  wrefresh(options->windows->tetris);
  return (0);
}

void	down_map(t_options *options, int y)
{
  char	*save;

  while (y >= 1)
    {
      save = options->map[y - 1];
      options->map[y] = save;
      y--;
    }
}

void	delete_line(t_options *options, int y)
{
  int	x;

  x = -1;
  while (++x < options->map_col)
    options->map[y][x] = '0';
  options->lines++;
  options->scores += 20;
  down_map(options, y);
}
