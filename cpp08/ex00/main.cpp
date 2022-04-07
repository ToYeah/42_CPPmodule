#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main(void) {
  std::vector<int> vector = std::vector<int>(3);

  vector[0] = 1;
  vector[1] = 2;
  vector[2] = 3;

  std::list<float> list(3);

  list.push_back(4);
  list.push_back(5);
  list.push_back(6);

  std::cout << "-----------" << std::endl;
  std::vector<int>::iterator it_v;
  it_v = easyfind(vector, 1);

  while (it_v != vector.end()) {
    std::cout << *it_v;
    it_v++;
  }
  std::cout << std::endl;

  std::cout << "-----------" << std::endl;
  std::list<float>::iterator it_f;
  it_f = easyfind(list, 4);

  while (it_f != list.end()) {
    std::cout << *it_f;
    it_f++;
  }
  std::cout << std::endl;

  std::cout << "-----------" << std::endl;
  try {
    it_v = easyfind(vector, 10);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}