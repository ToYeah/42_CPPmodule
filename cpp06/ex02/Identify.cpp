#include "Identify.hpp"

Base* generate(void) {
  int rand_value = rand() % 3;
  switch (rand_value) {
    case 0:
      return new A();
      break;
    case 1:
      return new B();
      break;
    case 2:
      return new C();
      break;
  }
  return NULL;
};

void identify(Base* p) {
  if (dynamic_cast<A*>(p) != NULL) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p) != NULL) {
    std::cout << "B" << std::endl;
  } else {
    std::cout << "C" << std::endl;
  }
};

void identify(Base& p) {
  Base a = p;

  if (dynamic_cast<A*>(&p) != NULL) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(&p) != NULL) {
    std::cout << "B" << std::endl;
  } else {
    std::cout << "C" << std::endl;
  }
}