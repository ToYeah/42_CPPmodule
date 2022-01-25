#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class Character : public ICharacter {
 public:
  Character(std::string name);
  Character(Character const& src);
  ~Character();

  Character& operator=(Character const& rhs);

  std::string const& getName() const;
  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter& target);
  void showMaterias();

 private:
  Character();

  static const int k_max_materias_size = 4;

  std::string name_;
  AMateria* materias_[k_max_materias_size];
  size_t index_;
};

std::ostream& operator<<(std::ostream& o, Character const& i);

#endif /* ******************************************************* CHARACTER_H \
        */