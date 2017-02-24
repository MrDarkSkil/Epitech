/*
** my_takestr.c for take_str in /home/hubert_i/rendu/2015/PSU_2015_tetris
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar  2 01:43:33 2016 Léo Hubert
** Last update Mon Mar 14 23:19:58 2016 Antoine Roig
*/

#include "tetris.h"

char	*take_after(char *str, char c)
{
  int	i;

  i = -1;
  while (str[++i] != c && str[i]);
  return (&str[i + 1]);
}

char	*take_begin(char *str, char c)
{
  int	i;

  i = -1;
  while (str[++i] != c && str[i]);
  str[i] = '\0';
  return (str);
}
