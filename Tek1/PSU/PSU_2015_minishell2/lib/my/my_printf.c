/*
** my_printf.c for my_printf in /home/hubert_i/rendu/PSU_2015_my_printf
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Mon Nov  2 10:40:55 2015 leo hubert
** Last update Mon Dec 14 08:47:28 2015 leo hubert
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../include/my.h"

int	my_printf_S(char *str)
{
  int   counter;

  counter = 0;
  while (str[counter] != 0)
    {
      if (str[counter] < 32 || str[counter] >= 127)
	{
	  my_putchar(92);
	  if (str[counter] >= 0 && str[counter] <= 7)
	    my_putstr("00");
	  if (str[counter] >= 8 && str[counter] <= 63)
	    my_putstr("0");
	  my_putnbr_base(str[counter], "01234567");
	}
      else
	my_putchar(str[counter]);
      counter++;
    }
  return (0);
}

int	my_printf_p(size_t pointer)
{
  my_putstr("0x");
  my_putnbr_base_size(pointer, "0123456789abcdef");
  return (0);
}

int	my_printf_x(int	arg, int type)
{
  if (type == 1)
    my_putnbr_base(arg, "0123456789abcdef");
  else
    my_putnbr_base(arg, "0123456789ABCDEF");
  return (0);
}

int    my_printf(char *arg, ...)
{
  int  ct;
  va_list ap;

  ct = 0;
  va_start(ap, arg);
  while (arg[ct] != 0)
    {
      if (arg[ct] == '%')
	{
	  chek_flags(ap, arg[ct + 1]);
	  ct++;
	}
      else
	my_putchar(arg[ct]);
      ct++;
    }
  va_end(ap);
  return (0);
}

int	chek_flags(char arg)
{
  arg == 's' ? my_putstr(va_arg(ap, char *))
    : arg == 'c' ? my_putchar(va_arg(ap, int))
    : arg == 'd' ? my_put_nbr(va_arg(ap, int))
    : arg == 'i' ? my_put_nbr(va_arg(ap, int))
    : arg == 'u' ? my_putnbr_unsigned(va_arg(ap, unsigned int))
    : arg == 'S' ? my_printf_S(va_arg(ap, char *))
    : arg == 'p' ? my_printf_p(va_arg(ap, int))
    : arg == 'b' ? my_putnbr_base(va_arg(ap, int), "01")
    : arg == 'X' ? my_printf_x(va_arg(ap, int), 0)
    : arg == 'x' ? my_printf_x(va_arg(ap, int), 1)
    : arg == '%' ? my_putchar('%')
    : arg;
  return (0);
}
