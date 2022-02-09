#include "Convert.hpp"

float convertFloat(std::string& val) {
  double res;
  errno = 0;
  res = strtod(val.c_str(), NULL);
  if (res < std::numeric_limits<float>::min() ||
      res > std::numeric_limits<float>::max() || errno == ERANGE) {
    throw UnknownLiteralException();
  }
  return static_cast<float>(res);
}

void printFloatFormat(std::string& val) {
  float res;
  char* res_char_ptr = NULL;
  int* res_int_ptr = NULL;

  res = convertFloat(val);
  if (isCharRange(res)) {
    char res_char = static_cast<char>(res);
    res_char_ptr = &res_char;
  }
  if (isIntRange(res)) {
    int res_int = static_cast<int>(res);
    res_int_ptr = &res_int;
  }
  double res_double = static_cast<double>(res);

  printValues(res_char_ptr, res_int_ptr, &res, &res_double);
}
