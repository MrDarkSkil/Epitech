/*
** lib.c for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/objdump
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sun Feb 26 04:20:08 2017 Leo HUBERT
** Last update Sun Feb 26 15:19:26 2017 LEO Leo HUBERT
*/

#include "objdump.h"

void	print_ascii(unsigned int j,
		    unsigned int *i,
		    unsigned char *ii,
		    char *t)
{
  int	jj;
  
  jj = j;
  while (jj % 16 != 0)
    {
      if (jj % 4 == 0 && jj % 16)
	printf(" ");
      printf("  ");
      ++jj;
    }
  printf("  ");
  while (*i < j)
    {
      if (isprint(ii[*i]))
	printf("%c", t[*i]);
      else
	printf(".");
      (*i)++;
    }
  while ((*i)++ % 16 != 0)
    printf(" ");
  *i = j;
  printf("\n");
}
