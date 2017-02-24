/*
** loop.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/bonus
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Sat Mar 26 09:36:26 2016 Eric DESCHODT
** Last update Sun Mar 27 00:35:09 2016 Eric DESCHODT
*/

#include "corewar.h"

int			check_prec(char chmp[4], int id)
{
  int			i;

  i = 0;
  while (i < 4)
    {
      if (chmp[i] == id)
	{
	  chmp[i] = 0;
	  return (0);
	}
      i++;
    }
  return (-1);
}

void			init_names(char chmp[4])
{
  chmp[0] = 1;
  chmp[1] = 2;
  chmp[2] = 3;
  chmp[3] = 4;
}

void			print_names(t_bunny_pixelarray *pix,
				    t_vm *vm,
				    t_data *data)
{
  int			i;
  t_bunny_position	start;
  t_champ		*tmp;
  char			chmp[4];
  t_bunny_position	size;

  size.x = 20;
  size.y = 20;
  start.x = 10;
  start.y = 20;
  init_names(chmp);
  i = 0;
  tmp = vm->begin;
  while (i < vm->nb)
    {
      if (check_prec(chmp, tmp->id) == 0)
	{
	  square(pix, size, start, tmp->id);
	  start.x += 25;
	  my_tektext(tmp->name, pix, data->font, &start);
	  start.x += 200;
	}
      i++;
      tmp = tmp->next;
    }
}
