/*
** pages.c for pages in /home/hubert_i/menu
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 27 10:33:37 2016 Léo Hubert
** Last update Sun Mar 27 17:57:55 2016 Léo Hubert
*/

# include			"graph.h"

void				show_credit(t_data		*data,
					    t_bunny_position	pos)
{
  tekblit(data->pix, data->credits_screen, &pos);
  if (data->pos.x >= data->pix->clipable.clip_width
      - data->button->back->clipable.clip_width &&
      data->pos.x < data->pix->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height
      - data->button->back->clipable.clip_height &&
      data->pos.y < data->pix->clipable.clip_height)
    {
      pos.x = data->pix->clipable.clip_width
	- data->button->back->clipable.clip_width;
      pos.y = data->pix->clipable.clip_height
	- data->button->back->clipable.clip_height;
      tekblit(data->pix, data->button->back_select, &pos);
    }
  else
    {
      pos.x = data->pix->clipable.clip_width
	- data->button->back->clipable.clip_width;
      pos.y = data->pix->clipable.clip_height
	- data->button->back->clipable.clip_height;
      tekblit(data->pix, data->button->back, &pos);
    }
}

void				text_options(t_data *data)
{
  t_bunny_position		pos;

      pos.x = data->pix->clipable.clip_width
	- (data->button->minus->clipable.clip_width * 2)
	- data->volume->clipable.clip_width;
      pos.y = data->pix->clipable.clip_height / 2
	- data->button->minus->clipable.clip_height + 150;
      tekblit(data->pix, data->effects, &pos);
      pos.y = data->pix->clipable.clip_height / 2
	- data->button->minus->clipable.clip_height - 70;
      tekblit(data->pix, data->volume, &pos);
}

void				show_options2(t_data *data)
{
  t_bunny_position		pos;

  if (data->pos.x >= data->pix->clipable.clip_width
      - data->button->back->clipable.clip_width &&
      data->pos.x < data->pix->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height
      - data->button->back->clipable.clip_height &&
      data->pos.y < data->pix->clipable.clip_height)
    {
      pos.x = data->pix->clipable.clip_width
	- data->button->back->clipable.clip_width;
      pos.y = data->pix->clipable.clip_height
	- data->button->back->clipable.clip_height;
      tekblit(data->pix, data->button->back_select, &pos);
    }
  else
    {
      pos.x = data->pix->clipable.clip_width
	- data->button->back->clipable.clip_width;
      pos.y = data->pix->clipable.clip_height
	- data->button->back->clipable.clip_height;
      tekblit(data->pix, data->button->back, &pos);
    }
}

void				show_options(t_data *data)
{
  t_bunny_position		pos;

  pos.x = 0;
  pos.y = 0;
  tekblit(data->pix, data->options_screen, &pos);
  volume_music(data, pos);
  volume_effect(data, pos);
  text_options(data);
  show_options2(data);
}

void				show_wesh(t_data *data)
{
  static int			i = 0;
  t_bunny_position		pos;

  pos.x = 0;
  pos.y = 0;
  tekblit(data->pix, data->wesh_screen, &pos);
  i++;
  if (i > 50)
    {
      data->page = 0;
      i = 0;
    }
}
