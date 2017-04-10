/*
** my_strlen.c for strlen in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minitalk
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Jan 30 11:43:01 2016 Léo Hubert
** Last update Sat Jan 30 11:43:59 2016 Léo Hubert
*/

#include "../include/my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++]);
  return (i);
}
