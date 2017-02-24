/*
** main.c for main in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 17 19:58:56 2016 Léo Hubert
** Last update Tue Jan 26 19:02:37 2016 Léo Hubert
*/

#include <stdio.h>
#include "my.h"

int			main()
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	init;
  t_data		data;

  win = bunny_start(1280, 720, false, "DEMO Load Bitmap");
  if (win == NULL)
    return (0);
  init.x = 50;
  init.y = 50;
  pix = load_bitmap("test.bmp");
  bunny_blit(&win->buffer, &pix->clipable, &init);
  bunny_display(win);
  bunny_loop(win, 120, &data);
  bunny_stop(win);
  return (0);
}
