#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap(std::string name);

  DiamondTrap(DiamondTrap const& src);
  ~DiamondTrap();

  DiamondTrap& operator=(DiamondTrap const& rhs);

  void attack(std::string const& target);
  void whoAmI();

  std::string getName() const;

 private:
  DiamondTrap();

  std::string name_;
};

std::ostream& operator<<(std::ostream& o, DiamondTrap const& i);

#endif /* ***************************************************** DIAMONDTRAP_H \
        */