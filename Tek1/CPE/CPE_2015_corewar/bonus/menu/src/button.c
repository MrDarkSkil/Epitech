/*
** button.c for button in /home/hubert_i/menu
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 27 10:40:40 2016 Léo Hubert
** Last update Sun Mar 27 12:20:09 2016 Léo Hubert
*/

# include			"graph.h"

void				button_fight(t_data *data)
{
  t_bunny_position		pos;

  if (data->pos.x >= data->pix->clipable.clip_width / 2
      - (data->button->fight->clipable.clip_width / 2) &&
      data->pos.x < data->pix->clipable.clip_width / 2
      + data->button->fight->clipable.clip_width / 2 &&
      data->pos.y >= data->pix->clipable.clip_height / 2 - 250 &&
      data->pos.y < data->pix->clipable.clip_height / 2
      + data->button->fight->clipable.clip_height - 250)
    {
      pos.x = data->pix->clipable.clip_width / 2 -
	(data->button->fight_select->clipable.clip_width / 2);
      pos.y = data->pix->clipable.clip_height / 2 - 250;
      tekblit(data->pix, data->button->fight_select, &pos);
    }
  else
    {
      pos.x = data->pix->clipable.clip_width / 2 -
	(data->button->fight->clipable.clip_width / 2);
      pos.y = data->pix->clipable.clip_height / 2 - 250;
      tekblit(data->pix, data->button->fight, &pos);
    }
}

void				button_options(t_data *data)
{
  t_bunny_position		pos;

  if (data->pos.x >= data->pix->clipable.clip_width / 2
      - (data->button->options->clipable.clip_width / 2) &&
      data->pos.x < data->pix->clipable.clip_width / 2
      + data->button->options->clipable.clip_width  / 2 &&
      data->pos.y >= data->pix->clipable.clip_height / 2 - 50 &&
      data->pos.y < data->pix->clipable.clip_height / 2
      + data->button->options->clipable.clip_height - 50)
    {
      pos.x = data->pix->clipable.clip_width / 2
	- (data->button->options_select->clipable.clip_width / 2);
      pos.y = data->pix->clipable.clip_height / 2 - 50;
      tekblit(data->pix, data->button->options_select, &pos);
    }
  else
    {
      pos.x = data->pix->clipable.clip_width / 2
	- (data->button->options->clipable.clip_width / 2);
      pos.y = data->pix->clipable.clip_height / 2 - 50;
      tekblit(data->pix, data->button->options, &pos);
    }
}

void				button_credits(t_data *data)
{
  t_bunny_position		pos;

  if (data->pos.x >= data->pix->clipable.clip_width / 2
      - (data->button->credits->clipable.clip_width / 2) &&
      data->pos.x < data->pix->clipable.clip_width / 2
      + data->button->credits->clipable.clip_width / 2 &&
      data->pos.y >= data->pix->clipable.clip_height / 2 + 120 &&
      data->pos.y < data->pix->clipable.clip_height / 2
      + data->button->credits->clipable.clip_height + 120)
    {
      pos.x = data->pix->clipable.clip_width / 2
	- (data->button->credits_select->clipable.clip_width / 2);
      pos.y = data->pix->clipable.clip_height / 2 + 120;
      tekblit(data->pix, data->button->credits_select, &pos);
    }
  else
    {
      pos.x = data->pix->clipable.clip_width / 2
	- (data->button->credits->clipable.clip_width / 2);
      pos.y = data->pix->clipable.clip_height / 2 + 120;
      tekblit(data->pix, data->button->credits, &pos);
    }
}

void				display_button(t_data *data)
{
  t_bunny_position		pos;

  button_fight(data);
  button_options(data);
  button_credits(data);
  if (data->pos.x >= 0 &&
      data->pos.x < data->button->wesh->clipable.clip_width &&
      data->pos.y >= data->pix->clipable.clip_height
      - data->button->wesh->clipable.clip_height &&
      data->pos.y < data->pix->clipable.clip_height)
    {
      pos.x = 0;
      pos.y = data->pix->clipable.clip_height
	- data->button->wesh->clipable.clip_height;
      tekblit(data->pix, data->button->wesh_select, &pos);
    }
  else
    {
      pos.x = 0;
      pos.y = data->pix->clipable.clip_height
	- data->button->wesh->clipable.clip_height;
      tekblit(data->pix, data->button->wesh, &pos);
    }
}
