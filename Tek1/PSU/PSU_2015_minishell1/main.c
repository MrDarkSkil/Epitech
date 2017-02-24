/*
** main.c for main in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan 19 16:56:38 2016 Léo Hubert
** Last update Sun Jan 24 18:05:00 2016 Léo Hubert
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	sigproc()
{
  signal(SIGINT, sigproc);
  my_putstr("\n");
  my_putstr("$> ");
}

int		main(int ac, char **av, char **env)
{
  t_list	*list;
  char		*arg;

  (void)ac;
  (void)av;
  if (env[0] == NULL)
    return (0);
  my_putstr("$> ");
  signal(SIGINT, sigproc);
  list = init_env(env);
  while ((arg = get_next_line(0)))
    {
      init_command(arg, list);
      free(arg);
      my_putstr("$> ");
    }
  return (0);
}
