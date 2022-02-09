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
  char* res_char_ptr = NULL;

  res = convertInt(val);
  if (isCharRange(res)) {
    char res_char = static_cast<char>(res);
    res_char_ptr = &res_char;
  }
  float res_float = static_cast<float>(res);
  double res_double = static_cast<double>(res);

  printValues(res_char_ptr, &res, &res_float, &res_double);
}

bool isIntRange(float& val) {
  if (val >= std::numeric_limits<int>::min() &&
      val <= std::numeric_limits<int>::max()) {
    return true;
  }
  return false;
}

bool isIntRange(double& val) {
  if (val >= std::numeric_limits<int>::min() &&
      val <= std::numeric_limits<int>::max()) {
    return true;
  }
  return false;
}