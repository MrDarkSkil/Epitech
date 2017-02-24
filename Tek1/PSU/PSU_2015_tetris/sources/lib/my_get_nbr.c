/*
** my_get_nbr.c for my_get_nbr.c in /home/roig_a/rendu/PSU_2015_tetris/sources
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Fri Feb 26 16:15:17 2016 Antoine Roig
** Last update Fri Feb 26 16:15:33 2016 Antoine Roig
*/

#include "tetris.h"

int     is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

int     is_neg(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
        n++;
      i++;
    }
  if (n % 2 != 0)
    return (1);
  else
    return (0);
}

int     my_getnbr(char *str)
{
  int   i;
  int   nbr;

  i = 0;
  nbr = 0;
  while (is_num(str[i]) == 0)
    i++;
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] -'0'));
      i++;
    }
  if (is_neg(str) == 1)
    nbr = nbr * -1;
  return (nbr);
}
