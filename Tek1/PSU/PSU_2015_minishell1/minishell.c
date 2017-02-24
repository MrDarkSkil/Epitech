/*
** minishell.c for minishell in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan 19 17:37:08 2016 Léo Hubert
** Last update Sun Jan 24 17:19:35 2016 Léo Hubert
*/

#include "my.h"

int	init_command(char *arg, t_list *list)
{
  pid_t	pid;
  char	**command;
  char	**env;
  char	*path;

  command = my_str_to_wordtab(arg, ' ');
  if (command[0] == NULL)
    return (0);
  env = get_env(list);
  if (check_command(command, list) == 1)
    return (1);
  if (command[0][0] == '.' && command[0][1] == '/')
    return (local_exec(list, command));
  path = get_path(list, command[0]);
  if (path[0] == 'P' || path[0] == 'C')
    return (my_error(command[0], "%s: Command not found.\n"));
  if ((pid = fork()) == 0)
    execve(path, command, env);
  wait(&pid);
  return (0);
}

int	size_list(t_list *list)
{
  int	i;

  i = 0;
  while (list->first != 1)
    list = list->next;
  i++;
  list = list->next;
  while (list->first != 1)
    {
      list = list->next;
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
      tab[y] = my_fusionstr(tab[y], "/");
      tab[y] = my_fusionstr(tab[y], command);
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

char	*get_path(t_list *list, char *command)
{
  while (list->first != 1)
    list = list->next;
  if (list->key[0] == 'P' && list->key[1] == 'A'
      && list->key[2] == 'T' && list->key[3] == 'H')
    return (custom_path(list->str, command));
  else
    {
      list = list->next;
      while (list->first != 1)
	{
	  if (list->key[0] == 'P' && list->key[1] == 'A'
	      && list->key[2] == 'T' && list->key[3] == 'H')
	    return (custom_path(list->str, command));
	  list = list->next;
	}
    }
  return ("P");
}
