#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

#define INT_SUFFIX "int: "
#define CHAR_SUFFIX "char: "
#define FLOAT_SUFFIX "float: "
#define DOUBLE_SUFFIX "double: "
#define PRINTABLE_MIN 32
#define PRINTABLE_MAX 126
#define NON_PRINTABLE_STR "Non displayable"
#define IMPOSSIBLE "impossible"

class UnknownLiteralException : public std::exception {
 public:
  const char* what() const throw();
};

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
void printConvertedValues(std::string& val, FormatTypes& type);
void printValues(char* c, int* i, float* f, double* d);
void printIntFormat(std::string& val);
void printCharFormat(std::string& val);
void printFloatFormat(std::string& val);
bool isCharRange(int& val);
bool isCharRange(float& val);
bool isCharRange(double& val);
bool isIntRange(float& val);
bool isIntRange(double& val);
#endif