#include "ClapTrap.hpp"

int main(void) {
  ClapTrap trap("robot");
  std::cout << trap << std::endl;
  trap.attack("enemy");
  trap.takeDamage(100);
  trap.beRepaired(100);
}