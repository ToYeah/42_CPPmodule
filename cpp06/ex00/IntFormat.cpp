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
  float* res_float_ptr = NULL;
  double* res_double_ptr = NULL;

  res = convertInt(val);
  if (isCharRange(res)) {
    char res_char = static_cast<char>(res);
    res_char_ptr = &res_char;
  }
  float res_float = static_cast<float>(res);
  res_float_ptr = &res_float;
  double res_double = static_cast<double>(res);
  res_double_ptr = &res_double;

  printValues(res_char_ptr, &res, res_float_ptr, res_double_ptr);
}
