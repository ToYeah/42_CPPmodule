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

void Brain::showIdeas() const {
  std::cout << "-----IDEAS-----" << std::endl;
  for (size_t i = 0; i < idea_size; i++) {
    std::cout << this->ideas[i] << std::endl;
  }
  std::cout << "---------------" << std::endl;
};

void Brain::setIdea(std::string& idea) {
  this->ideas[index] = idea;
  this->index = this->index == Brain::k_idea_max_size ? 0 : this->index + 1;
  this->idea_size = this->index == Brain::k_idea_max_size
                        ? Brain::k_idea_max_size
                        : idea_size + 1;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */