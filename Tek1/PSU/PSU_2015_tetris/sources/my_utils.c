/*
** my_strlen.c for my_strlen.c in /home/roig_a/rendu/PSU_2015_tetris
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Fri Feb 26 18:26:12 2016 Antoine Roig
** Last update Thu Mar 17 10:43:33 2016 Antoine Roig
*/

#include "tetris.h"

int	my_strlen(char * str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char    *my_strcat(char *dest, char *src)
{
  int   i;
  int   j;
  char  *new;

  j = 0;
  i = my_strlen(dest);
  new = xmalloc(sizeof(char) *(i + my_strlen(src) + 1));
  i = 0;
  while (dest[j])
    new[i++] = dest[j++];
  j = 0;
  while (src[j])
    new[i++] = src[j++];
  new[i] = '\0';
  return (new);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(1, &str[i], 1);
      i++;
    }
  return (1);
}

int     my_show_wordtab(char **tab)
{
  int   i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      write(1, "\n", 1);
      i++;
    }
      write(1, "\n", 1);
  return (0);
}

int     my_strncmp(char *s1, char *s2, int nb)
{
  int   i;

  i = 0;
  while (s1[i] && s2[i] && i < nb)
    {
      if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
