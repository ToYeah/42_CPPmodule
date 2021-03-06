#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "ScavTrap \"" << getName() << "\" was born.(DefaultConstructor)"
            << std::endl;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name, k_default_hit_points, k_default_energy_points_,
               k_default_attack_damage_) {
  std::cout << "ScavTrap \"" << name << "\" was born." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
  if (this != &src) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap \"" << this->getName() << "\" was gone." << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
  if (this != &rhs) {
    ClapTrap::operator=(rhs);
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, ScavTrap const& i) {
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

void ScavTrap::attack(std::string const& target) {
  std::cout << "ScavTrap " << this->getName() << " attack " << target
            << ", causing " << this->getAttackDamage() << " points of damage!"
            << std::endl;
};

void ScavTrap::guardGate() {
  std::cout << "ScavTrap \"" << this->getName()
            << "\" have enterred in Gate keeper mode." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */