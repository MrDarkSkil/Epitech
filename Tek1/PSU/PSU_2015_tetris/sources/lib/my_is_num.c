/*
** my_is_num.c for my_is_num in /home/hubert_i/rendu/2015/PSU_2015_tetris
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Mar  1 22:47:09 2016 Léo Hubert
** Last update Tue Mar  8 03:09:02 2016 Léo Hubert
*/

#include "tetris.h"

int	my_is_num(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
    }
  return (0);
}
