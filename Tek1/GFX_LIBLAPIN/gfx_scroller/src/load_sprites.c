/*
** load_sprites.c for load_sprite in /home/hubert_i/rendu/2015/INFO/gfx_scroller
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 20 19:05:21 2016 Léo Hubert
** Last update Sun Mar 20 20:09:29 2016 Léo Hubert
*/

#include "scroller.h"

t_bunny_pixelarray	*scale_pix(t_bunny_pixelarray	*pix,
				   int			posx,
				   int			posy,
				   int			size)
{
  t_bunny_pixelarray	*result;
  t_bunny_position	pos;
  t_bunny_position	new_pos;
  t_color		color;

  if ((result = bunny_new_pixelarray(size, pix->clipable.clip_height)) == NULL)
    return (NULL);
  color.full = BLACK;
  tekpaint(result, &color);
  pos.y = posy - 1;
  new_pos.y = 0;
  while (++pos.y < pix->clipable.clip_height)
    {
      new_pos.x = 0;
      pos.x = posx - 1;
      while (++pos.x < posx + size)
	{
	  color = getpixel(pix, &pos);
	  tekpixel(result, &new_pos, &color);
	  new_pos.x++;
	}
      new_pos.y++;
    }
  return (result);
}

int		load_bornzombie(t_data *data)
{
  t_bunny_pixelarray	*sprite;
  t_bunny_pixelarray	*tmp;
  t_sprite		*list;
  t_bunny_position	pos;
  int			i;

  list = NULL;
  i = 0;
  pos.x = 0;
  pos.y = 0;
  if ((sprite = bunny_load_pixelarray("textures/zombieBorn.png")) == NULL)
    return (-1);
  while (i < 6)
    {
      tmp = scale_pix(sprite, i * 65, 0, 65);
      list = add_sprite(list, tmp, &pos);
      i++;
    }
  data->sprites->zombieBorn = list;
  return (0);
}

int		load_zombieWalk(t_data *data)
{
  t_bunny_pixelarray	*sprite;
  t_bunny_pixelarray	*tmp;
  t_sprite		*list;
  t_bunny_position	pos;
  int			i;

  list = NULL;
  i = 0;
  pos.x = 0;
  pos.y = 0;
  if ((sprite = bunny_load_pixelarray("textures/zombieWalk.png")) == NULL)
    return (-1);
  while (i < 3)
    {
      tmp = scale_pix(sprite, i * 65, 0, 65);
      list = add_sprite(list, tmp, &pos);
      i++;
    }
  data->sprites->zombieWalk = list;
  return (0);
}
