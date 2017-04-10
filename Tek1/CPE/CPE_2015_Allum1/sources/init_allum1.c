/*
** init_allum1.c for init_project in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_Allum1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Feb 13 16:58:35 2016 Léo Hubert
** Last update Sat Feb 13 22:40:01 2016 Léo Hubert
*/

#include "my.h"

t_allum		*init_allum1(int etage)
{
  t_allum	*allum;
  int		i;
  int		allumette;

  allum = NULL;
  i = 0;
  allumette = 1;
  while (i < etage)
    {
      allum = add_etage(allum, allumette, i);
      allumette += 2;
      i++;
    }
  return (allum);
}
