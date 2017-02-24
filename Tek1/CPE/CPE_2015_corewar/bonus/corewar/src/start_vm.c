/*
** start_vm.c for  in /home/descho_e/CPE_2015_corewar/bonus
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Sun Mar 27 16:01:30 2016 Eric DESCHODT
** Last update Sun Mar 27 16:01:41 2016 Eric DESCHODT
*/

#include "corewar.h"

void            init_alive(t_vm *vm)
{
  int           i;
  t_champ       *tmp;

  tmp = vm->begin;
  i = 0;
  while (i < vm->nb)
    {
      tmp->alive = 0;
      tmp = tmp->next;
      i++;
    }
}

int		execute_champ(t_vm *vm, t_champ *champ,
			      unsigned char board[2][MEM_SIZE])
{
  if (champ->cycle == 0)
    load_instru(vm, champ, board);
  else if (champ->cycle == champ->ope.nbr_cycles)
    champ->cycle = -1;
  champ->cycle++;
  return (0);
}

int		all_champ(t_vm *vm,
			  unsigned char board[2][MEM_SIZE],
			  t_data *data,
			  int start)
{
  int		i;
  t_champ	*tmp;
  static int	cd = 0;

  if (cd == 10)
    {
      printboardgraph2(data->pix, board);
      data->font.size = 4;
      put_nbr_scr(start, data);
      bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
      bunny_display(data->win);
      cd = 0;
    }
  else
    cd++;
  i = 0;
  tmp = vm->begin;
  while (i < vm->nb && tmp != NULL)
    {
      execute_champ(vm, tmp, board);
      tmp = tmp->next;
      i++;
    }
  return (0);
}

int		start_vm(t_vm *vm,
			 unsigned char board[2][MEM_SIZE],
			 t_data *data)
{
  int		end;
  int		start;
  int		var;

  var = 0;
  end = CYCLE_TO_DIE;
  while (end > 0 && vm->nb > 1)
    {
       start = end;
      init_alive(vm);
      while (start > 0)
	{
	  if (vm->dump != 0)
	    var++;
	  all_champ(vm, board, data, start);
	  start--;
	  if (vm->dump != 0 && vm->dump == var)
	    return (0);
	}
      check_ko(vm, data);
      kill_champ(vm);
      end -= CYCLE_DELTA;
    }
  return (0);
}
