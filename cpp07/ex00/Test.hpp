#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>

#include "whatever.hpp"

template <typename T>
void test(T a, T b) {
  std::cout << "-------------------------------" << std::endl;
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  ::swap(a, b);
  std::cout << "swap(a , b) -> "
            << "a = " << a << ", b = " << b << std::endl;
}

#endif /* ************************************************************ TEST_H \
        */