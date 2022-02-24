#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap \"" << getName() << "\" was born.(DefaultConstructor)"
            << std::endl;
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name, k_default_hit_points, k_default_energy_points_,
               k_default_attack_damage_) {
  std::cout << "FragTrap \"" << name << "\" was born." << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
  if (this != &src) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap() {
  std::cout << "FragTrap \"" << this->getName() << "\" was gone." << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
  if (this != &rhs) {
    ClapTrap::operator=(rhs);
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, FragTrap const& i) {
  std::cout << "-----------------------" << std::endl;
  std::cout << "Name: " << i.getName() << std::endl;
  std::cout << "HitPoints: " << i.getHitPoints() << std::endl;
  std::cout << "EnergyPoints: " << i.getEnergyPoints() << std::endl;
  std::cout << "AtackDamage: " << i.getAttackDamage() << std::endl;
  std::cout << "-----------------------" << std::endl;
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::attack(std::string const& target) {
  std::cout << "FragTrap " << this->getName() << " attack " << target
            << ", causing " << this->getAttackDamage() << " points of damage!"
            << std::endl;
};

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap \"" << this->getName()
            << "\" said \'Give me highfive!\'" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */