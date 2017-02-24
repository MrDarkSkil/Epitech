/*
** main.c for main.c in /home/roig_a/rendu/PSU_2015_tetris
**
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
**
** Started on  Thu Feb 25 17:21:33 2016 Antoine Roig
** Last update Sat Mar 19 16:02:39 2016 Antoine Roig
*/

#include "tetris.h"

char	**make_tetri(int l, int c, char *content, int i)
{
  char  **tetrimino;
  int   y;
  int   x;

  y = -1;
  tetrimino = xmalloc(sizeof(char *) * (l + 1));
  while (++y < l)
    {
      x = 0;
      tetrimino[y] = xmalloc(sizeof(char) * (c + 1));
      while (x < c)
        tetrimino[y][x++] = ' ';
      tetrimino[y][x] = '\0';
    }
  tetrimino[y] = NULL;
  return (make_tetri2(content, tetrimino, i, c));
}

char	***tab_orientation(int l, int c, char **tetrimino)
{
  char	***tab;
  char	**substi1;
  char	**substi2;
  char	**substi3;
  char	**substi4;

  tab = malloc_tab(l, c);
  tab = first_dim(tab, l, c, tetrimino);
  tab = last_dim(tab, l, c);
  substi1 = make_substi(tab[0], l, c);
  tab[0] = substi1;
  substi2 = make_substi(tab[1], l, c);
  tab[1] = substi2;
  substi3 = make_substi(tab[2], l, c);
  tab[2] = substi3;
  substi4 = make_substi(tab[3], l, c);
  tab[3] = substi4;
  return (tab);
}

t_dlist	*parsing(t_dlist *list, char *content, char *name)
{
  char	*width;
  char	*height;
  char	*color;
  char	**tetrimino;
  int	i;
  t_tetri	*tetri;
  int	l;
  int	c;
  int	rx;
  int	ry;

  content = parsing1(content, &width, &height, &color);
  tetri = xmalloc(sizeof(t_tetri));
  i = 0;
  l = my_getnbr(height);
  c = my_getnbr(width);
  ry = l;
  rx = c;
  (l > c) ? (c = l) : (l = c);
  tetrimino = make_tetri(l, c, content, i);
  tetri = load_tetri(tetri, rx, ry, name);
  tetri = load_tetri2(tetri, l, c, color);
  tetri->tetriminos = tab_orientation(l, c, tetrimino);
  add_list_end(list, tetri);
  return (list);
}

int	check_file(char	*str)
{
  int	i;

  i = my_strlen(str);
  while (str[i] != '.')
    i--;
  if (str[i] == '.')
    {
      str = (char*)str + i;
      if ((my_strncmp(str, ".tetrimino", 10) != 0))
	return (0);
      if (str[10] != '\0')
	return (0);
      return (1);
    }
  else
    return (0);
}

t_dlist			*load_tetriminos(t_dlist *list)
{
  DIR			*repository;
  struct	stat	buffer;

  list = new_list(list);
  if (stat("tetrimino", &buffer) == -1)
    {
      perror("stat");
      return (NULL);
    }
  if ((repository = opendir("tetrimino")) == NULL)
    {
      perror("Can't open tetrimino");
      return (NULL);
    }
  else
    load_tetri_loop(list, buffer, repository);
  closedir(repository);
  return (list);
}
