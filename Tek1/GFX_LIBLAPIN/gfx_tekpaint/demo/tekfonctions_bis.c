/*
** tekfonction_bis.c for tekfonction_bis in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan 26 17:46:12 2016 Léo Hubert
** Last update Tue Jan 26 19:08:02 2016 Léo Hubert
*/

#include "my.h"

void			teksquare(t_bunny_pixelarray	*pix,
				  t_bunny_position	*pos,
				  t_color		*color,
				  int			r)
{
  t_bunny_position	pos2;

  pos2.x = pos->x - (r / 2);
  pos2.y = pos->y - (r / 2);
  while (pos2.x++ < pos->x + (r / 2))
    tekpixel(pix, &pos2, color);
  while (pos2.y++ < pos->y + (r / 2))
    tekpixel(pix, &pos2, color);
  while (pos2.x-- > pos->x - (r / 2))
    tekpixel(pix, &pos2, color);
  while (pos2.y-- > pos->y - (r / 2))
    tekpixel(pix, &pos2, color);
}

void	tekcircle_bis(t_bunny_pixelarray	*pix,
		      t_bunny_position		*pos,
		      t_color			*color,
		      t_list			list)
{
  list.pos2.x = pos->x + list.x;
  list.pos2.y = pos->y + list.y;
  tekpixel(pix, &list.pos2, color);
  list.pos2.x = pos->x + list.y;
  list.pos2.y = pos->y + list.x;
  tekpixel(pix, &list.pos2, color);
  list.pos2.x = pos->x - list.x;
  list.pos2.y = pos->y + list.y;
  tekpixel(pix, &list.pos2, color);
  list.pos2.x = pos->x - list.y;
  list.pos2.y = pos->y + list.x;
  tekpixel(pix, &list.pos2, color);
  list.pos2.x = pos->x + list.x;
  list.pos2.y = pos->y - list.y;
  tekpixel(pix, &list.pos2, color);
  list.pos2.x = pos->x + list.y;
  list.pos2.y = pos->y - list.x;
  tekpixel(pix, &list.pos2, color);
  list.pos2.x = pos->x - list.x;
  list.pos2.y = pos->y - list.y;
  tekpixel(pix, &list.pos2, color);
  list.pos2.x = pos->x - list.y;
  list.pos2.y = pos->y - list.x;
  tekpixel(pix, &list.pos2, color);
}
