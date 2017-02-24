/*
** contribute_scene3.c for contribute_scene3.c in /home/lopez_i/traitements/gfx_tekadventure
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Apr 17 18:39:44 2016 Loic Lopez
** Last update Sun Apr 17 18:43:42 2016 Loic Lopez
*/

# include			"tekAdventure.h"

int				check_scene3(t_data *data, t_bunny_position init,
					     int size[2])
{
  if (data->light == 1)
    tekResize(data->pix, data->textures->middleScene3, &init, size);
  else
    tekResize(data->pix, data->textures->middleScene3, &init, size);
  if (data->pos.x >= 601 && data->pos.x <= 642
      && data->pos.y >= 341 && data->pos.y <= 432)
    showAffiche2(data, 50, 50);
  if (data->pos.x >= 650 && data->pos.x <= 754
      && data->pos.y >= 270 && data->pos.y <= 543
      && data->key == 1 && data->click == 1)
    {
      my_putstr("Game Finish !");
      return (EXIT_ON_SUCCESS);
    }
  if (data->pos.x <= 100 &&
      data->pos.y >= 550)
    showNext4(data, 550, -20);
  return (0);
}
