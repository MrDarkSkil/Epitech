/*
** my_put_bin.c for my_put_bin in /home/hubert_i/bin/lib/lib/my
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Mon Nov  9 14:25:07 2015 leo hubert
** Last update Mon Nov  9 15:02:09 2015 leo hubert
*/

#include "../../include/my.h"

int	my_putnbr_bin(int nb)
{
  if (nb > 0)
    {
      my_putnbr_bin(nb / 2);
      my_putchar(nb % 2 + '0');
    }
  return (0);
}
