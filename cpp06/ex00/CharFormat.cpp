#include "Convert.hpp"

void printCharFormat(std::string& val) {
  char res;
  res = val[0];

  std::cout << CHAR_SUFFIX;
  if (res >= PRINTABLE_MIN && res <= PRINTABLE_MAX) {
    std::cout << "'" << res << "'" << std::endl;
  } else {
    std::cout << NON_PRINTABLE_STR << std::endl;
  }
  std::cout << INT_SUFFIX << static_cast<int>(res) << std::endl;
  std::cout << FLOAT_SUFFIX << static_cast<float>(res) << std::endl;
  std::cout << DOUBLE_SUFFIX << static_cast<double>(res) << std::endl;
}
