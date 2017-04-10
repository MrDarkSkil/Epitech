/*
** main.c for server in /home/hubert_i/rendu/2015/PSU_2015/PSU_2015_minitalk
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Feb  2 22:38:17 2016 Léo Hubert
** Last update Wed Feb  3 11:06:17 2016 Léo Hubert
*/

#include "../include/my.h"

void		show_caract(int sig)
{
  static int	check;
  static char	c;
  static int	i;
  int		bin;

  bin = (sig == 10 ?  1 : 0);
  c += (bin << i++);
  if (i > 7)
    {
      (check == 1 ? color(c, &check) : (0));
      if (c == '%')
	check = 1;
      else
	{
	  if (check == 2)
	    check = 0;
	  else
	    if (c == 0)
	      my_putchar('\n');
	    else
	      my_putchar(c);
	}
      c = 0;
      i = 0;
    }
}

int	color(char c, int *check)
{
  char	*tab[8];
  char	*color;
  int	i;

  color = "BRGntrSC";
  tab[0] = COLOR_BLUE;
  tab[1] = COLOR_RED;
  tab[2] = COLOR_GREEN;
  tab[3] = "\n";
  tab[4] = "\t";
  tab[5] = "\r";
  tab[6] = COLOR_RESET;
  tab[7] = COLOR_CLIGNO;
  *check = 2;
  i = 0;
  while (color[i])
    {
      if (color[i] == c)
	return (my_putstr(tab[i]));
      i++;
    }
  return (0);
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
