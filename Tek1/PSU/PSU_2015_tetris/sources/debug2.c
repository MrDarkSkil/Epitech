/*
** debug2.c for debug2.c in /home/roig_a/rendu/PSU_2015_tetris
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Thu Mar 17 10:29:04 2016 Antoine Roig
** Last update Thu Mar 17 10:34:40 2016 Antoine Roig
*/

#include "tetris.h"

void	debug_tetrimino2(t_list *tmp)
{
  my_putstr("Tetriminos : Name ");
  my_putstr(take_begin(tmp->tetri->name, '.'));
  my_putstr(" : Size ");
  my_put_nbr(tmp->tetri->rx);
  my_putchar('*');
  my_put_nbr(tmp->tetri->ry);
  my_putstr(" : Color ");
  my_put_nbr(tmp->tetri->color);
  my_putstr(" :\n");
}

void		debug_tetriminos(t_options *options)
{
  t_list	*tmp;
  int		x;
  int		y;

  my_putstr("\nTetriminos :");
  my_put_nbr(options->tetriminos->size);
  tmp = options->tetriminos->begin;
  my_putchar('\n');
  while (tmp)
    {
      debug_tetrimino2(tmp);
      y = 0;
      while (tmp->tetri->tetriminos[3][y])
	  {
	    x = -1;
	    while (tmp->tetri->tetriminos[3][y][++x])
	      write(1, &tmp->tetri->tetriminos[3][y][x], 1);
	    write(1, "\n", 1);
	    y++;
	  }
      tmp = tmp->next;
    }
  press_any_key();
}
