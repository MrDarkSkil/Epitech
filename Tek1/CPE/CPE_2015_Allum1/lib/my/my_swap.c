/*
** my_swap.c for my_swa in /home/hubert_1/rendu/Piscine_C_J07/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:24:22 2015 leo hubert
** Last update Tue Nov 10 15:01:27 2015 leo hubert
*/

#include "../../include/my.h"

int	my_swap(int *a, int *b)
{
  int	var_change;

  var_change = *a;
  *a = *b;
  *b = var_change;
  return (0);
}
