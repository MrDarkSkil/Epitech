/*
** my_strcpy.c for my_strcpy in /home/hubert_1/rendu/Piscine_C_J06
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Mon Oct  5 09:18:14 2015 leo hubert
** Last update Wed Nov 04 10:59:06 2015 leo hubert
*/

#include "../../include/my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	counter;

  counter = 0;
  while (src[counter] != 0)
    {
      dest[counter] = src[counter];
      counter = counter + 1;
    }
  return (dest);
}
