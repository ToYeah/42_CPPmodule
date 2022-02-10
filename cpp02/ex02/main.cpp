#include <iomanip>
#include <iostream>

#include "Fixed.hpp"

void test(Fixed a, Fixed b) {
  std::cout << a << "  +  " << b << "  " << a + b << std::endl;
  std::cout << a << "  -  " << b << "  " << a - b << std::endl;
  std::cout << a << "  *  " << b << "  " << a * b << std::endl;
  std::cout << a << "  /  " << b << "  " << a / b << std::endl;
  std::cout << a << "  <  " << b << "  " << (a < b) << std::endl;
  std::cout << a << "  >  " << b << "  " << (a > b) << std::endl;
  std::cout << a << " <=  " << b << "  " << (a <= b) << std::endl;
  std::cout << a << " >=  " << b << "  " << (a >= b) << std::endl;
  std::cout << a << " ==  " << b << "  " << (a == b) << std::endl;
  std::cout << a << " !=  " << b << "  " << (a != b) << std::endl;
  std::cout << a << " max " << b << "  " << Fixed::max(a, b) << std::endl;
  std::cout << a << " min " << b << "  " << Fixed::min(a, b) << std::endl;
  std::cout << "------------------------------------------" << std::endl;
}

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  test(10, 20);
  test(10, -10);
  test(10, 10);
  test(1, -1);
  test(0.5f, 0.2f);
}
