/*
** main.c for main.c in /home/lopez_i
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Thu Apr 14 20:38:21 2016 Loic Lopez
** Last update Thu Apr 14 20:52:51 2016 Léo Hubert
*/

#include <stdlib.h>

int	my_str_is_num(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] <= '0' && str[i] >= '9')
	return (-1);
      i++;
    }
  return (0);
}

int     my_getnbr(char *str)
{
  int   i;
  int   s;
  int   nb;

  if (str == NULL)
    return (-1);
  if ((my_str_is_num(str)) == -1)
    return (-1);
  s = 1;
  i = 0;
  nb = 0;
  while (str[i] && (str[i] == '+' || str[i] == '-'))
    if (str[i++] == '-')
      s *= -1;
  while (str[i] >= '0' && str[i] <= '9')
    nb = nb * 10 + (str[i++] - '0');
  return (nb * s);
}
