/*
** symboles.c for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/nm
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sun Feb 26 02:34:15 2017 Leo HUBERT
** Last update Sun Feb 26 15:26:27 2017 LEO Leo HUBERT
*/

#include "my.h"

void printNameSym(int fd)
{
  char c;
  
  while (1)
    {
      read(fd, &c, 1);
      if (c == '\0')
	break;
      write(1, &c, 1);
    }
}
