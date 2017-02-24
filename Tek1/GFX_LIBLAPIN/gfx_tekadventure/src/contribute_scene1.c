/*
** contribute_scene1.c for contribute_scene1.c in /home/lopez_i/traitements/gfx_tekadventure
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Apr 17 18:48:38 2016 Loic Lopez
** Last update Sun Apr 17 18:54:42 2016 Loic Lopez
*/

#include			"tekAdventure.h"

void				print_scene1(t_data *data, t_bunny_position init,
					     int size[2])
{
  if (data->pos.x < 0)
    init.x = 300;
  else
    init.x = 300 - data->pos.x / 2;
  tekblit(data->pix, data->textures->sky, &init);
  init.y = 0;
  if (data->pos.x < 0)
    init.x = 0;
  else
    init.x = 0 + data->pos.x;
  if (data->light == 1)
    tekResize(data->pix, data->textures->middleScene1_light, &init, size);
  else
    tekResize(data->pix, data->textures->middleScene1_dark, &init, size);
  if (data->pos.x >= 31 && data->pos.x <= 52
      && data->pos.y >= 620 && data->pos.y <= 655)
    showAffiche1(data, 50, 50);
  if (data->pos.x >= 950 &&
      data->pos.y >= 550)
    showNext1(data, 550, 850);
}
