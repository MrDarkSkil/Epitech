/*
** main.c for main in /home/hubert_i/rendu/2015/Info_2015/gfx_tekpaint
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 17 19:58:56 2016 Léo Hubert
** Last update Sun Mar 20 19:56:20 2016 Léo Hubert
*/

#include <stdio.h>
#include "scroller.h"

t_bunny_response	key(t_bunny_event_state	state,
			    t_bunny_keysym	key,
			    void		*my_data)
{
  (void)my_data;
  if (state == 1)
    return (GO_ON);
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response		refresh(void *my_data)
{
  t_bunny_position		init;
  t_data			*data;

  data = ((t_data *)my_data);
  display_map(data);
  play_music(data);
  init.x = 0;
  init.y = 0;
  bunny_blit(&data->win->buffer, &data->pix->clipable, &init);
  bunny_display(data->win);
  return (GO_ON);
}

int			main()
{
  t_data		data;

  srand(time(NULL));
  set_max_heap_size(100);
  data.win = bunny_start(1920, 1080, false, "Scroller by huber_i");
  data.pix = bunny_new_pixelarray(1920, 1080);
  if (data.win == NULL)
    return (puts("sa"));
  if (malloc_textures(&data) == -1 || load_textures(&data) == -1)
    return(puts("Error: Cannot malloc or cannot load textures, music."));
  if (load_music(&data) == -1)
    return (puts("Error music: malloc or music file not found."));
  bunny_set_loop_main_function(&refresh);
  bunny_set_key_response(key);
  bunny_loop(data.win, 90, &data);
  bunny_delete_sound(&data.sounds->music->sound);
  bunny_stop(data.win);
  return (0);
}
