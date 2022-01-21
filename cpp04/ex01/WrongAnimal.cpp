#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal() : type("Animal") {
  std::cout << "WrongAnimal constructor executed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
  std::cout << "WrongAnimal copy constructor executed" << std::endl;
  if (this != &src) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor executed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal!" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongAnimal::getType() const { return this->type; };

/* ************************************************************************** */