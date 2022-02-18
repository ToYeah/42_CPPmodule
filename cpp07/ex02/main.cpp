#include "Array.hpp"

int main(void) {
  Array<int> int_array;

  std::cout << "Size: " << int_array.size() << std::endl;

  int_array = Array<int>(3);
  std::cout << "Size: " << int_array.size() << std::endl;

  for (size_t i = 0; i < int_array.size(); i++) {
    std::cout << "int_array[" << i << "]: " << int_array[i] << std::endl;
  }

  int_array[0] = 1;
  int_array[1] = 2;
  int_array[2] = 3;

  for (size_t i = 0; i < int_array.size(); i++) {
    std::cout << "int_array[" << i << "]: " << int_array[i] << std::endl;
  }

  Array<int> int_array2;
  int_array2 = int_array;

  std::cout << "Size: " << int_array2.size() << std::endl;
  for (size_t i = 0; i < int_array2.size(); i++) {
    std::cout << "int_array2[" << i << "]: " << int_array2[i] << std::endl;
  }

  Array<int> int_array3 = Array<int>(3);
  int_array3 = Array<int>(int_array2);

  int_array3[0] = 4;
  int_array3[1] = 5;
  int_array3[2] = 6;

  std::cout << "Size: " << int_array3.size() << std::endl;
  for (size_t i = 0; i < int_array3.size(); i++) {
    std::cout << "int_array3[" << i << "]: " << int_array3[i] << std::endl;
  }

  std::cout << "Size: " << int_array2.size() << std::endl;
  for (size_t i = 0; i < int_array2.size(); i++) {
    std::cout << "int_array2[" << i << "]: " << int_array2[i] << std::endl;
  }

  std::cout << "-------------------" << std::endl;

  return 0;
}