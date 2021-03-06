#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie() {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie() { std::cout << name_ << " is gone." << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void Zombie::announce(void) {
  std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void Zombie::SetName(const std::string& s) { name_ = s; }

/* ************************************************************************** */