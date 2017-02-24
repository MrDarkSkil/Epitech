/*
** check_flags.c for check_flags in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_tetris
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Mon Feb 29 04:27:01 2016 Léo Hubert
** Last update Fri Mar 18 14:07:07 2016 Antoine Roig
*/

#include "tetris.h"

void	fill_tab(t_options *options)
{
  options->tab_key[0] = options->key_left;
  options->tab_key[1] = options->key_right;
  options->tab_key[2] = options->key_turn;
  options->tab_key[3] = options->key_quit;
  options->tab_key[4] = options->key_pause;
  options->tab_key[5] = options->key_drop;
  if (check_tab(options->tab_key) == 1)
    {
      options->key_left = KEY_LEFT;
      options->key_right = KEY_RIGHT;
      options->key_turn = KEY_UP;
      options->key_quit = 'q';
      options->key_pause = 32;
      options->key_drop = KEY_DOWN;
    }
}

char	**get_flags(void)
{
  char	**flags;

  flags = xmalloc(sizeof(char *) * 20);
  flags[0] = "--help";
  flags[1] = "--level";
  flags[2] = "--key-left";
  flags[3] = "--key-right";
  flags[4] = "--key-turn";
  flags[5] = "--key-drop";
  flags[6] = "--key-quit";
  flags[7] = "--key-pause";
  flags[8] = "--map-size";
  flags[9] = "--without-next";
  flags[10] = "--debug";
  flags[11] = "-l";
  flags[12] = "-w";
  flags[13] = "-d";
  flags[14] = "-kl";
  flags[15] = "-kr";
  flags[16] = "-kt";
  flags[17] = "-kd";
  flags[18] = "-kq";
  flags[19] = "-kp";
  return (flags);
}

int	get_pointeurs(int (*p[20])(t_options *options, char *flag))
{
  p[0] = show_help;
  p[1] = change_level;
  p[2] = key_left;
  p[3] = key_right;
  p[4] = key_turn;
  p[5] = key_drop;
  p[6] = key_quit;
  p[7] = key_pause;
  p[8] = change_map;
  p[9] = without_next;
  p[10] = active_debug;
  p[11] = change_level;
  p[12] = without_next;
  p[13] = active_debug;
  p[14] = key_left;
  p[15] = key_right;
  p[16] = key_turn;
  p[17] = key_drop;
  p[18] = key_quit;
  p[19] = key_pause;
  return (0);
}

int	check_flags(t_options	*options,
		    int		ac,
		    char	**av)
{
  int	(*p[20])(t_options *options, char *flag);
  char	**flags;
  int	i;
  int	c;

  c = 0;
  flags = get_flags();
  get_pointeurs(p);
  while (++c != ac)
    {
      i = -1;
      while (++i < 20)
	{
	  if (((i >= 14 && i <= 19) || i == 11) &&
	      (my_strcmp(av[c], flags[i]) == 0 && c + 1 < ac))
	    p[i](options, av[c + 1]);
	  else if (i >= 1 && i <= 8 &&
		   (my_strcmp(take_begin(av[c], '='), flags[i]) == 0))
	    p[i](options, take_after(av[c], '='));
	  else if (my_strcmp(av[c], flags[i]) == 0)
	    p[i](options, av[c]);
	}
    }
  fill_tab(options);
  return (0);
}
