/*
** disp_stdarg.c for PSU_2015_my_printf_bootstrap in /home/hubert_i/rendu/PSU_2015_my_printf_bootstrap
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Mon Nov 02 22:44:56 2015 leo hubert
** Last update Tue Nov 10 15:00:33 2015 leo hubert
*/

#include <stdarg.h>
#include "../../include/my.h"

int     disp_stdarg(char *s, ...)
{
  int    counter;
  va_list ap;

  counter = 0;
  va_start(ap, s);
  while (s[counter] != 0)
    {
      if (s[counter] == 'c')
	my_putchar(va_arg(ap, int));
      if (s[counter] == 's')
	my_putstr(va_arg(ap, char *));
      if (s[counter] == 'i')
	my_put_nbr(va_arg(ap, int));
      my_putchar('\n');
      counter++;
    }
  va_end(ap);
  return (0);
}
