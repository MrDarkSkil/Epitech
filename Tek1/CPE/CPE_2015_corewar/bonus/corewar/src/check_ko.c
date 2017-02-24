/*
** loop.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/bonus
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Sat Mar 26 09:36:26 2016 Eric DESCHODT
** Last update Sun Mar 27 00:41:54 2016 Eric DESCHODT
*/

#include "corewar.h"

void			put_ko(int id, t_data *data)
{
  t_bunny_position	start;
  int			i;

  if (&data->sko->sound != NULL)
    bunny_sound_play(&data->sko->sound);
  i = 1;
  start.x = 20;
  start.y = 0;
  while (i < id)
    {
      start.x += 225;
      i++;
    }
  put_bmp(data->ko, data->pix, &start);
}

void			put_nbr_scr(int nb, t_data *data)
{
  char			nbr[10];
  int			pow;
  int			i;
  t_bunny_position	start;
  t_bunny_position	size;

  size.x = 200;
  size.y = 50;
  start.x = 0;
  start.y = 680;
  square(data->pix, size, start, 4);
  pow = 1;
  while (pow <= nb)
    pow *= 10;
  pow /= 10;
  i = -1;
  while (pow >= 1 && ++i < 9)
    {
      nbr[i] = nb / pow + 48;
      nbr[i + 1] = '\0';
      nb %= pow;
      pow /= 10;
    }
  my_tektext(nbr, data->pix, data->font, &start);
}

int			check_alone(int id, t_vm *vm)
{
  t_champ		*tmp;
  int			i;

  i = 0;
  tmp = vm->begin;
  while (i < vm->nb)
    {
      if (tmp->id == id && tmp->alive == 1)
	return (0);
      tmp = tmp->next;
      i++;
    }
  return (-1);
}

void			check_ko(t_vm *vm, t_data *data)
{
  t_champ		*tmp;
  int			i;

  i = 0;
  tmp = vm->begin;
  while (i < vm->nb)
    {
      if (tmp->alive == 0 && check_alone(tmp->id, vm) == -1)
	put_ko(tmp->id, data);
      tmp = tmp->next;
      i++;
    }
  return;
}
