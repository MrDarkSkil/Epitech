/*
** check_game.c for check_game in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_Allum1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Feb 13 22:30:19 2016 Léo Hubert
** Last update Sun Feb 14 13:47:49 2016 Léo Hubert
*/

#include "my.h"

int	check_game(t_allum *allum, int player)
{
  int	nb_matches;

  nb_matches = total_matches(allum);
  if (player == 1)
    {
      if (nb_matches == 0)
	{
	  my_putstr("\nYou lost, too bad..\n");
	  return (-1);
	}
    }
  else
    {
      if (nb_matches == 0)
	{
	  my_putstr("\nI lost.. snif.. but I’ll get you next time!!\n");
	  return (-1);
	}
    }
  return (0);
}
