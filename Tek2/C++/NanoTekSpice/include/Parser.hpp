/*
** Parser.hpp for cpp_nanotekspice in /Users/hubert_i/Documents/Shared/C++_2016/cpp_nanotekspice/include
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sun Feb 05 00:09:39 2017 Leo HUBERT
** Last update Tue Feb 28 19:25:46 2017 Leo HUBERT
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <fstream>
#include <algorithm>

#include "IParser.hpp"

std::vector<struct nts::s_ast_node	*>	*getLinks(nts::s_ast_node	*root);
std::vector<struct nts::s_ast_node	*>	*getChipsets(nts::s_ast_node	*root);

namespace nts
{
  class Parser : public nts::IParser
  {
    private:
      std::ifstream	file;
    public:
      Parser();
      virtual ~Parser();
      Parser(const Parser &obj);
      Parser  &operator=(const Parser &obj);

      virtual void feed(std::string const& input);
      virtual void parseTree(nts::t_ast_node& root);
      virtual nts::t_ast_node *createTree();
  };
}
#endif /* !PARSER_HPP_ */
