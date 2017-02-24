/*
** make_substi.c for make_susbti.c in /home/roig_a/rendu/PSU_2015_tetris
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sun Mar 13 19:59:40 2016 Antoine Roig
** Last update Thu Mar 17 11:22:51 2016 Antoine Roig
*/

#include "tetris.h"

int	search_x_ref(char **tab, int c)
{
  int	s;
  int	x;
  int	y;
  int	x_ref;

  s = 0;
  x = 0;
  while (x < c)
    {
      y = 0;
      while (tab[y])
	{
	  if (tab[y][x] == '*')
	    {
	      x_ref = x;
	      s = 1;
	      break;
	    }
	  y++;
	}
      if (s == 1)
	break;
      x++;
    }
  return (x_ref);
}

int	search_y_ref(char **tab)
{
  int	s;
  int	y;
  int	x;
  int	y_ref;

  s = 0;
  y = 0;
  while (tab[y])
    {
      x = 0;
      while (tab[y][x])
	{
	  if (tab[y][x] == '*')
	    {
	      y_ref = y;
	      s = 1;
	      break;
	    }
	  x++;
	}
      if (s == 1)
	break;
      y++;
    }
  return (y_ref);
}
char	**fil_substi2(int y, t_l_c *l_c, char **substi)
{
  int	x;

  while (y < l_c->l)
    {
      substi[y] = xmalloc(sizeof(char) * (l_c->c + 1));
      x = 0;
      while (x < l_c->c)
	substi[y][x++] = ' ';
      substi[y][x] = '\0';
      y++;
    }
  substi[y] = NULL;
  return (substi);
}

char	**fil_substi(t_var *var, t_l_c *l_c, char **tab, char **substi)
{
  int	y;
  int	x;

  y = 0;
  while (tab[var->j])
    {
      substi[y] = xmalloc(sizeof(char) * (l_c->c + 1));
      var->i = var->x_ref;
      x = 0;
      while (tab[var->j][var->i])
	substi[y][x++] = tab[var->j][var->i++];
      while (x < l_c->c)
	substi[y][x++] = ' ';
      substi[y][x] = '\0';
      var->j++;
      y++;
    }
  return (fil_substi2(y, l_c, substi));
}

char	**make_substi(char **tab, int l, int c)
{
  char	**substi;
  t_var	*var;
  t_l_c	*l_c;

  l_c = xmalloc(sizeof(t_l_c));
  var = xmalloc(sizeof(t_var));
  var->x_ref = search_x_ref(tab, c);
  var->y_ref = search_y_ref(tab);
  substi = xmalloc(sizeof(char *) * (l + 1));
  var->j = var->y_ref;
  l_c->c = c;
  l_c->l = l;
  substi = fil_substi(var, l_c, tab, substi);
  return (substi);
}
