/*
** scare.c for scare in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_BSQ
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Fri Dec 18 17:59:29 2015 leo hubert
** Last update Fri Dec 18 18:13:49 2015 leo hubert
*/

#include "my.h"

int	save_scare(t_scare *scare, t_pos *pos, int size)
{
  if (size > scare->size)
    {
      scare->bas_x = pos->max_x;
      scare->bas_y = pos->max_y;
      scare->haut_x = pos->cur_x;
      scare->haut_y = pos->cur_y;
      scare->size = pos->size;
    }
  return (0);
}
