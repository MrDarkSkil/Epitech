/*
** main.c for main in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_BSQ
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Fri Dec 11 14:03:56 2015 leo hubert
** Last update Fri Dec 18 18:12:31 2015 leo hubert
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int	main(int ac, char **av)
{
  const char *dest;

  if (ac > 1)
    {
      dest = av[1];
      open_file(dest);
    }
  else
    usage();
  return (0);
}

typedef struct s_interact
{
  int	i;
  int	b;
  int	result;
  int	size_line;
}	t_interact;

char	*putnbr_line(char *buffer, t_bsq *bsq)
{
  t_interact	in;

  in.i = 0;
  in.b = 0;
  in.size_line = 0;
  in.result = 0;
  while (buffer[in.b] != '\n')
    if (buffer[in.b++] == '\0')
      return ("err");
  while (buffer[in.i] != '\0')
    {
      if (buffer[in.i] == '\n')
	{
	  in.result++;
	  if (buffer[in.i + 1] != '\0')
	    in.size_line = 0;
	}
      in.size_line++;
      in.i++;
    }
  bsq->nb_lines = in.result - 1;
  bsq->size_line = in.size_line - 1;
  return (&buffer[in.b + 1]);
}

int	get_octe(const char *dest)
{
  struct stat sb;

  if (stat(dest, &sb) == -1)
    return (my_putstr("Error: Cannot get info map file\n"));
  return (sb.st_size);
}

int		open_file(const char *dest)
{
  t_bsq		bsq;
  t_scare	scare;
  int		fd;
  int		size;
  char	        *buffer;

  fd = open(dest, O_RDONLY);
  if (fd == -1)
    return (my_putstr("error: file not found\n"));
  size = get_octe(dest);
  buffer = malloc(sizeof(char) * size);
  read(fd, buffer, size);
  buffer = putnbr_line(buffer, &bsq);
  if (buffer[1] == 'r')
    return (not_filemap());
  my_putin_tab(buffer, &bsq);
  scare.size = 0;
  my_bsq(&bsq, &scare);
  close(fd);
  return (0);
}
