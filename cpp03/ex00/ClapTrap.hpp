#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iomanip>
#include <iostream>
#include <string>

class ClapTrap {
 public:
  ClapTrap(std::string name);
  ClapTrap(ClapTrap const& src);
  ~ClapTrap();

  ClapTrap& operator=(ClapTrap const& rhs);

  void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDamage() const;

 private:
  ClapTrap();

  std::string name_;
  int hit_points_;
  int energy_points_;
  int attack_damage_;
};

std::ostream& operator<<(std::ostream& o, ClapTrap const& i);

#endif /* ******************************************************** CLAPTRAP_H \
        */