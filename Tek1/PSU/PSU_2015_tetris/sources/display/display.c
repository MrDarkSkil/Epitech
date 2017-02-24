/*
** display.c for display in /home/hubert_i/rendu/2015/PSU/PSU_2015_tetris
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Mar  8 00:26:12 2016 Léo Hubert
** Last update Sun Mar 20 14:26:51 2016 Antoine Roig
*/

#include "tetris.h"

int	old_time = 0;

void	display_score(t_options *options)
{
  static int	timer;

  if (old_time == 0)
    old_time = time(NULL);
  mvwprintw(options->windows->scores, 2, 1, "Hight Score \t%d", options->high);
  mvwprintw(options->windows->scores, 3, 1, "Score\t\t%d", options->scores);
  mvwprintw(options->windows->scores, 5, 1, "Lines\t\t%d", options->lines);
  mvwprintw(options->windows->scores, 6, 1, "Level\t\t%d", options->level);
  get_time(time(NULL) - old_time, options);
  if ((time(NULL) - old_time) != timer)
    {
      if (check_colision_down(options) == 1)
	{
	  options->down = 1;
	  put_in_map(options);
	}
      options->current->pos_y++;
      timer = time(NULL) - old_time;
      display_tetris(options);
      wrefresh(options->windows->tetris);
    }
  wrefresh(options->windows->scores);
}

int	options_down(t_options *options)
{
  options->down = 2;
  return (0);
}

int		put_in_map(t_options *options)
{
  char		**tetrimino;
  int		y;
  int		x;

  y = -1;
  tetrimino = options->current->tetriminos[options->current->position];
  wattron(options->windows->tetris, COLOR_PAIR(options->current->color));
  while (++y < options->current->height)
    {
      x = -1;
      while (++x < options->current->width)
	if (!(tetrimino[y][x] == ' '))
	  {
	    if (options->map[options->current->pos_y + y - 1]
		[options->current->pos_x + x - 1] != '0')
	      return (options_down(options));
	    mvwprintw(options->windows->tetris, options->current->pos_y + y,
		      options->current->pos_x + x, "%c", '*');
	    options->map[options->current->pos_y + y - 1]
	      [options->current->pos_x + x - 1] = options->current->color;
	  }
    }
  wattroff(options->windows->tetris, COLOR_PAIR(options->next->color));
  wrefresh(options->windows->tetris);
  return (0);
}

void	check_key(t_options *options, int key)
{
  int	pause;
  int	time_pause;

  pause = 0;
  if (key == options->key_left)
    colision_left(options);
  else if (key == options->key_right)
    colision_right(options);
  else if (key == options->key_turn)
    colision_rotate(options);
  else if (key == options->key_drop)
    drop(options);
  else if (key == options->key_pause)
    {
      pause = 1;
      time_pause = time(NULL);
      while (pause != 0)
      	{
      	  if (getch() == options->key_pause)
	    {
	      pause = 0;
	      old_time += (time(NULL) - time_pause);
	    }
      	}
    }
}

int		display(t_options *options)
{
  int		key;

  options->windows = xmalloc(sizeof(t_windows));
  init_display(options);
  while (key != options->key_quit)
    {
      if (options->down == 1)
	option_down(options);
      if (check_windows(options) == -1)
      	{
      	  endwin();
      	  return (my_putstr("Error: Fenetre trop petite\n"));
      	}
      simple_aff(options);
      key = getch();
      check_key(options, key);
      if (options->current->pos_y >
	  (options->map_row - options->current->height / 2))
	options->down = 1;
      if (options->down == 2)
	end_game(options);
    }
  endwin();
  return (0);
}
