#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 public:
  Cat();
  Cat(Cat const& src);
  ~Cat();

  Cat& operator=(Cat const& rhs);

  void makeSound() const;
  void showIdeas() const;
  void setIdea(std::string& idea);

 private:
  Brain* brain;
};

#endif /* ************************************************************* CAT_H \
        */