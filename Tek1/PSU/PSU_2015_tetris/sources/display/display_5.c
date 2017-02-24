/*
** display_5.c for display_5.c in /home/roig_a/rendu/PSU_2015_tetris
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sat Mar 19 19:23:32 2016 Antoine Roig
** Last update Sat Mar 19 19:24:11 2016 Antoine Roig
*/

#include "tetris.h"

void	check_game(t_options *options)
{
  int	x;
  int	y;
  int	i;

  y = 0;
  while (y < options->map_row)
    {
      x = 0;
      i = 0;
      while (x < options->map_col)
	{
	  if (options->map[y][x] != '0')
	    i++;
	  x++;
	}
      if (i == options->map_col)
	delete_line(options, y);
      y++;
    }
}
