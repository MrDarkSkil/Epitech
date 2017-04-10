/*
** my_put_nbr.c for my_put_nbr in /home/hubert_1/rendu/Piscine_C_J07/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:22:37 2015 leo hubert
** Last update Thu Jan 28 21:39:18 2016 Léo Hubert
*/

#include "../include/my.h"

int	my_put_nbr(int nb)
{
  if (nb <= -2147483647 || nb >= 2147483647)
    return (0);
  if (nb < 0)
    {
      my_putstr("-");
      nb = -nb;
    }
  if (nb < 10)
    my_putchar(nb + '0');
  else if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + '0');
    }
  else
    my_putstr("Nombre invalide\n");
  return (0);
}
