/*
** winning.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Fri Mar 25 14:42:37 2016 Eric DESCHODT
** Last update Sun Mar 27 16:09:54 2016 Eric DESCHODT
*/

#include "corewar.h"

void                    put_end_ko(int id, t_data *data)
{
  t_bunny_position      start;
  int                   i;

  if (&data->eko->sound != NULL)
    {
      bunny_sound_volume(&data->eko->sound, data->vol_music);
      bunny_sound_play(&data->eko->sound);
    }
  i = 1;
  start.x = 20;
  start.y = 0;
  while (i <= 4)
    {
      if (i != id)
	put_bmp(data->ko, data->pix, &start);
      start.x += 225;
      i++;
    }
}

void			winning(t_vm *vm, t_data *data)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 230;
  if (vm->begin != NULL)
    {
      put_end_ko(vm->begin->id, data);
      put_bmp(data->end, data->pix, &pos);
      pos.x = 500;
      pos.y = 550;
      data->font.size = 10;
      my_tektext(vm->begin->name, data->pix, data->font, &pos);
      bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
      my_putstr("Le champion ");
      my_put_nbr(vm->begin->id);
      my_putstr(" (");
      my_putstr(vm->begin->name);
      my_putstr(") a gagné\n");
    }
}
