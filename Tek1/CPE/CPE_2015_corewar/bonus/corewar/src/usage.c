/*
** usage.c for usage.c in /home/roig_a/COREWAR/CPE_2015_corewar/bonus
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sat Mar 26 18:00:41 2016 Antoine Roig
** Last update Sat Mar 26 18:01:16 2016 Antoine Roig
*/

#include "corewar.h"

int	usage()
{
  my_putstr("Usage : ./corewar [-dump nbr_cycle] [[-n prog_number]\
 [-a load_address ] prog_name] ...");
  return (0);
}
