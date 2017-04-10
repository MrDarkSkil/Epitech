/*
** main.c for main in /home/hubert_i/rendu/PSU_2015_my_popup
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Thu Dec  3 14:28:24 2015 leo hubert
** Last update Sat Dec 12 22:23:11 2015 leo hubert
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "my_select.h"

int		main(int argc, char **argv)
{
  t_list	*list;

  if (argc > 1)
    {
      list = my_select_init(argc, argv);
      my_select_show(list, argc);
    }
  else
    return (usage());
  return (0);
}

int	usage()
{
  my_putstr("Usage: ./my_select option1 option2 [...]\n");
  return (0);
}

int	my_select_show(t_list *list, int argc)
{
  int	key;

  argc--;
  newterm(NULL, stderr, stdin);
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  while (key != 27)
    {
      clear();
      show_list(list);
      refresh();
      key = getch();
      list = key_action(list, key);
    }
  endwin();
  return (0);
}

t_list	*key_action(t_list *list, int key)
{
  key == 32 ? list = select_target(list)
    : key == KEY_UP ? list = up_buttom(list)
    : key == KEY_DOWN ? list = down_buttom(list)
    : key == 10 ? list = enter_buttom(list)
    : key == KEY_BACKSPACE ? list = delete_target(list)
    : key == KEY_DC ? list = delete_target(list)
    : list;
  return (list);
}

t_list		*my_select_init(int argc, char **argv)
{
  t_list	*list;
  int		i;

  i = 1;
  list = NULL;
  while (i < argc)
    {
      list = add_list(list, argv[i]);
      i++;
    }
  return (list);
}
