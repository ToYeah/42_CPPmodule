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
}