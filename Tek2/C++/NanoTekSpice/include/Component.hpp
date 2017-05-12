/*
** Component.hpp for cpp_nanotekspice in /Users/hubert_i/Documents/Shared/C++_2016/cpp_nanotekspice/include
**
** Made by Leo HUBERT
** Login   <leo.hubert@epitech.eu>
**
** Started on  Mon Feb 27 19:11:09 2017 Leo HUBERT
** Last update Fri Mar 03 21:55:44 2017 Leo Hubert Froideval
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <map>
#include <vector>
#include <iostream>
#include "IComponent.hpp"
#include "Parser.hpp"

namespace nts
{
  class Component : public IComponent
  {
  protected:
      std::map<std::string, t_pin> pins;
  private:
    IComponent *create4001(std::vector<struct nts::s_ast_node	*> *links, std::vector<struct nts::s_ast_node	*> *chipsets) const;
    IComponent *create4081(std::vector<struct nts::s_ast_node	*> *links, std::vector<struct nts::s_ast_node	*> *chipsets) const;
    IComponent *create4011(std::vector<struct nts::s_ast_node	*> *links, std::vector<struct nts::s_ast_node	*> *chipsets) const;
    IComponent *create4030(std::vector<struct nts::s_ast_node	*> *links, std::vector<struct nts::s_ast_node	*> *chipsets) const;
    IComponent *create4069(std::vector<struct nts::s_ast_node	*> *links, std::vector<struct nts::s_ast_node	*> *chipsets) const;
    IComponent *create4071(std::vector<struct nts::s_ast_node	*> *links, std::vector<struct nts::s_ast_node	*> *chipsets) const;
    /* data */
  public:
    Component ();
    virtual ~Component ();
    Component(const Component &obj);
    Component  &operator=(const Component &obj);
    virtual IComponent *createComponent(const std::string &type,
      std::vector<struct nts::s_ast_node	*>	 *links,
      std::vector<struct nts::s_ast_node	*>	 *chipsets);
    Tristate convertBool(bool boolean)
    {
      if (boolean == 1)
        return (Tristate::TRUE);
      else
        return (Tristate::FALSE);
      return (Tristate::FALSE);
    }


    virtual std::map<std::string, t_pin> const &getPins() const
    {
      return (this->pins);
    };
    virtual void setValue(std::string const &name, nts::Tristate const &value);
    virtual void simulate() { };
    virtual nts::Tristate Compute(size_t pin_num_this)
    {
      (void)pin_num_this;
      return nts::Tristate::UNDEFINED;
    };
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component,
      size_t pin_num_target)
      {
        (void)pin_num_target;
        (void)pin_num_this;
        (void)component;
      };
    virtual void Dump(void) const;
  };

}

#endif /* !COMPONENT_HPP_ */
