#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name", FragTrap::k_default_hit_points,
               ScavTrap::k_default_energy_points_,
               FragTrap::k_default_attack_damage_),
      ScavTrap(name + "_clap_name"),
      FragTrap(name + "_clap_name"),
      name_(name) {
  std::cout << "DiamondTrap \"" << name << "\" was born." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
    : ClapTrap(src), ScavTrap(src), FragTrap(src) {
  if (this != &src) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap \"" << this->name_ << "\" was gone." << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs) {
  if (this != &rhs) {
    ClapTrap::operator=(rhs);
    this->name_ = rhs.name_;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, DiamondTrap const& i) {
  std::cout << "-----------------------" << std::endl;
  std::cout << "Name: " << i.getName() << std::endl;
  std::cout << "ClapName: " << i.ClapTrap::getName() << std::endl;
  std::cout << "HitPoints: " << i.getHitPoints() << std::endl;
  std::cout << "EnergyPoints: " << i.getEnergyPoints() << std::endl;
  std::cout << "AtackDamage: " << i.getAttackDamage() << std::endl;
  std::cout << "-----------------------" << std::endl;
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void DiamondTrap::attack(std::string const& target) {
  this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "My name is \"" << this->getName() << "\"" << std::endl;
  std::cout << "My ClapTrap name is \"" << this->ClapTrap::getName() << "\""
            << std::endl;
};
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string DiamondTrap::getName() const { return this->name_; };

/* ************************************************************************** */