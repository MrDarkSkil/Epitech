/*
** my_str_isnum.c for my_str_isnum in /home/hubert_1/rendu/Piscine_C_J07/lib/my/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:54:33 2015 leo hubert
** Last update Sat Nov 14 21:00:50 2015 leo hubert
*/

#include "../../include/my.h"

int	my_str_isnum(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != 0)
    {
      if ((str[counter] > 57 || str[counter] < 48) && str[counter] != '-')
	return (0);
      counter++;
    }
  return (1);
}
