/*
** my_strncmp.c for my_strncmp in /home/hubert_1/rendu/Piscine_C_J06/ex_07
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 15:19:59 2015 leo hubert
** Last update Wed Apr  6 20:49:56 2016 Léo Hubert
*/

#include "../../include/my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] != 0 && s2[i] != 0 && i < n - 1)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}
