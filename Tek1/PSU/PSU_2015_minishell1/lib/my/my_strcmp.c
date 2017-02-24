/*
** my_strcmp.c for my_strcmp in /home/hubert_1/rendu/Piscine_C_J06/ex_06
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 14:52:28 2015 leo hubert
** Last update Tue Nov 10 14:59:37 2015 leo hubert
*/

#include "../../include/my.h"
#include <stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  int	counter;

  counter = 0;
  if (s1 == NULL)
    {
      return (0);
    }
  if (my_strlen(s1) != my_strlen(s2))
    {
      return (1);
    }
  while (s1[counter] != 0)
    {
      if (s1 == 0 || s2 == 0 || s1[counter] != s2[counter])
	{
	  return (1);
	}
      counter++;
    }
  return (0);
}
