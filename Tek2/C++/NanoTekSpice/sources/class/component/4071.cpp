/*
** Component4071.cpp for cpp_nanotekspice in /Users/leohubertfroideval/Documents/Shared/C++_2016/cpp_nanotekspice/sources/class/component
**
** Made by Leo Hubert Froideval
** Login   <leohubertfroideval@epitech.net>
**
** Started on  Fri Mar 03 17:44:45 2017 Leo Hubert Froideval
** Last update Fri Mar 03 21:57:17 2017 Leo Hubert Froideval
*/

#include "component/4071.hpp"

static bool checkGate(std::vector<struct nts::s_ast_node	*>	 *chipsets, std::string const &name)
{
  bool check = false;
  for(size_t i = 0; i < chipsets->size(); i++)
  {
    if (std::all_of(chipsets->at(i)->lexeme.begin(), chipsets->at(i)->lexeme.end(), ::isdigit) && chipsets->at(i)->value == name)
      check = true;
  }
  return (check);
}

static nts::PinType  getType(std::vector<struct nts::s_ast_node	*>	 *chipsets, std::string const &name)
{
  for(size_t i = 0; i < chipsets->size(); i++)
  {
    if (chipsets->at(i)->lexeme == "input" && chipsets->at(i)->value == name)
      return (nts::PinType::INPUT);
    else if (chipsets->at(i)->lexeme == "output" && chipsets->at(i)->value == name)
      return (nts::PinType::OUTPUT);
  }
  return (nts::PinType::MORDOR);
}

nts::Component4071::Component4071(std::vector<struct nts::s_ast_node	*>	 *links,
  std::vector<struct nts::s_ast_node	*>	 *chipsets)
{
  size_t find;

  for(size_t i = 0; i < links->size(); i++)
  {
    std::string curPin;
    std::string curInput;
    std::string curPin2;
    std::string curInput2;
    find = links->at(i)->lexeme.find(':');
    if (find != std::string::npos)
    {
      curPin = links->at(i)->lexeme.substr(find + 1);
      curInput = links->at(i)->lexeme.substr(0, find);
    }

    find = links->at(i)->value.find(':');
    if (find != std::string::npos)
    {
      curPin2 = links->at(i)->value.substr(find + 1);
      curInput2 = links->at(i)->value.substr(0, find);
    }

    if (checkGate(chipsets, curInput))
    {
      if (checkGate(chipsets, curInput2))
      {
        //LINK LES DEUX GATES (SI UN DES DEUX MAILLON N'EXISTE PAS ON LE CREE)
      }
      else
      {
        // CREE LE MAILLON
        t_pin pin;

        pin.name = curInput2;
        pin.type = getType(chipsets, curInput2);
        pin.linked_to = "-1";
        pin.nbr_pin = curPin;
        this->pins[curPin] = pin;
      }
    }
     else if (checkGate(chipsets, curInput2))
    {
      if (checkGate(chipsets, curInput))
      {
        //LINK LES DEUX GATES
      }
      else
      {
        // CREE LE MAILLON
        t_pin pin;

        pin.name = curInput;
        pin.type = getType(chipsets, curInput);
        pin.linked_to = "-1";
        pin.nbr_pin = curPin2;
        this->pins[curPin2] = pin;
      }
    }
  }
}

nts::Component4071::~Component4071()
{

}

nts::Component4071::Component4071(const nts::Component4071 &obj) : Component(obj)
{
  (void)obj;
}

nts::Component4071 &nts::Component4071::operator=(const nts::Component4071 &obj)
{
  (void)obj;
  return (*this);
}

void nts::Component4071::simulate()
{
  this->pins["3"].value = this->convertBool((this->pins["1"].value or this->pins["2"].value));
  this->pins["4"].value = this->convertBool((this->pins["5"].value or this->pins["6"].value));
  this->pins["10"].value = this->convertBool((this->pins["8"].value or this->pins["9"].value));
  this->pins["11"].value = this->convertBool((this->pins["12"].value or this->pins["13"].value));
}
