/*
** errors.c for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/nm
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sat Feb 18 23:30:42 2017 Leo HUBERT
** Last update Sun Feb 26 02:53:54 2017 Leo HUBERT
*/

#include "nm.h"

void	errorWithExit(const char *str)
{
  if (str == NULL)
    return;
  write(2, str, strlen(str));
  exit(-1);
}

void error(const char *str)
{
  if (str == NULL)
    return;
  write(2, str, strlen(str));
}

void	showUsage(char *binary)
{
  error("Usage: ");
  error(binary);
  error(" binary1 binary2 ...\n");
}

void	fileNotFound(char *file)
{
  error(file);
  errorWithExit(": file not found\n");
}

void	fileInvalid(char *file)
{
  error(file);
  errorWithExit(": is not a valid binary file\n");
}
