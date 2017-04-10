/*
** my_putnbr_base.c for my_punbr_base in /home/hubert_i/bin/lib/lib/my
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Mon Nov  9 17:57:39 2015 leo hubert
** Last update Tue Feb  2 00:16:40 2016 Léo Hubert
*/

#include "../include/my.h"

int	my_putnbr_base(int nbr, char *base)
{
  int	calcul;
  int	size;
  int	nombre;
  int	temp;

  calcul = 0;
  size = my_strlen(base);
  nombre = 0;
  if (nbr < 0)
    {
      nombre = nombre + my_putchar('-');
      nombre = nombre + my_putnbr_base(-nbr, base);
    }
  else
    {
      temp = nbr % size;
      calcul = (nbr - temp) / size;
      if (calcul != 0)
	my_putnbr_base(calcul, base);
      nombre = my_putchar(base[temp]);
    }
  return (nombre);
}
