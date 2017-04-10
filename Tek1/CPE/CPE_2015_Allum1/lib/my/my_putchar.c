/*
** my_putchar.c for my_putchar in /home/hubert_1/rendu/Piscine_C_J07/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:18:18 2015 leo hubert
** Last update Tue Nov 10 14:57:06 2015 leo hubert
*/

#include "../../include/my.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
