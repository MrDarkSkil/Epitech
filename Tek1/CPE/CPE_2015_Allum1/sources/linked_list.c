/*
** linked_list.c for linkedlist in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_Allum1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Feb 13 17:22:45 2016 Léo Hubert
** Last update Fri Feb 19 14:13:28 2016 Léo Hubert
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

t_allum		*add_etage(t_allum	*allum,
			  int		nb_allum,
			  int		etage)
{
  t_allum	*newelem;

  newelem = malloc(sizeof(t_allum));
  newelem->nb_allum = nb_allum;
  newelem->etage = etage;
  newelem->first = 0;
  newelem->binary = 001;
  newelem->next = NULL;
  newelem->prev = NULL;
  if (allum == NULL)
    {
      newelem->first = 1;
      newelem->next = newelem;
      newelem->prev = newelem;
    }
  else
    {
      while (allum->first != 1)
	allum = allum->next;
      newelem->prev = allum->prev;
      newelem->next = allum;
      allum->prev->next = newelem;
      allum->prev = newelem;
    }
  return (newelem);
}

int	count_allum(t_allum	*allum)
{
  int	i;

  while (allum->first != 1)
    allum = allum->next;
  i = 1;
  allum = allum->next;
  while (allum->first != 1)
    {
      allum = allum->next;
      i++;
    }
  return (i);
}
