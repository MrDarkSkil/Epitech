/*
** pop_list.c for pop_list.c in /home/roig_a/Desktop/fct/link-list/simple
**
** Made by Roig Antoine
** Login   <roig_a@epitech.net>
**
** Started on  Sun Oct 11 22:15:40 2015 Roig Antoine
** Last update Fri Mar 18 14:25:31 2016 Antoine Roig
*/

#include "tetris.h"

t_list	*pop_list_begin(t_dlist *list)
{
  t_list	*tmp;

  if (!list)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (list->begin == NULL || list->end == NULL)
    return (NULL);
  tmp = list->begin;
  if (list->size == 1)
    {
      list->begin = NULL;
      list->end = NULL;
      list->size = list-> size - 1;
      return (tmp);
    }
  list->begin = tmp->next;
  tmp->next->prev = NULL;
  tmp->next = NULL;
  list->size = list-> size - 1;
  return (tmp);
}

t_list	*pop_list_end(t_dlist *list)
{
  t_list	*tmp;

  if (!list)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  if (list->begin == NULL || list->end == NULL)
    return (NULL);
  tmp = list->end;
  if (list->size == 1)
    {
      list->begin = NULL;
      list->end = NULL;
      list->size = list-> size - 1;
      return (tmp);
    }
  list->end = tmp->prev;
  tmp->prev->next = NULL;
  tmp->prev = NULL;
  list->size = list-> size - 1;
  return (tmp);
}
