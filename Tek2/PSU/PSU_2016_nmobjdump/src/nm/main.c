/*
** main.c for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/nm
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Wed Feb 22 22:34:29 2017 Leo HUBERT
** Last update Sun Feb 26 15:25:54 2017 LEO Leo HUBERT
*/

#include "nm.h"

int	count_files(int ac, char **av, int i)
{
  int	files;

  files = 0;
  while (i < ac)
    {
      if (av[i][0] && av[i][0] != '-')
	files++;
      i++;
    }
  return (files);
}

int		startRead(int fd, Elf64_Ehdr *elf, char *file)
{
  Elf32_Ehdr	_elf;

  if (elf->e_ident[4] == ELFCLASS64)
    {
      if (startSymbolsRead64(fd, elf) == -1)
	fileInvalid(file);
    }
  else
    {
      if (read(fd, elf, sizeof(Elf64_Ehdr)) == -1)
	return (-1);
      lseek(fd, 0, SEEK_SET);
      if (startSymbolsRead32(fd, &_elf) == -1)
	fileInvalid(file);
    }
  return (0);
}

int	startMain(int ac, char **av, Elf64_Ehdr *elf)
{
  int	i;
  int	fd;

  i = 1;
  while (i < ac)
    {
      fd = open(av[i], O_RDONLY);
      if (fd == -1)
	fileNotFound(av[i]);
      else
	{
	  if (count_files(ac, av, 1) > 1)
	    printf("%s\n", av[i]);
	  if (read(fd, elf, sizeof(Elf64_Ehdr)) == -1)
        return (-1);
	  if (checkElfHeader(elf) == 1)
          startRead(fd, elf, av[i]);
	  else
	    fileInvalid(av[i]);
	  if (count_files(ac, av, i) > 1)
	    printf("\n");
	}
      i++;
    }
  return (0);
}

int		main(int ac, char **av)
{
  Elf64_Ehdr	elf;

  if (ac == 1)
    {
      showUsage(av[0]);
      return (-1);
    }
  else
    startMain(ac, av, &elf);
  return (1);
}
