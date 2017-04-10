/*
** format.c for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/objdump/x64
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sun Feb 26 04:01:57 2017 Leo HUBERT
** Last update Sun Feb 26 15:23:39 2017 LEO Leo HUBERT
*/

#include "objdump.h"

void   		print_section64_2(char *strtab,
				  Elf64_Ehdr *elf,
				  Elf64_Shdr *shdr,
				  int i)
{
  unsigned char	*a;
  unsigned int	j;
  int		addr;
  unsigned int	ii;

  addr = shdr[i].sh_addr;
  j = 0;
  ii = 0;
  a = (unsigned char*)((char*)elf + shdr[i].sh_offset);
  printf("Contents of section %s:\n", &strtab[shdr[i].sh_name]);
  while (j < shdr[i].sh_size)
    {
      if (j % 16 == 0)
	printf(" %04x ", addr);
      printf("%02x", a[j++]);
      if (j % 4 == 0 && j % 16 && j < shdr[i].sh_size)
	printf(" ");
      if (j % 16 == 0)
	addr += 16;
      if (j % 16 == 0 || j >= shdr[i].sh_size)
	print_ascii(j, &ii, a, (char*)a);
    }
}

void	print_section64(char *strtab,
			Elf64_Ehdr *elf,
			Elf64_Shdr *shdr)
{
  int	i;

  i = 0;
  while (i < elf->e_shnum)
    {
      if (shdr[i].sh_size
	  && strcmp(&strtab[shdr[i].sh_name], ".strtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".symtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".shstrtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".bss"))
      	{
	  print_section64_2(strtab, elf, shdr, i);
	}
  i++;
    }
}

void		x64_format(void *data, char *file)
{
  Elf64_Ehdr	*elf;
  Elf64_Shdr	*shdr;
  char		*strtab;

  elf = (Elf64_Ehdr*)data;
  if (checkElfHeader(elf) == -1)
    return ;
  shdr = (Elf64_Shdr*)(data + elf->e_shoff);
  strtab = (char*)(data + shdr[elf->e_shstrndx].sh_offset);
  printf("\n%s:%5cfile format\n", file, ' ');
  printf("architecture: %s, flags 0x%08x:\n\n",
	 elf->e_machine == 3 ? "i386" : "notf", elf->e_flags);
  printf("start address 0x%016x\n\n", (int)elf->e_entry);
  print_section64(strtab, elf, shdr);
}
