/*
** init_menu.c for init_menu in /home/hubert_i/menu
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 27 11:58:55 2016 Léo Hubert
** Last update Sun Mar 27 12:12:31 2016 Léo Hubert
*/

# include			"graph.h"

void				init_menu(t_data *data)
{
  data->fade.full = BLACK;
  data->pos.x = 0;
  data->pos.y = 0;
  data->display_mouse = 0;
  data->page = 0;
  data->vol_music = 50;
  data->vol_effect = 50;
  music_vol(data);
  effect_vol(data);
}

void				delete_sound(t_data *data)
{
  bunny_delete_sound(&data->music->sound);
  bunny_delete_sound(&data->wesh_sound->sound);
  bunny_delete_sound(&data->click_sound->sound);
  bunny_delete_sound(&data->fight_sound->sound);
}

void				music_vol(t_data *data)
{
  bunny_sound_volume(&data->music->sound, data->vol_music);
}

void				effect_vol(t_data *data)
{
  bunny_sound_volume(&data->wesh_sound->sound, data->vol_effect);
  bunny_sound_volume(&data->click_sound->sound, data->vol_effect);
  bunny_sound_volume(&data->fight_sound->sound, data->vol_effect);
}
