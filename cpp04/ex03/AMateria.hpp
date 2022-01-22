#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {
 public:
  AMateria(std::string const& type);
  AMateria(AMateria const& src);
  virtual ~AMateria();

  AMateria& operator=(AMateria const& rhs);

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

  std::string const& getType() const;

 protected:
  std::string type_;

 private:
  AMateria();
};

std::ostream& operator<<(std::ostream& o, AMateria const& i);

#endif /* ******************************************************** AMATERIA_H \
        */