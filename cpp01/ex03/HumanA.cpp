#include "HumanA.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(std::string name, Weapon& weapon)
    : weapon_(weapon), name_(name) {
  std::cout << name_ << " was born" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA() { std::cout << name_ << " is gone" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void HumanA::attack() {
  std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */