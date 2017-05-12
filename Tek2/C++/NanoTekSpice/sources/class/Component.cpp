/*
** Component.cpp for cpp_nanotekspice in /Users/hubert_i/Documents/Shared/C++_2016/cpp_nanotekspice/sources/class
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Mon Feb 27 19:10:47 2017 Leo HUBERT
** Last update Fri Mar 03 21:56:47 2017 Leo Hubert Froideval
*/

#include "Component.hpp"
#include "Exception.hpp"
#include "component/4001.hpp"
#include "component/4081.hpp"
#include "component/4011.hpp"
#include "component/4030.hpp"
#include "component/4069.hpp"
#include "component/4071.hpp"

nts::Component::Component()
{

}

nts::Component::~Component()
{

}

nts::Component::Component(const Component &obj)
{
  (void)obj;
}

nts::Component &nts::Component::operator=(const Component &obj)
{
  (void)obj;
  return (*this);
}

nts::IComponent *nts::Component::createComponent(const std::string &type,
  std::vector<struct nts::s_ast_node	*>	 *links,
  std::vector<struct nts::s_ast_node	*>	 *chipsets)
{
  if (type == "4001")
    return (this->create4001(links, chipsets));
  else if (type == "4081")
    return (this->create4081(links, chipsets));
  else if (type == "4011")
    return (this->create4011(links, chipsets));
  else if (type == "4030")
    return (this->create4030(links, chipsets));
  else if (type == "4069")
    return (this->create4069(links, chipsets));
  else if (type == "4071")
    return (this->create4071(links, chipsets));
  else
    nts::Exception::ErrorAndExit("A component type is unknown");
  return (NULL);
}

nts::IComponent *nts::Component::create4001(std::vector<struct nts::s_ast_node	*>	 *links,
  std::vector<struct nts::s_ast_node	*>	 *chipsets) const
{
  return (new nts::Component4001(links, chipsets));
}

nts::IComponent *nts::Component::create4081(std::vector<struct nts::s_ast_node	*>	 *links,
  std::vector<struct nts::s_ast_node	*>	 *chipsets) const
{
  return (new nts::Component4081(links, chipsets));
}

nts::IComponent *nts::Component::create4011(std::vector<struct nts::s_ast_node	*>	 *links,
  std::vector<struct nts::s_ast_node	*>	 *chipsets) const
{
  return (new nts::Component4011(links, chipsets));
}

nts::IComponent *nts::Component::create4030(std::vector<struct nts::s_ast_node	*>	 *links,
  std::vector<struct nts::s_ast_node	*>	 *chipsets) const
{
  return (new nts::Component4030(links, chipsets));
}

nts::IComponent *nts::Component::create4069(std::vector<struct nts::s_ast_node	*>	 *links,
  std::vector<struct nts::s_ast_node	*>	 *chipsets) const
{
  return (new nts::Component4069(links, chipsets));
}

nts::IComponent *nts::Component::create4071(std::vector<struct nts::s_ast_node	*>	 *links,
  std::vector<struct nts::s_ast_node	*>	 *chipsets) const
{
  return (new nts::Component4071(links, chipsets));
}

void nts::Component::Dump(void) const
{
  for (const auto& kv : this->pins)
  {
    std::cout << "Pin nbr: " << kv.first << " named: " << kv.second.name << " as value " << kv.second.value << std::endl;
  }
}

void nts::Component::setValue(std::string const &name, nts::Tristate const &value)
{
  std::string nb_pin = "-1";

  for (const auto& kv : this->pins)
  {
    if (name == kv.second.name)
      nb_pin = kv.second.nbr_pin;
  }
  this->pins[nb_pin].value = value;
}
