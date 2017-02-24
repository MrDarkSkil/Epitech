/*
** load_tetriminos2.c for load_tetriminos2.c in /home/roig_a/rendu/PSU_2015_tetris
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Thu Mar 17 11:59:46 2016 Antoine Roig
** Last update Thu Mar 17 15:00:27 2016 Antoine Roig
*/

#include "tetris.h"

char	*parsing1(char *content, char **width, char **height, char **color)
{
  int		i;

  i = 0;
  while (content[i] != ' ')
    i++;
  *width = strndup(content, i);
  content = (char *)(content + i + 1);
  i = 0;
  while (content[i] != ' ')
    i++;
  *height = strndup(content, i);
  content = (char *)(content + i + 1);
  i = 0;
  while (content[i] != '\n')
    i++;
  *color = strndup(content, i);
  content = (char *)(content + i + 1);
  return (content);
}

char	**make_tetri2(char *content, char **tetrimino, int i, int c)
{
  int	y;
  int	x;

  y = -1;
  while (++y < c)
    {
      x = 0;
      while (content[i])
        {
          if (content[i] == '\n')
            {
              i++;
              break;
            }
          else
            tetrimino[y][x++] = content[i++];
        }
    }
  return (tetrimino);
}

t_tetri	*load_tetri(t_tetri *tetri, int rx, int ry, char *name)
{
  tetri->rx = rx;
  tetri->ry = ry;
  tetri->name = name;
  tetri->name[strlen(name)] = '\0';
  return (tetri);
}

t_tetri	*load_tetri2(t_tetri * tetri, int l, int c, char *color)
{
  tetri->height = l;
  tetri->width = c;
  tetri->color = my_getnbr(color);
  return (tetri);
}

void	load_tetri_loop(t_dlist *list, struct stat buffer, DIR *repository)
{
  struct dirent	*file;
  int		fd;
  char		*content;
  char		*fichier;

  while ((file = readdir(repository)))
    {
      if (file == NULL)
	break;
      if (file->d_name[0] == '.' || check_file(file->d_name) == 0)
	continue;
      fichier = my_strcat(my_strcat("tetrimino", "/"), file->d_name);
      fd = open(fichier, O_RDONLY);
      if (stat(fichier, &buffer) == -1)
	perror("stat");
      content = xmalloc(sizeof(char) * (buffer.st_size + 1));
      read(fd, content, buffer.st_size);
      content[buffer.st_size] = '\0';
      parsing(list, content, file->d_name);
      free(fichier);
      free(content);
    }
}
