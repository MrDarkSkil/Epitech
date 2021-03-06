/*
** main.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/src
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:26:06 2016 Eric DESCHODT
** Last update Sun Mar 27 15:58:14 2016 Eric DESCHODT
*/

#include "corewar.h"

void		id_champ2(t_vm *vm, char *tab)
{
  int		i;
  t_champ	*tmp;

  tmp = vm->begin;
  while (tmp)
    {
      if (tmp->id == 0)
  	{
  	  i = -1;
  	  while (tab[++i])
	    if (tab[i] != 'x')
	      {
		tmp->id = tab[i] - 48;
		tab[i] = 'x';
		break;
	      }
  	}
      tmp = tmp->next;
    }
}

void	id_champ(t_vm *vm)
{
  char		*tab;
  t_champ	*tmp;
  int		i;

  tmp = vm->begin;
  tab = xmalloc(sizeof(char) * 5);
  tab[0] = '1';
  tab[1] = '2';
  tab[2] = '3';
  tab[3] = '4';
  tab[4] = '\0';
  while (tmp)
    {
      i = -1;
      while (tab[++i])
	if (tmp->id == tab[i] - 48)
	  tab[i] = 'x';
      tmp = tmp->next;
    }
  id_champ2(vm, tab);
  check_multiple_id(vm);
}

void		check_debug(t_dlist *list, t_vm *vm)
{
  if (my_strcmp(list->begin->arg, "-debug") == 0)
    {
      vm->debug = 1;
      pop_list_begin(list);
    }
  return;
}

void		champ_id_reg(t_vm *vm)
{
  t_champ	*tmp;
  t_byte	nb;
  int		i;

  tmp = vm->begin;
  while (tmp != NULL)
    {
      nb.full = tmp->id;
      i = 0;
      while (i < REG_SIZE)
	{
	  tmp->reg[0][i] = nb.byte[i];
	  i++;
	}
      tmp = tmp->next;
    }
}

void		start_game(t_dlist *list,
			   t_vm *vm,
			   t_data *data,
			   unsigned char board[2][MEM_SIZE])
{
  check_debug(list, vm);
  syntax(list);
  find_dump(list, vm);
  find_champ(list, vm, board, 0);
  id_champ(vm);
  champ_id_reg(vm);
  init_alive(vm);
  elarg_text(data->pix, &data->pos, &data->size, data->back);
  print_names(data->pix, vm, data);
  printboardgraph(data->pix, board);
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_display(data->win);
  bunny_set_loop_main_function(pausing);
  bunny_loop(data->win, 60, data);
  start_vm(vm, board, data);
  winning(vm, data);
}
