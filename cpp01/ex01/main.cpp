#include "Zombie.hpp"

int main() {
  try {
    Zombie* brand;
    Zombie* nunu;

    int brand_count = 3;
    int nunu_count = 6;

    brand = zombieHorde(brand_count, "Brand");
    nunu = zombieHorde(nunu_count, "Nunu");

    for (int i = 0; i < nunu_count; i++) {
      nunu[i].announce();
    }

    for (int i = 0; i < brand_count; i++) {
      brand[i].announce();
    }

    delete[] brand;

    delete[] nunu;

  } catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }
}