/*
** error.c for error in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_BSQ
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Fri Dec 11 14:07:20 2015 leo hubert
** Last update Fri Dec 18 18:10:11 2015 leo hubert
*/

#include "my.h"

void	usage()
{
  my_putstr("Usage: ./bsq 'dest_file_map'\n");
}

int	error_openfile()
{
  my_putstr("Error: Cannot open file \n");
  return (0);
}

int	not_filemap()
{
  my_putstr("Error: This file is not a map\n");
  return (0);
}
