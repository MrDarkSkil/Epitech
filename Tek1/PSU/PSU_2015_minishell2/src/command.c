/*
** command.c for command in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Jan 22 20:10:23 2016 Léo Hubert
** Last update Tue Apr 12 17:01:59 2016 Léo Hubert
*/

#include	"my.h"

char		*search_env(t_env *env, char *search)
{
  while (env->first != 1)
    env = env->next;
  if ((my_strncmp(env->key, search, my_strlen(search))) == 0)
    return (env->str);
  else
    {
      env = env->next;
      while (env->first != 1)
	{
	  if ((my_strncmp(env->key, search, my_strlen(search))) == 0)
	    return (env->str);
	  env = env->next;
	}
    }
  return (NULL);
}

int		my_unset(t_env *env, char **command)
{
  if (command[1] != NULL)
    {
      while (env->first != 1)
	env = env->next;
      if ((my_strncmp(env->key, command[1], my_strlen(command[1]))) == 0)
	{
	  delete_maillon(env);
	  return (1);
	}
      env = env->next;
      while (env->first != 1)
	{
	  if ((my_strncmp(env->key, command[1], my_strlen(command[1]))) == 0)
	    {
	      env = delete_maillon(env);
	      return (1);
	    }
	  env = env->next;
	}
    }
  else
    return (my_error(NULL, "unsetenv: Too few arguments\n"));
  return (0);
}

int		my_set(t_env *env, char **command)
{
  if (command[1] == NULL)
    return (show_env(env));
  if (command[1] != NULL && command[2] != NULL)
    {
      if ((search_env(env, command[1])) == NULL)
	{
	  add_env(env, command[2], command[1]);
	  return (1);
	}
      else
	{
	  while (my_strncmp(env->key, command[1], my_strlen(command[1])) != 0)
	    env = env->next;
	  env->str = command[2];
	}
    }
  else
    return (my_error(NULL, "setenv: Too few arguments\n"));
  return (0);
}

int		my_exit(t_env *env, char **command)
{
  (void)env;
  (void)command;
  if (command[1] != NULL)
    {
      if (my_str_isnum(command[1]) == 1)
	{
	  my_error(NULL, "exit\n");
	  free_env(env);
	  exit(my_getnbr(command[1]));
	}
      else
	my_error(NULL, "exit: Expression Syntax\n");
    }
  else
    {
      my_error(NULL, "exit\n");
      free_env(env);
      exit(0);
    }
  return (0);
}

int	check_command(char **command, t_env *env)
{
  int	(*tab[6])();
  char	**tableau;
  int	i;

  i = -1;
  tableau = my_str_to_wordtab("cd exit env unsetenv setenv", ' ');
  tab[0] = my_cd;
  tab[1] = my_exit;
  tab[2] = show_env;
  tab[3] = my_unset;
  tab[4] = my_set;
  while (tableau[++i])
    {
      if ((my_strncmp(tableau[i], command[0], my_strlen(tableau[i]))) == 0
	  && my_strlen(tableau[i]) == my_strlen(command[0]))
	{
	  tab[i](env, command);
	  return (1);
	}
    }
  return (0);
}
