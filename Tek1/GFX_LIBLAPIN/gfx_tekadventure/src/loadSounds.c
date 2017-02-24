/*
** loadMusic.c for loadMusic in /home/hubert_i/rendu/2015/INFO/gfx_tekadventure
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Apr 15 16:38:43 2016 Léo Hubert
** Last update Sun Apr 17 17:55:07 2016 Loic Lopez
*/

# include		"tekAdventure.h"

int			loadMusic(t_data *data)
{
  char			*result;

  data->pos.x = 0;
  data->pos.y = 0;
  data->state = 0;
  data->light = 1;
  if ((data->sounds = bunny_malloc(sizeof(t_sounds))) == NULL)
    return (-1);
  if ((result = (char *)bunny_ini_get_field(data->iniSounds,
					    "ambiance", "sound", 0)) == NULL)
    return (-1);
  if ((data->sounds->ambiance = bunny_load_music(result)) == NULL)
    return (-1);
  return (0);
}
