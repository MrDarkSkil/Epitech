/*
** display_allum1.c for display_allum1 in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_Allum1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Feb 13 17:23:50 2016 Léo Hubert
** Last update Sun Feb 14 13:50:27 2016 Léo Hubert
*/

#include "my.h"

void	display_allum1_part2(t_allum	*allum,
			     int	width,
			     int	etage)
{
  int	i;
  int	x;
  int	space;

  i = 0;
  while (i++ < etage)
    {
      space = (width - 2) - allum->etage * 2;
      x = 0;
      my_putchar('*');
      while (x++ < space / 2)
	my_putchar(' ');
      x = 0;
      while (x++ < allum->nb_allum)
	my_putchar('|');
      x = allum->nb_allum + space / 2;
      while (x++ < width - 2)
	my_putchar(' ');
      my_putstr("*\n");
      allum = allum->next;
    }
}

void		display_allum1(t_allum	*allum)
{
  int		etage;
  int		width;
  int		i;

  etage = count_allum(allum);
  width = etage * 2 + 1;
  i = 0;
  while (i++ < width)
    my_putchar('*');
  my_putchar('\n');
  while (allum->first != 1)
    allum = allum->next;
  display_allum1_part2(allum, width, etage);
  i = 0;
  while (i++ < width)
    my_putchar('*');
}
