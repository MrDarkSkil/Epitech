/*
** get_next_line.c for get_next_line in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_getnextline
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan  5 09:44:43 2016 leo hubert
** Last update Fri Jan 22 20:05:12 2016 Léo Hubert
*/

#include "../../include/get_next_line.h"

char		*get_next_line(const int fd)
{
  char		*buffer;
  static char	*save = "\0";
  static int	stat = 0;
  t_next	next;

  while (my_strsearch(save, '\n') != 1)
    {
      if ((buffer = malloc(sizeof(char) * READ_SIZE + 1)) == NULL || fd == -1)
	return (NULL);
      if (read(fd, buffer, READ_SIZE) == -1)
	return (NULL);
      if (buffer[0] == 0 && stat == 0)
	{
	  my_show_next_line(&next, save);
	  stat = 1;
	  return (next.result);
	}
      else if (stat == 1)
	return (NULL);
      save = my_fusionstr(save, buffer);
      free(buffer);
    }
  my_show_next_line(&next, save);
  save = next.save;
  return (next.result);
}

void	my_show_next_line(t_next *next, char *save)
{
  int	i;
  char	*result;

  i = 0;
  while (save[i] != '\n' && save[i++] != 0);
  result = malloc(sizeof(char) * i);
  if (result == NULL)
    return ;
  i = 0;
  while (save[i] != '\n' && save[i] != 0)
    {
      result[i] = save[i];
      i++;
    }
  next->save = &save[i + 1];
  next->result = result;
}

char	*my_fusionstr(char *str, char *str2)
{
  char	*result;
  int	counter;
  int	counter2;

  counter = 0;
  counter2 = 0;
  result = malloc(my_strlen(str) + my_strlen(str2) * sizeof(char) + 1);
  if (result == NULL)
    return (NULL);
  while (str[counter] != 0)
    {
      result[counter] = str[counter];
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
