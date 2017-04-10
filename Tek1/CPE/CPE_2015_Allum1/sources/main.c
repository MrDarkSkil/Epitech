/*
** main.c for main in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_Allum1
**
** Made by Léo Hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Sat Feb 13 13:47:39 2016 Léo Hubert
** Last update Fri Feb 19 15:12:19 2016 Léo Hubert
*/

#include "my.h"

char	*reset(char *str, int nbr)
{
  char	*buffer;
  int	i;

  if ((buffer = malloc(sizeof(char) * nbr)) == NULL)
    return (NULL);
  i = -1;
  while (++i <= nbr)
    buffer[i] = '\0';
  return (buffer);
}

int	getline(t_allum *allum)
{
  int	nb_lines;
  int	line;
  char	*buffer;

  if ((buffer = malloc(sizeof(char) * 4048)) == NULL)
    return (-1);
  nb_lines = count_allum(allum);
  while (1)
    {
      my_putstr("Line: ");
      if (read(0, buffer, 4048) == -1)
	return (-1);
      if (my_strlen(buffer) == 0)
	return (-1);
      if (my_str_isnum(buffer) == 0 || buffer[0] == '\n')
	my_putstr("Error: invalid input (positive number expected)\n");
      else
	{
	  line = my_getnbr(buffer);
	  if (line > nb_lines || my_strlen(buffer) == 1 || line == 0)
	    my_putstr("Error: this line is out of range\n");
	  else
	    {
	      while (allum->etage != line - 1)
		allum = allum->next;
	      if (allum->nb_allum == 0)
	    my_putstr("Error: this line is empty\n");
	      else
		return (line);
	    }
	}
      if ((buffer = reset(buffer, 4048)) == NULL)
	return (-1);
    }
  return (0);
}

int	getmatches(t_allum *allum, int line)
{
  int	nb_matches;
  int	matches;
  char	buffer[4048];

  while (allum->etage != line - 1)
    allum = allum->next;
  nb_matches = allum->nb_allum;
  my_putstr("Matches: ");
  if (read(0, buffer, 4048) == -1)
    return (-1);
  if (buffer[1] == 0)
    return (-1);
  if (my_str_isnum(buffer) == 0 || buffer[0] == '\n')
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (-2);
    }
  else
    {
      matches = my_getnbr(buffer);
      if (matches > nb_matches || my_strlen(buffer) == 1 || matches == 0)
	{
	  my_putstr("Error: not enough matches on this line\n");
	  return (-2);
	}
      else
	return (matches);
    }
}

void	remove_matches(t_allum	*allum,
		       int	line,
		       int	matches)
{
  while (allum->etage != line - 1)
    allum = allum->next;
  allum->nb_allum = allum->nb_allum - matches;
}

void	display_playerturn(int	matches,
			   int	line)
{
  my_putstr("Player removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

int		main()
{
  t_allum	*allum;
  int		line;
  int		matches;

  allum = init_allum1(4);
  display_allum1(allum);
  while (1)
    {
      my_putstr("\n\nYour turn:\n");
      matches = -2;
      line = -2;
      while (line == -2 || matches == -2)
	{
	  if ((line = getline(allum)) == -1)
	    return (-1);
	  if ((matches = getmatches(allum, line)) == -1 && line != -2)
	    return (-1);
	}
      remove_matches(allum, line, matches);
      display_playerturn(matches, line);
      display_allum1(allum);
      if (check_game(allum, 1) == -1)
	return (-1);
      if (IA(allum) == -1)
	return (-1);
    }
  return (0);
}
