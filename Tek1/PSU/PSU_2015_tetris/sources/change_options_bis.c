/*
** change_key_bis.c for change_key_bis in /home/hubert_i/PSU_2015_tetris
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Feb 27 00:59:34 2016 Léo Hubert
** Last update Mon Mar 14 13:49:57 2016 Antoine Roig
*/

#include "tetris.h"

int	key_pause(t_options	*options,
		  char		*flag)
{
  if (flag[0] == ' ' && my_strlen(flag) == 1)
    return (options->key_pause = 32);
  if (my_is_num(flag) != -1)
    options->key_pause = my_getnbr(flag);
  else if (my_strlen(flag) == 1)
    options->key_pause = flag[0];
  else
    return (my_putstr("Error: KeyPause key not found"));
  return (0);
}

int	change_level(t_options	*options,
		     char	*flag)
{
  if (my_is_num(flag) != -1)
    options->level = my_getnbr(flag);
  else
    return (my_putstr("Error: Level not good\n"));
  return (0);
}

int	change_map(t_options	*options,
		   char		*flag)
{
  char	*row;
  char	*col;

  if (my_search_to_str(flag, ',') == 1)
    {
      col = take_after(flag, ',');
      row = take_begin(flag, ',');
      if (my_strlen(row) != 0 && my_strlen(col) != 0
	  && my_is_num(col) != 1 && my_is_num(row) != -1)
	{
	  options->map_row = my_getnbr(row);
	  options->map_col = my_getnbr(col);
	}
      else
	return (my_putstr("Error: MapSize just enter number\n"));
    }
  else
    return (my_putstr("Error: Map entry not good\n"));
  return (0);
}

int	without_next(t_options	*options,
		     char	*flag)
{
  options->without_next = 1;
  (void)flag;
  return (0);
}
