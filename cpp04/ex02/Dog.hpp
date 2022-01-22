#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(Dog const& src);
  ~Dog();

  Dog& operator=(Dog const& rhs);

  void makeSound() const;
  void showIdeas() const;
  void setIdea(std::string idea);

 private:
  Brain* brain;
};

#endif /* ************************************************************* DOG_H \
        */