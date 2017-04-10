/*
** main.c for main in /home/hubert_i/rendu/PSU_2015_my_ls
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Thu Nov 26 22:51:57 2015 leo hubert
** Last update Sun Nov 29 21:10:40 2015 leo hubert
*/

#include <stdlib.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

int	main(int argc, char **argv)
{
  char	*dest;
  char	*flags;
  int	counter;
  int	i;
  int	ibis;
  
  dest = "./";
  counter = 1;
  i = 0;
  flags = malloc(count_flag(argc, argv) * sizeof(char));
  while (counter < argc)
    {
      if (argv[counter][0] == '-')
	{
	  ibis = 0;
	  while (argv[counter][ibis++] != 0)
	    flags[i++] = argv[counter][ibis];
	}
      else
	dest = argv[counter];
      counter++;
    }
  my_ls(dest, flags);
  free(flags);
}

int	count_flag(int argc, char **argv)
{
  int	counter;
  int	result;
  
  counter = 1;
  result = 0;
  while (counter < argc)
    {
      if (argv[counter][0] == '-')
	result = result + my_strlen(argv[counter]) - 1;
      counter++;
    }
  return (result);
}
