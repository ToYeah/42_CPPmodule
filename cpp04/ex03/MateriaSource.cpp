#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource() : index_(0) {
  for (size_t i = 0; i < k_max_materias_size; i++) {
    materias_[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource& src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource() {
  for (size_t i = 0; i < k_max_materias_size; i++) {
    delete materias_[i];
  }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs) {
  if (this != &rhs) {
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

void MateriaSource::learnMateria(AMateria* m) {
  if (m) {
    delete materias_[index_];
    materias_[index_] = m;
    index_++;
    index_ = index_ == k_max_materias_size ? 0 : index_;
  }
};

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (size_t i = 0; i < k_max_materias_size; i++) {
    if (materias_[i] && materias_[i]->getType() == type) {
      return materias_[i]->clone();
    }
  }
  return NULL;
};

void MateriaSource::showMaterias() {
  std::cout << "----------" << std::endl;
  std::cout << "Name: "
            << "MateriaSource" << std::endl;
  for (size_t i = 0; i < k_max_materias_size; i++) {
    std::string materiaName =
        this->materias_[i] ? this->materias_[i]->getType() : "NULL";
    std::cout << i << ": " << materiaName << std::endl;
  }
  std::cout << "----------" << std::endl;
};

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */