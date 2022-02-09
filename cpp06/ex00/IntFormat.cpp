#include "Convert.hpp"

int convertInt(std::string& val) {
  long res;
  errno = 0;
  res = strtol(val.c_str(), NULL, 10);
  if (res < std::numeric_limits<int>::min() ||
      res > std::numeric_limits<int>::max() || errno == ERANGE) {
    throw UnknownLiteralException();
  }
  return static_cast<int>(res);
}

void printIntFormat(std::string& val) {
  int res;
  res = convertInt(val);

  std::cout << CHAR_SUFFIX;
  if (res >= PRINTABLE_MIN && res <= PRINTABLE_MAX) {
    std::cout << "'" << static_cast<char>(res) << "'" << std::endl;
  } else {
    std::cout << NON_PRINTABLE_STR << std::endl;
  }
  std::cout << INT_SUFFIX << res << std::endl;
  std::cout << FLOAT_SUFFIX << static_cast<float>(res) << std::endl;
  std::cout << DOUBLE_SUFFIX << static_cast<double>(res) << std::endl;
}
