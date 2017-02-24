/*
** load_textures.c for load_textures in /home/hubert_i/rendu/2015/INFO/gfx_scroller
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Mar 19 17:32:28 2016 Léo Hubert
** Last update Sun Mar 20 20:05:39 2016 Léo Hubert
*/

#include "scroller.h"

int	malloc_textures(t_data *data)
{
  data->sounds = malloc(sizeof(t_sounds));
  data->textures = malloc(sizeof(t_textures));
  data->sprites = malloc(sizeof(t_sprites));
  if (data->sounds == NULL || data->textures == NULL || data->sprites == NULL)
    return (-1);
  data->sounds->duration = 0;
  data->sounds->i = 0;
  return (0);
}

int			load_cloud(t_data *data)
{
  t_bunny_pixelarray	*sprite;
  t_sprite		*list;
  t_bunny_position	pos;

  list = NULL;
  pos.x = 0;
  pos.y = 0;
  if ((sprite = bunny_load_pixelarray("textures/cloud/1.png")) == NULL)
    return (-1);
  list = add_sprite(list, sprite, &pos);
  if ((sprite = bunny_load_pixelarray("textures/cloud/2.png")) == NULL)
    return (-1);
  list = add_sprite(list, sprite, &pos);
  if ((sprite = bunny_load_pixelarray("textures/cloud/3.png")) == NULL)
    return (-1);
  list = add_sprite(list, sprite, &pos);
  if ((sprite = bunny_load_pixelarray("textures/cloud/4.png")) == NULL)
    return (-1);
  list = add_sprite(list, sprite, &pos);
  if ((sprite = bunny_load_pixelarray("textures/cloud/5.png")) == NULL)
    return (-1);
  list = add_sprite(list, sprite, &pos);
  data->sprites->cloud = list;
  return (0);
}

int	load_sprites(t_data *data)
{
  if (load_cloud(data) == -1 || load_bornzombie(data) == -1
      || load_zombieWalk(data) == -1)
    return (-1);
  return (0);
}

int	load_textures(t_data *data)
{
  data->textures->sol = bunny_load_pixelarray("textures/grass.png");
  data->textures->nuit = bunny_load_pixelarray("textures/nuit.png");
  data->textures->font = bunny_load_pixelarray("textures/font.png");
  if (data->textures->sol == NULL || data->sounds->music == NULL
      || data->textures->nuit == NULL
      || data->textures->font == NULL || load_sprites(data) == -1)
    return (-1);
  return (0);
}
