/*
** click_handler.c for click_handler in /home/hubert_i/menu
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 27 10:35:47 2016 Léo Hubert
** Last update Sun Mar 27 17:42:10 2016 Léo Hubert
*/

# include			"graph.h"

void				handler_click_page1(t_data *data)
{
  if (data->pos.x >= data->pix->clipable.clip_width
      - data->button->back->clipable.clip_width &&
      data->pos.x < data->pix->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height
      - data->button->back->clipable.clip_height &&
      data->pos.y < data->pix->clipable.clip_height)
    {
      bunny_sound_play(&data->click_sound->sound);
      data->page = 0;
    }
}

void				handler_click_page2(t_data *data)
{
  if (data->pos.x >= data->pix->clipable.clip_width
      - data->button->back->clipable.clip_width &&
      data->pos.x < data->pix->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height
      - data->button->back->clipable.clip_height &&
      data->pos.y < data->pix->clipable.clip_height)
    {
      bunny_sound_play(&data->click_sound->sound);
      data->page = 0;
    }
  if (data->pos.x >= data->pix->clipable.clip_width
      - data->button->plus->clipable.clip_width &&
      data->pos.x < data->pix->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height / 2
      - data->button->plus->clipable.clip_height + 100 &&
      data->pos.y < data->pix->clipable.clip_height / 2 + 100)
    {
      if (data->vol_effect < 100)
	{
	  data->vol_effect += 5;
	  effect_vol(data);
	  bunny_sound_play(&data->click_sound->sound);
	}
    }
  handler_click2_page2(data);
}

void				handler_click2(t_data *data)
{
  if (data->pos.x >= data->pix->clipable.clip_width / 2
      - (data->button->credits->clipable.clip_width / 2) &&
      data->pos.x < data->pix->clipable.clip_width / 2
      + data->button->credits->clipable.clip_width / 2 &&
      data->pos.y >= data->pix->clipable.clip_height / 2 + 120 &&
      data->pos.y < data->pix->clipable.clip_height / 2
      + data->button->credits->clipable.clip_height + 120)
    {
      bunny_sound_play(&data->click_sound->sound);
      data->page = 1;
    }
  if (data->pos.x >= 0 &&
      data->pos.x < data->button->wesh->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height
      - data->button->wesh->clipable.clip_height &&
      data->pos.y < data->pix->clipable.clip_height)
    {
      bunny_sound_play(&data->wesh_sound->sound);
      data->page = 3;
    }
}

int				handler_click(t_data *data)
{
  if (data->pos.x >= data->pix->clipable.clip_width / 2
      - (data->button->fight->clipable.clip_width / 2) &&
      data->pos.x < data->pix->clipable.clip_width / 2
      + data->button->fight->clipable.clip_width / 2 &&
      data->pos.y >= data->pix->clipable.clip_height / 2 - 250 &&
      data->pos.y < data->pix->clipable.clip_height / 2
      + data->button->fight->clipable.clip_height - 250)
    {
      bunny_sound_play(&data->fight_sound->sound);
      sleep(3);
      return (-1);
    }
  if (data->pos.x >= data->pix->clipable.clip_width / 2
      - (data->button->options->clipable.clip_width / 2) &&
      data->pos.x < data->pix->clipable.clip_width / 2
      + data->button->options->clipable.clip_width / 2 &&
      data->pos.y >= data->pix->clipable.clip_height / 2 - 50 &&
      data->pos.y < data->pix->clipable.clip_height / 2
      + data->button->options->clipable.clip_height - 50)
    {
      bunny_sound_play(&data->click_sound->sound);
      data->page = 2;
    }
  handler_click2(data);
  return (1);
}
