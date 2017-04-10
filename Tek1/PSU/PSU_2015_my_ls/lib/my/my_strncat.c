/*
** my_strncat.c for my_strncat in /home/hubert_1/rendu/Piscine_C_J07/ex_03
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 20:29:36 2015 leo hubert
** Last update Wed Nov 04 10:59:23 2015 leo hubert
*/

#include "../../include/my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int	counter_strike;
  int	counter_source;

  counter_strike = 0;
  counter_source = 0;
  while (dest[counter_strike] != 0)
    {
      counter_strike++;
    }
  while (src[counter_source] && counter_strike < nb)
    {
      dest[counter_strike] = src[counter_source];
      counter_strike++;
      counter_source++;
    }
  dest[counter_strike] = '\0';
  return (dest);
}
