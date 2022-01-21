#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() {
  this->type = "Dog";
  std::cout << "Dog constructor executed" << std::endl;
}

Dog::Dog(const Dog& src) {
  std::cout << "Dog copy constructor executed" << std::endl;
  if (this != &src) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() { std::cout << "Dog destructor executed" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog& Dog::operator=(Dog const& rhs) {
  if (this != &rhs) {
    Animal::operator=(rhs);
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const { std::cout << "Wan! Wan!" << std::endl; }
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */