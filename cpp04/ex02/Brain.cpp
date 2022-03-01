#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() : index(0), idea_size(0) {
  std::cout << "Brain constructor executed" << std::endl;
}

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
    for (size_t i = 0; i < k_idea_max_size; i++) {
      this->ideas[i] = rhs.ideas[i];
    }
    this->index = rhs.index;
    this->idea_size = rhs.idea_size;
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Brain::showIdeas() const {
  std::cout << "-----IDEAS-----" << std::endl;
  for (size_t i = 0; i < idea_size; i++) {
    std::cout << ideas[i] << std::endl;
  }
  std::cout << "---------------" << std::endl;
};

void Brain::setIdea(std::string& idea) {
  ideas[index] = idea;

  bool is_max_index = index + 1 == k_idea_max_size;
  index = is_max_index ? 0 : index + 1;
  idea_size = is_max_index ? k_idea_max_size : idea_size + 1;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */