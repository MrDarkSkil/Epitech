/*
** bsq.c for bsq in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_BSQ
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Fri Dec 18 00:17:19 2015 leo hubert
** Last update Fri Dec 18 18:13:33 2015 leo hubert
*/

#include "my.h"

int	my_putin_tab(char *buffer, t_bsq *bsq)
{
  int	i;
  int	y;
  int	x;
  char	**tab;

  tab = malloc(sizeof(char *) * bsq->nb_lines);
  i = 0;
  x = 0;
  y = 0;
  while (buffer[i] != '\0')
    {
      tab[y] = malloc(sizeof(char *) * bsq->size_line);
      while (buffer[i] != '\n')
	{
	  tab[y][x] = buffer[i];
	  x++;
	  i++;
	}
      tab[y][x] = '\n';
      x = 0;
      y++;
      i++;
    }
  bsq->tab = tab;
  return (0);
}

int	my_bsq(t_bsq *bsq, t_scare *scare)
{
  t_pos		pos;
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (x != bsq->size_line && y != bsq->nb_lines)
    {
      while (x != bsq->size_line)
	{
	  if (bsq->tab[y][x] == '.')
	    {
	      pos.cur_x = x;
	      pos.cur_y = y;
	      if (x < bsq->size_line / 2 && y < bsq->nb_lines / 2)
		search_scare(bsq, &pos, scare);
	    }
	  x++;
	}
      x = 0;
      y++;
    }
  make_scare(bsq, scare);
  my_show_bsq(bsq);
  return (0);
}

int	make_scare(t_bsq *bsq, t_scare *scare)
{
  int	size;
  int	x;
  int	y;

  x = scare->haut_x;
  y = scare->haut_y;
  size = scare->bas_y - scare->haut_y;
  while (x < scare->bas_x + size && y < scare->bas_y)
    {
      while (x != scare->bas_x + size)
	{
	  bsq->tab[y][x] = 'X';
	  x++;
	}
      x = scare->bas_x;
      y++;
    }
  return (0);
}

int	search_scare(t_bsq *bsq, t_pos *pos, t_scare *scare)
{
  int	x;
  int	y;
  int	size;
  int	set;

  x = pos->cur_x;
  y = pos->cur_y;
  size = 1;
  set = 0;
  while (bsq->tab[y][x] != 'o' && set != 1)
    {
      pos->max_x = x;
      pos->max_y = y;
      pos->size = size;
      x = pos->cur_x;
      y = pos->cur_y;
      while (y < pos->cur_y + size && bsq->tab[y][x] != 'o')
	{
	  while (x < pos->cur_x + size && bsq->tab[y][x] != 'o')
	    {
	      if (bsq->tab[y][x++ + 1] == 'o')
		set = 1;
	    }
	  x = pos->cur_x;
	  y++;
	}
      if (set != 1)
	size++;
    }
  save_scare(scare, pos, size);
  return (0);
}

int	my_show_bsq(t_bsq *bsq)
{
  int	y;

  y = 0;
  while (y < bsq->nb_lines)
    {
      my_putstr(bsq->tab[y]);
      y++;
    }
  return (0);
}
