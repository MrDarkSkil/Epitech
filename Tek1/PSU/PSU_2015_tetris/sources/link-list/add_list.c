/*
** add_list.c for add_list.c in /home/roig_a/Desktop/fct/link-list/simple
**
** Made by Roig Antoine
** Login   <roig_a@epitech.net>
**
** Started on  Sun Oct 11 20:25:22 2015 Roig Antoine
** Last update Fri Mar 18 14:25:42 2016 Antoine Roig
*/

#include "tetris.h"

void	add_list_end(t_dlist *list, t_tetri *tetri)
{
  t_list	*new;

  if (!list)
    {
      my_putstr("add_list_end : list is NULL\nExit program\n");
      exit(EXIT_FAILURE);
    }
  new = xmalloc(sizeof(t_list));
  new->tetri = tetri;
  new->n = tetri->name;
  new->next = NULL;
  new->prev = NULL;
  if (list->begin == NULL)
    {
      list->begin = new;
      list->end = new;
      list->size = 1;
    }
  else
    {
      new->prev = list->end;
      list->end->next = new;
      list->end = new;
      list->size = list->size + 1;
    }
}
