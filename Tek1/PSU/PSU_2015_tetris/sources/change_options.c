/*
** change_key.c for change_key in /home/hubert_i/PSU_2015_tetris
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Feb 27 00:56:55 2016 Léo Hubert
** Last update Tue Mar  8 03:08:24 2016 Léo Hubert
*/

#include "tetris.h"

int	key_left(t_options	*options,
		 char		*flag)
{
  if (flag[0] == ' ' && my_strlen(flag) == 1)
    return (options->key_left = 32);
  if (my_is_num(flag) != -1)
    options->key_left = my_getnbr(flag);
  else if (my_strlen(flag) == 1)
    options->key_left = flag[0];
  else
    return (my_putstr("Error: KeyLeft key not found"));
  return (0);
}

int	key_right(t_options	*options,
		 char		*flag)
{
  if (flag[0] == ' ' && my_strlen(flag) == 1)
    return (options->key_right = 32);
  if (my_is_num(flag) != -1)
    options->key_right = my_getnbr(flag);
  else if (my_strlen(flag) == 1)
    options->key_right = flag[0];
  else
    return (my_putstr("Error: KeyRight key not found"));
  return (0);
}

int	key_turn(t_options	*options,
		 char		*flag)
{
  if (flag[0] == ' ' && my_strlen(flag) == 1)
    return (options->key_turn = 32);
  if (my_is_num(flag) != -1)
    options->key_turn = my_getnbr(flag);
  else if (my_strlen(flag) == 1)
    options->key_turn = flag[0];
  else
    return (my_putstr("Error: KeyTurn key not found"));
  return (0);
}

int	key_drop(t_options	*options,
		 char		*flag)
{
  if (flag[0] == ' ' && my_strlen(flag) == 1)
    return (options->key_drop = 32);
  if (my_is_num(flag) != -1)
    options->key_drop = my_getnbr(flag);
  else if (my_strlen(flag) == 1)
    options->key_drop = flag[0];
  else
    return (my_putstr("Error: KeyDrop key not found"));
  return (0);
}

int	key_quit(t_options	*options,
		 char		*flag)
{
  if (flag[0] == ' ' && my_strlen(flag) == 1)
    return (options->key_quit = 32);
  if (my_is_num(flag) != -1)
    options->key_quit = my_getnbr(flag);
  else if (my_strlen(flag) == 1)
    options->key_quit = flag[0];
  else
    return (my_putstr("Error: KeyQuit key not found"));
  return (0);
}
