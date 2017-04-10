/*
** main.c for main_client in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minitalk
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Thu Jan 28 01:30:33 2016 Léo Hubert
** Last update Sat Feb  6 00:32:18 2016 Léo Hubert
*/

#include "../include/my.h"

int	send_binary(char caract, int uid)
{
  char	i;

  i = 0;
  while (i < 8)
    {
      usleep(70);
      if (((caract >> i) & 1) == 1)
	{
	  if (kill(uid, SIGUSR1) == -1)
	    return (-1);
	}
      else
	{
	  if (kill(uid, SIGUSR2) == -1)
	    return (-1);
	}
      i++;
    }
  return (0);
}

int	error(int mode)
{
  write(2, COLOR_RED, 5);
  if (mode == 1)
    write(2, "Ereur de signal ou de PID\n", 27);
  else if (mode == 2)
    write(2, "Usage: ./client PID <message>\n", 30);
  write(2, COLOR_RESET, 5);
  return (0);
}

int	main(int ac, char **av)
{
  int   i;
  char 	*str;
  int	uid;

  if (ac == 3)
    {
      i = 0;
      str = av[2];
      uid = my_getnbr(av[1]);
      while (str[i])
	{
	  if (send_binary(str[i], uid) == -1)
	    return (error(1));
	  i++;
	}
      if (send_binary(str[i], uid) == -1)
	return (error(1));
    }
  else
    return (error(2));
  return (0);
}
