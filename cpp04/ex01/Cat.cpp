#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() {
  this->type = "Cat";
  std::cout << "Cat constructor executed" << std::endl;
}

Cat::Cat(const Cat& src) {
  std::cout << "Cat copy constructor executed" << std::endl;
  if (this != &src) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() { std::cout << "Cat destructor executed" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat& Cat::operator=(Cat const& rhs) {
  if (this != &rhs) {
    Animal::operator=(rhs);
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const { std::cout << "Nya-! Nya-!" << std::endl; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */