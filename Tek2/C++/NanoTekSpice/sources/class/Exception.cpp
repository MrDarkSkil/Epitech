/*
** Exception.cpp for cpp_nanotekspice in /Users/loiclopez/Documents/Shared/Epitech/year_2016/cpp_nanotekspice/sources/class
**
** Made by loic lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  Mon Feb 06 14:36:13 2017 loic lopez
** Last update Fri Mar 03 16:39:50 2017 Leo Hubert Froideval
*/

#include "NanoTekSpice.hpp"

nts::Exception::Exception(std::string const &message)
{
  this->message = message;
}

const char	*nts::Exception::what() const throw()
{
  return this->message.c_str();
}

void	nts::Exception::Error(std::string const &error)
{
  try
  {
    throw Exception(error);
  }
  catch (Exception const &error)
  {
    std::cerr << error.what()  << std::endl;
  }
}

void	nts::Exception::ErrorAndExit(std::string const &error)
{
  try
  {
    throw Exception(error);
  }
  catch (Exception const &error)
  {
    std::cerr << error.what()  << std::endl;
    exit(1);
  }
}
