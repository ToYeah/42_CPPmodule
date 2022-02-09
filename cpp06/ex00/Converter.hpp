#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>

class Converter {
 public:
  Converter(std::string value);
  Converter(Converter const& src);
  ~Converter();

  const std::string& getOriginalValue() const;
  int getType() const;

  Converter& operator=(Converter const& rhs);

 private:
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

  static FormatTypes judgeArgumentFormat(std::string& val);
  static FormatTypes judgeNotNumberFormat(std::string& val);
  static bool isCharFormat(std::string& val);
  static bool isIntFormat(std::string& val);
  static bool isDoubleFormat(std::string& val);
  static bool isPrintableChar(char c);
  static bool isdigit(char c);
  static size_t countNumStrLen(std::string val);

  const std::string original_value_;
  FormatTypes type_;
  Converter();
};

std::ostream& operator<<(std::ostream& o, Converter const& i);

#endif /* ******************************************************* CONVERTER_H \
        */