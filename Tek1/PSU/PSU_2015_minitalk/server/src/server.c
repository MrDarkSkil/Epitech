/*
** main.c for server in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minitalk
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Feb  2 22:38:17 2016 Léo Hubert
** Last update Thu Feb  4 15:03:41 2016 Léo Hubert
*/

#include "../include/my.h"

void		show_caract(int sig)
{
  static char	c;
  static int	i;
  int		bin;

  bin = (sig == 10 ?  1 : 0);
  c += (bin << i++);
  if (i > 7)
    {
      my_putchar(c);
      c = 0;
      i = 0;
    }
}

int	error(int mode)
{
  write(2, COLOR_RED, 5);
  if (mode == 1)
    write(2, "Ereur de signal\n", 17);
  else if (mode == 2)
    write(2, "Usage: ./server\n", 30);
  write(2, COLOR_RESET, 5);
  return (0);
}

int	main()
{
  signal(SIGUSR1, show_caract);
  signal(SIGUSR2, show_caract);
  init_serveur();
  while (1);
  return (0);
}

void	init_serveur()
{
  pid_t	pid;

  pid = getpid();
  my_putstr("Server PID: ");
  my_put_nbr(pid);
  my_putchar('\n');
}
