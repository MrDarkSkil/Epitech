/*
** main.c for main in /home/hubert_i/PSU_2015_tetris
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Feb 26 23:36:12 2016 Léo Hubert
** Last update Fri Mar 18 20:48:06 2016 Antoine Roig
*/

#include "tetris.h"

int	search_high(t_options *options)
{
  int	fd;
  char	*buff;
  int	nb;

  buff = xmalloc(sizeof(char) * 4096);
  if ((fd = open("Score", O_RDONLY)) == -1)
    {
      options->high = 500;
      return (0);
    }
  else
    {
      nb = read(fd, buff, sizeof(buff));
      if (nb == 0)
	{
	  options->high = 500;
	  return (0);
	}
      options->high = my_getnbr(buff);
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_options	*options;
  t_dlist	*list;

  list = NULL;
  if ((options = xmalloc(sizeof(t_options))) == NULL)
    return (-1);
  list = new_list(list);
  init_options(options, av);
  check_flags(options, ac, av);
  search_high(options);
  init_map(options);
  if ((options->tetriminos = load_tetriminos(list)) == NULL)
    return (0);
  if (options->debug == 1)
    debug(options);
  display(options);
  return (0);
}
