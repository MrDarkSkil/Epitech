/*
** objdump.h for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/objdump
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sun Feb 26 03:06:22 2017 Leo HUBERT
** Last update Sun Feb 26 15:33:12 2017 LEO Leo HUBERT
*/

#ifndef _OBJDUMP_H_
# define _OBJDUMP_H_

#include <elf.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>

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
int	checkElfHeader32(Elf32_Ehdr *);
int	checkElfClass(const char);
int	checkElfData(const char);
int	checkElfVersion(const char);
int	checkElfSystem(const char);
int	checkElfType(uint16_t);
int	checkSym(Elf64_Sym *);
int	checkSym32(Elf32_Sym *);

/*
**  OBJDUMP
*/
void	print_ascii(unsigned int j,
		    unsigned int *z,
		    unsigned char *w,
		    char *t);
void	x32_format(void *data, char *file);
void	x64_format(void *data, char *file);

#endif /* !_OBJDUMP_H_ */
