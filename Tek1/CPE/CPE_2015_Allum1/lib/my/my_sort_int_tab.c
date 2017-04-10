/*
** my_sort_int_tab.c for my_sort_int_tab in /home/hubert_1/rendu/Piscine_C_J07/alllib
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Tue Oct  6 19:33:10 2015 leo hubert
** Last update Wed Nov 04 10:58:13 2015 leo hubert
*/

#include "../../include/my.h"

void	my_sort_int_tab(int *tab, int size)
{
  int           counter_1;
  int           counter_2;
  int           save;

  counter_1 = 0;
  counter_2 = 0;
  while (counter_1 != size)
    {
      save = tab[counter_1];
      while (counter_2 != size)
        {
          if (tab[counter_2] < save)
            my_swap(&tab[counter_2], &save);
        }
    }
  return;
}
