/*
** my_strlowcase.c for my_strlowcase in /home/hubert_1/rendu/Piscine_C_J07/lib/my/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:50:46 2015 leo hubert
** Last update Tue Nov 10 15:00:16 2015 leo hubert
*/

#include "../../include/my.h"
#include <stdlib.h>

char	*my_strlowcase(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != 0)
    {
      if (str[counter] >= 'A' && str[counter] <= 'Z')
	str[counter] = str[counter] + 32;
      counter = counter + 1;
    }
  return (NULL);
}
