#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  Animal* animals[4];

  for (size_t i = 0; i < 2; i++) {
    animals[i] = new Dog();
    std::cout << "\n";
  }
  for (size_t i = 2; i < 4; i++) {
    animals[i] = new Cat();
    std::cout << "\n";
  }
  std::cout << "\n////////////////////////////////\n" << std::endl;

  for (size_t i = 0; i < 4; i++) {
    delete animals[i];
    std::cout << "\n";
  }

  std::cout << "\n////////////////////////////////\n" << std::endl;

  Dog dog1;
  Dog dog2;

  dog1.setIdea("hello");
  dog2 = dog1;
  dog1.setIdea("HELLO");
  dog2.setIdea("world");
  dog1.showIdeas();
  dog2.showIdeas();

  std::cout << "\n////////////////////////////////\n" << std::endl;

  Cat cat1;
  Cat cat2;

  cat1.setIdea("neko");
  cat2 = cat1;
  cat1.setIdea("NEKO");
  cat2.setIdea("world");
  cat1.showIdeas();
  cat2.showIdeas();
}