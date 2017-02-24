/*
** sum_stdarg.c for PSU_2015_my_printf_bootstrap in /home/hubert_i/rendu/PSU_2015_my_printf_bootstrap
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Mon Nov 02 18:50:49 2015 leo hubert
** Last update Sat Jan 16 16:54:17 2016 Léo Hubert
*/

#include <stdarg.h>
#include "../../include/my.h"

int     sum_stdarg(int i, int nb, ...)
{
  int   result;
  int   counter;
  va_list ap;

  counter = 0;
  result = 0;
  va_start(ap, nb);
  if (i == 1)
    {
      while (nb > counter)
	{
	  result = result + my_strlen(va_arg(ap, char *));
	  counter++;
	}
    }
  else if (i == 0)
    {
      while (nb > counter)
	{
	  result = result + va_arg(ap, int);
	  counter++;
	}
    }
  va_end(ap);
  return (result);
}
