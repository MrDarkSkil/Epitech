/*
** menu.c for menu in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Mon Jan 18 17:36:18 2016 Léo Hubert
** Last update Tue Jan 26 23:29:31 2016 Léo Hubert
*/

#include "my.h"

void			menu(t_data *data)
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*pix2;
  t_color		color;

  pix = bunny_new_pixelarray(50, 720);
  pix2 = bunny_new_pixelarray(1280, 50);
  color.full = BLACK;
  tekpaint(data->pix, &color);
  pix = load_bitmap("img/menu1.bmp");
  pix2 = load_bitmap("img/header.bmp");
  data->pix = load_bitmap("img/instructions.bmp");
  data->music = bunny_load_music("sound/music.ogg");
  data->bouton = bunny_load_effect("sound/bouton.ogg");
  data->in_tab = 1;
  data->music_play = 0;
  data->click = 0;
  data->pos.x = 0;
  data->pos.y = 0;
  data->size = 4;
  data->color.full = WHITE;
  data->type = 's';
  data->pencil = 'p';
  data->menu_1 = pix;
  data->menu_2 = pix2;
  bouton_check(data);
}
