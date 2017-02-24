/*
** init_paint.c for init_paint in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 24 21:18:24 2016 Léo Hubert
** Last update Tue Jan 26 21:16:41 2016 Léo Hubert
*/

#include <math.h>
#include "my.h"

void	circle(t_data *data)
{
  int	size;

  size = 0;
  while (size++ < data->size)
    tekcircle(data->pix, &data->pos, &data->color, size / 2);
}

void			square(t_data *data)
{
  t_bunny_position	pos;
  int			size;

  size = data->size;
  pos.x = data->pos.x - (size / 2);
  pos.y = data->pos.y - (size / 2);
  while (pos.x != data->pos.x + (size / 2)
	 && pos.y != data->pos.y + (size / 2))
    {
      while (pos.x != data->pos.x + (size / 2))
	{
	  tekpixel(data->pix, &pos, &data->color);
	  pos.x++;
	}
      pos.x = data->pos.x - (size / 2);
      pos.y++;
    }
}

void		paint(t_data *data)
{
  tekpaint(data->pix, &data->color);
}
