#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(): name_("none"), hit_points_(0), energy_points_(0), attack_damage_(0) {
  std::cout << "ClapTrap was born.(DefaultConstructor)" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name_(name), hit_points_(10), energy_points_(10), attack_damage_(0) {
  std::cout << "ClapTrap was born." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
  if (this != &src) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() { std::cout << "ClapTrap was gone." << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
  if (this != &rhs) {
    this->name_ = rhs.name_;
    this->hit_points_ = rhs.hit_points_;
    this->energy_points_ = rhs.energy_points_;
    this->attack_damage_ = rhs.attack_damage_;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, ClapTrap const& i) {
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

void ClapTrap::attack(std::string const& target) {
  std::cout << "ClapTrap " << this->name_ << " attack " << target
            << ", causing " << this->attack_damage_ << " points of damage!"
            << std::endl;
};

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << this->name_ << " takes " << amount << " points of damage."
            << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << this->name_ << " has repaired " << amount << " points."
            << std::endl;
};

/*
** --------------------------------- ACCESSOR
*---------------------------------
*/

std::string ClapTrap::getName() const { return this->name_; };

int ClapTrap::getHitPoints() const { return this->hit_points_; };

int ClapTrap::getEnergyPoints() const { return this->energy_points_; };

int ClapTrap::getAttackDamage() const { return this->attack_damage_; };

/* **************************************************************************
 */