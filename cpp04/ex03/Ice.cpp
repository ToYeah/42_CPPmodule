#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& src) : AMateria(src) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice& Ice::operator=(Ice const& rhs) {
  if (this != &rhs) {
    AMateria::operator=(rhs);
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, Ice const& i) {
  std::cout << "This is " << i.getType() << std::endl;
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */