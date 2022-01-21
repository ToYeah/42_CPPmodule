#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() { std::cout << "Brain constructor executed" << std::endl; }

Brain::Brain(const Brain& src) {
  std::cout << "Brain copy constructor executed" << std::endl;
  if (this != &src) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() { std::cout << "Brain destructor executed" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain& Brain::operator=(Brain const& rhs) {
  if (this != &rhs) {
    for (size_t i = 0; i < 100; i++) {
      this->ideas[i] = rhs.ideas[i];
    }
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */