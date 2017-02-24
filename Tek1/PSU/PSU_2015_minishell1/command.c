/*
** command.c for command in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Jan 22 20:10:23 2016 Léo Hubert
** Last update Sun Jan 24 17:32:49 2016 Léo Hubert
*/

#include "my.h"

char	*search_list(t_list *list, char *search)
{
  while (list->first != 1)
    list = list->next;
  if ((my_strcmp(list->key, search)) != 1)
    return (list->str);
  else
    {
      list = list->next;
      while (list->first != 1)
	{
	  if ((my_strcmp(list->key, search)) != 1)
	    return (list->str);
	  list = list->next;
	}
    }
  return (NULL);
}

int	my_unset(t_list *list, char **command)
{
  if (command[1] != NULL)
    {
      while (list->first != 1)
	list = list->next;
      if ((my_strcmp(list->key, command[1])) == 0)
	{
	  delete_maillon(list);
	  return (1);
	}
      list = list->next;
      while (list->first != 1)
	{
	  if ((my_strcmp(list->key, command[1])) == 0)
	    {
	      list = delete_maillon(list);
	      return (1);
	    }
	  list = list->next;
	}
    }
  else
    return (my_error(NULL, "unsetenv: Too few arguments\n"));
  return (0);
}

int	my_set(t_list *list, char **command)
{
  if (command[1] != NULL && command[2] != NULL)
    {
      if ((search_list(list, command[1])) == NULL)
	{
	  add_list(list, command[2], command[1]);
	  return (1);
	}
      else
	{
	  while (my_strcmp(list->key, command[1]) != 0)
	    list = list->next;
	  list->str = command[2];
	}
    }
  else
    return (my_error(NULL, "setenv: Too few arguments\n"));
  return (0);
}

int	my_exit(t_list *list, char **command)
{
  (void)list;
  (void)command;
  my_error(NULL, "exit\n");
  exit(EXIT_SUCCESS);
  return (0);
}

int	check_command(char **command, t_list *list)
{
  int	(*tab[6])();
  char	**tableau;
  int	i;

  i = -1;
  tableau = my_str_to_wordtab("cd exit env unsetenv setenv", ' ');
  tab[0] = my_cd;
  tab[1] = my_exit;
  tab[2] = show_list;
  tab[3] = my_unset;
  tab[4] = my_set;
  while (tableau[++i])
    {
      if ((my_strcmp(tableau[i], command[0])) == 0)
	{
	  tab[i](list, command);
	  return (1);
	}
    }
  return (0);
}
