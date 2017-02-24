/*
** bouton.c for bouton in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan 26 16:44:06 2016 Léo Hubert
** Last update Fri May 27 18:40:12 2016 Jabbari Yassir
*/

#include "my.h"

void	bouton_handler(t_data *data)
{
  if (data->pos.y >= 60 && data->pos.y <= 120)
    data->pencil = 'e';
  else if (data->pos.y >= 124 && data->pos.y <= 184)
    data->pencil = 'p';
  else if (data->pos.y >= 190 && data->pos.y <= 240)
    data->pencil = 'l';
  else if (data->pos.y >= 245 && data->pos.y <= 300)
    data->pencil = '?';
  else if (data->pos.x >= 67 && data->pos.y >= 8
	   && data->pos.x <= 107 && data->pos.y <= 46)
    data->type = 's';
  else if (data->pos.x >= 129 && data->pos.y >= 6
	   && data->pos.x <= 167 && data->pos.y <= 42)
    data->type = 'c';
  bouton_sound(data);
  bouton_check(data);
}

void		bouton_sound(t_data *data)
{
  bunny_sound_volume(&data->bouton->sound, 50);
  bunny_sound_play(&data->bouton->sound);
}

void			check_next(t_color	    color,
				   t_bunny_position pos,
				   t_data	    *data)
{
  if (data->pencil == 'l')
    {
      pos.x = 25;
      pos.y = 220;
      teksquare(data->menu_1, &pos, &color, 50);
    }
  if (data->pencil == '?')
    {
      pos.x = 25;
      pos.y = 275;
      teksquare(data->menu_1, &pos, &color, 50);
    }
  if (data->type == 's')
    {
      pos.x = 86;
      pos.y = 25;
      teksquare(data->menu_2, &pos, &color, 47);
    }
  else if (data->type == 'c')
    {
      pos.x = 147;
      pos.y = 25;
      teksquare(data->menu_2, &pos, &color, 47);
    }
}

void                    bouton_check(t_data *data)
{
  t_color               color;
  t_bunny_position      pos;

  color.full = RED;
  data->menu_1 = load_bitmap("img/menu1.bmp");
  data->menu_2 = load_bitmap("img/header.bmp");
  refresh_header(data);
  if (data->pencil == 'e')
    {
      pos.x = 25;
      pos.y = 85;
      teksquare(data->menu_1, &pos, &color, 50);
    }
  else if (data->pencil == 'p')
    {
      pos.x = 25;
      pos.y = 155;
      teksquare(data->menu_1, &pos, &color, 50);
    }
  check_next(color, pos, data);
}
