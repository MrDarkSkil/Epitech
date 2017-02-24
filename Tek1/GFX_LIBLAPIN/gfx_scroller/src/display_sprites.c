/*
** display_sprites.c for display_sprites in /home/hubert_i/rendu/2015/INFO/gfx_scroller
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Mar 20 06:47:31 2016 Léo Hubert
** Last update Sun Mar 20 20:09:25 2016 Léo Hubert
*/

#include "scroller.h"

void	display_zombieWalk(t_data *data)
{
  data->sprites->zombieWalk->pos->x = data->sprites->zombieBorn->pos->x;
  data->sprites->zombieWalk->pos->y = data->pix->clipable.clip_height - 187;
  tekblit(data->pix, data->sprites->zombieWalk->sprite
	  , data->sprites->zombieWalk->pos);
  data->sprites->zombieWalk = data->sprites->zombieWalk->prev;
}

void	display_zombieBorn(t_data *data)
{
  static int		time_old = 0;
  static int		pos = 0;

  if (pos != -1)
    {
      data->sprites->zombieBorn->pos->y = data->pix->clipable.clip_height
	- 187;
      data->sprites->zombieBorn->pos->x = 500 - pos;
      tekblit(data->pix, data->sprites->zombieBorn->sprite
	      , data->sprites->zombieBorn->pos);
      if (time(NULL) > time_old + 1)
      	{
	  data->sprites->zombieBorn = data->sprites->zombieBorn->prev;
	  time_old = time(NULL);
	}
      pos += 2;
      if (data->sprites->zombieBorn->first == 1)
	pos = -1;
    }
  else
    display_zombieWalk(data);
}

void			display_cloud(t_data *data)
{
  if (data->sprites->cloud->pos->x > data->pix->clipable.clip_width)
    {
      data->sprites->cloud = data->sprites->cloud->next;
      data->sprites->cloud->pos->x =
	-data->sprites->cloud->next->sprite->clipable.clip_width;
    }
  tekblit(data->pix, data->sprites->cloud->sprite, data->sprites->cloud->pos);
  data->sprites->cloud->pos->x += 4;

}
