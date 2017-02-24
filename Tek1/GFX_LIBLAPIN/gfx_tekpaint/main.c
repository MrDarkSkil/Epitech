/*
** main.c for main in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 17 19:58:56 2016 Léo Hubert
** Last update Fri May 27 18:40:38 2016 Jabbari Yassir
*/

#include <stdio.h>
#include "my.h"

t_bunny_response	key(t_bunny_event_state	state,
			    t_bunny_keysym	key,
			    void		*my_data)
{
  t_data		*data;

  data = ((t_data *)my_data);
  if (state == 1)
    return (GO_ON);
  if (key == BKS_PAGEDOWN)
    data->size--;
  if (key == BKS_PAGEUP)
      data->size++;
  if (data->size < 2)
    data->size++;
  if (key == BKS_O)
    {
      bunny_delete_clipable(&data->pix->clipable);
      data->pix = bunny_load_pixelarray("save.png");
    }
  bouton_click(data, key);
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response		refresh(void *my_data)
{
  t_bunny_position		init;
  t_bunny_window		*win;
  t_data			*data;

  data = ((t_data *)my_data);
  win = data->win;
  init.x = 0;
  init.y = 0;
  if (data->click == 1 && data->in_tab == 0
      && data->pos.y >= 310 && data->pos.y <= 720)
    {
      data->color = getpixel(data->menu_1, &data->pos);
      refresh_header(data);
    }
  if (data->click == 1 && data->in_tab == 1)
    draw(data);
  bunny_blit(&win->buffer, &data->pix->clipable, &init);
  bunny_blit(&win->buffer, &data->menu_1->clipable, &init);
  bunny_blit(&win->buffer, &data->menu_2->clipable, &init);
  bunny_display(win);
  return (GO_ON);
}

t_bunny_response	mouse(t_bunny_position	*relativ,
			      void		*my_data)
{
  t_data		*data;

  data = ((t_data *)my_data);
  data->pos.x += relativ->x;
  data->pos.y += relativ->y;
  if (data->pos.x < 49)
    data->in_tab = 0;
  else if (data->pos.x > 49 && data->pos.y > 49)
    data->in_tab = 1;
  else if (data->pos.y < 49)
    data->in_tab = 2;
  return (GO_ON);
}

t_bunny_response	click(t_bunny_event_state            state,
			      t_bunny_mousebutton            button,
			      void                           *my_data)
{
  t_data		*data;

  data = ((t_data *)my_data);
  if (state == 0 && button == 0)
    {
      data->click = 1;
      data->pos_old = data->pos;
    }
  else
    {
      data->click = 0;
      if (data->pencil == 'l')
	draw(data);
    }
  if (data->in_tab == 0 || data->in_tab == 2)
    bouton_handler(data);
  return (GO_ON);
}

int			main()
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_data		data;

  set_max_heap_size(30);
  win = bunny_start(1280, 720, false, "TekPaint by BiBi");
  if (win == NULL)
    return (0);
  pix = bunny_new_pixelarray(1280, 720);
  if (pix == NULL)
    return (0);
  data.win = win;
  data.pix = pix;
  menu(&data);
  bunny_set_mouse_position_window(win, 0, 0);
  bunny_set_loop_main_function(&refresh);
  bunny_set_key_response(key);
  bunny_set_move_response((t_bunny_move)mouse);
  bunny_set_click_response(click);
  bunny_loop(win, 120, &data);
  bunny_delete_sound(&data.music->sound);
  bunny_delete_sound(&data.bouton->sound);
  bunny_stop(win);
  return (0);
}
