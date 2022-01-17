#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
 public:
  Zombie();
  ~Zombie();
  void announce(void);

  void SetName(const std::string& s);

 private:
  std::string name_;
};

Zombie* zombieHorde(int N, std::string name);

#endif /* ********************************************************** ZOMBIE_H \
        */