/*
** my_put_nbr.c for my_put_nbr in /home/hubert_1/rendu/Piscine_C_J07/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:22:37 2015 leo hubert
** Last update Wed Nov 11 03:36:05 2015 leo hubert
*/

#include "../../include/my.h"

int	my_putnbr_unsigned(unsigned int nb)
{
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
