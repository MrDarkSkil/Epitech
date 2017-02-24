/*
** list.c for list in /home/hubert_i/rendu/2015/INFO/gfx_scroller
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Mar 19 21:21:03 2016 Léo Hubert
** Last update Sun Mar 20 20:10:16 2016 Léo Hubert
*/

#include "scroller.h"

t_sprite	*add_sprite(t_sprite		*list,
			    t_bunny_pixelarray	*new_sprite,
			    t_bunny_position	*pos)
{
  t_sprite	*newelem;

  if ((newelem = malloc(sizeof(t_sprite))) == NULL)
    return (NULL);
  newelem->sprite = new_sprite;
  newelem->pos = pos;
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
