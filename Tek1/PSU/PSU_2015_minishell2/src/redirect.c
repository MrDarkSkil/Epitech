/*
** redirect.c for redirect in /home/hubert_i/rendu/2015/PSU/PSU_2015_minishell2
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Apr 12 18:16:20 2016 Léo Hubert
** Last update Tue Apr 12 18:17:41 2016 Léo Hubert
*/

# include		"my.h"

int			exec_commandredirect(t_data *data)
{
  t_env			*env_list;
  t_bin			bin;

  bin.commands = my_str_to_wordtab(data->commands->arg, '>');
  bin.command = my_str_to_wordtab(bin.commands[0], ' ');
  if (bin.command[0] == NULL || bin.commands[1] == NULL)
    return (0);
  bin.file = bin.commands[1];
  bin.file = &bin.file[1];
  bin.file[my_strlen(bin.file) - 1] = '\0';
  env_list = data->env;
  bin.env = get_env(env_list);
  if (check_command(bin.command, env_list) == 1)
    return (1);
  bin.path = get_path(env_list, bin.command[0]);
  if (bin.path[0] == 'P' || bin.path[0] == 'C')
    return (my_error(bin.command[0], "%s: Command not found.\n"));
  if ((bin.pid = fork()) == 0)
    {
      bin.fd = open(bin.file, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
      dup2(bin.fd, 1);
      execve(bin.path, bin.command, bin.env);
    }
  wait(&bin.pid);
  return (0);
}

int			exec_commandredirect2(t_data *data)
{
  t_env			*env_list;
  t_bin			bin;

  bin.commands = my_str_to_wordtab(data->commands->arg, '>');
  bin.command = my_str_to_wordtab(bin.commands[0], ' ');
  if (bin.command[0] == NULL || bin.commands[1] == NULL)
    return (0);
  bin.file = bin.commands[1];
  bin.file = &bin.file[1];
  bin.file[my_strlen(bin.file) - 1] = '\0';
  env_list = data->env;
  bin.env = get_env(env_list);
  if (check_command(bin.command, env_list) == 1)
    return (1);
  bin.path = get_path(env_list, bin.command[0]);
  if (bin.path[0] == 'P' || bin.path[0] == 'C')
    return (my_error(bin.command[0], "%s: Command not found.\n"));
  if ((bin.pid = fork()) == 0)
    {
      bin.fd = open(bin.file, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
      dup2(bin.fd, 1);
      execve(bin.path, bin.command, bin.env);
    }
  wait(&bin.pid);
  return (0);
}
