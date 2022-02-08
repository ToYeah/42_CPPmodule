#include "Converter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Converter::Converter() {}
Converter::Converter(std::string value) : original_value_(value) {}

Converter::Converter(const Converter& src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Converter::~Converter() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Converter& Converter::operator=(Converter const&) {
  // if ( this != &rhs )
  //{
  // this->_value = rhs.getValue();
  //}
  return *this;
}

std::ostream& operator<<(std::ostream& o, Converter const& i) {
  o << "Original: " << i.getOriginalValue() << std::endl;
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Converter::getOriginalValue() const {
  return original_value_;
};
/* ************************************************************************** */