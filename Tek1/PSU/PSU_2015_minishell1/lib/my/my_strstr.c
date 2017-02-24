/*
** my_strstr.c for my_strstr in /home/hubert_1/rendu/Piscine_C_J06/ex_05
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Mon Oct  5 18:59:57 2015 leo hubert
** Last update Fri Jan 22 18:04:51 2016 Léo Hubert
*/

#include "../../include/my.h"

char	*my_strstr(char *str, char *to_find)
{
  int	counter;

  counter = 0;
  if (str[counter] != 0)
    {
      while (to_find[counter] != 0)
	{
	  if (to_find[counter] != str[counter])
	    {
	      return (my_strstr(str + 1, to_find));
	    }
	  counter++;
	}
      return (str);
    }
  else
    {
      return (0);
    }
}
