/*
** tekfonction.c for tekfonctions in /home/hubert_i/rendu/2015/Info_2015/gfx_wolf3d
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Dec 22 18:35:25 2015 leo hubert
** Last update Tue Jan 26 19:06:59 2016 Léo Hubert
*/

#include "my.h"

void	tekpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position	*pos,
		 t_color		*color)
{
  if (pos->x < pix->clipable.clip_width && pos->y < pix->clipable.clip_height
      && pos->x > 0 && pos-> y > 0)
    ((t_color *)pix->pixels)[pos->x + pos->y * pix->clipable.clip_width] = *color;
}

t_color	getpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position	*pos)
{
  return (((t_color *)pix->pixels)[pos->x + pos->y * pix->clipable.clip_width]);
}

void	tekline(t_bunny_pixelarray	*pix,
		t_bunny_position	*pos,
		t_color			*color)
{
  int		i;
  t_line	line;

  line.dx = pos[1].x - pos[0].x;
  line.dy = pos[1].y - pos[0].y;
  line.xinc = (line.dx > 0 ) ? 1 : -1;
  line.yinc = (line.dy > 0 ) ? 1 : -1;
  line.dx = ABS(line.dx);
  line.dy = ABS(line.dy);
  tekpixel(pix, pos, color);
  line.cumul = LINE / 2;
  i = 1;
  while (i <= LINE)
    {
      XY;
      line.cumul += ULINE;
      if (line.cumul >= ULINE)
	{
	  line.cumul -= LINE;
	  YX;
	}
      tekpixel(pix, pos, color) ;
      i++;
    }
}

void			tekpaint(t_bunny_pixelarray	*pix,
				 t_color		*color)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.x != pix->clipable.clip_width
	 && pos.y != pix->clipable.clip_height)
    {
      tekpixel(pix, &pos, color);
      pos.y++;
      if (pos.y >= pix->clipable.clip_height)
	{
	  pos.y = 0;
	  pos.x++;
	}
    }
}

void	       	tekcircle(t_bunny_pixelarray	*pix,
			  t_bunny_position	*pos,
			  t_color		*color,
			  int			r)
{
  t_list	list;

  list.x = 0;
  list.y = r;
  list.d = r - 1;
  tekpixel(pix, pos, color);
  while(list.y >= list.x)
    {
      tekcircle_bis(pix, pos, color, list);
      if (list.d >= 2 * list.x)
	{
	  list.d -= 2 * list.x + 1;
	  list.x++;
	}
      else if (list.d < 2 * (r - list.y))
	{
	  list.d += 2 * list.y - 1;
	  list.y--;
	}
      else
	list.d += 2 * (list.y-- - list.x++ - 1);
    }
}
