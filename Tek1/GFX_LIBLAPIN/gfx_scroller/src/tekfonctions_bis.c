/*
** tekfonction_bis.c for tekfonction_bis in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan 26 17:46:12 2016 Léo Hubert
** Last update Sun Mar 20 20:09:28 2016 Léo Hubert
*/

#include "scroller.h"

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
		      t_bunny_position	*pos,
		      t_color		*color,
		      t_list		list)
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

void			tekblit(t_bunny_pixelarray		*destination,
				const t_bunny_pixelarray	*origin,
				const t_bunny_position		*pos)
{
  t_bunny_position	start_pos;
  t_bunny_position	pos_bis;
  t_color		color;

  start_pos.y = origin->clipable.clip_y_position;
  pos_bis.y = pos->y;
  while (start_pos.y <= origin->clipable.clip_height)
    {
      start_pos.x = origin->clipable.clip_x_position;
      pos_bis.x = pos->x;
      while (start_pos.x <= origin->clipable.clip_width)
	{
	  color = getpixel((t_bunny_pixelarray *)origin, &start_pos);
	  tekpixel(destination, &pos_bis, &color);
	  pos_bis.x++;
	  start_pos.x++;
	}
      pos_bis.y++;
      start_pos.y++;
    }
}

void		tekchar(t_bunny_pixelarray	*pix,
			t_bunny_pixelarray	*font,
			t_bunny_position	*pos,
			t_tektext		*tek)
{
  tek->save_caract.x = tek->caract.x;
  tek->save_caract.y = tek->caract.y;
  while (tek->caract.y < tek->save_caract.y + 32)
    {
      while (tek->caract.x < tek->save_caract.x + 31)
	{
	  tek->color = getpixel(font, &tek->caract);
	  tekpixel(pix, pos, &tek->color);
	  pos->x++;
	  tek->caract.x++;
	}
      pos->x = tek->save_pos.x + tek->i * 32;
      pos->y++;
      tek->caract.x = tek->save_caract.x;
      tek->caract.y++;
    }
  tek->l = 1;
  tek->caract.y = tek->save_caract.y;

}

void			tektext(t_bunny_pixelarray	*pix,
				t_bunny_pixelarray	*font,
				t_bunny_position	*pos,
				char			*str)
{
  t_tektext		tek;

  tek.i = -1;
  tek.ordre = "opq  rst  uvT 0w  23456789xyz  ? A  \
BCDEFGHIJKLMNOPQ  RS UVWXYZ abcdef  ghjklmn1 ] i  !:";
  while (str[++tek.i])
    {
      tek.l = 0;
      tek.c = -1;
      tek.caract.x = 0;
      tek.caract.y = 0;
      tek.save_pos.x = pos->x;
      tek.save_pos.y = pos->y;
      while (tek.ordre[++tek.c] && tek.l != 1)
	{
	  (str[tek.i] == tek.ordre[tek.c]) ? tekchar(pix, font, pos, &tek) : (1);
	  (tek.caract.x > font->clipable.clip_width) ? tek.caract.y += 32 : (0);
	  if (tek.caract.x > font->clipable.clip_width)
	    tek.caract.x = 0;
	  else
	    tek.caract.x += 32;
	}
      pos->x = tek.save_pos.x;
      pos->y = tek.save_pos.y;
    }
}
