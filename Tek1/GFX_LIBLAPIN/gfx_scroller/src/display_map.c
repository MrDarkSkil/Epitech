/*
** display_map.c for display_map in /home/hubert_i/rendu/2015/INFO/gfx_scroller
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Mar 19 20:31:32 2016 Léo Hubert
** Last update Sun Mar 20 20:23:06 2016 Léo Hubert
*/

#include "scroller.h"

void			display_grass(t_data *data)
{
  static int		pos = 0;
  t_bunny_position	init;

  init.x = -pos;
  init.y = data->pix->clipable.clip_height - 130;
  tekblit(data->pix, data->textures->sol, &init);
  init.x = data->pix->clipable.clip_width - pos;
  init.y = data->pix->clipable.clip_height - 130;
  tekblit(data->pix, data->textures->sol, &init);
  pos = pos + 2;
  if (pos > data->pix->clipable.clip_width)
    pos = 0;
}

void			display_font(t_data *data)
{
  static int		pos = 0;
  t_bunny_position	init;

  init.x = -pos;
  init.y = 0;
  tekblit(data->pix, data->textures->nuit, &init);
  init.x = data->pix->clipable.clip_width - pos;
  init.y = 0;
  tekblit(data->pix, data->textures->nuit, &init);
  pos++;
  if (pos > data->pix->clipable.clip_width)
    pos = 0;
}

void			display_message(t_data *data)
{
  static int		pos = 1920;
  t_bunny_position	init;
  char			*str;

  str = "Ce jeu a ete cracke par MrDarkSkil";
  init.x = pos -= 5;
  init.y = 300;
  tektext(data->pix, data->textures->font, &init, str);
  if (init.x < -(my_strlen(str) * 32))
    pos = 1920;
}

void			display_map(t_data *data)
{
  display_font(data);
  display_cloud(data);
  display_message(data);
  display_zombieBorn(data);
  display_grass(data);
}
