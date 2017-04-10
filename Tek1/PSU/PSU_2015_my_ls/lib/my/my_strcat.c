/*
** my_strcat.c for my_strcat in /home/hubert_1/rendu/Piscine_C_J07/ex_02
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 20:19:56 2015 leo hubert
** Last update Wed Nov 04 10:58:54 2015 leo hubert
*/

#include "../../include/my.h"

char	*my_strcat(char *dest, char *src)
{
  int	counter_strike;
  int	counter_source;

  counter_strike = 0;
  counter_source = 0;
  while (dest[counter_strike] != 0)
    {
      counter_strike++;
    }
  while (src[counter_source] != 0)
    {
      dest[counter_strike] = src[counter_source];
      counter_strike++;
      counter_source++;
    }
  dest[counter_strike] = 0;
  return dest;
}
