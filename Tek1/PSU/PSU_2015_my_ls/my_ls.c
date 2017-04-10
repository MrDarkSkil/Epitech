/*
** my_ls.c for my_ls in /home/hubert_i/rendu/PSU_2015_my_ls
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Sun Nov 29 05:49:59 2015 leo hubert
** Last update Sun Nov 29 21:04:29 2015 leo hubert
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

int	my_ls(char *dest, char *flags)
{
  DIR           *dirp;
  struct dirent *entry;
  
  dirp = opendir(dest);
  if (dirp == NULL)
    return (my_printf("Error: No such file or directory\n"));
  while ((entry = readdir(dirp)) != NULL)
    {
      if (entry == NULL)
	exit (0);
      show_ls(entry, flags, dest);
    }
  return (0);
}

int	show_ls(struct dirent *entry, char *flags, char *dest)
{
  if (my_strsearch(flags, 'a') != 1)
    if (entry->d_name[0] == '.' )
      return (0);
  if (my_strsearch(flags, 'l') == 1)
    ls_show_detail(entry, dest);
  ls_color(entry);
  my_putstr(entry->d_name);
  my_putstr(COLOR_RESET);
  my_putchar('\n');
  return (0);
}

int	ls_show_detail(struct dirent *entry, char *dest)
{
  struct stat sb;
  char *destination;

  destination = my_fusionstr(dest, entry->d_name);
  if (stat(destination, &sb) == -1)
    return (my_printf("Error: Info file %s\t", destination));
  my_printf( (S_ISDIR(sb.st_mode)) ? "d" : "-");
  my_printf( (sb.st_mode & S_IRUSR) ? "r" : "-");
  my_printf( (sb.st_mode & S_IWUSR) ? "w" : "-");
  my_printf( (sb.st_mode & S_IXUSR) ? "x" : "-");
  my_printf( (sb.st_mode & S_IRGRP) ? "r" : "-");
  my_printf( (sb.st_mode & S_IWGRP) ? "w" : "-");
  my_printf( (sb.st_mode & S_IXGRP) ? "x" : "-");
  my_printf( (sb.st_mode & S_IROTH) ? "r" : "-");
  my_printf( (sb.st_mode & S_IWOTH) ? "w" : "-");
  my_printf( (sb.st_mode & S_IXOTH) ? "x" : "-");
  my_printf(" %d %d %d %d ", sb.st_nlink , sb.st_uid, sb.st_gid, sb.st_size);
  return (0);
}

char	*my_fusionstr(char *str, char *str2)
{
  char	*result;
  int	counter;
  int	counter2;

  counter = 0;
  counter2 = 0;
  result = malloc(my_strlen(str) + my_strlen(str2) * sizeof(char *) + 1);
  while (str[counter] != 0)
    {
      result[counter] = str[counter];
      counter++;
    }
  if (str[my_strlen(str) - 1] != '/')
    {
      result[counter] = '/';
      counter++;
    }
  while (str2[counter2] != 0)
    {
      result[counter] = str2[counter2];
      counter2++;
      counter++;
    }
  return (result);
}

int	my_strsearch(char *str, char search)
{
  int	counter;

  counter = 0;
  while (str[counter] != 0)
    {
      if (str[counter] == search)
	return (1);
      counter++;
    }
  return (0);
}
