#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <bitset>
#include <cstdint>
#include <iostream>
#include <string>

typedef struct {
  std::string name;
  int age;
} Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
