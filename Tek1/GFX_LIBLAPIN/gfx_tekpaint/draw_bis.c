/*
** draw_bis.c for draw_bis in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan 26 19:21:57 2016 Léo Hubert
** Last update Tue Jan 26 21:33:57 2016 Léo Hubert
*/

#include "my.h"

void		erase(t_data *data)
{
  void		(*tabf[2])(t_data *data);
  t_color	color;
  char		*flags;
  int		i;

  i = 0;
  flags = "sc";
  tabf[0] = square;
  tabf[1] = circle;
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

void			ligne(t_data *data)
{
  t_bunny_position	pos[2];

  pos[0].x = data->pos.x;
  pos[0].y = data->pos.y;
  pos[1].x = data->pos_old.x;
  pos[1].y = data->pos_old.y;
  if (data->click == 0)
    tekline(data->pix, pos, &data->color);
}

void	pen(t_data *data)
{
  void	(*tabf[2])(t_data *data);
  char	*flags;
  int	i;

  i = 0;
  flags = "sc";
  tabf[0] = square;
  tabf[1] = circle;
  while (flags[i])
    {
      if (flags[i] == data->type)
	tabf[i](data);
      i++;
    }
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
