/*
** error.c for  in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minishell1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sun Jan 24 16:39:47 2016 Léo Hubert
** Last update Thu Mar 24 03:54:11 2016 Léo Hubert
*/

#include "my.h"

void	my_puterror(char c)
{
  write(2, &c, 1);
}

int	my_error(char *com, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '%' && str[i + 1] == 's')
	{
	  my_error(str, com);
	  i += 2;
	}
      my_puterror(str[i]);
      i++;
    }
  return (0);
}
