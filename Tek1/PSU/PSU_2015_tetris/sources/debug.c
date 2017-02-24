/*
** debug.c for debug.c in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_tetris
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Mon Feb 29 04:27:55 2016 Léo Hubert
** Last update Thu Mar 17 10:35:42 2016 Antoine Roig
*/

#include "tetris.h"

int	active_debug(t_options	*options,
		     char	*flag)
{
  options->debug = 1;
  (void)flag;
  return (0);
}

void	print_debugkey(int key)
{
  (key == 32) ? my_putstr("(space)") :
    (key == KEY_LEFT) ? my_putstr("^E[C") :
    (key == KEY_RIGHT) ? my_putstr("^E[D") :
    (key == KEY_UP) ? my_putstr("^E[U") :
    (key == KEY_DOWN) ? my_putstr("^E[R") :
    (key == KEY_DC) ? my_putstr("^E")
    : my_putchar(key);
}

int	debug(t_options	*options)
{
  my_putstr("*** DEBUG MODE ***\n");
  my_putstr("Key Left : ");
  print_debugkey(options->key_left);
  my_putstr("\nKey Right : ");
  print_debugkey(options->key_right);
  my_putstr("\nKey Turn : ");
  print_debugkey(options->key_turn);
  my_putstr("\nKey Drop : ");
  print_debugkey(options->key_drop);
  my_putstr("\nKey Quit : ");
  print_debugkey(options->key_quit);
  my_putstr("\nKey Pause : ");
  print_debugkey(options->key_pause);
  my_putstr("\nNext : ");
  (options->without_next == 1) ? my_putstr("No") : my_putstr("Yes");
  my_putstr("\nLevel : ");
  my_put_nbr(options->level);
  my_putstr("\nSize : ");
  my_put_nbr(options->map_row);
  my_putchar('*');
  my_put_nbr(options->map_col);
  debug_tetriminos(options);
  return (0);
}

void			press_any_key()
{
  static struct termios	oldkey;
  static struct termios	key;

  ioctl(0, TCGETS, &oldkey);
  ioctl(0, TCGETS, &key);
  key.c_lflag &= ~ICANON;
  ioctl(0, TCSETS, &key);
  my_putstr("Press any key to start tetris\n");
  read(0, NULL, 1);
  ioctl(0, TCSETS, &oldkey);
}
