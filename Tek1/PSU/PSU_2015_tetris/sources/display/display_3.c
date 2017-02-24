/*
** display_3.c for display_3.c in /home/roig_a/rendu/PSU_2015_tetris
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sat Mar 19 19:05:25 2016 Antoine Roig
** Last update Sun Mar 20 21:35:42 2016 Léo Hubert
*/

#include "tetris.h"

void	get_time(int sec, t_options *options)
{
  int	m;
  int	h;
  int	s;

  m = sec / 60;
  s = sec % 60;
  h = m / 60;
  mvwprintw(options->windows->scores, 8, 1, "Timer\t\t%d:%d:%d  ", h, m, s);
}

int	check_colision_down(t_options *options)
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
     x = 0;
      while (x < options->current->width)
	{
	  if (!(tetrimino[y][x] == ' '))
	    {
	      if (options->map[options->current->pos_y + y]
		  [options->current->pos_x + x - 1] != '0')
		ret = 1;
	    }
	  x++;
	}
      y++;
    }
  return (ret);
}

int	drop_tetris(t_options *options)
{
  int	ret;

  ret = 0;
  while (ret != 1)
    {
      if ((ret = check_colision_down(options)) == 1)
	return (1);
      options->current->pos_y++;
    }
  return (ret);
}

int	check_colision_left(t_options *options)
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
      x = 0;
      while (x < options->current->width)
	{
	  if (!(tetrimino[y][x] == ' '))
	    {
	      if (options->map[options->current->pos_y + y - 1]
		  [options->current->pos_x + x - 2] != '0'
		  && options->current->pos_x + x - 2 >= 0)
		ret = 1;
	    }
	  x++;
	}
      y++;
    }
  return (ret);
}

int	check_colision_right(t_options *options)
{
  char		**tetrimino;
  int		y;
  int		x;
  int		ret;

  y = -1;
  ret = 0;
  tetrimino = options->current->tetriminos[options->current->position];
  while (++y < options->current->height)
    {
      x = 0;
      while (x < options->current->width)
	{
	  if (tetrimino[y][x] != ' ')
	    {
	      if (options->map[options->current->pos_y + y - 1]
		  [options->current->pos_x + x]  != '0'
		  || options->map[options->current->pos_y + y - 1]
		  [options->current->pos_x + x]  == 'b')
		ret = 1;
	    }
	  x++;
	}
    }
  return (ret);
}
