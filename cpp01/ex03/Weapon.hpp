#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
 public:
  Weapon(std::string name);
  ~Weapon();

  const std::string& getType() const;
  void setType(const std::string& name);

 private:
  std::string type_;
};

#endif /* ********************************************************** WEAPON_H \
        */