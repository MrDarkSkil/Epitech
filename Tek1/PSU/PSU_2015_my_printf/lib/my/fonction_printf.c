/*
** fonction_printf.c for fonction printf in /home/hubert_i/rendu/PSU_2015_my_printf/lib/my
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Mon Nov 16 14:12:38 2015 leo hubert
** Last update Mon Nov 16 14:37:27 2015 leo hubert
*/

#include "../../include/my.h"
#include <stdarg.h>
#include <stdlib.h>

int	chek_flag(char flag, va_list ap)
{
  if (va_arg(ap, int) == 000)
    return (0);
  flag == 's' ? my_putstr(va_arg(ap, char *))
    : flag == 'c' ? my_putchar(va_arg(ap, int))
    : flag == 'd' ? my_put_nbr(va_arg(ap, int)) 
    : flag == 'i' ? my_put_nbr(va_arg(ap, int))
    : flag == 'u' ? my_putnbr_unsigned(va_arg(ap, unsigned int))
    : flag == 'S' ? my_printf_S(va_arg(ap, char *))
    : flag == 'p' ? my_printf_p(va_arg(ap, int))
    : flag == 'b' ? my_putnbr_base(va_arg(ap, int), "01")
    : flag == 'X' ? my_printf_x(va_arg(ap, int), 0)
    : flag == 'x' ? my_printf_x(va_arg(ap, int), 1)
    : flag == '%' ? my_putchar('%')
    : flag;
  return (0);
}
