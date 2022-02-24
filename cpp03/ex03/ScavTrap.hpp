#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap(std::string name);
  ScavTrap(ScavTrap const& src);
  ~ScavTrap();

  ScavTrap& operator=(ScavTrap const& rhs);

  void attack(std::string const& target);
  void guardGate();

 protected:
  ScavTrap();
  static const size_t k_default_energy_points_ = 50;

 private:
  static const size_t k_default_hit_points = 100;
  static const size_t k_default_attack_damage_ = 20;
};

std::ostream& operator<<(std::ostream& o, ScavTrap const& i);

#endif /* ******************************************************** SCAVTRAP_H \
        */