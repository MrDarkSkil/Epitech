/*
** header.c for header in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan 26 16:28:17 2016 Léo Hubert
** Last update Tue Jan 26 21:24:48 2016 Léo Hubert
*/

#include "my.h"

void			refresh_header(t_data *data)
{
  t_bunny_position	pos;
  int			size;

  pos.x = 66;
  pos.y = 5;
  size = 0;
  while (pos.y <= 45)
    {
      while (pos.x <= 106)
	{
	  tekpixel(data->menu_2, &pos, &data->color);
	  pos.x++;
	}
      pos.x = 66;
      pos.y++;
    }
  pos.x = 148;
  pos.y = 25;
  tekpixel(data->menu_2, &pos, &data->color);
  while (size++ <= 17)
    tekcircle(data->menu_2, &pos, &data->color, size);
}
