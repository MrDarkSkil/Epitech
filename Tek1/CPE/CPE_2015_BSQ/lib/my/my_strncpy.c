/*
** my_strcpy.c for my_strcpy in /home/hubert_1/rendu/Piscine_C_J06
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Mon Oct  5 09:18:14 2015 leo hubert
** Last update Wed Nov 04 10:59:32 2015 leo hubert
*/

#include "../../include/my.h"

char	*my_strncpy(char *dest, char *src, int nb)
{
  int	counter;

  counter = 0;
  while (src[counter] && counter < nb)
    {
      dest[counter] = src[counter];
      counter = counter + 1;
    }
  dest[counter] = '\0';
  return (dest);
}
