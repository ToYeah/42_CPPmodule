#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource();
  MateriaSource(MateriaSource const& src);
  ~MateriaSource();

  void learnMateria(AMateria* m);
  AMateria* createMateria(std::string const& type);
  void showMaterias();

  MateriaSource& operator=(MateriaSource const& rhs);

 private:
  static const size_t k_max_materias_size = 4;

  AMateria* materias_[k_max_materias_size];
  size_t index_;
};

std::ostream& operator<<(std::ostream& o, MateriaSource const& i);

#endif /* *************************************************** MATERIASOURCE_H \
        */