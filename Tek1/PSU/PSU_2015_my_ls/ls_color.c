/*
** ls_color.c for my_lscolor in /home/hubert_i/rendu/PSU_2015_my_ls
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Sun Nov 29 20:56:39 2015 leo hubert
** Last update Sun Nov 29 23:22:54 2015 leo hubert
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

int	ls_color(struct dirent *entry)
{
  entry->d_type == 4 ? my_putstr(COLOR_BLUE) : entry->d_type;
  return (0);
}
