#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : type("Animal") {
  std::cout << "Animal constructor executed" << std::endl;
}

Animal::Animal(const Animal& src) {
  std::cout << "Animal copy constructor executed" << std::endl;
  if (this != &src) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() { std::cout << "Animal destructor executed" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal& Animal::operator=(Animal const& rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType() const { return this->type; };

/* ************************************************************************** */