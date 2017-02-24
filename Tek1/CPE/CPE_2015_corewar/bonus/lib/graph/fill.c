/*
** fill.c for  in /home/descho_e/year_2015_2016/I_graph/gfx_tekgui
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Tue Feb  2 15:46:56 2016 Eric DESCHODT
** Last update Sun Mar 27 09:30:07 2016 Eric DESCHODT
*/

#include "libgraph.h"

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
