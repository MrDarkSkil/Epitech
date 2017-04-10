/*
** my_str_isupper.c for my_str_isupper in /home/hubert_1/rendu/Piscine_C_J07/lib/my/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:56:16 2015 leo hubert
** Last update Wed Nov 04 10:58:46 2015 leo hubert
*/

#include "../../include/my.h"

int	is_upper_char(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

int	my_str_islower(char *str)
{
  if (*str == 0)
    return (1);
  while (*str != 0)
    {
      if (!is_upper_char(*str))
        return (0);
      str++;
    }
  return (1);
}
