/*
** free.c for fre in /home/hubert_i/rendu/2015/PSU/PSU_2015_minishell2
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Apr 12 16:49:51 2016 Léo Hubert
** Last update Tue Apr 12 16:54:48 2016 Léo Hubert
*/

# include	"my.h"

void		free_env(t_env *env)
{
  while (env->first != 1)
    env = env->next;
  env = env->next->next;
  while (env->first != 1)
    {
      if (env->prev != NULL)
	free(env->prev);
      env = env->next;
    }
  if (env != NULL)
    free(env);
}

void			free_commands(t_commands *commands)
{
  while (commands->first != 1)
    commands = commands->next;
  commands = commands->next->next;
  while (commands->first != 1)
    {
      if (commands->prev != NULL)
	free(commands->prev);
      commands = commands->next;
    }
  if (commands != NULL)
    free(commands);
}
