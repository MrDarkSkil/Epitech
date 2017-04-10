/*
** IA.c for IA in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_Allum1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Feb 13 22:10:31 2016 Léo Hubert
** Last update Mon Feb 15 15:07:01 2016 Léo Hubert
*/

#include "my.h"

int	total_matches(t_allum *allum)
{
  int	total;

  total = 0;
  while (allum->first != 1)
    allum = allum->next;
  total += allum->nb_allum;
  allum = allum->next;
  while (allum->first != 1)
    {
      total += allum->nb_allum;
      allum = allum->next;
    }
  return (total);
}

int	remove_IA(t_allum *allum)
{
  int	nb;

  if (total_matches(allum) == 2)
    allum->nb_allum -= 1;
  else
    {
      nb = 1 + rand()%allum->nb_allum;
      allum->nb_allum -= nb;
    }
  my_putstr("\n\nAI's turn...\nAI removed ");
  my_put_nbr(nb);
  my_putstr(" match(es) from line ");
  my_put_nbr(allum->etage + 1);
  my_putchar('\n');
  display_allum1(allum);
  if (check_game(allum, 0) == -1)
    return (-1);
  return (0);
}

int	IA(t_allum *allum)
{
  int	nb;
  int	nb_etage;

  nb_etage = count_allum(allum);
  nb = rand()%nb_etage;
  while (allum->etage != nb)
    allum = allum->next;
  if (allum->nb_allum >= 1)
    return (remove_IA(allum));
  allum = allum->next;
  while (allum->etage != nb)
    {
      if (allum->nb_allum >= 1)
	return (remove_IA(allum));
      allum = allum->next;
    }
  return (0);
}
