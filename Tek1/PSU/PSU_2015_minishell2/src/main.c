/*
** main.c for main in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan 19 16:56:38 2016 Léo Hubert
** Last update Tue Apr 12 05:10:40 2016 Léo Hubert
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	print_bash(t_data *data)
{
  (void)data;
  my_putstr("$> ");
}

void	sigproc()
{
  my_putstr("\n");
  print_bash(NULL);
}

char	*epur_str(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '#')
	str[i] = '\0';
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
  return (str);
}

int		main(int ac, char **av, char **env)
{
  t_data	data;
  char		*args;

  (void)ac;
  (void)av;
  if (env[0] == NULL)
    return (-1);
  signal(SIGINT, sigproc);
  data.env = init_env(env);
  print_bash(&data);
  while ((args = get_next_line(0)))
    {
      if (args[0] != '\0')
	{
	  args = epur_str(args);
	  init_commands(&data, args);
	  exec_commands(&data);
	  free_commands(data.commands);
	}
      free(args);
      print_bash(&data);
    }
  free_env(data.env);
  my_error(NULL, "exit\n");
  return (0);
}
