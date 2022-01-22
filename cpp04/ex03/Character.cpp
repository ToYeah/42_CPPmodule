#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(std::string name) : name_(name), index_(0) {
  for (size_t i = 0; i < k_max_materias_size; i++) {
    materias_[i] = NULL;
  }
};

Character::Character(const Character& src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character() {
  for (size_t i = 0; i < k_max_materias_size; i++) {
    delete materias_[i];
  }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character& Character::operator=(Character const& rhs) {
  if (this != &rhs) {
    this->name_ = rhs.name_;
    for (size_t i = 0; i < k_max_materias_size; i++) {
      delete this->materias_[i];
      this->materias_[i] = rhs.materias_[i]->clone();
    }
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m) {
  delete materias_[index_];
  materias_[index_] = m;
  index_++;
  index_ = index_ == k_max_materias_size ? 0 : index_;
};

void Character::unequip(int idx) {
  if (idx < k_max_materias_size) {
    delete materias_[idx];
    materias_[idx] = NULL;
  }
};

void Character::use(int idx, ICharacter& target) {
  if (idx < k_max_materias_size && materias_[idx]) {
    materias_[idx]->use(target);
  }
};

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const& Character::getName() const { return this->name_; };

/* ************************************************************************** */