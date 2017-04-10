/*
** my_str_islower.c for my_str_islower in /home/hubert_1/rendu/Piscine_C_J07/lib/my/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:55:33 2015 leo hubert
** Last update Wed Nov 04 10:58:24 2015 leo hubert
*/

#include "../../include/my.h"

int	is_lower_char(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

int	my_str_islower(char *str)
{
  if (*str == 0)
    return (1);
  while (*str != 0)
    {
      if (!is_lower_char(*str))
        return (0);
      str++;
    }
  return (1);
}
