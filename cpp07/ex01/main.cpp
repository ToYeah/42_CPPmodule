#include "iter.hpp"

int main(void) {
  int int_array[3] = {1, 2, 3};
  float float_array[3] = {1.5, 2.5, 3.5};

  ::iter(int_array, 3, ::print);
  std::cout << "------------" << std::endl;
  ::iter(float_array, 3, ::print);

  return 0;
}