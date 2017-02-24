/*
** button_options.c for button_options in /home/hubert_i/rendu/2015/CPE/CPE_2015_corewar/bonus
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 27 17:44:52 2016 Léo Hubert
** Last update Sun Mar 27 17:52:48 2016 Léo Hubert
*/

# include			"graph.h"

void				volume_music2(t_data		*data,
					     t_bunny_position	pos)
{
 if (data->pos.x >= data->pix->clipable.clip_width
      - (data->button->minus->clipable.clip_width * 2) &&
      data->pos.x < data->pix->clipable.clip_width
      - data->button->minus->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height / 2
      - data->button->minus->clipable.clip_height - 100 &&
      data->pos.y < data->pix->clipable.clip_height / 2 - 100)
    {
      pos.x = data->pix->clipable.clip_width
	- (data->button->minus->clipable.clip_width * 2);
      pos.y = data->pix->clipable.clip_height / 2
	- data->button->minus->clipable.clip_height - 100;
      tekblit(data->pix, data->button->minus_select, &pos);
    }
  else
    {
      pos.x = data->pix->clipable.clip_width
	- (data->button->minus->clipable.clip_width * 2);
      pos.y = data->pix->clipable.clip_height / 2
	- data->button->minus->clipable.clip_height - 100;
      tekblit(data->pix, data->button->minus, &pos);
    }
}

void				volume_music(t_data		*data,
					     t_bunny_position	pos)
{
  if (data->pos.x >= data->pix->clipable.clip_width
      - data->button->plus->clipable.clip_width &&
      data->pos.x < data->pix->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height / 2
      - data->button->plus->clipable.clip_height - 100 &&
      data->pos.y < data->pix->clipable.clip_height / 2 - 100)
    {
      pos.x = data->pix->clipable.clip_width
	- data->button->plus->clipable.clip_width;
      pos.y = data->pix->clipable.clip_height / 2
	- data->button->plus->clipable.clip_height - 100;
      tekblit(data->pix, data->button->plus_select, &pos);
    }
  else
    {
      pos.x = data->pix->clipable.clip_width
	- data->button->plus->clipable.clip_width;
      pos.y = data->pix->clipable.clip_height / 2
	- data->button->plus->clipable.clip_height - 100;
      tekblit(data->pix, data->button->plus, &pos);
    }
  volume_music2(data, pos);
}

void				volume_effect2(t_data		*data,
					       t_bunny_position	pos)
{
  if (data->pos.x >= data->pix->clipable.clip_width
      - (data->button->minus->clipable.clip_width * 2) &&
      data->pos.x < data->pix->clipable.clip_width
      - data->button->minus->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height / 2
      - data->button->minus->clipable.clip_height + 100 &&
      data->pos.y < data->pix->clipable.clip_height / 2 + 100)
    {
      pos.x = data->pix->clipable.clip_width
	- (data->button->minus->clipable.clip_width * 2);
      pos.y = data->pix->clipable.clip_height / 2
	- data->button->minus->clipable.clip_height + 100;
      tekblit(data->pix, data->button->minus_select, &pos);
    }
  else
    {
      pos.x = data->pix->clipable.clip_width
	- (data->button->minus->clipable.clip_width * 2);
      pos.y = data->pix->clipable.clip_height / 2
	- data->button->minus->clipable.clip_height + 100;
      tekblit(data->pix, data->button->minus, &pos);
    }
}

void				volume_effect(t_data		*data,
					      t_bunny_position	pos)
{
  if (data->pos.x >= data->pix->clipable.clip_width
      - data->button->plus->clipable.clip_width &&
      data->pos.x < data->pix->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height / 2
      - data->button->plus->clipable.clip_height + 100 &&
      data->pos.y < data->pix->clipable.clip_height / 2 + 100)
    {
      pos.x = data->pix->clipable.clip_width
	- data->button->plus->clipable.clip_width;
      pos.y = data->pix->clipable.clip_height / 2
	- data->button->plus->clipable.clip_height + 100;
      tekblit(data->pix, data->button->plus_select, &pos);
    }
  else
    {
      pos.x = data->pix->clipable.clip_width
	- data->button->plus->clipable.clip_width;
      pos.y = data->pix->clipable.clip_height / 2
	- data->button->plus->clipable.clip_height + 100;
      tekblit(data->pix, data->button->plus, &pos);
    }
  volume_effect2(data, pos);
}
