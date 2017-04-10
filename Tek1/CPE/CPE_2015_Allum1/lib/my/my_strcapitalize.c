/*
** my_strcapitalize.c for my_strcapitalize in /home/hubert_1/rendu/Piscine_C_J07/lib/my/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:52:06 2015 leo hubert
** Last update Wed Nov  4 11:05:35 2015 leo hubert
*/

#include "../../include/my.h"

char	*my_strcapitalize(char *str)
{
  int           i;

  i = 0;
  str = my_strlowcase(str);
  while (str[i] != 0)
    {
      if (i == 0)
	if (str[i] >= 'a' && str[i] <= 'z')
	  str[i] = str[i] - 32;
      if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
        {
          if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
            str[i + 1] = str[i + 1] - 32;
        }
      i++;
    }
  return (str);
}
