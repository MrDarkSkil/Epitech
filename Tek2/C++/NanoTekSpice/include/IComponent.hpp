/*
** IComponent.hpp for cpp_nanotekspice in /Users/loiclopez/Documents/Shared/Epitech/year_2016/cpp_nanotekspice/include
**
** Made by loic lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  Mon Feb 06 15:46:39 2017 loic lopez
** Last update Fri Mar 03 21:21:28 2017 Leo Hubert Froideval
*/

#ifndef __ICOMPONENT_HPP__
# define __ICOMPONENT_HPP__

#include <cstddef>
#include <string>
#include "Parser.hpp"
#include "Component.hpp"

namespace nts
{
  enum Tristate
  {
     UNDEFINED = (-true),
     TRUE = true,
     FALSE = false
   };

   enum PinType
   {
     INPUT,
     OUTPUT,
     MORDOR
   };

   typedef struct s_pin
   {
     PinType type;
     std::string name;
     std::string nbr_pin;
     Tristate  value = Tristate::FALSE;
     std::string linked_to = "-1";
   } t_pin;

   class IComponent
   {
     public:

       virtual IComponent *createComponent(const std::string &type,
         std::vector<struct nts::s_ast_node	*>	 *links,
         std::vector<struct nts::s_ast_node	*>	 *chipsets) = 0;
       virtual std::map<std::string, t_pin> const &getPins() const = 0;

       virtual void setValue(std::string const &name, nts::Tristate const &value) = 0;
       virtual void simulate() = 0;

       /// Compute value of the precised pin
       virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;

       /// Useful to link IComponent together
       virtual void SetLink(size_t pin_num_this, nts::IComponent &component,
         size_t pin_num_target) = 0;

        ///// Print on terminal the name of the component and
        //// the state of every pin of the current component
        /// The output won’t be tested, but it may help you
        // as a trace.
        virtual void Dump(void) const = 0;

        virtual ~IComponent(void) { }
  };
}

#endif // __ICOMPONENT_HPP__
