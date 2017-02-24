/*
** contribute_main.c for contribute_main.c in /home/lopez_i/traitements/gfx_tekadventure
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Apr 17 17:57:03 2016 Loic Lopez
** Last update Sun Apr 17 18:01:32 2016 Loic Lopez
*/

#include			"tekAdventure.h"

t_bunny_response		key(t_bunny_event_state	state,
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

void				showNext1(t_data		*data,
					  int			y,
					  int			x)
{
  t_bunny_position		pos;

  pos.x = x;
  pos.y = y;
  tekblit(data->pix, data->textures->nextRight, &pos);
  if (data->click == 1 && data->state == 0)
    data->state = 2;
  if (data->click == 0 && data->state == 2)
    {
      bunny_set_loop_main_function(&scene2);
      data->state = 0;
    }
}

void				showNext2(t_data		*data,
					  int			y,
					  int			x)
{
  t_bunny_position		pos;

  pos.x = x;
  pos.y = y;
  tekblit(data->pix, data->textures->nextLeft, &pos);
  if (data->click == 1 && data->state == 0)
    data->state = 2;
  if (data->click == 0 && data->state == 2)
    {
      bunny_set_loop_main_function(&scene1);
      data->state = 0;
    }
}

void				showNext3(t_data		*data,
					  int			y,
					  int			x)
{
  t_bunny_position		pos;

  pos.x = x;
  pos.y = y;
  tekblit(data->pix, data->textures->nextDown, &pos);
  if (data->click == 1 && data->state == 0)
    data->state = 2;
  if (data->click == 0 && data->state == 2)
    {
      bunny_set_loop_main_function(&scene3);
      data->state = 0;
    }
}

void				showNext4(t_data		*data,
					  int			y,
					  int			x)
{
  t_bunny_position		pos;

  pos.x = x;
  pos.y = y;
  tekblit(data->pix, data->textures->nextLeft, &pos);
  if (data->click == 1 && data->state == 0)
    data->state = 2;
  if (data->click == 0 && data->state == 2)
    {
      bunny_set_loop_main_function(&scene2);
      data->state = 0;
    }
}
