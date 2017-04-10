/*
** format.c for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/objdump/x32
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sun Feb 26 03:42:26 2017 Leo HUBERT
** Last update Sun Feb 26 15:22:22 2017 LEO Leo HUBERT
*/

#include "objdump.h"

void		print_section32_2(char *strtab,
					  Elf32_Ehdr *elf,
					  Elf32_Shdr *shdr,
					  int i)
{
  unsigned char	*a;
  unsigned int	j;
  int		addr;
  unsigned int	ii;

  j = 0;
  ii = 0;
  addr = shdr[i].sh_addr;
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

void	print_section32(char *strtab,
			Elf32_Ehdr *elf,
			Elf32_Shdr *shdr)
{
  int	i;

  i = -1;
  while (++i < elf->e_shnum)
    {
      if (shdr[i].sh_size
	  && strcmp(&strtab[shdr[i].sh_name], ".strtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".symtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".shstrtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".bss"))
      	{
	  print_section32_2(strtab, elf, shdr, i);
	}
    }
}

void		x32_format(void *data, char *file)
{
  Elf32_Ehdr	*elf;
  Elf32_Shdr	*shdr;
  char		*strtab;
  
  elf = (Elf32_Ehdr*)data;
  if (checkElfHeader32(elf) == -1)
    return (fileInvalid(file));
  shdr = (Elf32_Shdr*)(data + elf->e_shoff);
  strtab = (char*)(data + shdr[elf->e_shstrndx].sh_offset);
  printf("\n%s:%5cfile format\n", file, ' ');
  printf("architecture: %s, flags 0x%08x:\n\n",
	 elf->e_machine == 3 ? "i386" : "notf", elf->e_flags);
  printf("start address 0x%08x\n\n", elf->e_entry);
  print_section32(strtab, elf, shdr);
}
