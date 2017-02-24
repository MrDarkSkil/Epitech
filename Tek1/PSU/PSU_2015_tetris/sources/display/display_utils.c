/*
** display_utils.c for display_utils.c in /home/roig_a/rendu/PSU_2015_tetris
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sat Mar 19 18:49:32 2016 Antoine Roig
** Last update Sat Mar 19 18:51:30 2016 Antoine Roig
*/

#include "tetris.h"

void	my_putchar_file(char c, int fd)
{
  write(fd , &c, 1);
}

int	my_put_nbr_file(int nb, int fd)
{
  if (nb < 10)
    my_putchar_file((char)(nb + '0'), fd);
  else if (nb > 9)
    {
      my_put_nbr_file(nb / 10, fd);
      my_putchar_file((char)(nb % 10 + '0'), fd);
    }
  else
    my_putstr("Nombre invalide\n");
  return (0);
}

void	load_title_color()
{
  init_pair(10, COLOR_RED, COLOR_RED);
  init_pair(20, COLOR_BLUE, COLOR_BLUE);
  init_pair(30, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(40, COLOR_GREEN, COLOR_GREEN);
  init_pair(50, COLOR_CYAN, COLOR_CYAN);
  init_pair(60, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(70, COLOR_MAGENTA, COLOR_BLACK);
}
