#include "Convert.hpp"

int convertInt(std::string& val) {
  long res;
  errno = 0;
  res = strtol(val.c_str(), NULL, 10);
  if (val[0] < std::numeric_limits<int>::min() ||
      val[0] > std::numeric_limits<int>::max() || errno == ERANGE) {
    throw UnknownLiteralException();
  }
  return static_cast<int>(res);
}

void printIntFormat(std::string& val) {
  int res;
  res = convertInt(val);

  std::cout << INT_SUFFIX << res << std::endl;
}
