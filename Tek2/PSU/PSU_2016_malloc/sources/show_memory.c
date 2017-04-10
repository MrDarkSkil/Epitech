/*
** show_memory.c for PSU_2016_malloc in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_malloc/sources
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Fri Feb 03 12:29:20 2017 Leo HUBERT
** Last update	Fri Feb 03 13:15:56 2017 Full Name
*/

#include "malloc.h"

int		my_putchar(char c)
{
  return (write(1, &c, 1));
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    i++;
  return (i);
}

int		my_putstr(char *str)
{
  int		i;

  i = 0;
  if (!str)
    return (-1);
  while (str[i])
    my_putchar(str[i++]);
  return (0);
}

int		my_putnbr_g_base(int nbr, char *g_base)
{
  int		calcul;
  int		size;
  int		nombre;
  int		temp;

  calcul = 0;
  size = my_strlen(g_base);
  nombre = 0;
  if (nbr < 0)
    {
      nombre = nombre + my_putchar('-');
      nombre = nombre + my_putnbr_g_base(-nbr, g_base);
    }
  else
    {
      temp = nbr % size;
      calcul = (nbr - temp) / size;
      if (calcul != 0)
        my_putnbr_g_base(calcul, g_base);
      nombre = my_putchar(g_base[temp]);
    }
  return (nombre);
}

void		show_alloc_mem()
{
  t_chunk	*ptr;

  ptr = ((t_chunk*)g_base);
  my_putstr("break : 0x");
  my_putnbr_g_base((size_t)sbrk(0), "0123456789ABCDEF");
  my_putchar('\n');
  while (ptr != NULL)
  {
    my_putstr("0x");
    my_putnbr_g_base((size_t)ptr, "0123456789ABCDEF");
    my_putstr(" - 0x");
    my_putnbr_g_base((size_t)ptr + (sizeof(t_chunk) + ptr->size) ,
      "0123456789ABCDEF");
    my_putstr(" : ");
    my_putnbr_g_base(sizeof(t_chunk) + ptr->size, "0123456789");
    my_putstr(" bytes\n");
    ptr = ptr->next;
  }
}
