
#include "Test.hpp"
#include "whatever.hpp"

int main(void) {
  std::cout << "Subject Test ------------------------------------" << std::endl;
  int a = 2;
  int b = 3;
  swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  float f_a = 20.3;
  float f_b = -123.4;
  test(f_a, f_b);

  std::string str_a = "hello!";
  std::string str_b = "world";
  test(str_a, str_b);

  int *p_a = &a;
  int *p_b = &b;
  test(p_a, p_b);

  return 0;
}