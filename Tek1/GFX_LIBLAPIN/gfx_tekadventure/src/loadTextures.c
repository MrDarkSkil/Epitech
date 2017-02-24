/*
** loadTextures.c for loadTextures in /home/hubert_i/rendu/2015/INFO/gfx_tekadventure
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Apr 15 01:09:52 2016 Léo Hubert
** Last update Sun Apr 17 18:18:31 2016 Loic Lopez
*/

# include		"tekAdventure.h"

void			init_textures(t_data *data)
{
  data->textures->middleScene1_light =
    bunny_load_pixelarray("textures/middleScene1_light.png");
  data->textures->middleScene1_dark =
    bunny_load_pixelarray("textures/middleScene1_dark.png");
  data->textures->middleScene2_light =
    bunny_load_pixelarray("textures/middleScene2_light.png");
  data->textures->middleScene2_dark =
    bunny_load_pixelarray("textures/middleScene2_dark.png");
  data->textures->middleScene3 =
    bunny_load_pixelarray("textures/middleScene3.png");
}

int			loadTextures(t_data *data)
{
  if ((data->textures = bunny_malloc(sizeof(t_textures))) == NULL)
    return (-1);
  init_textures(data);
  data->textures->sky = bunny_load_pixelarray("textures/sky.png");
  data->textures->nextRight = bunny_load_pixelarray("textures/nextRight.png");
  data->textures->nextLeft = bunny_load_pixelarray("textures/nextLeft.png");
  data->textures->nextDown = bunny_load_pixelarray("textures/nextDown.png");
  data->textures->menu = bunny_load_pixelarray("textures/menu.png");
  data->textures->feuille1 = bunny_load_pixelarray("textures/feuille1.png");
  data->textures->feuille2 = bunny_load_pixelarray("textures/feuille2.png");
  if (data->textures->sky == NULL || data->textures->nextRight == NULL
      || data->textures->nextLeft == NULL
      || data->textures->middleScene1_light == NULL
      || data->textures->middleScene1_dark == NULL
      || data->textures->middleScene2_light == NULL
      || data->textures->middleScene2_dark == NULL
      || data->textures->nextDown == NULL ||
      data->textures->middleScene3 == NULL
      || data->textures->menu == NULL || data->textures->feuille1 == NULL
      || data->textures->feuille2 == NULL)
    return (-1);
  return (0);
}
