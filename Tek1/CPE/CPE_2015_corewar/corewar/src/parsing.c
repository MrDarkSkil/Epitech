/*
** parsing.c for parsing.c in /home/roig_a/coreware/coreware/src/list
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 16 14:47:43 2016 Antoine Roig
** Last update Sat Mar 26 15:55:51 2016 Antoine Roig
*/

#include <stdio.h>
#include "corewar.h"

void		fill_list(t_dlist *list, char **av)
{
  int		y;

  y = 1;
  while (av[y])
    {
      add_list_end(list, av[y]);
      y++;
    }
}

t_list		*double_pop(t_dlist *list, int j, t_list *tmp, int k)
{
  if (k == 1)
    {
      tmp = pop_list_somewhere(list, j);
      tmp = pop_list_somewhere(list, j);
    }
  else
    {
      pop_list_end(list);
      pop_list_end(list);
    }
  return (tmp);
}

void		info_champ(t_dlist *list,
			   int i,
			   t_lcmd *info,
			   char *name)
{
  t_list	*tmp;
  int		j;

  fill_info(info, name);
  tmp = list->begin;
  j = 0;
  while (j < i)
    {
      if (my_strcmp("-a", tmp->arg) == 0)
	{
	  tmp = double_pop(list, j, tmp, 1);
	  info->a = my_getnbr(tmp->arg);
	  i -= 2;
	  tmp = list->begin;
	}
      else if (my_strcmp("-n", tmp->arg) == 0)
	{
	  tmp = double_pop(list, j, tmp, 1);
	  info->id = my_getnbr(tmp->arg);
	  i -= 2;
	  tmp = list->begin;
	}
      else
	tmp = parsing2(tmp, &j);
    }
}

void		find_dump(t_dlist *list, t_vm *vm)
{
  t_list	*tmp;
  int		i;

  i = 1;
  tmp = list->begin;
  vm->dump = 0;
  while (tmp)
    {
      if (my_strcmp(tmp->arg, "-dump") == 0)
	{
	  vm->dump = my_getnbr(tmp->next->arg);
	  if (tmp->next->next == NULL)
	      double_pop(list, 0, tmp, 0);
	  else
	    {
	      pop_list_somewhere(list, i - 1);
	      pop_list_somewhere(list, i - 1);
	    }
	  return;
	}
      i++;
      tmp = tmp->next;
    }
}

void		find_champ(t_dlist *list,
			   t_vm *vm,
			   unsigned char *board,
			   int i)
{
  t_list	*tmp;
  t_lcmd	*info;
  t_champ	*new_elem;
  int		j;

  tmp = inifind(list, &j);
  new_elem = xmalloc(sizeof(t_champ));
  while (tmp)
    {
      if (my_strcmp(&tmp->arg[my_strlen(tmp->arg) - 4], ".cor") == 0)
	{
	  info = xmalloc(sizeof(t_lcmd));
	  info->p = j++;
	  info_champ(list, i, info, tmp->arg);
	  if (create_champ(new_elem, info, board) == -1)
	    exit(0);
	  i = 0;
	  add_list_end_vm(vm, new_elem);
	  pop_list_begin(list);
	  tmp = list->begin;
	}
      else
	tmp = tmp->next;
      i++;
    }
}
