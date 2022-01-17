#include "Weapon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Weapon::Weapon(std::string type) : type_(type) {
  std::cout << type_ << " was cerated" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Weapon::~Weapon() { std::cout << type_ << " was throw away" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Weapon::getType() const { return type_; }

void Weapon::setType(const std::string& name) { type_ = name; }

/* ************************************************************************** */