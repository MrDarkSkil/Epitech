/*
** screens.c for screens.c in /home/lopez_i/traitements/gfx_tekadventure
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Apr 17 18:22:37 2016 Loic Lopez
** Last update Sun Apr 17 18:25:36 2016 Loic Lopez
*/

# include			"tekAdventure.h"

void				showAffiche2(t_data    		*data,
					     int       		y,
					     int		x)
{
  t_bunny_position		pos;

  pos.x = x;
  pos.y = y;
  if (data->click == 1)
    data->showAffiche2 = 1;
  if (data->showAffiche2 == 1)
    tekblit(data->pix, data->textures->feuille2, &pos);
}

void				showAffiche1(t_data    		*data,
					     int       		y,
					     int		x)
{
  t_bunny_position		pos;

  pos.x = x;
  pos.y = y;
  if (data->click == 1)
    data->showAffiche1 = 1;
  if (data->showAffiche1 == 1)
    tekblit(data->pix, data->textures->feuille1, &pos);
}

t_bunny_response		loadingScreen(void *my_data)
{
  t_bunny_position		init;
  t_data			*data;
  static int			loop = 0;
  static int			i = 0;

  data = ((t_data *)my_data);
  init.x = 0;
  init.y = 0;
  tekResize(data->pix, data->sprites->loading->pix,
	    &data->sprites->loading->spritePos->pos, data->sprites->loading->size);
  if (loop > 60)
    {
      data->sprites->loading->spritePos =
	data->sprites->loading->spritePos->next;
      loop = 0;
      i++;
    }
  bunny_blit(&data->win->buffer, &data->pix->clipable, &init);
  bunny_display(data->win);
  loop++;
  if (i > 3)
    bunny_set_loop_main_function(&menu);
  return (GO_ON);
}

int				loadConfig(t_data *data)
{
  t_bunny_ini		*config;
  char			*tmp;

  if ((config = bunny_load_ini("ini/config.ini")) == NULL)
    return (-1);
  if ((tmp = (char *)bunny_ini_get_field(config,
					 "config", "max_ram", 0)) == NULL)
    return (-1);
  if ((data->max_ram = my_getnbr(tmp)) == -1)
    return (-1);
  if ((tmp = (char *)bunny_ini_get_field(config,
					 "config", "sprites_dest", 0)) == NULL)
    return (-1);
  if ((data->iniSprites = bunny_load_ini(tmp)) == NULL)
    return (-1);
  if ((tmp = (char *)bunny_ini_get_field(config,
					 "config", "sounds_dest", 0)) == NULL)
    return (-1);
  if ((data->iniSounds = bunny_load_ini(tmp)) == NULL)
    return (-1);
  return (0);
}
