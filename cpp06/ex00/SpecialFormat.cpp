#include "Convert.hpp"

void printNanFormat() {
  float res_float;
  double res_double;

  res_double = std::numeric_limits<double>::quiet_NaN();
  res_float = std::numeric_limits<float>::quiet_NaN();

  printValues(NULL, NULL, &res_float, &res_double);
}

void printPInfFormat() {
  float res_float;
  double res_double;

  res_double = std::numeric_limits<double>::infinity();
  res_float = std::numeric_limits<float>::infinity();
  std::cout << CHAR_SUFFIX << IMPOSSIBLE << std::endl;
  std::cout << INT_SUFFIX << IMPOSSIBLE << std::endl;
  std::cout << FLOAT_SUFFIX << res_float << "f" << std::endl;
  std::cout << DOUBLE_SUFFIX << res_double << std::endl;
}

void printMInfFormat() {
  float res_float;
  double res_double;

  res_double = std::numeric_limits<double>::infinity() * -1;
  res_float = std::numeric_limits<float>::infinity() * -1;
  std::cout << CHAR_SUFFIX << IMPOSSIBLE << std::endl;
  std::cout << INT_SUFFIX << IMPOSSIBLE << std::endl;
  std::cout << FLOAT_SUFFIX << res_float << "f" << std::endl;
  std::cout << DOUBLE_SUFFIX << res_double << std::endl;
}
