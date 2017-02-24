/*
** cd.c for cd in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 24 14:35:00 2016 Léo Hubert
** Last update Sun Jan 24 17:27:46 2016 Léo Hubert
*/

#include "my.h"

int	my_cd(t_list *list, char **command)
{
  char	*pwd;
  char	**str;

  pwd = "\0";
  if (command[1] != NULL)
    {
      if (command[1][0] == '-')
	return (my_cd_moin(list));
      if ((pwd = my_cd_bis(list, command, pwd)) == 0)
	return (-1);
      str = my_str_to_wordtab(my_fusionstr("s OLDPWD ",
					   search_list(list, "PWD")), ' ');
      my_set(list, str);
      pwd = my_fusionstr("cd PWD ", pwd);
      str = my_str_to_wordtab(pwd, ' ');
      my_set(list, str);
    }
  else
    {
      str = my_str_to_wordtab(my_fusionstr("cd ",
					   search_list(list, "HOME")), ' ');
      my_cd(list, str);
    }
  return (0);
}

char	*my_cd_bis(t_list *list, char **command, char *pwd)
{
  if (command[1][0] == '/')
    {
      if (chdir(command[1]) == -1)
	{
	  my_error(command[1], "%s: No such file or directory.\n");
	  return (0);
	}
      pwd = command[1];
    }
  else
    {
      pwd = search_list(list, "PWD");
      if (pwd[my_strlen(pwd) - 1] != '/')
	pwd = my_fusionstr(pwd, "/");
      pwd = my_fusionstr(pwd, command[1]);
      if (chdir(pwd) == -1)
	{
	  my_error(command[1], "%s: No such file or directory.\n");
	  return (0);
	}
    }
  return (pwd);
}

int	my_cd_moin(t_list *list)
{
  char	*pwd;
  char	*old_pwd;
  char	**command;

  if ((search_list(list, "OLDPWD")) != NULL
      && (search_list(list, "PWD")) != NULL)
    {
      old_pwd = search_list(list, "OLDPWD");
      pwd = search_list(list, "PWD");
      if (chdir(old_pwd) == -1)
	my_error(old_pwd, "%s: No such file or directory.\n");
      command = my_str_to_wordtab(my_fusionstr("s PWD ", old_pwd), ' ');
      my_set(list, command);
      command = my_str_to_wordtab(my_fusionstr("s OLDPWD ", pwd), ' ');
      my_set(list, command);
    }
  else
    my_error(NULL, "No PWD or OLDPWD found.\n");
  return (0);
}
