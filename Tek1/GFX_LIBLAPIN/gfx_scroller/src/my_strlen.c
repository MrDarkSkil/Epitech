/*
** my_strlen.c for my_strlen in /home/hubert_i/rendu/2015/INFO/gfx_scroller
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 20 03:47:19 2016 Léo Hubert
** Last update Sun Mar 20 20:09:29 2016 Léo Hubert
*/

#include "scroller.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
