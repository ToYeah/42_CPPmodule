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

 protected:
  ClapTrap();
  ClapTrap(std::string name, int hit_points, int energy_points,
           int attack_damage);

 private:

  std::string name_;
  int hit_points_;
  int energy_points_;
  int attack_damage_;

  static const size_t k_default_hit_points = 10;
  static const size_t k_default_energy_points_ = 10;
  static const size_t k_default_attack_damage_ = 0;
};

std::ostream& operator<<(std::ostream& o, ClapTrap const& i);

#endif /* ******************************************************** CLAPTRAP_H \
        */