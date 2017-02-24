/*
** init_tetris.c for init_tetris.c in /home/hubert_i/rendu/2015/PSU_2015_tetris
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Mar  2 01:07:03 2016 Léo Hubert
** Last update Sun Mar 20 21:38:13 2016 Léo Hubert
*/

#include "tetris.h"

void	init_options(t_options	*options, char **av)
{
  options->tab_key = xmalloc(sizeof(int) * 6);
  options->key_left = KEY_LEFT;
  options->key_right = KEY_RIGHT;
  options->key_turn = KEY_UP;
  options->key_quit = 'q';
  options->key_pause = 32;
  options->key_drop = KEY_DOWN;
  options->map_row = 20;
  options->map_col = 10;
  options->level = 1;
  options->without_next = 0;
  options->debug = 0;
  options->scores = -5;
  options->lines = 0;
  options->binary = av[0];
}

int	init_map(t_options *options)
{
  int	y;
  int	x;

  y = -1;
  if ((options->map = xmalloc(sizeof(char *) * options->map_row + 1)) == NULL)
    return (-1);
  while (++y != options->map_row)
    {
      x = -1;
      if ((options->map[y] =
	   xmalloc(sizeof(char) * options->map_col + 1)) == NULL)
	return (-1);
      while (++x != options->map_col + 1)
	options->map[y][x] = '0';
      options->map[y][x - 1] = 'b';
    }
  x = 0;
  if ((options->map[y] = xmalloc(sizeof(char) * options->map_col)) == NULL)
    return (-1);
  while (x != options->map_col)
    options->map[y][x++] = '1';
  return (0);
}

int	show_help(t_options *options)
{
  my_putstr("Usage: ");
  my_putstr(options->binary);
  my_putstr(" [options]\n");
  my_putstr("Options:\n");
  my_putstr("\t--help Display this help\n");
  my_putstr("\t-l --level={num} Start Tetris at level num\n");
  my_putstr("\t-kl --key-left={K} Move tetrimino on LEFT with key K\n");
  my_putstr("\t-kr --key-right={K} Move tetrimino on RIGHT with key K\n");
  my_putstr("\t-kt --key-turn={K} Turn tetrimino with key K\n");
  my_putstr("\t-kd --key-drop={K} Set default DROP on key K\n");
  my_putstr("\t-kq --key-quit={K} Quit program when press key K\n");
  my_putstr("\t-kp --key-pause={K} Pause and restart game when press key K\n");
  my_putstr("\t--map-size={row,col} Set game size at row, col\n");
  my_putstr("\t-w --without-next Hide next tetrimino\n");
  my_putstr("\t-d --debug Debug mode\n");
  exit(0);
  return (0);
}
