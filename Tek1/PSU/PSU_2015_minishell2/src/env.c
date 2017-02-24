/*
** env.c for env in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Jan 22 18:19:22 2016 Léo Hubert
** Last update Tue Apr 12 11:12:50 2016 Léo Hubert
*/

#include "my.h"

char	**get_env(t_env *env)
{
  char	**result;
  int	y;

  y = 0;
  if ((result = malloc(sizeof(char *) * size_env(env))) == NULL)
    return (NULL);
  while (env->first != 1)
    env = env->next;
  result[y] = get_fusion(env->key, "=");
  result[y] = get_fusion(result[y], env->str);
  y++;
  env = env->next;
  while (env->first != 1)
    {
      result[y] = get_fusion(env->key, "=");
      result[y] = get_fusion(result[y], env->str);
      y++;
      env = env->next;
    }
  result[y - 1] = NULL;
  return (result);
}

t_env   	*init_env(char **env)
{
  t_env		*env_list;
  char		*key;
  int		i;
  int		ibis;

  env_list = NULL;
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
      env_list = add_env(env_list, &env[i][ibis + 1], key);
      i++;
    }
  return (env_list);
}
