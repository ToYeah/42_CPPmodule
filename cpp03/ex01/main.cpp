#include "ScavTrap.hpp"

int main(void) {
  ClapTrap clap("clap");
  std::cout << clap << std::endl;
  clap.attack("enemy");
  clap.takeDamage(100);
  clap.beRepaired(100);

  std::cout << "\n/////////////////////////////////////\n" << std::endl;

  ScavTrap scav("scav");
  std::cout << scav;
  scav.attack("enemy");
  scav.takeDamage(100);
  scav.beRepaired(100);
  scav.guardGate();
}