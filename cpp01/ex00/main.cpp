#include "Zombie.hpp"

int main() {
  try {
    Zombie *nosuzuki;
    Zombie *sso;

    nosuzuki = newZombie("nosuzuki");
    sso = newZombie("sso");

    nosuzuki->announce();
    sso->announce();

    randomChump("kohkubo");

    delete nosuzuki;
    delete sso;

  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
}