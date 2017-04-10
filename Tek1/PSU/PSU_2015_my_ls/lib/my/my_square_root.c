/*
** my_square_root.c for my_square_root in /home/hubert_1/rendu/Piscine_C_J05
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Mon Oct  5 18:15:17 2015 leo hubert
** Last update Wed Nov 04 10:58:17 2015 leo hubert
*/

#include "../../include/my.h"

int	my_square_root(int nb)
{
  int	counter_strike_2;

  counter_strike_2 = 0;
  if (nb == 1)
    {
      return (0);
    }
  while (counter_strike_2 <= (nb / 2))
    {
      if ((counter_strike_2 * counter_strike_2) == nb)
	{
	  return (counter_strike_2);
	}
      counter_strike_2++;
    }
  return (0);
}
