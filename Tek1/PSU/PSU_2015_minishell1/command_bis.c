/*
** command_bis.c for command_bis in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 24 14:34:08 2016 Léo Hubert
** Last update Sun Jan 24 17:22:31 2016 Léo Hubert
*/

#include "my.h"

int	local_exec(t_list *list, char **command)
{
  pid_t	pid;
  int	fd;
  char	**env;
  char	*path;
  char	*pwd;

  env = get_env(list);
  pwd = search_list(list, "PWD");
  if (pwd[my_strlen(pwd) - 1] != '/')
    pwd = my_fusionstr(pwd, "/");
  path = my_fusionstr(pwd, &command[0][2]);
  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (my_error(command[0], "%s: Command not found.\n"));
  if ((pid = fork()) == 0)
    execve(path, command, env);
  wait(&pid);
  return (0);
}
