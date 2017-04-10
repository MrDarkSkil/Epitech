/*
** my_is_prime.c for my_is_prime in /home/hubert_1/rendu/Piscine_C_J05
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Mon Oct  5 18:24:08 2015 leo hubert
** Last update Tue Nov 10 14:56:53 2015 leo hubert
*/

#include "../../include/my.h"

int	my_is_prime(int nombre)
{
  int	counter;

  counter = 2;
  if (nombre <= 1 || ((nombre > 2) && ((nombre % 2) == 0)))
    {
      return (0);
    }
    while (counter < nombre)
      {
	if (nombre % counter == 0)
	  {
	    return (0);
	  }
	counter++;
      }
    return (1);
}
