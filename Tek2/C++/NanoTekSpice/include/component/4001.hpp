/*
** 4001.hpp for cpp_nanotekspice in /Users/leohubertfroideval/Documents/Shared/C++_2016/cpp_nanotekspice/include/chipsets
**
** Made by Leo Hubert Froideval
** Login   <leohubertfroideval@epitech.net>
**
** Started on  Fri Mar 03 17:40:52 2017 Leo Hubert Froideval
** Last update Fri Mar 03 20:50:48 2017 Leo Hubert Froideval
*/

#ifndef COMPONENT_4001_HPP_
#define COMPONENT_4001_HPP_

#include "Component.hpp"

namespace nts
{
  class Component4001 : public nts::Component {
  private:
    /* data */
  public:
    Component4001 (std::vector<struct nts::s_ast_node	*>	 *links,
      std::vector<struct nts::s_ast_node	*>	 *chipsets);
    virtual ~Component4001 ();
    Component4001(const Component4001 &obj);
    Component4001  &operator=(const Component4001 &obj);

    virtual void simulate();
    virtual std::map<std::string, t_pin> const &getPins() const
    {
      return (Component::getPins());
    };
    void setValue(std::string const &name, nts::Tristate const &value)
    {
      Component::setValue(name, value);
    };
    virtual IComponent *createComponent(const std::string &type,
      std::vector<struct nts::s_ast_node	*>	 *links,
      std::vector<struct nts::s_ast_node	*>	 *chipsets)
      {
        (void)links;
        (void)chipsets;
        (void)type;
        return (NULL);
      };
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
     virtual void Dump(void) const
     {
       Component::Dump();
     };
  };

}

#endif /* !COMPONENT_4001_HPP_ */
