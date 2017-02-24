/*
** click_handler2.c for click_handler in /home/hubert_i/rendu/2015/CPE/CPE_2015_corewar/bonus
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 27 17:30:36 2016 Léo Hubert
** Last update Sun Mar 27 17:37:54 2016 Léo Hubert
*/

# include			"graph.h"

void				handler_click4_page2(t_data *data)
{
  if (data->pos.x >= data->pix->clipable.clip_width
      - (data->button->minus->clipable.clip_width * 2) &&
      data->pos.x < data->pix->clipable.clip_width
      - data->button->minus->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height / 2
      - data->button->minus->clipable.clip_height - 100 &&
      data->pos.y < data->pix->clipable.clip_height / 2 - 100)
    {
      if (data->vol_music > 0)
	{
	  data->vol_music -= 5;
	  music_vol(data);
	}
    }
}

void				handler_click3_page2(t_data *data)
{
  if (data->pos.x >= data->pix->clipable.clip_width
      - data->button->plus->clipable.clip_width &&
      data->pos.x < data->pix->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height / 2
      - data->button->plus->clipable.clip_height - 100 &&
      data->pos.y < data->pix->clipable.clip_height / 2 - 100)
    {
      if (data->vol_music < 100)
	{
	  data->vol_music += 5;
	  music_vol(data);
	}
    }
  handler_click4_page2(data);
}

void				handler_click2_page2(t_data *data)
{
  if (data->pos.x >= data->pix->clipable.clip_width
      - (data->button->minus->clipable.clip_width * 2) &&
      data->pos.x < data->pix->clipable.clip_width
      - data->button->minus->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height / 2
      - data->button->minus->clipable.clip_height + 100 &&
      data->pos.y < data->pix->clipable.clip_height / 2 + 100)
    {
      if (data->vol_effect > 0)
	{
	  data->vol_effect -= 5;
	  effect_vol(data);
	  bunny_sound_play(&data->click_sound->sound);
	}
    }
  handler_click3_page2(data);
}
