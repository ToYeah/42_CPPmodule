#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() : type_("none") {}

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

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const& AMateria::getType() const { return this->type_; };

void AMateria::use(ICharacter& target) {
  std::cout << "* AMateria! Type " << target.getName() << "’s wounds *"
            << std::endl;
}

/* ************************************************************************** */