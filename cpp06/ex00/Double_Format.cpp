#include "Convert.hpp"

double convertDouble(std::string& val) {
  double res;
  errno = 0;
  res = strtod(val.c_str(), NULL);
  if (errno == ERANGE) {
    throw ImpossibleException();
  }
  return static_cast<float>(res);
}

void printDoubleFormat(std::string& val) {
  double res;
  char* res_char_ptr = NULL;
  int* res_int_ptr = NULL;

  res = convertDouble(val);
  if (isCharRange(res)) {
    char res_char = static_cast<char>(res);
    res_char_ptr = &res_char;
  }
  if (isIntRange(res)) {
    int res_int = static_cast<int>(res);
    res_int_ptr = &res_int;
  }
  float res_float = static_cast<float>(res);

  printValues(res_char_ptr, res_int_ptr, &res_float, &res);
}
