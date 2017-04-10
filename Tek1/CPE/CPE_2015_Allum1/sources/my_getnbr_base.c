/*
** my_getnbr_base.c for my_getnbr_base in /home/hubert_i/CPE_2015_Allum1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Feb 19 01:52:40 2016 Léo Hubert
** Last update Fri Feb 19 01:53:32 2016 Léo Hubert
*/

#include "my.h"

int		my_strchar(char *str, char to_find)
{
  int		len;
  int		i;

  if (!to_find)
    return (0);
  i = 0;
  len = my_strlen(str);
  while (i < len)
    {
      if (*(str + i) == to_find)
	return (i);
      ++i;
    }
  return (0);
}

long		determine_power(char* str, int base)
{
  long		power;
  int		j;

  power = 1;
  j = 1;
  while (j++ < my_strlen(str))
    power *= base;
  return (power);
}

int		my_getnbr_base(char *str, char *base)
{
  long		power;
  int		j;
  long		ret;
  int		minus;

  minus = 0;
  ret = 0;
  if (!str)
    return (0);
  if (*str == '-')
    {
      minus = - 1;
      str++;
    }
  power = determine_power(str, my_strlen(base));
  j = 0;
  while (j++ < my_strlen(str))
    {
      ret += my_strchar(base, *(str + j - 1)) * power;
      power /= my_strlen(base);
    }
  if (minus == - 1)
    return (- ret);
  return (ret);
}
