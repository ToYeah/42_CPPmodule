#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  FragTrap(std::string name);
  FragTrap(FragTrap const& src);
  ~FragTrap();

  FragTrap& operator=(FragTrap const& rhs);

  void attack(std::string const& target);
  void highFivesGuys(void);

 private:
  FragTrap();

  static const size_t k_default_hit_points = 100;
  static const size_t k_default_energy_points_ = 100;
  static const size_t k_default_attack_damage_ = 30;
};

std::ostream& operator<<(std::ostream& o, FragTrap const& i);

#endif /* ******************************************************** FRAGTRAP_H \
        */