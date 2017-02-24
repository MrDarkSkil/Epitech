/*
** list.c for list in /home/hubert_i/rendu/2015/INFO/gfx_scroller
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Mar 19 21:21:03 2016 Léo Hubert
** Last update Thu Apr 14 23:38:10 2016 Léo Hubert
*/

#include "tekAdventure.h"

t_spritePos	*add_spritePos(t_spritePos		*list,
			       int			y,
			       int			x)
{
  t_spritePos	*newelem;

  if ((newelem = malloc(sizeof(t_spritePos))) == NULL)
    return (NULL);
  newelem->pos.x = x;
  newelem->pos.y = y;
  newelem->first = 0;
  newelem->next = NULL;
  newelem->prev = NULL;
  if (list == NULL)
    {
      newelem->first = 1;
      newelem->next = newelem;
      newelem->prev = newelem;
    }
  else
    {
      while (list->first != 1)
	list = list->next;
      newelem->prev = list->prev;
      newelem->next = list;
      list->prev->next = newelem;
      list->prev = newelem;
    }
  return (newelem);
}
