/*
** my_putnbr_base.c for my_punbr_base in /home/hubert_i/bin/lib/lib/my
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Mon Nov  9 17:57:39 2015 leo hubert
** Last update Wed Nov 11 19:43:50 2015 leo hubert
*/

#include "../../include/my.h"
#include <stdlib.h>

int	my_putnbr_base_size(size_t nbr, char *base)
{
  size_t	calcul;
  size_t	size;
  size_t	nombre;
  size_t	temp;

  calcul = 0;
  size = my_strlen(base);
  nombre = 0;
  temp = nbr % size;
  calcul = (nbr - temp) / size;
  if (calcul != 0)
    my_putnbr_base_size(calcul, base);
  nombre = my_putchar(base[temp]);
  return (nombre);
}
