/*
** env.c for env in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Jan 22 18:19:22 2016 Léo Hubert
** Last update Fri Jan 22 18:24:21 2016 Léo Hubert
*/

#include "my.h"

char	**get_env(t_list *list)
{
  char	**result;
  int	y;

  y = 0;
  if ((result = malloc(sizeof(char *) * size_list(list) + 1)) == NULL)
    return (NULL);
  while (list->first != 1)
    list = list->next;
  result[y] = my_fusionstr(list->key, "=");
  result[y] = my_fusionstr(result[y], list->str);
  y++;
  list = list->next;
  while (list->first != 1)
    {
      result[y] = my_fusionstr(list->key, "=");
      result[y] = my_fusionstr(result[y], list->str);
      y++;
      list = list->next;
    }
  result[++y] = NULL;
  return (result);
}

t_list   	*init_env(char **env)
{
  t_list	*list;
  char		*key;
  int		i;
  int		ibis;

  list = NULL;
  i = 0;
  while (env[i] != NULL)
    {
      ibis = 0;
      while (env[i][ibis++] != '=');
      if ((key = malloc(sizeof(char) * ibis)) == NULL)
	return (NULL);
      ibis = 0;
      while (env[i][ibis] != '=')
	{
	  key[ibis] = env[i][ibis];
	  ibis++;
	}
      list = add_list(list, &env[i][ibis + 1], key);
      i++;
    }
  return (list);
}
