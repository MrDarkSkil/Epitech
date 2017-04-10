/*
** my_putnbr_base.c for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/nm/lib
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Fri Feb 24 14:16:24 2017 Leo HUBERT
** Last update Sun Feb 26 15:34:08 2017 LEO Leo HUBERT
*/

#include "nm.h"

int     my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

int     my_putstr(char *str)
{
  int   counter;
  
  counter = 0;
  while (str[counter] != '\0')
    {
      my_putchar(str[counter]);
      counter++;
    }
  return (0);
}

int     my_strlen(char *str)
{
  int   counter;
  
  counter = 0;
  while (str[counter] != '\0')
    counter++;
  return (counter);
}

int     my_put_nbr(int nb)
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

int     my_putnbr_base(int nbr, char *base)
{
  int   calcul;
  int   size;
  int   nombre;
  int   temp;
  
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
