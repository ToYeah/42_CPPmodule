#include "HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB(std::string name) : name_(name) {
  weapon_ = NULL;
  std::cout << name_ << " was born" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB() { std::cout << name_ << " is gone" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void HumanB::attack() {
  std::string weapon_name;
  weapon_name = weapon_ == NULL ? "Fist" : weapon_->getType();
  std::cout << name_ << " attacks with his " << weapon_name << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void HumanB::setWeapon(Weapon& weapon) { weapon_ = &weapon; }

/* ************************************************************************** */