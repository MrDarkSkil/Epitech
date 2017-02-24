/*
** loop.c for  in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/bonus
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Sat Mar 26 09:36:26 2016 Eric DESCHODT
** Last update Sun Mar 27 16:17:13 2016 Eric DESCHODT
*/

#include "corewar.h"

t_bunny_response        pausing(void *_data)
{
  t_data                *data;
  t_bunny_position	pos;

  data = _data;
  pos.x = 0;
  pos.y = 700;
  my_tektext("press space", data->pix, data->font, &pos);
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_display(data->win);
  if (bunny_get_keyboard()[BKS_SPACE] == 1)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response        mainloop(void *_data)
{
  t_data		*data;

  data = _data;
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response        endloop(void *_data)
{
  t_data		*data;
  static int		i = 0;
  t_color		color;

  data = _data;
  color.full = BLACK;
  color.argb[3] = 1;
  fill(data->pix, &color);
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_display(data->win);
  i++;
  if (i == 256)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response       key(t_bunny_event_state state,
                           t_bunny_keysym      key,
                           void                *p)
{
  (void)p;
  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_ERROR);
  if (state == GO_DOWN && key == BKS_SPACE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

int             start_graph(t_data *data)
{
  set_max_heap_size(100);
  if ((data->win = bunny_start(1280, 720, false, "Corewar")) == NULL
      || (data->pix = bunny_new_pixelarray(1280, 720)) == NULL
      || (data->back = load_bitmap("files/streetboard.png")) == NULL
      || ((load_font(&data->font, "files/font.png", 2)) == -1)
      || (data->ko = load_bitmap("files/ko.png")) == NULL
      || (data->sko = bunny_load_effect("files/KOsimple.ogg")) == NULL
      || (data->eko = bunny_load_effect("files/KOend.ogg")) == NULL
      || (data->end = load_bitmap("files/Juriend.png")) == NULL)
    return (-1);
  if (menu(data) == -1)
    return (-1);
  if ((data->music = bunny_load_music("files/music.ogg")) == NULL)
    return (-1);
  bunny_sound_volume(&data->music->sound, data->vol_music / 2);
  bunny_sound_loop(&data->music->sound, true);
  bunny_sound_play(&data->music->sound);
  data->size.x = 1280;
  data->size.y = 720;
  data->pos.x = 0;
  data->pos.y = 0;
  return (0);
}
