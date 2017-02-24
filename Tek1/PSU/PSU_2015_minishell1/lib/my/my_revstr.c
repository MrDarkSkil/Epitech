/*
** my_revstr.c for my_revstr in /home/hubert_1/rendu/Piscine_C_J06/ex_04
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Mon Oct  5 14:03:34 2015 leo hubert
** Last update Tue Nov 10 14:57:53 2015 leo hubert
*/

#include "../../include/my.h"

char	*my_revstr(char *str)
{
  int	counter_1;
  int	counter_2;
  char	save_string;

  counter_1 = 0;
  counter_2 = 0;
  while (str[counter_2] != 0)
    {
      counter_2++;
    }
  counter_2 = counter_2 - 1;
  while (counter_1 < counter_2)
    {
      save_string = str[counter_1];
      str[counter_1] = str[counter_2];
      str[counter_2] = save_string;
      counter_1++;
      counter_2--;
    }
  return (str);
}
