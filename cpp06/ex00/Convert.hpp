#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>

enum FormatTypes {
  NONE_FORMAT,
  CHAR_FORMAT,
  INT_FORMAT,
  FLOAT_FORMAT,
  DOUBLE_FORMAT,
  NAN_FORMAT,
  NANF_FORMAT,
  P_INF_FORMAT,
  P_INFF_FORMAT,
  M_INF_FORMAT,
  M_INFF_FORMAT
};

FormatTypes judgeArgumentFormat(std::string& val);
FormatTypes judgeNotNumberFormat(std::string& val);
bool isCharFormat(std::string& val);
bool isIntFormat(std::string& val);
bool isDoubleFormat(std::string& val);
bool isFloatFormat(std::string& val);
bool isPrintableChar(char c);
bool isDigit(char c);
size_t countNumStrLen(std::string val);

#endif