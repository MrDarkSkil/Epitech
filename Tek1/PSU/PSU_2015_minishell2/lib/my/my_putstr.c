/*
** my_putstr.c for my_putstr in /home/hubert_1/rendu/Piscine_C_J07/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:27:08 2015 leo hubert
** Last update Mon Jan 18 22:19:49 2016 Léo Hubert
*/

#include "../../include/my.h"

int	my_putstr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != '\0')
    {
      my_putchar(str[counter]);
      counter++;
    }
  return (0);
}
