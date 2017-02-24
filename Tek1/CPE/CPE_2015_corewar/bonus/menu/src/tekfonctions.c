/*
** tekfonction.c for tekfonctions in /home/hubert_i/rendu/2015/Info_2015/gfx_wolf3d
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Dec 22 18:35:25 2015 leo hubert
** Last update Sun Mar 27 16:27:48 2016 Léo Hubert
*/

#include "graph.h"

void	tekpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position	*pos,
		 t_color		*color)
{
  if (pos->x < pix->clipable.clip_width && pos->y < pix->clipable.clip_height
      && pos->x >= 0 && pos-> y >= 0 && color->argb[3] == 255)
    ((t_color *)pix->pixels)[pos->x + pos->y * pix->clipable.clip_width]
      = *color;
}

t_color		getpixel(t_bunny_pixelarray	*pix,
			 t_bunny_position	*pos)
{
  t_color	error;

  error.full = BLACK;
  if (pos->x <= pix->clipable.clip_width && pos->y <= pix->clipable.clip_height
      && pos->x >= 0 && pos-> y >= 0)
    return (((t_color *)pix->pixels)[pos->x
				     + pos->y * pix->clipable.clip_width]);
  else
    return (error);
}

void			tekblit(t_bunny_pixelarray		*destination,
				const t_bunny_pixelarray	*origin,
				const t_bunny_position		*pos)
{
  t_bunny_position	start_pos;
  t_bunny_position	pos_bis;
  t_color		color;

  start_pos.y = origin->clipable.clip_y_position;
  pos_bis.y = pos->y;
  while (start_pos.y < origin->clipable.clip_height)
    {
      start_pos.x = origin->clipable.clip_x_position;
      pos_bis.x = pos->x;
      while (start_pos.x < origin->clipable.clip_width)
	{
	  color = getpixel((t_bunny_pixelarray *)origin, &start_pos);
	  tektranspa(destination, &pos_bis, &color);
	  pos_bis.x++;
	  start_pos.x++;
	}
      pos_bis.y++;
      start_pos.y++;
    }
}

void			tektranspa(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_color *color)
{
  t_color	 c;

  if (color->argb[3] == 255)
    {
      tekpixel(pix, pos, color);
      return;
    }
  if (pos->x < pix->clipable.clip_width &&
      pos->y < pix->clipable.clip_height &&
      pos->x >= 0 && pos->y >= 0)
    {
      c = ((t_color *)pix->pixels)[pos->x + pix->clipable.clip_width * pos->y];
      c.argb[0] = (float)c.argb[0] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[0] * ((float)color->argb[3] / 255));
      c.argb[1] = (float)c.argb[1] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[1] * ((float)color->argb[3] / 255));
      c.argb[2] = (float)c.argb[2] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[2] * ((float)color->argb[3] / 255));
      c.argb[3] = 255;
      ((t_color *)pix->pixels)[pos->x + pix->clipable.clip_width * pos->y]
	= c;
    }
}

void			fill(t_bunny_pixelarray *pix,
			     t_color *color)
{
  t_bunny_position	pixel;

  pixel.y = 0;
  while (pixel.y < pix->clipable.clip_height)
    {
      pixel.x = 0;
      while (pixel.x < pix->clipable.clip_width)
	{
	  tektranspa(pix, &pixel, color);
	  pixel.x++;
	}
      pixel.y++;
    }
}
