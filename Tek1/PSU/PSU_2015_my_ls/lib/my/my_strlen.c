/*
** my_strlen.c for my_strlen in /home/hubert_1/rendu/Piscine_C_J07/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:30:43 2015 leo hubert
** Last update Wed Nov 04 10:59:14 2015 leo hubert
*/

#include "../../include/my.h"

int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != 0)
    {
      counter++;
    }
  return (counter);
}
