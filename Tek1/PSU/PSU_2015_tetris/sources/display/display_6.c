/*
** display_6.c for display_6.c in /home/roig_a/rendu/PSU_2015_tetris
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sun Mar 20 14:15:02 2016 Antoine Roig
** Last update Sun Mar 20 14:26:58 2016 Antoine Roig
*/

#include "tetris.h"

void	init_display(t_options *options)
{
  newterm(NULL, stderr, stdin);
  curs_set(0);
  noecho();
  choose_next(options);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  load_color();
  options->windows->tetris = subwin(stdscr, options->map_row + 2,
				    options->map_col + 2, 0, 25);
  options->windows->scores = subwin(stdscr, 11, 25, 7, 0);
  options->down = 1;

}

void	option_down(t_options *options)
{
  options->scores += 5;
  options->current = options->next;
  choose_next(options);
  clear();
  options->windows->next = subwin(stdscr, (options->next->height
 + 1 > 5 ? options->next->height + 2 : options->next->height + 2),
 (options->next->width + 2 > 7 ? options->next->width
  + 4 : options->next->width + 4), 0, options->map_col + 28);
  box(options->windows->next, ACS_VLINE, ACS_HLINE);
  mvwprintw(options->windows->next, 0, 1, "Next");
  title(0, 0);
  box(options->windows->tetris, ACS_VLINE, ACS_HLINE);
  refresh();
  check_game(options);
  display_next(options);
  display_map(options);
  display_tetris(options);
  options->down--;
}

void	simple_aff(t_options *options)
{
  box(options->windows->scores, ACS_VLINE, ACS_HLINE);
  attron(COLOR_PAIR(70));
  attroff(COLOR_PAIR(70));
  display_map(options);
  display_score(options);
  attron(COLOR_PAIR(5));
  mvprintw(LINES - 1, 0, "EpiTetris(c) - 2015");
  attroff(COLOR_PAIR(5));
}

void	end_game(t_options *options)
{
  int	fd;

  endwin();
  my_putstr("Game Over\n");
  fd = open("Score", O_CREAT | O_TRUNC | O_WRONLY,
	    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (options->scores > options->high)
    my_put_nbr_file(options->scores, fd);
  exit(EXIT_SUCCESS);
}
