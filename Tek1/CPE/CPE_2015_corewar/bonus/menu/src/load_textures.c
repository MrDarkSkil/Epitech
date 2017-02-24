/*
** load_textures.c for load_textures in /home/hubert_i/menu
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 27 11:42:56 2016 Léo Hubert
** Last update Sun Mar 27 14:21:38 2016 Léo Hubert
*/

# include			"graph.h"

int				check_textures(t_data *data)
{
  if (data->mouse == NULL || data->menu_screen == NULL
      || data->button->options == NULL
      || data->button->options_select == NULL || data->button->fight == NULL
      || data->button->fight_select == NULL || data->button->credits == NULL
      || data->button->credits_select == NULL || data->button->wesh == NULL
      || data->button->wesh_select == NULL || data->credits_screen == NULL
      || data->button->back == NULL || data->button->back_select == NULL
      || data->options_screen == NULL || data->wesh_screen == NULL
      || data->wesh_sound == NULL || data->click_sound == NULL
      || data->fight_sound == NULL || data->button->plus == NULL
      || data->button->plus_select == NULL || data->button->minus == NULL
      || data->button->minus_select == NULL || data->volume == NULL
      || data->effects == NULL)
    return (-1);
  return (0);
}

void				load_textures3(t_data *data)
{
  data->volume =
    bunny_load_pixelarray("textures/volume.png");
  data->effects =
    bunny_load_pixelarray("textures/effects.png");
  data->button->options =
    bunny_load_pixelarray("textures/button/options.png");
  data->button->options_select =
    bunny_load_pixelarray("textures/button/options_select.png");
  data->button->fight =
    bunny_load_pixelarray("textures/button/fight.png");
  data->button->fight_select =
    bunny_load_pixelarray("textures/button/fight_select.png");
}

void				load_textures2(t_data *data)
{
  load_textures3(data);
  data->button->credits =
    bunny_load_pixelarray("textures/button/credits.png");
  data->button->credits_select =
    bunny_load_pixelarray("textures/button/credits_select.png");
  data->button->wesh =
    bunny_load_pixelarray("textures/button/wesh.png");
  data->button->wesh_select =
    bunny_load_pixelarray("textures/button/wesh_select.png");
  data->button->back = bunny_load_pixelarray("textures/button/back.png");
  data->button->back_select =
    bunny_load_pixelarray("textures/button/back_select.png");
  data->button->minus =
    bunny_load_pixelarray("textures/button/minus.png");
  data->button->minus_select =
    bunny_load_pixelarray("textures/button/minus_select.png");
  data->button->plus =
    bunny_load_pixelarray("textures/button/plus.png");
  data->button->plus_select =
    bunny_load_pixelarray("textures/button/plus_select.png");
}

int				load_textures(t_data *data)
{
  data->menu_screen = bunny_load_pixelarray("textures/menu_screen.png");
  data->mouse = bunny_load_pixelarray("textures/mouse.png");
  if ((data->button = malloc(sizeof(t_button))) == NULL)
    return (-1);
  load_textures2(data);
  data->credits_screen = bunny_load_pixelarray("textures/credits_screen.png");
  data->options_screen = bunny_load_pixelarray("textures/options_screen.png");
  data->wesh_screen = bunny_load_pixelarray("textures/wesh_screen.png");
  data->wesh_sound = bunny_load_music("sounds/wesh.wav");
  data->click_sound = bunny_load_music("sounds/click.wav");
  data->fight_sound = bunny_load_music("sounds/fight.ogg");
  if (check_textures(data) == -1)
    return (-1);
  return (0);
}
