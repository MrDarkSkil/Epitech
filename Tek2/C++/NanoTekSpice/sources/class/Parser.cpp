/*
** Parser.cpp for cpp_nanotekspice in /Users/hubert_i/Documents/Shared/C++_2016/cpp_nanotekspice/sources/class
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Sun Feb 05 00:08:54 2017 Leo HUBERT
** Last update Fri Mar 03 17:28:07 2017 Leo Hubert Froideval
*/

#include "Parser.hpp"
#include "Exception.hpp"

nts::Parser::Parser()
{

}

nts::Parser::~Parser()
{

}

nts::Parser::Parser(const Parser &obj)
{
  *this = obj;
}

nts::Parser &nts::Parser::operator=(const Parser &obj)
{
  (void)obj;
  return *this;
}

static	char *getValue(std::string &str, int j, std::string const &input)
{
  int	i;

  i = 0;
  while (!isalpha(str[i]))
    i++;
  if (i > (int)str.length())
    nts::Exception::ErrorAndExit("Syntax error at line : " + std::to_string(j) + " in file : " + input);
  return (&str[i]);
}

static	void	checkStructure(std::ifstream	&file)
{
  bool	chipset = false;
  bool	links = false;

  for(std::string line; std::getline(file, line);)
  {
    if (line.find(".chipsets:") != std::string::npos)
      chipset = true;
    else if (line.find(".links:") != std::string::npos)
      links = true;
  }
  if (chipset == false)
    nts::Exception::ErrorAndExit("No chipset section");
  else if (links == false)
    nts::Exception::ErrorAndExit("No links section");
  file.clear();
  file.seekg(0);
}

static	void	clearTabsOrSpaces(std::string &line)
{
  line.erase(remove_if(line.begin(), line.end(), isblank), line.end());
}

static	bool	checkLine(std::string const &str, size_t pos)
{
  while (str[pos])
    pos++;
  if (str[pos - 1] == '\t' || str[pos - 1] == ' ')
    return (true);
  return (false);
}

static	std::string getInputOrOutput(std::string &str, int i, std::string const &input)
{
  size_t	pos;
  std::string	finalStr;

  if ((pos = str.find("\t")) != std::string::npos || (pos = str.find(" ")) != std::string::npos)
  {
    if (checkLine(str, pos))
      nts::Exception::ErrorAndExit("Syntax error at line : " + std::to_string(i) + " in file : " + input);
    else
      return (str.substr(0, pos));
  }
  nts::Exception::ErrorAndExit("Syntax error at line : " + std::to_string(i) + " in file : " + input);
  return ("");
}

void	nts::Parser::feed(std::string const& input)
{
  std::ifstream	file(input);

  if (file.is_open())
  {
    checkStructure(file);
    this->file = std::ifstream(input);
    file.close();
  }
  else
    nts::Exception::ErrorAndExit("Unable to open file : " + input);
}

void	nts::Parser::parseTree(nts::t_ast_node& root)
{
  (void)root;
}

static	void	checkInputOrOuputError(std::string const &value, std::string const &lexeme)
{
  if (lexeme == "input")
    nts::Exception::ErrorAndExit("Input '" + value + "' is not linked to anything.");
  else
    nts::Exception::ErrorAndExit("Output '" + value + "' is not linked to anything.");
}

std::vector<struct nts::s_ast_node	*>	*getChipsets(nts::s_ast_node	*root)
{
  std::vector<struct nts::s_ast_node	*>	*chipsets = new std::vector<struct nts::s_ast_node	*>;
  size_t	i;

  i = 0;
  while (root->children->at(++i)->lexeme != ".chipsets:");
  while (root->children->at(++i)->lexeme != ".links:")
  {
    if (root->children->at(i)->type != nts::ASTNodeType::NEWLINE)
      chipsets->push_back(root->children->at(i));
  }
  return (chipsets);
}

std::vector<struct nts::s_ast_node	*>	*getLinks(nts::s_ast_node	*root)
{
  std::vector<struct nts::s_ast_node	*>	*links = new std::vector<struct nts::s_ast_node	*>;
  size_t	i;

  i = 0;
  while (root->children->at(++i)->lexeme != ".links:");
  while (++i < root->children->size())
  {
    if (root->children->at(i)->type != nts::ASTNodeType::NEWLINE)
      links->push_back(root->children->at(i));
  }
  return (links);
}

