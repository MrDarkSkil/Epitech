/*
** symboles.c for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/nm/x32
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sun Feb 26 02:32:31 2017 Leo HUBERT
** Last update Sun Feb 26 15:28:24 2017 LEO Leo HUBERT
*/

#include "nm.h"

char    print_type_232(Elf32_Sym sym, Elf32_Shdr *shdr)
{
  char  c;

  if (sym.st_shndx == SHN_COMMON)
    c = 'C';
  else if (shdr[sym.st_shndx].sh_type == SHT_NOBITS
	   && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
    c = 'B';
  else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
	   && shdr[sym.st_shndx].sh_flags == SHF_ALLOC)
    c = 'R';
  else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
	   && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
    c = 'D';
  else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
	   && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
    c = 'T';
  else if (shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
    c = 'D';
  else
    c = '?';
  if (ELF32_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
    c += 32;
  return (c);
}

char	print_type32(Elf32_Sym sym, Elf32_Shdr *shdr)
{
  char	c;

  if (ELF32_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
    c = 'u';
  else if (ELF32_ST_BIND(sym.st_info) == STB_WEAK)
    {
      c = 'W';
      if (sym.st_shndx == SHN_UNDEF)
        c = 'w';
    }
  else if (ELF32_ST_BIND(sym.st_info) == STB_WEAK
	   && ELF32_ST_TYPE(sym.st_info) == STT_OBJECT)
    {
      c = 'V';
      if (sym.st_shndx == SHN_UNDEF)
        c = 'v';
    }
  else if (sym.st_shndx == SHN_UNDEF)
    c = 'U';
  else if (sym.st_shndx == SHN_ABS)
    c = 'A';
  else
    c = print_type_232(sym, shdr);
  return c;
}

void symHexa32(Elf32_Sym sym)
{
  if (sym.st_value != 0)
  {
    my_putstr("0000000000");
    my_putnbr_base(sym.st_value, "0123456789abcdef");
    write(1, " ", 1);
  }
  else
  {
    my_putstr("                 ");
  }
}

int		readSymboles32(Elf32_Shdr symtab,
			       Elf32_Shdr strtab,
			       int fd,
			       Elf32_Shdr **symsTab)
{
  Elf32_Sym	sym;
  size_t	i;

  i = 0;
  while (i < symtab.sh_size / symtab.sh_entsize)
    {
      lseek(fd, symtab.sh_offset + i * sizeof(sym), SEEK_SET);
      read(fd, &sym, sizeof(sym));
      lseek(fd, strtab.sh_offset + sym.st_name, SEEK_SET);
      if (sym.st_info != STT_FILE &&
	  sym.st_name != 0)
	{
	  symHexa32(sym);
	  my_putchar(print_type32(sym, *symsTab));
	  my_putchar(' ');
	  printNameSym(fd);
	  write(1, "\n", 1);
	}
      i++;
    }
  return (0);
}

int	startSymbolsRead32(int fd, Elf32_Ehdr *elf)
{
  Elf32_Shdr  **symsTab;
  Elf32_Shdr  syms;
  Elf32_Shdr  symtab;
  Elf32_Shdr  strtab;
  size_t	total;
  size_t	i;

  total = elf->e_shnum;
  if (!elf->e_shnum || !elf->e_shoff
    || elf->e_shoff == 0 || lseek(fd, elf->e_shoff, SEEK_SET) == -1
    || (symsTab = malloc(total)) == NULL)
    return (-1);
  i = -1;
  while (++i < total)
  {
    read(fd, &syms, sizeof(syms));
    symsTab[i] = malloc(sizeof(Elf32_Shdr));
    symsTab[i] = &syms;
    if (syms.sh_type == SHT_STRTAB)
      strtab = syms;
    if (syms.sh_type == SHT_SYMTAB)
      symtab = syms;
  }
  readSymboles32(symtab, strtab, fd, symsTab);
  return (0);
}
