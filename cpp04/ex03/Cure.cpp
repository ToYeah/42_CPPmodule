#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& src) : AMateria(src) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure& Cure::operator=(Cure const& rhs) {
  if (this != &rhs) {
    AMateria::operator=(rhs);
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, Cure const& i) {
  std::cout << "This is " << i.getType() << std::endl;
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria* Cure::clone() const { return new Cure(*this); };

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */