/*
** my_str_isnum.c for my_str_isnum in /home/hubert_1/rendu/Piscine_C_J07/lib/my/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:54:33 2015 leo hubert
** Last update Sat Feb 13 21:20:24 2016 Léo Hubert
*/

#include "../../include/my.h"

int	my_str_isnum(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != 0)
    {
      if (str[counter] == '-')
	return (0);
      if (str[counter] == '\n')
	return (1);
      if (str[counter] > '9' || str[counter] < '0')
	return (0);
      counter++;
    }
  return (1);
}
