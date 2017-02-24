/*
** get_next_line.c for get_next_line in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_getnextline
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan  5 09:44:43 2016 leo hubert
** Last update Tue Apr 12 11:02:33 2016 Léo Hubert
*/

#include "my.h"

char		*get_next_line(const int fd)
{
  static char	*save = "\0";
  static int	stat = 0;
  t_next	next;

  while (get_search(save, '\n') != 1)
    {
      if (((next.buffer = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
	  || (fd == -1) || ((next.rd = read(fd, next.buffer, READ_SIZE)) == 0)
	  || (next.buffer[0] == '\0'))
	return (NULL);
      next.buffer[next.rd] = '\0';
      if (next.buffer[0] == 0 && stat == 0)
	{
	  my_show_next_line(&next, save);
	  stat = 1;
	  return (next.result);
	}
      else if (stat == 1)
	return (NULL);
      save = get_fusion(save, next.buffer);
      free(next.buffer);
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
  if ((result = malloc(sizeof(char) * i + 1)) == NULL)
    return ;
  i = 0;
  while (save[i] != '\n' && save[i] != 0)
    {
      result[i] = save[i];
      i++;
    }
  result[i] = '\0';
  next->save = &save[i + 1];
  next->result = my_strdup(result);
  free(result);
}

char	*get_fusion(char *str, char *str2)
{
  char	*result;
  int	counter;
  int	counter2;

  counter = 0;
  counter2 = 0;
  if ((result = malloc(my_strlen(str) + my_strlen(str2) + 1)) == NULL)
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
  result[counter] = '\0';
  return (result);
}

int	get_search(char *str, char search)
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
