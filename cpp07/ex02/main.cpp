#include <cstdlib>
#include <ctime>

#include "Array.hpp"
#define MAX_VAL 750
int main(void) {
  std::cout << "Subject Test ------------------------------------" << std::endl;
  {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
      const int value = rand();
      numbers[i] = value;
      mirror[i] = value;
    }
    // SCOPE
    {
      Array<int> tmp = numbers;
      Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
      if (mirror[i] != numbers[i]) {
        std::cerr << "didn't save the same value!!" << std::endl;
        return 1;
      }
    }
    try {
      numbers[-2] = 0;
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    try {
      numbers[MAX_VAL] = 0;
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
      numbers[i] = rand();
    }
    delete[] mirror;
  }

  std::cout << "-------------------------------------------------" << std::endl;
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