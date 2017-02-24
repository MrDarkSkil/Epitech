/*
** main.c for main in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 17 19:58:56 2016 Léo Hubert
** Last update Sun Mar 27 18:13:19 2016 Eric DESCHODT
*/

# include			"graph.h"

t_bunny_response		key2(t_bunny_event_state	state,
				     t_bunny_keysym	key,
				     void		*my_data)
{
  (void)my_data;
  if (state == 1)
    return (GO_ON);
  if (key == BKS_ESCAPE)
    return (EXIT_ON_ERROR);
  return (GO_ON);
}

t_bunny_response		refresh(void *my_data)
{
  t_bunny_position		init;
  t_data			*data;

  data = ((t_data *)my_data);
  init.x = 0;
  init.y = 0;
  if (data->page == 0)
    {
      tekblit(data->pix, data->background, &init);
      if (data->display_mouse == 0)
	load_screen(data);
      else
	display_button(data);
    }
  else if (data->page == 1)
    show_credit(data, init);
  else if (data->page == 2)
    show_options(data);
  else if (data->page == 3)
    show_wesh(data);
  show_mouse(data);
  bunny_blit(&data->win->buffer, &data->pix->clipable, &init);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response		click(t_bunny_event_state            state,
				      t_bunny_mousebutton            button,
				      void                           *my_data)
{
  t_data			*data;

  data = ((t_data *)my_data);
  if (state == 0 && button == 0)
    {
      data->click = 1;
      if (data->display_mouse == 1 && data->page == 0)
	{
	  if (handler_click(data) == -1)
	    return (EXIT_ON_SUCCESS);
	}
      else if (data->display_mouse == 1 && data->page == 1)
	handler_click_page1(data);
      else if (data->display_mouse == 1 && data->page == 2)
	handler_click_page2(data);
    }
  else
      data->click = 0;
  return (GO_ON);
}

t_bunny_response		mouse(t_bunny_position	*relativ,
				      void		*my_data)
{
  t_data			*data;

  data = ((t_data *)my_data);
  data->pos.x += relativ->x;
  data->pos.y += relativ->y;
  return (GO_ON);
}

int				menu(t_data *data)
{
  int				check;

  check = 0;
  data->background = bunny_load_pixelarray("textures/load_screen.png");
  data->music = bunny_load_music("sounds/music.ogg");
  if (data->win == NULL || data->pix == NULL || data->music == NULL)
    exit(my_putstr("Error loading textures !"));
  if (load_textures(data) == -1)
    exit(my_putstr("Error loading all textures !"));
  init_menu(data);
  bunny_set_mouse_visibility(data->win, false);
  bunny_sound_play(&data->music->sound);
  bunny_sound_loop(&data->music->sound, true);
  bunny_set_mouse_position_window(data->win, 0, 0);
  bunny_set_loop_main_function(&refresh);
  bunny_set_move_response((t_bunny_move)mouse);
  bunny_set_click_response(click);
  bunny_set_key_response(key2);
  check = bunny_loop(data->win, 60, data);
  delete_sound(data);
  if (check == EXIT_ON_ERROR)
    return (-1);
  return (0);
}
