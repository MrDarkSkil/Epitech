/*
** minishell.c for minishell in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan 19 17:37:08 2016 Léo Hubert
** Last update Tue Apr 12 06:42:51 2016 Léo Hubert
*/

#include "my.h"

int	exec_command(t_data *data)
{
  t_env	*env_list;
  pid_t	pid;
  char	**command;
  char	**env;
  char	*path;

  env_list = data->env;
  command = data->commands->command;
  if (command[0] == NULL)
    return (0);
  env = get_env(env_list);
  if (check_command(command, env_list) == 1)
    return (1);
  if (command[0][0] == '.' && command[0][1] == '/')
    return (local_exec(env_list, command));
  path = get_path(env_list, command[0]);
  if (path[0] == 'P' || path[0] == 'C')
    return (my_error(command[0], "%s: Command not found.\n"));
  if ((pid = fork()) == 0)
    execve(path, command, env);
  wait(&pid);
  return (0);
}

int	size_env(t_env *env)
{
  int	i;

  i = 0;
  while (env->first != 1)
    env = env->next;
  i++;
  env = env->next;
  while (env->first != 1)
    {
      env = env->next;
      i++;
    }
  return (i);
}

int	check_path(char *check)
{
  int	fd;

  fd = open(check, O_RDONLY);
  if (fd == -1)
    return (-1);
  return (1);
}

char	*custom_path(char *str, char *command)
{
  char	**tab;
  char	*result;
  int	y;

  y = 0;

  tab = my_str_to_wordtab(str, ':');
  result = NULL;
  while (tab[y] != NULL)
    {
      tab[y] = get_fusion(tab[y], "/");
      tab[y] = get_fusion(tab[y], command);
      if (check_path(tab[y]) == 1)
      	result = tab[y];
      y++;
    }
  if (result == NULL)
    return ("C");
  else
    return (result);
  return (NULL);
}

char	*get_path(t_env *env, char *command)
{
  while (env->first != 1)
    env = env->next;
  if (env->key[0] == 'P' && env->key[1] == 'A'
      && env->key[2] == 'T' && env->key[3] == 'H')
    return (custom_path(env->str, command));
  else
    {
      env = env->next;
      while (env->first != 1)
	{
	  if (env->key[0] == 'P' && env->key[1] == 'A'
	      && env->key[2] == 'T' && env->key[3] == 'H')
	    return (custom_path(env->str, command));
	  env = env->next;
	}
    }
  return ("P");
}
