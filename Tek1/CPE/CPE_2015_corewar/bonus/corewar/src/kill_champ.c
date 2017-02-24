/*
** kill_champ.c for kill_champ in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 23 10:10:39 2016 Antoine Roig
** Last update Sun Mar 27 00:42:11 2016 Eric DESCHODT
*/

#include "corewar.h"

void		remove_cell(t_vm *vm, t_champ *tmp)
{
  t_champ	*previous;
  t_champ	*nextious;

  previous = tmp->prev;
  nextious = tmp->next;
  if (vm->begin == tmp)
    vm->begin = vm->begin->next;
  else
    previous->next = nextious;
  if (vm->end == tmp)
   vm->end = vm->end->prev;
  else
    nextious->prev = previous;
  free(tmp);
  vm->nb--;
}

void		kill_champ(t_vm *vm)
{
  t_champ	*tmp;

  if (!vm)
    {
      my_putstr("pop_list_begin : list NULL\n");
      exit(EXIT_FAILURE);
    }
  tmp = vm->begin;
  while (tmp)
    {
      if (tmp->alive == 0)
	{
	  remove_cell(vm, tmp);
	  if (vm->nb == 1)
	    return;
	  tmp = vm->begin;
	}
      tmp = tmp->next;
    }
  return;
}
