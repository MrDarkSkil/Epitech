/*
** pipes.c for pipes in /home/hubert_i/rendu/2015/PSU/PSU_2015_minishell2
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Apr 12 17:07:23 2016 Léo Hubert
** Last update Tue Apr 12 17:56:39 2016 Léo Hubert
*/

# include	"my.h"

int		exec_commandpipe2(char		**commands,
				  int		fd[2],
				  t_env		*env_list,
				  char		**env)
{
  char		**command2;
  char		*path;
  pid_t		child2;

  env = get_env(env_list);
  command2 = my_str_to_wordtab(commands[1], ' ');
  path = get_path(env_list, command2[0]);
  if (check_command(command2, env_list) == 1)
    return (1);
  if (path[0] == 'P' || path[0] == 'C')
    return (my_error(command2[0], "%s: Command not found.\n"));
  child2 = fork();
  if (child2 == 0)
    {
      close(fd[1]);
      dup2(fd[0], 0);
      execve(path, command2, env);
      return (my_error(NULL, "execve() failed\n"));
    }
  close(fd[0]);
  close(fd[1]);
  wait(&child2);
  return (0);
}

int		exec_commandpipe1(char		**commands,
				  int		fd[2],
				  t_env		*env_list,
				  char		**env)
{
  char		**command1;
  char		*path;
  int		child1;

  command1 = my_str_to_wordtab(commands[0], ' ');
  if (check_command(command1, env_list) == 1)
    return (1);
  path = get_path(env_list, command1[0]);
  if (path[0] == 'P' || path[0] == 'C')
    return (my_error(command1[0], "%s: Command not found.\n"));
  pipe(fd);
  child1 = fork();
  if (child1 == 0)
    {
      close(fd[0]);
      dup2(fd[1], 1);
      execve(path, command1, env);
      return (my_error(NULL, "execve() failed\n"));
    }
  wait(&child1);
  return (0);
}

int		exec_commandpipe(t_data *data)
{
  t_env	*env_list;
  int fd[2];
  char	**env;
  char	**commands;

  env_list = data->env;
  env = get_env(env_list);
  if ((commands = my_str_to_wordtab(data->commands->arg, '|')) == NULL)
    return (my_error(NULL, "Invalid null command.\n"));
  if (commands[0] == NULL || (commands[0][0] == ' '
			      && my_strlen(commands[0]) == 1))
    return (my_error(NULL, "Invalid null command.\n"));
  if (commands[1] == NULL || (commands[1][0] == ' '
			      && my_strlen(commands[1]) == 1))
    return (my_error(NULL, "Invalid null command.\n"));
  exec_commandpipe1(commands, fd, env_list, env);
  exec_commandpipe2(commands, fd, env_list, env);
  return (0);
}
