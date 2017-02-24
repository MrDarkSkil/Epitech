/*
** keys_and_menu.c for keys_and_menu.c in /home/lopez_i/traitements/gfx_tekadventure
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Apr 17 18:28:30 2016 Loic Lopez
** Last update Sun Apr 17 18:34:36 2016 Loic Lopez
*/

# include			"tekAdventure.h"

int				initTekadventure(t_data *data)
{
  if ((data->sprites = malloc(sizeof(t_sprites))) == NULL)
    return (-1);
  if ((data->sprites->loading = loadSprite("loading",
					   data->iniSprites,
					   data->sprites->loading)) == NULL)
    return (-1);
  data->sprites->loading->spritePos = data->sprites->loading->spritePos->next;
  return (0);
}

t_bunny_response		menu(void *my_data)
{
  t_bunny_position		init;
  t_data			*data;

  data = ((t_data *)my_data);
  init.x = 0;
  init.y = 0;
  if (data->click == 1 && data->state == 0 &&
      data->pos.x >= 438 && data->pos.x <= 595
      && data->pos.y >= 347 && data->pos.y <= 500)
    {
      bunny_set_loop_main_function(&scene1);
      bunny_sound_play(&data->sounds->ambiance->sound);
      bunny_sound_loop(&data->sounds->ambiance->sound, true);
    }
  bunny_blit(&data->win->buffer, &data->textures->menu->clipable, &init);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response	mouse(t_bunny_position	*relativ,
			      void		*my_data)
{
  t_data		*data;

  data = ((t_data *)my_data);
  data->pos.x += relativ->x;
  data->pos.y += relativ->y;
  return (GO_ON);
}

t_bunny_response	click(t_bunny_event_state            state,
			      t_bunny_mousebutton            button,
			      void                           *my_data)
{
  t_data		*data;

  data = ((t_data *)my_data);
  if (state == 0 && button == 0)
    data->click = 1;
  else
    data->click = 0;
  return (GO_ON);
}
