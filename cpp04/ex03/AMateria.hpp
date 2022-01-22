#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class AMateria {
 public:
  AMateria(std::string const& type);

  std::string const& getType() const;

  virtual AMateria* clone() const = 0;
  // virtual void use(ICharacter& target);

 protected:
  std::string type_;
};

#endif /* ******************************************************** AMATERIA_H \
        */