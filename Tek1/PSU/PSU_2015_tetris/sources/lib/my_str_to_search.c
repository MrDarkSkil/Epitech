/*
** my_str_to_search.c for my_str_to_search in /home/hubert_i/rendu/2015/PSU_2015_tetris
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar  2 01:57:04 2016 Léo Hubert
** Last update Tue Mar  8 03:09:28 2016 Léo Hubert
*/

#include "tetris.h"

int	my_search_to_str(char *str, char to_search)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == to_search)
	return (1);
    }
  return (0);
}
