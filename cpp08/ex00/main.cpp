#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main(void) {
  std::vector<int> value = std::vector<int>(3);
  std::vector<int>::iterator iter;

  value[0] = 1;
  value[1] = 2;
  value[2] = 3;

  iter = easyfind(value, 1);
  while (*iter) {
    std::cout << *iter << ", ";
    iter++;
  }
  std::cout << std::endl;

  iter = easyfind(value, 2);
  while (*iter) {
    std::cout << *iter << ", ";
    iter++;
  }
  std::cout << std::endl;

  value[1] = 5;
  iter = easyfind(value, 1);
  while (*iter) {
    std::cout << *iter << ", ";
    iter++;
  }
  std::cout << std::endl;

  try {
    std::vector<int> error_value = std::vector<int>(3);
    error_value[0] = 1;
    error_value[1] = 2;
    error_value[2] = 3;
    easyfind(error_value, 4);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}