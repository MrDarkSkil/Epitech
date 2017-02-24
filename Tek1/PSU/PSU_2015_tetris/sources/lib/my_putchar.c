/*
** my_putchar.c for my_putchar in /home/hubert_1/rendu/Piscine_C_J07/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:18:18 2015 leo hubert
** Last update Mon Feb 29 04:00:22 2016 Léo Hubert
*/

#include "tetris.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
