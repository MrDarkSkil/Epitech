/*
** key_fonction.c for key_fonct in /home/hubert_i/rendu/PSU_2015_my_select
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Tue Dec  8 15:37:49 2015 leo hubert
** Last update Sat Dec 12 22:22:27 2015 leo hubert
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "my_select.h"

t_list	*up_buttom(t_list *list)
{
  while (list->is_target != 1)
    list = list->next;
  list->is_target = 0;
  list = list->prev;
  list->is_target = 1;
  return (list);
}

t_list	*down_buttom(t_list *list)
{
  while (list->is_target != 1)
    list = list->next;
  list->is_target = 0;
  list = list->next;
  list->is_target = 1;
  return (list);
}

t_list	*delete_target(t_list *list)
{
  while (list->is_target != 1)
    list = list->next;
  if (list->next == list)
    {
      endwin();
      exit(EXIT_SUCCESS);
    }
  list = down_buttom(list);
  if (list->prev->first == 1)
    list->first = 1;
  list->prev->prev->next = list->prev->next;
  list->prev = list->prev->prev;
  return (list);
}

t_list	*enter_buttom(t_list *list)
{
  int	i;

  i = 0;
  endwin();
  while (list->first != 1)
    list = list->next;
  if (list->is_selected == 1)
    {
      i++;
      my_putstr(list->str);
    }
  list = list->next;
  while (list->first != 1)
    {
      if (list->is_selected == 1)
	{
	  if (i != 0)
	    my_putchar(' ');
	  my_putstr(list->str);
	  i++;
	}
      list = list->next;
    }
  exit(EXIT_SUCCESS);
  return (list);
}

t_list	*select_target(t_list *list)
{
  while (list->is_target != 1)
    list = list->next;
  if (list->is_selected == 0)
    list->is_selected = 1;
  else
    list->is_selected = 0;
  list = down_buttom(list);
  return (list);
}
