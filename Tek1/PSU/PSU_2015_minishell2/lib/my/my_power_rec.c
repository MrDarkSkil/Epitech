/*
** my_power_rec.c for my_power_rec in /home/hubert_1/rendu/Piscine_C_J05
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Sun Oct  4 20:09:39 2015 leo hubert
** Last update Wed Nov 04 10:57:36 2015 leo hubert
*/

#include "../../include/my.h"

int	my_power_rec(int nb, int power)
{
  if (power > 1)
    {
      nb = nb * my_power_rec(nb, power -1);
    }
  if (power == 0)
    {
      return (0);
    }
  return (nb);
}
