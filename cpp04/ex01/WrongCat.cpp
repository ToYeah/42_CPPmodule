#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() {
  this->type = "WrongCat";
  std::cout << "WrongCat constructor executed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) {
  std::cout << "WrongCat copy constructor executed" << std::endl;
  if (this != &src) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor executed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat& WrongCat::operator=(WrongCat const& rhs) {
  if (this != &rhs) {
    WrongAnimal::operator=(rhs);
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound() const { std::cout << "Meaw-! Meaw-!" << std::endl; }
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */