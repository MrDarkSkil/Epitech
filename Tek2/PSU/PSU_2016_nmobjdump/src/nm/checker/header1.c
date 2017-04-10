/*
** checkElfHeader.c for PSU_2016_nmobjdump in /Users/hubert_i/Documents/Shared/PSU_2016/PSU_2016_nmobjdump/src/nm
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sun Feb 19 03:19:02 2017 Leo HUBERT
** Last update Sun Feb 26 15:30:52 2017 LEO Leo HUBERT
*/

#include "nm.h"

int	checkElfClass(const char class)
{
  if ((class == ELFCLASS32
       || class == ELFCLASS64)
      && class != ELFCLASSNONE)
    {
      return (1);
    }
  return (0);
}

int	checkElfData(const char data)
{
  if ((data == ELFDATA2LSB
       || data == ELFDATA2MSB)
      && data != ELFDATANONE)
  {
    return (1);
  }
  return (0);
}

int checkElfVersion(const char version)
{
  if ((version == EV_CURRENT)
      && version != EV_NONE)
    {
      return (1);
    }
  return (0);
}

int	checkElfSystem(const char sys)
{
  if ((sys == ELFOSABI_SYSV
       || sys == ELFOSABI_HPUX
       || sys == ELFOSABI_NETBSD
       || sys == ELFOSABI_LINUX
       || sys == ELFOSABI_SOLARIS
       || sys == ELFOSABI_IRIX
       || sys == ELFOSABI_FREEBSD
       || sys == ELFOSABI_TRU64
       || sys == ELFOSABI_ARM)
      && sys != ELFOSABI_NONE)
    {
      return (1);
    }
  return (0);
}

int	checkElfType(uint16_t type)
{
  if ((type == ET_REL
       || type == ET_EXEC
       || type == ET_DYN
       || type == ET_CORE)
      && type != ET_NONE)
    {
      return (1);
    }
  return (0);
}
