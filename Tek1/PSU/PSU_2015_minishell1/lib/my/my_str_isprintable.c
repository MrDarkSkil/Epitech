/*
** my_str_isprintable.c for my_str_isprintable in /home/hubert_1/rendu/Piscine_C_J07/lib/my/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:57:18 2015 leo hubert
** Last update Wed Nov 04 10:58:40 2015 leo hubert
*/

#include "../../include/my.h"

int	is_printable_char(char c)
{
  if (c > 32 && c < 127)
    return (1);
  return (0);
}

int	my_str_isprintable(char *str)
{
  if (*str == 0)
    return (1);
  while (*str != 0)
    {
      if (!is_printable_char(*str))
        return (0);
      str++;
    }
  return (1);
}
