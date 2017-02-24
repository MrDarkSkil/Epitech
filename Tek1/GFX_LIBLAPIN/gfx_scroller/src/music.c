/*
** music.c for music in /home/hubert_i/rendu/2015/INFO/gfx_scroller
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 20 04:58:48 2016 Léo Hubert
** Last update Sun Mar 20 20:09:27 2016 Léo Hubert
*/

#include "scroller.h"

int	load_music(t_data *data)
{
  if ((data->sounds->sample = bunny_load_ini("sounds/beverly.bsf")) == NULL)
    return (-1);
  if ((data->sounds->music =
    bunny_load_effect(bunny_ini_get_field(data->sounds->sample, "track1",
					  "sample", 0))) == NULL)
    return (-1);
  return (0);
}

void		play_music(t_data *data)
{
  double	ratio;

  if (data->sounds->duration == 0)
    {
      if (bunny_ini_get_field(data->sounds->sample,
      			      "track1", "frequency", data->sounds->i) == NULL)
      	data->sounds->i = 0;
      ratio = atof(bunny_ini_get_field(data->sounds->sample,
      				       "track1", "frequency", data->sounds->i))
	/ ((double)data->sounds->music->sample_per_second / 100.0);
      data->sounds->duration = atoi(bunny_ini_get_field(data->sounds->sample,
      							"track1", "duration",
							data->sounds->i)) * 60 / 4000;
      bunny_sound_pitch(&data->sounds->music->sound, ratio);
      bunny_sound_play(&data->sounds->music->sound);
      data->sounds->i++;
    }
  else
    data->sounds->duration--;
}
