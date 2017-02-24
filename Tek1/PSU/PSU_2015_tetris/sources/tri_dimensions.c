/*
** tri_dimensions.c for tri_dimensions.c in /home/roig_a/rendu/PSU_2015_tetris
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Thu Mar 17 15:26:04 2016 Antoine Roig
** Last update Thu Mar 17 15:40:50 2016 Antoine Roig
*/

#include "tetris.h"

char	***malloc_tab(int l, int c)
{
  int	y;
  int	x;
  int	z;
  char	***tab;

  tab = xmalloc(sizeof(char**) * 5);
  z = 0;
  while (z < 4)
    {
      y = 0;
      tab[z] = xmalloc(sizeof(char *) * (l + 1));
      while (y < l)
	{
	  x = 0;
	  tab[z][y] = xmalloc(sizeof(char) * (c + 1));
	  while (x < c)
	    tab[z][y][x++] = 'A';
	  tab[z][y][x] = '\0';
	  y++;
	}
      tab[z][y] = NULL;
      z++;
    }
  tab[z] = NULL;
  return (tab);
}

char	***first_dim(char ***tab, int l, int c, char **tetrimino)
{
  int	i;
  int	k;
  int	j;

  i = 0;
  while (i < l)
     {
      j = 0;
      k = 0;
      while (j < c)
	{
	  tab[0][i][j] = tetrimino[l - 1 - k][i];
	  j++;
	  k++;
	}
      i++;
     }
  return (tab);
}

char	***last_dim(char ***tab, int l, int c)
{
  int	z;
  int	w;
  int	i;
  int	k;
  int	j;

  z = 1;
  w = 0;
  while (z < 4)
    {
      i = -1;
      while (++i < l)
  	{
  	  j = -1;
  	  k = 0;
  	  while (++j < c)
  	    {
	      tab[z][i][j] = tab[w][l - 1 - k][i];
  	      k++;
  	    }
	}
      w++;
      z++;
    }
  return (tab);
}
