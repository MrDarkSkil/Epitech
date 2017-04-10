/*
** main.c for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/objdump
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sun Feb 25 23:10:45 2017 Leo HUBERT
** Last update Sun Feb 26 15:20:54 2017 LEO Leo HUBERT
*/

#include "objdump.h"

void		startMain(char *file)
{
  void		*data;
  Elf32_Ehdr	*elf;
  int		fd;
  long int	size;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (fileNotFound(file));
  if ((size = lseek(fd, 0, SEEK_END)) == -1)
    return (error("Error with lseek\n"));
  if ((data = mmap(NULL, size,
		   PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED)
    return ;
  elf = (Elf32_Ehdr*)data;
  if (elf->e_ident[EI_CLASS] == ELFCLASS32)
    x32_format(data, file);
  else if (elf->e_ident[EI_CLASS] == ELFCLASS64)
    x64_format(data, file);
  if (close(fd) == -1)
    return (error("Cannot close file descriptor\n"));
  if (munmap(data, size) == -1)
    return (error("Cannot mumap memory\n"));
}

int	main(int ac, char **av)
{
  int	i;
  
  if (ac > 1)
    {
      i = 0;
      while (++i < ac)
	startMain(av[i]);
    }
  else
    startMain("./a.out");
  return (1);
}
