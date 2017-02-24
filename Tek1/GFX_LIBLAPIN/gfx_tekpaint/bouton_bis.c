/*
** bouton_bis.c for bouton_bis in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan 26 22:11:52 2016 Léo Hubert
** Last update Fri May 27 18:42:52 2016 Jabbari Yassir
*/

#include "my.h"

void	bouton_click(t_data *data,
		     t_bunny_keysym key)
{
  t_color		color;
  int			i;

  i = 0;
  color.full = BLACK;
  if (key == BKS_F1)
    data->pencil = 'e';
  if (key == BKS_F2)
    data->pencil = 'p';
  if (key == BKS_F3)
    data->pencil = 'l';
  if (key == BKS_F4)
    data->pencil = '?';
  if (key == BKS_F5)
    data->type = 's';
  if (key == BKS_F6)
    data->type = 'c';
  if (key == BKS_F7)
    play_music(data);
  if (key == BKS_I)
    tekpaint(data->pix, &color);
  if (i == 1)
    bouton_check(data);
}

void	play_music(t_data *data)
{
  bunny_sound_volume(&data->music->sound, 50);
  if (data->music_play == 0)
    {
      bunny_sound_play(&data->music->sound);
      data->music_play = 1;
    }
  else
    {
      bunny_sound_stop(&data->music->sound);
      data->music_play = 0;
    }
}
