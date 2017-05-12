/*
** Exception.hpp for cpp_nanotekspice in /Users/loiclopez/Documents/Shared/Epitech/year_2016/cpp_nanotekspice/include
**
** Made by loic lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  Mon Feb 06 14:42:05 2017 loic lopez
** Last update Fri Feb 17 10:54:53 2017 Leo HUBERT
*/

#ifndef Exception_HPP_
#define Exception_HPP_

#include <exception>

namespace nts
{
  class Exception : std::exception
  {
    private:
      std::string	message;
    public:
      Exception(std::string const &message);
      virtual ~Exception() throw() {};
      virtual const char	*what() const throw();
      static void	Error(std::string const &);
      static void	ErrorAndExit(std::string const &error);
  };
}

#endif /* !Exception_HPP_ */
