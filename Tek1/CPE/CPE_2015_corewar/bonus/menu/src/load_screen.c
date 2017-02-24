/*
** load_screen.c for load_screen in /home/hubert_i/menu
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 27 12:07:56 2016 Léo Hubert
** Last update Sun Mar 27 12:15:57 2016 Léo Hubert
*/

# include			"graph.h"

void				load_screen(t_data *data)
{
  static int			i;

  if (i > 240)
    {
      fill(data->pix, &data->fade);
      data->display_mouse = 1;
      bunny_delete_clipable(&data->background->clipable);
      data->background = data->menu_screen;
    }
  else if (i++ > 175)
    {
      if (data->fade.argb[3] < 245)
      	{
      	  data->fade.argb[3] += 1;
	  fill(data->pix, &data->fade);
      	}
    }
  else
    {
      if (data->fade.argb[3] > 0)
      	{
      	  data->fade.argb[3] -= 1;
	  fill(data->pix, &data->fade);
      	}
    }
}

void				show_mouse(t_data *data)
{
  t_bunny_position		init;

  if (data->display_mouse == 1)
    {
      init.x = data->pos.x - data->mouse->clipable.clip_width / 2;
      init.y = data->pos.y - data->mouse->clipable.clip_height / 2;
      tekblit(data->pix, data->mouse, &init);
    }
}
