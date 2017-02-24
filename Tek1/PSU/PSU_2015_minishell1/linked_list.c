/*
** linked_list.c for linked_list in /home/hubert_i/rendu/PSU_2015_my_select
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Dec  8 13:44:18 2015 leo hubert
** Last update Sat Jan 23 01:39:30 2016 Léo Hubert
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"

t_list		*add_list(t_list *list, char *str, char *key)
{
  t_list	*newelem;

  if ((newelem = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  newelem->str = str;
  newelem->key = key;
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

int	show_list(t_list *list)
{
  while (list->first != 1)
    list = list->next;
  my_putstr(list->key);
  my_putchar('=');
  my_putstr(list->str);
  list = list->next;
  while (list->first != 1)
    {
      my_putstr(list->key);
      my_putchar('=');
      my_putstr(list->str);
      my_putchar('\n');
      list = list->next;
    }
  return (0);
}

t_list		*delete_maillon(t_list *list)
{
  t_list	*maillon;

  maillon = list;
  list = list->next;
  if (list->prev->first == 1)
    list->first = 1;
  list->prev->prev->next = list->prev->next;
  list->prev = list->prev->prev;
  free(maillon);
  return (list);
}
