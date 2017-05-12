/*
** main.cpp for cpp_nanotekspice in /Users/hubert_i/Documents/Shared/C++_2016/cpp_nanotekspice/sources
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Wed Feb 01 17:42:27 2017 Leo HUBERT
** Last update Sat Mar 04 17:47:24 2017 Leo Hubert Froideval
*/

#include "NanoTekSpice.hpp"

void	show_help(char const **av)
{
  std::cerr << "Usage: " << av[0] << " filename.nts [ARGS]\nOR " << av[0] << " [OPTIONS]\n" << std::endl;
  std::cerr << " [OPTIONS] : " << std::endl;
  std::cerr << " -h, --help\t\tfor show help" << std::endl;
  std::cerr << " -C, --comands\t\tshow all commands available in NTShell" << std::endl;
}

int	parse_options(int ac, char const **av)
{
  std::string cur;

  for(int i = 1; i < ac; i++)
  {
    if (av[i][0] && av[i][0] == '-')
    {
      cur = av[i];
      if (cur == "-h" || cur == "--help")
        show_help(av);
      else if (cur == "-C" || cur == "--commands")
        std::cerr << "show commands a faires si le temps" << '\n';
      else
        std::cerr << av[i] << " option not found\nTry -h or --help for show help" << '\n';
      return (-1);
    }
  }
  return(0);
}

void	setInputValue(std::string &curValue, std::string &curInput, nts::IComponent  *component,
  std::vector<struct nts::s_ast_node	*>	 *chipsets)
{
  if (curValue.empty())
    nts::Exception::Error("Missing input value on command line");
  else
  {
    if (curInput.empty())
      nts::Exception::Error("Unknown input specified by command line");
    else
    {
      bool check = false;
      for(size_t i = 0; i < chipsets->size(); i++)
      {
        if (chipsets->at(i)->lexeme == "input" && chipsets->at(i)->value == curInput)
        {
          check = true;
          if (curValue != "1" && curValue != "0")
          {
            nts::Exception::Error("Input value is not a boolean");
            break;
          }
          nts::Tristate state;

          if (curValue == "0")
            state = nts::Tristate::FALSE;
          else if (curValue == "1")
            state = nts::Tristate::TRUE;
          component->setValue(curInput, state);
          break;
        }
      }
      if (check == false)
        nts::Exception::Error("Unknown input specified by command line");
    }
  }
}

void initValues(int ac, char const **av, nts::IComponent *component, std::vector<struct nts::s_ast_node	*>	 *chipsets)
{
  int	i;
  std::string	tmp;
  size_t	find;
  (void)component;

  if (ac > 2)
  {
    i = 2;
    while (i < ac)
    {
      tmp = av[i];
      find = tmp.find('=');
      if (find != std::string::npos)
      {
        std::string curValue = tmp.substr(find + 1);
        std::string curInput = tmp.substr(0, find);
        setInputValue(curValue, curInput, component, chipsets);
      }
      else
        nts::Exception::ErrorAndExit(tmp + ": command not found");
      i++;
    }
  }
}

static void	displayOutput(nts::IComponent *component, std::vector<struct nts::s_ast_node	*>	 *chipsets)
{
  std::map<std::string, nts::t_pin> pins;
  pins = component->getPins();
  for(size_t i = 0; i < chipsets->size(); i++)
  {
    if (chipsets->at(i)->lexeme == "output")
    {
      for (const auto& kv : pins)
      {
        if (kv.second.type == nts::PinType::OUTPUT && kv.second.name == chipsets->at(i)->value)
          std::cout << kv.second.name << "=" << kv.second.value << std::endl;
      }
    }
  }
}

void	prompt(nts::IParser *parser, nts::s_ast_node *nodes, char const **av, int ac)
{
  nts::IComponent  *component;
  std::string *cmd = new std::string;
  std::vector<struct nts::s_ast_node	*>	 *links;
  std::vector<struct nts::s_ast_node	*>	 *chipsets;
  size_t	find;

  (void)parser;
  links = getLinks(nodes->children->at(0));
  chipsets = getChipsets(nodes->children->at(0));
  for(size_t i = 0; i < chipsets->size(); i++)
  {
    if (std::all_of(chipsets->at(i)->lexeme.begin(), chipsets->at(i)->lexeme.end(), ::isdigit) == 1)
    {
      nts::IComponent *tmp = new nts::Component();
      component = tmp->createComponent(chipsets->at(i)->lexeme, links, chipsets);
      initValues(ac, av, component, chipsets);
      break;
    }
  }

  component->simulate();
  displayOutput(component, chipsets);

  std::cout << "> ";
  while (std::getline(std::cin, *cmd))
  {
    find = cmd->find('=');
    if (find != std::string::npos)
    {
      std::string curValue = cmd->substr(find + 1);
      std::string curInput = cmd->substr(0, find);
      setInputValue(curValue, curInput, component, chipsets);

    } else if (*cmd == "exit")
      return;
    else if (*cmd == "display")
    {
      displayOutput(component, chipsets);
    }
    else if (*cmd == "simulate")
    {
      component->simulate();
    }
    else if (*cmd == "loop")
    {
      std::cout << "loop" << '\n';
    }
    else if (*cmd == "dump")
    {
      component->Dump();
    }
    else if (*cmd != "")
    {
      nts::Exception::Error(*cmd + ": command not found");
    }
    std::cout << "> ";
    delete cmd;
    cmd = new std::string;
  }
  std::cout << std::endl;
}

int	main(int ac, char const **av)
{
  nts::s_ast_node *nodes;

  if (ac == 1)
    show_help(av);
  else
  {
    std::string	tmp;
    tmp = av[1];
    if (parse_options(ac, av) == -1)
      return (-1);
    if (!tmp.empty() && tmp[tmp.length() - 1] == 's' && \
	   tmp[tmp.length() - 2] == 't' && tmp[tmp.length() - 3] == 'n' && \
	    tmp[tmp.length() - 4] == '.')
      {
        nts::IParser *parser = new nts::Parser;

        parser->feed(av[1]);
        nodes = parser->createTree();
        prompt(parser, nodes, av, ac);
        return (0);
      }
    else
      std::cerr << "Bad file extension" << std::endl;
  }
  return (0);
}
