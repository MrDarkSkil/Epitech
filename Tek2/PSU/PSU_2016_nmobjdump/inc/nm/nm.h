/*
** nm.h for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/inc/nm
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sat Feb 18 20:54:25 2017 Leo HUBERT
** Last update Sun Feb 26 15:32:24 2017 LEO Leo HUBERT
*/

#ifndef MY_NM_
#define MY_NM_

#include <elf.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

/*
**  ERRORS FUNCTIONS
*/

void	error(const char *);
void	errorWithExit(const char *);
void	showUsage(char *binary);
void	fileNotFound(char *file);
void	fileInvalid(char *file);

/*
**  HEADER CHECKER FUNCTIONS
*/

int	checkElfHeader(Elf64_Ehdr *);
int	checkElfClass(const char);
int	checkElfData(const char);
int	checkElfVersion(const char);
int	checkElfSystem(const char);
int	checkElfType(uint16_t);
int	checkSym(Elf64_Sym *);

/*
**  x64
*/

int	readSymboles64(Elf64_Shdr symtab,
		       Elf64_Shdr strtab,
		       int fd,
		       Elf64_Shdr **symsTab);
void	symHexa64(Elf64_Sym sym);
int	startSymbolsRead64(int fd, Elf64_Ehdr *elf);
char    print_type64(Elf64_Sym sym, Elf64_Shdr *shdr);

/*
**  x32
*/

int	readSymboles32(Elf32_Shdr symtab,
		       Elf32_Shdr strtab,
		       int fd,
		       Elf32_Shdr **symsTab);
void	symHexa32(Elf32_Sym sym);
int	startSymbolsRead32(int fd, Elf32_Ehdr *elf);
char	print_type32(Elf32_Sym sym, Elf32_Shdr *shdr);

void	printNameSym(int fd);

#endif /* !MY_NM_ */
