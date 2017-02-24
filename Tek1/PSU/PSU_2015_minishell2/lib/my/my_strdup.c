/*
** my_strdup.c for my_strdup in /home/hubert_i/rendu/2015/PSU/PSU_2015_minishell2
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Wed Apr  6 21:06:55 2016 Léo Hubert
** Last update Wed Apr  6 21:09:24 2016 Léo Hubert
*/

#include "../../include/my.h"

char	*my_strdup(char *src)
{
  char	*result;

  if ((result = malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  return (my_strcpy(result, src));
}
