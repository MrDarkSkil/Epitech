/*
** display_colision.c for colision.c in /home/roig_a/rendu/PSU_2015_tetris/sources/display
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Sun Mar 20 14:02:06 2016 Antoine Roig
** Last update Sun Mar 20 21:37:41 2016 Léo Hubert
*/

#include "tetris.h"

void	colision_left(t_options *options)
{
  if (check_colision_left(options) != 1)
    {
      if (options->current->pos_x - 1 > 0)
	options->current->pos_x--;
      display_tetris(options);
      wrefresh(options->windows->tetris);
    }
}

void	colision_right(t_options *options)
{
  if (check_colision_right(options) != 1)
    {
      if (options->current->pos_x + options->current->width - 2
	  <= options->map_col)
	options->current->pos_x++;
      display_tetris(options);
      wrefresh(options->windows->tetris);
    }
}

void	colision_rotate(t_options *options)
{

  if (options->current->position + 1 > 3)
    options->current->position = 0;
  else
    options->current->position++;
  if (check_if_in_map(options) == 1 || check_if_col(options) == 1)
    {
      if (options->current->position - 1 < 0)
	options->current->position = 3;
      else
	options->current->position--;
    }
  display_tetris(options);
  wrefresh(options->windows->tetris);
}

void	drop(t_options *options)
{
  drop_tetris(options);
  put_in_map(options);
  display_tetris(options);
  wrefresh(options->windows->tetris);
  options->down = 1;
}
