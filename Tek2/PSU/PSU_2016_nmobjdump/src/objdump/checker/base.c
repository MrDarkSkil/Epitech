/*
** base.c for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/nm/elf-checker
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sun Feb 19 03:20:50 2017 Leo HUBERT
** Last update Sun Feb 26 15:24:08 2017 LEO Leo HUBERT
*/

#include "nm.h"

int checkElfHeader32(Elf32_Ehdr *elf)
{
  if (elf->e_ident[0] == ELFMAG0
      && elf->e_ident[1] == ELFMAG1
      && elf->e_ident[2] == ELFMAG2
      && elf->e_ident[3] == ELFMAG3
      && checkElfClass(elf->e_ident[4])
      && checkElfData(elf->e_ident[5])
      && checkElfVersion(elf->e_ident[6])
      && elf->e_ident[8] == 0
      && checkElfVersion(elf->e_version))
    {
      return (1);
    }
  return (0);
}

int	checkSym32(Elf32_Sym *sym)
{
  (void)sym;
  return (1);
}