static	void	checkLinks(nts::s_ast_node	*node)
{
  size_t	i = 0;
  std::vector<struct nts::s_ast_node	*>	*links = new std::vector<struct nts::s_ast_node	*>;
  std::vector<struct nts::s_ast_node	*>	*chipsets = new std::vector<struct nts::s_ast_node	*>;
  nts::s_ast_node	*component = new nts::s_ast_node(NULL);

  while (i < node->children->size())
  {
    if (node->children->at(i)->type == nts::ASTNodeType::SECTION && node->children->at(i)->lexeme == ".chipsets:")
    {
      if (node->children->at(i)->type != nts::ASTNodeType::NEWLINE)
        chipsets->push_back(node->children->at(++i));
      i++;
      while (node->children->at(i)->type != nts::ASTNodeType::SECTION)
      {
        if (node->children->at(i)->type != nts::ASTNodeType::NEWLINE && node->children->at(i)->type != nts::ASTNodeType::COMPONENT)
          chipsets->push_back(node->children->at(i));
        else if (node->children->at(i)->type == nts::ASTNodeType::COMPONENT)
          {
            component->lexeme = node->children->at(i)->lexeme;
            component->value = node->children->at(i)->value;
          }
        i++;
      }
    }
    else if (node->children->at(i)->type == nts::ASTNodeType::SECTION && node->children->at(i)->lexeme == ".links:")
    {
      if (++i == node->children->size())
      {
        i = chipsets->size();
        while (chipsets->at(--i)->lexeme != "output");
        nts::Exception::ErrorAndExit("Ouput '" + chipsets->at(i)->value + "' is not linked to anything.");
      }
      while (i < node->children->size())
      {
        if (node->children->at(i)->type != nts::ASTNodeType::NEWLINE)
          links->push_back(node->children->at(i));
        i++;
      }
    }
    else
      i++;
  }

  i = -1;
  while (++i < chipsets->size() && i < links->size())
  {
    if (links->at(i)->lexeme.find(chipsets->at(i)->value) == std::string::npos
      && links->at(i)->lexeme.find(component->value) == std::string::npos)
      {
        if (links->at(i)->lexeme.find(chipsets->at(i - 1)->value) == std::string::npos)
          checkInputOrOuputError(chipsets->at(i)->value, chipsets->at(i)->lexeme);
      }
  }
  if ((i < links->size() || i < chipsets->size()) && links->at(i)->lexeme.find(component->value) == std::string::npos)
    checkInputOrOuputError(chipsets->at(i -1)->value, chipsets->at(i - 1)->lexeme);
  else
    delete chipsets, delete links, delete component;
}

nts::t_ast_node *nts::Parser::createTree()
{
  int	i = 0;
  nts::s_ast_node	*tmp;
  std::vector<struct nts::s_ast_node	*>	*childrens = new std::vector<struct nts::s_ast_node	*>;

  for(std::string line; std::getline(this->file, line);)
  {
    i++;
    if (line[0] == '#')
      continue;

    tmp = new nts::s_ast_node(childrens);
    if (line.find(".chipsets:") != std::string::npos)
    {
      tmp->type = nts::ASTNodeType::SECTION;
      tmp->lexeme = line;
      tmp->value = "";
    }
    else if (line.find(".links:") != std::string::npos)
    {
      tmp->type = nts::ASTNodeType::SECTION;
      tmp->lexeme = line;
      tmp->value = "";
    }
    else if (line.length() == 0)
    {
      tmp->type = nts::ASTNodeType::NEWLINE;
      tmp->lexeme = "";
      tmp->value = "";
    }
    else if (line[0] >= '0' && line[0] <= '9')
    {
      tmp->type = nts::ASTNodeType::COMPONENT;
      clearTabsOrSpaces(line);
      tmp->value = getValue(line, i, "salut");
      tmp->lexeme = line.substr(0, tmp->value.length());
    }
    else
    {
      tmp->lexeme = getInputOrOutput(line, i, "input");
      if (tmp->lexeme.length() == 0)
        nts::Exception::ErrorAndExit("Syntax error at line : " + std::to_string(i) + " in file : " + "input");
      clearTabsOrSpaces(line);
      tmp->value = line.substr(tmp->lexeme.length(), line.length());
      tmp->type = nts::ASTNodeType::LINK;
      if (tmp->lexeme.compare("output"))
        tmp->type = nts::ASTNodeType::LINK_END;
    }
    childrens->push_back(tmp);
  }
  checkLinks(tmp);
  return (tmp);
}
