/*
** check_tab.c for echeck_tab.c in /home/roig_a/rendu/PSU_2015_tetris
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Fri Mar 18 14:01:08 2016 Antoine Roig
** Last update Fri Mar 18 14:01:39 2016 Antoine Roig
*/

#include "tetris.h"

int	check_tab2(int *tab, int e)
{
  tab[0] == tab[1] ? e = 1 : tab[0] == tab[2] ? e = 1 : tab[0] == tab[3] ?
    e = 1 : tab[0] == tab[4] ? e = 1 :  tab[0] == tab[5] ? e = 1 : (e = 0);
  if (e == 1)
    return (e);
  tab[1] == tab[0] ? e = 1 : tab[1] == tab[2] ? e = 1 : tab[1] == tab[3] ?
    e = 1 : tab[1] == tab[4] ? e = 1 :  tab[1] == tab[5] ? e = 1 : (e = 0);
    if (e == 1)
      return (e);
  tab[2] == tab[0] ? e = 1 : tab[2] == tab[1] ? e = 1 : tab[2] == tab[3] ?
    e = 1 : tab[2] == tab[4] ? e = 1 :  tab[2] == tab[5] ? e = 1 : (e = 0);
  if (e == 1)
    return (e);
  tab[3] == tab[0] ? e = 1 : tab[3] == tab[1] ? e = 1 : tab[3] == tab[2] ?
    e = 1 : tab[3] == tab[4] ? e = 1 :  tab[3] == tab[5] ? e = 1 : (e = 0);
  if (e == 1)
    return (e);
  return (e);
}

int	check_tab(int *tab)
{
  int	e;

  e = 0;
  if (check_tab2(tab, e) == 1)
    return (1);
  tab[4] == tab[0] ? e = 1 : tab[4] == tab[1] ? e = 1 : tab[4] == tab[2] ?
    e = 1 : tab[4] == tab[3] ? e = 1 :  tab[4] == tab[5] ? e = 1 : (e = 0);
  if (e == 1)
    return (e);
  tab[5] == tab[0] ? e = 1 : tab[5] == tab[1] ? e = 1 : tab[5] == tab[2] ?
    e = 1 : tab[5] == tab[3] ? e = 1 :  tab[5] == tab[4] ? e = 1 : (e = 0);
  if (e == 1)
    return (e);
  return (e);
}
