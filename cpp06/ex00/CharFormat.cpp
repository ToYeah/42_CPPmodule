#include "Convert.hpp"

void printCharFormat(std::string& val) {
  char res_char;
  int res_int;
  float res_float;
  double res_double;

  res_char = val[0];
  res_int = static_cast<int>(res_char);
  res_float = static_cast<float>(res_char);
  res_double = static_cast<double>(res_char);

  printValues(&res_char, &res_int, &res_float, &res_double);
}

bool isCharRange(float& val) {
  if (val >= std::numeric_limits<char>::min() &&
      val <= std::numeric_limits<char>::max()) {
    return true;
  }
  return false;
}
bool isCharRange(int& val) {
  if (val >= std::numeric_limits<char>::min() &&
      val <= std::numeric_limits<char>::max()) {
    return true;
  }
  return false;
}
bool isCharRange(double& val) {
  if (val >= std::numeric_limits<char>::min() &&
      val <= std::numeric_limits<char>::max()) {
    return true;
  }
  return false;
}