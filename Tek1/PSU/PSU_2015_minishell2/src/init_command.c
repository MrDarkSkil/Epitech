/*
** init_command.c for init_command.c in /home/hubert_i/rendu/2015/PSU/PSU_2015_minishell2
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Fri Apr  8 12:36:00 2016 Léo Hubert
** Last update Tue Apr 12 18:16:40 2016 Léo Hubert
*/

# include		"my.h"

char			*getTab(char **tab)
{
  int			i;
  char			*result;

  i = 0;
  result = "\0";
  while (tab[i])
    {
      result = get_fusion(result, tab[i]);
      result = get_fusion(result, " ");
      i++;
    }
  return (result);
}

t_commands		*add_command(t_commands *commands, char **command)
{
  t_commands		*newelem;

  if ((newelem = malloc(sizeof(t_commands))) == NULL)
    return (NULL);
  newelem->command = command;
  newelem->arg = getTab(command);
  newelem->first = 0;
  newelem->next = NULL;
  newelem->prev = NULL;
  if (commands == NULL)
    {
      newelem->first = 1;
      newelem->next = newelem;
      newelem->prev = newelem;
    }
  else
    {
      while (commands->first != 1)
	commands = commands->next;
      newelem->prev = commands->prev;
      newelem->next = commands;
      commands->prev->next = newelem;
      commands->prev = newelem;
    }
  return (newelem);
}

int			init_commands(t_data *data, char *args)
{
  char			**commands;
  int			i;

  data->commands = NULL;
  commands = my_str_to_wordtab(args, ';');
  i = 0;
  while (commands[i])
    {
      data->commands = add_command(data->commands,
				   my_str_to_wordtab(commands[i], ' '));
      i++;
    }
  data->commands = data->commands->next;
  return (0);
}

int			check_pipe(char **tab)
{
  int			y;

  y = 0;
  while (tab[y])
    {
      if (get_search(tab[y], '|'))
	return (1);
      if (get_search(tab[y], '>'))
	return (3);
      y++;
    }
  return (0);
}

int			exec_commands(t_data *data)
{
  int			pipe;

  while (data->commands->first != 1)
    data->commands = data->commands->next;
  if ((pipe = check_pipe(data->commands->command)) == 1)
    exec_commandpipe(data);
  else if (pipe == 3)
    exec_commandredirect(data);
  else
    exec_command(data);
  data->commands = data->commands->next;
  while (data->commands->first != 1)
    {
      if ((pipe = check_pipe(data->commands->command)) == 1)
	exec_commandpipe(data);
      else if (pipe == 3)
	exec_commandredirect(data);
      else
	exec_command(data);
      data->commands = data->commands->next;
    }
  return (0);
}
