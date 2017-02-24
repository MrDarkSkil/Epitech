/*
** main.c for main in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 17 19:58:56 2016 Léo Hubert
** Last update Sun Apr 17 18:58:29 2016 Loic Lopez
*/

# include			"tekAdventure.h"

t_bunny_response		scene3(void *my_data)
{
  t_bunny_position		init;
  t_data			*data;
  int				size[2];

  size[0] = 768;
  size[1] = 1024;
  data = ((t_data *)my_data);
  init.y = 0;
  if (data->pos.x < 0)
    init.x = 0;
  else
    init.x = 0 + data->pos.x;
  if ((check_scene3(data, init, size)) == EXIT_ON_SUCCESS)
    return (EXIT_ON_SUCCESS);
  init.x = 0;
  init.y = 0;
  bunny_blit(&data->win->buffer, &data->pix->clipable, &init);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response		scene2(void *my_data)
{
  t_bunny_position		init;
  t_data			*data;

  data = ((t_data *)my_data);
  init.y = 0;
  if (data->pos.x < 0)
    init.x = 683;
  else
    init.x = 683 - data->pos.x / 2;
  tekblit(data->pix, data->textures->sky, &init);
  init.x = 0;
  if (data->light == 1)
    tekblit(data->pix, data->textures->middleScene2_light, &init);
  else
    tekblit(data->pix, data->textures->middleScene2_dark, &init);
  if (data->pos.x >= 465 && data->pos.x <= 493
      && data->pos.y >= 218 && data->pos.y <= 267 && data->click == 1)
    data->key = 1;
  if (data->pos.x <= 100 && data->pos.y >= 550)
    showNext2(data, 550, -20);
  if (data->pos.x >= 786 && data->pos.y >= 540)
    showNext3(data, 340, 800);
  bunny_blit(&data->win->buffer, &data->pix->clipable, &init);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response		scene1(void *my_data)
{
  t_bunny_position		init;
  t_data			*data;
  int				size[2];

  size[0] = 768;
  size[1] = 1024;
  data = ((t_data *)my_data);
  if (data->click == 1 && data->state == 0 && data->pos.x >= 589
      && data->pos.x <= 610 && data->pos.y >= 347 && data->pos.y <= 394)
    {
      data->state = 1;
      if (data->light == 1)
	data->light = 0;
      else
	data->light = 1;
    }
  else if (data->click == 0 && data->state == 1)
    data->state = 0;
  init.y = 100;
  print_scene1(data, init, size);
  init.x = 0;
  init.y = 0;
  bunny_blit(&data->win->buffer, &data->pix->clipable, &init);
  bunny_display(data->win);
  return (GO_ON);
}

void				tekResize(t_bunny_pixelarray		*destination,
					  const t_bunny_pixelarray	*origin,
					  const t_bunny_position	*start,
					  int				size[2])
{
  t_bunny_position	pos;
  t_bunny_position	pos2;
  t_color		color;

  pos.y = start->y;
  pos2.y = 0;
  while (pos.y <= start->y + size[0])
    {
      pos2.x = 0;
      pos.x = start->x;
      while (pos.x <= start->x + size[1])
	{
	  color = getpixel((t_bunny_pixelarray *)origin, &pos);
	  tekpixel(destination, &pos2, &color);
	  pos.x++;
	  pos2.x++;
	}
      pos.y++;
      pos2.y++;
    }
}

int				main()
{
  t_data			data;

  if (loadConfig(&data) == -1)
    return (my_putstr("Error: Error load config launcher\n"));
  set_max_heap_size(data.max_ram);
  data.win = bunny_start(1024, 768, false, "TekAdventure");
  data.pix = bunny_new_pixelarray(1024, 768);
  if (data.win == NULL || initTekadventure(&data) == -1 || data.pix == NULL)
    {
      my_putstr("Error: Error when load texture or sprite or create window\n");
      return (0);
    }
  bunny_set_mouse_position_window(data.win, 0, 0);
  bunny_set_click_response(click);
  bunny_set_move_response((t_bunny_move)mouse);
  if (loadMusic(&data) == -1)
    return (my_putstr("Error: Error load sounds\n"));
  if (loadTextures(&data) == -1)
    return (my_putstr("Error: Error load textures\n"));
  bunny_set_loop_main_function(&loadingScreen);
  bunny_set_key_response(key);
  bunny_loop(data.win, 60, &data);
  bunny_stop(data.win);
  bunny_delete_sound(&data.sounds->ambiance->sound);
  return (0);
}
