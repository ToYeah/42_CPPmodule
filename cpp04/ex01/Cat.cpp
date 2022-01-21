#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() {
  this->type = "Cat";
  this->brain = new Brain();
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

Cat::~Cat() {
  delete this->brain;
  std::cout << "Cat destructor executed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat& Cat::operator=(Cat const& rhs) {
  if (this != &rhs) {
    Animal::operator=(rhs);
    this->brain = new Brain(*(rhs.brain));
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const { std::cout << "Nya-! Nya-!" << std::endl; }

void Cat::showIdeas() const { this->brain->showIdeas(); };

void Cat::setIdea(std::string idea) { this->brain->setIdea(idea); };
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */