/*
** init_paint.c for init_paint in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 24 21:18:24 2016 Léo Hubert
** Last update Tue Jan 26 16:57:59 2016 Léo Hubert
*/

#include "my.h"
#include <math.h>

void			circle(t_data *data)
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

void	triangle()
{

}

void	pen(t_data *data)
{
  void	(*tabf[3])(t_data *data);
  char	*flags;
  int	i;

  i = 0;
  flags = "sct";
  tabf[0] = square;
  tabf[1] = circle;
  tabf[2] = triangle;
  while (flags[i])
    {
      if (flags[i] == data->type)
	tabf[i](data);
      i++;
    }
}

void		erase(t_data *data)
{
  void		(*tabf[3])(t_data *data);
  t_color	color;
  char		*flags;
  int		i;

  i = 0;
  flags = "sct";
  tabf[0] = square;
  tabf[1] = circle;
  tabf[2] = triangle;
  color.full = data->color.full;
  data->color.full = BLACK;
  while (flags[i])
    {
      if (flags[i] == data->type)
	tabf[i](data);
      i++;
    }
  data->color.full = color.full;
}

void	paint(t_data *data)
{
  puts("pain");
}

void			ligne(t_data *data)
{
  t_bunny_position	pos[2];

  pos[0].x = data->pos.x;
  pos[0].y = data->pos.y;
  pos[1].x = data->pos_old.x;
  pos[1].y = data->pos_old.y;
  if (data->click == 0)
    tekline(data->pix, &pos, &data->color);
}

void	draw(t_data *data)
{
  void	(*tabf[4])(t_data *data);
  char	*flags;
  int	i;

  i = 0;
  flags = "pe?l";
  tabf[0] = pen;
  tabf[1] = erase;
  tabf[2] = paint;
  tabf[3] = ligne;
  while (flags[i])
    {
      if (flags[i] == data->pencil)
	tabf[i](data);
      i++;
    }
}
