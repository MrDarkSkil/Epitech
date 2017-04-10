/*
** my_isneg.c for my_isneg in /home/hubert_1/rendu/Piscine_C_J07/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:19:25 2015 leo hubert
** Last update Tue Nov 10 14:56:07 2015 leo hubert
*/

#include "../../include/my.h"

int	my_isneg(int nb)
{
  if (nb >= 0)
    {
      my_putchar(80);
    }
  else
    {
      my_putchar(78);
    }
  return (0);
}
