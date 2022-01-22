#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria(std::string const& type) : type_(type) {}

AMateria::AMateria(const AMateria& src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria& AMateria::operator=(AMateria const& rhs) {
  if (this != &rhs) {
    this->type_ = rhs.type_;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, AMateria const& i) {
  std::cout << "This is AMateria \"" << i.getType() << "\"" << std::endl;
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const& AMateria::getType() const { return this->type_; };

/* ************************************************************************** */