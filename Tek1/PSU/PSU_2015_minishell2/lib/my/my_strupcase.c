/*
** my_strupcase.c for my_strupcase in /home/hubert_1/rendu/Piscine_C_J06/ex_08
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:05:59 2015 leo hubert
** Last update Wed Nov 04 10:59:41 2015 leo hubert
*/

#include "../../include/my.h"

char	*my_strupcase(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != 0)
    {
      if (str[counter] >= 'a' && str[counter] <= 'z')
	{
	  str[counter] = str[counter] - 32;
	}
      counter = counter + 1;
    }
  return (str);
}
