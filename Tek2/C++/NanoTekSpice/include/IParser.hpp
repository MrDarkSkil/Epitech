/*
** parser.hpp for cpp_nanotekspice in /Users/hubert_i/Documents/Shared/C++_2016/cpp_nanotekspice/include
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sat Feb 04 23:05:32 2017 Leo HUBERT
** Last update Thu Feb 16 14:15:43 2017 Loic Lopez
*/

#ifndef CPP_NANOTEKSPICE_PARSER_HPP
#define CPP_NANOTEKSPICE_PARSER_HPP

# include <string>
# include <vector>
namespace nts
{
  enum class ASTNodeType : int
  {
    DEFAULT = -1,
    NEWLINE = 0,
    SECTION,
    COMPONENT,
    LINK,
    LINK_END,
    STRING
  };

  typedef struct s_ast_node
  {
    s_ast_node(std::vector<struct s_ast_node*> *children) : children(children) { }
    std::string    lexeme;
    ASTNodeType    type;
    std::string    value;
    std::vector<struct s_ast_node*> *children;
  } t_ast_node;

  class IParser
  {
  public:
    virtual void feed(std::string const& input) = 0;
    virtual void parseTree(t_ast_node& root) = 0;
    virtual t_ast_node *createTree() = 0;
    virtual ~IParser() {};
  };
}

#endif /* !CPP_NANOTEKSPICE_PARSER_HPP */
