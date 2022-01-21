#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() {
  this->type = "Dog";
  this->brain = new Brain();
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

Dog::~Dog() {
  delete this->brain;
  std::cout << "Dog destructor executed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog& Dog::operator=(Dog const& rhs) {
  if (this != &rhs) {
    Animal::operator=(rhs);
    *(this->brain) = *(rhs.brain);
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const { std::cout << "Wan! Wan!" << std::endl; }

void Dog::showIdeas() const { this->brain->showIdeas(); };

void Dog::setIdea(std::string& idea) { this->brain->setIdea(idea); };
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */