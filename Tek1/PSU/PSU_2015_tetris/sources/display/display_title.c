/*
** display_tile.c for display_tile.c in /home/roig_a/rendu/PSU_2015_tetris
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sat Mar 19 18:54:02 2016 Antoine Roig
** Last update Sat Mar 19 18:55:12 2016 Antoine Roig
*/

#include "tetris.h"

void	title_bis(int x, int y)
{
  attron(COLOR_PAIR(40));
  mvprintw(x, y, "***");
  mvprintw(x + 1, y, "*");
  mvprintw(x + 1, y + 2, "*");
  mvprintw(x + 2, y + 1, "**");
  mvprintw(x + 3, y + 2, "*");
  mvprintw(x + 3, y, "*");
  mvprintw(x + 4, y + 2, "*");
  mvprintw(x + 4, y, "*");
  y += 4;
  attroff(COLOR_PAIR(40));
  attron(COLOR_PAIR(50));
  mvprintw(x, y, "*");
  mvprintw(x + 2, y, "*");
  mvprintw(x + 3, y, "*");
  mvprintw(x + 4, y, "*");
  y += 2;
  attroff(COLOR_PAIR(50));
  attron(COLOR_PAIR(60));
  mvprintw(x, y, "***");
  mvprintw(x + 1, y, "*");
  mvprintw(x + 2, y, "***");
  mvprintw(x + 3, y + 2, "*");
  mvprintw(x + 4, y, "***");
  attroff(COLOR_PAIR(60));
}

void	title1(int x, int y)
{
  y += 3;
  attroff(COLOR_PAIR(30));
  title_bis(x, y);
}

void	title(int x, int y)
{
  load_title_color();
  attron(COLOR_PAIR(10));
  mvprintw(x, y, "***");
  mvprintw(x + 1, ++y, "*");
  mvprintw(x + 2, y, "*");
  mvprintw(x + 3, y, "*");
  mvprintw(x + 4, y, "*");
  attroff(COLOR_PAIR(10));
  attron(COLOR_PAIR(20));
  y += 3;
  mvprintw(x, y, "***");
  mvprintw(x + 1, y, "*");
  mvprintw(x + 2, y, "**");
  mvprintw(x + 3, y, "*");
  mvprintw(x + 4, y, "***");
  attroff(COLOR_PAIR(20));
  attron(COLOR_PAIR(30));
  y += 4;
  mvprintw(x, y, "***");
  mvprintw(x + 1, ++y, "*");
  mvprintw(x + 2, y, "*");
  mvprintw(x + 3, y, "*");
  mvprintw(x + 4, y, "*");
  title1(x, y);
}
