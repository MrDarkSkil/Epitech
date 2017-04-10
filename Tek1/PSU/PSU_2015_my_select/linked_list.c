/*
** linked_list.c for linked_list in /home/hubert_i/rendu/PSU_2015_my_select
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Tue Dec  8 13:44:18 2015 leo hubert
** Last update Sat Dec 12 22:22:10 2015 leo hubert
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "my_select.h"

t_list		*add_list(t_list *list, char *str)
{
  t_list	*newelem;

  newelem = malloc(sizeof(t_list));
  newelem->str = str;
  newelem->first = 0;
  newelem->next = NULL;
  newelem->prev = NULL;
  if (list == NULL)
    {
      newelem->first = 1;
      newelem->is_target = 1;
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
  color_select(list);
  printw(list->str);
  attroff(A_UNDERLINE);
  attroff(A_STANDOUT);
  list = list->next;
  while (list->first != 1)
    {
      color_select(list);
      printw("\n");
      printw(list->str);
      attroff(A_UNDERLINE);
      attroff(A_STANDOUT);
      list = list->next;
    }
  return (0);
}

int	color_select(t_list *list)
{
  if (list->is_selected == 1)
    attron(A_STANDOUT);
  if (list->is_target == 1)
    attron(A_UNDERLINE);
  return (0);
}
