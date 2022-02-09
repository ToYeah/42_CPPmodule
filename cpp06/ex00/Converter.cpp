#include "Converter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Converter::Converter() {}
Converter::Converter(std::string value)
    : original_value_(value), type_(NONE_FORMAT) {
  type_ = judgeArgumentFormat(value);
}

Converter::Converter(const Converter& src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Converter::~Converter() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Converter& Converter::operator=(Converter const&) {
  // if ( this != &rhs )
  //{
  // this->_value = rhs.getValue();
  //}
  return *this;
}

std::ostream& operator<<(std::ostream& o, Converter const& i) {
  o << "Original: " << i.getOriginalValue() << std::endl;
  o << "type: " << i.getType() << std::endl;
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Converter::FormatTypes Converter::judgeNotNumberFormat(std::string& val) {
  const std::string special_values[] = {"nan",   "nanf", "+inf",
                                        "+inff", "-inf", "-inff"};
  const FormatTypes special_formats[] = {NAN_FORMAT,   NANF_FORMAT,
                                         P_INF_FORMAT, P_INFF_FORMAT,
                                         M_INF_FORMAT, M_INFF_FORMAT};
  for (size_t i = 0; i < sizeof(special_values) / sizeof(std::string); i++) {
    if (special_values[i] == val) {
      return special_formats[i];
    }
  }
  return NONE_FORMAT;
};

bool Converter::isCharFormat(std::string& val) {
  if (val.length() == 1 && isPrintableChar(val[0])) {
    return true;
  }
  return false;
};

bool Converter::isIntFormat(std::string& val) {
  size_t index = 0;

  if (val[index] == '+' || val[index] == '-') {
    index++;
  }
  for (; index < val.length(); index++) {
    if (!isDigit(val[index])) {
      return false;
    }
  }
  return true;
};

bool Converter::isDoubleFormat(std::string& val) {
  size_t index = 0;
  size_t tmp = 0;

  if (val[index] == '+' || val[index] == '-') {
    index++;
  }
  if (val[index] == '.') {
    return false;
  }
  tmp = countNumStrLen(val.substr(index));
  if (tmp == 0) {
    return false;
  }
  index += tmp;
  if (val[index] != '.') {
    return false;
  }
  index += 1;
  index += countNumStrLen(val.substr(index));
  if (index == val.length()) {
    return true;
  }
  return false;
}

bool Converter::isFloatFormat(std::string& val) {
  if (val[val.length() - 1] != 'f') {
    return false;
  }
  std::string removed_str = val.substr(0, val.length() - 1);
  if (isIntFormat(removed_str) || isDoubleFormat(removed_str)) {
    return true;
  }
  return false;
}

Converter::FormatTypes Converter::judgeArgumentFormat(std::string& val) {
  if (val.length() == 0) {
    return NONE_FORMAT;
  }
  if (isIntFormat(val)) {
    return INT_FORMAT;
  };
  if (isCharFormat(val)) {
    return CHAR_FORMAT;
  };
  if (isDoubleFormat(val)) {
    return DOUBLE_FORMAT;
  };
  if (isFloatFormat(val)) {
    return FLOAT_FORMAT;
  };

  return judgeNotNumberFormat(val);
};

bool Converter::isPrintableChar(char c) {
  if (c >= 32 && c <= 126) {
    return true;
  }
  return false;
}

bool Converter::isDigit(char c) {
  if (c >= '0' && c <= '9') {
    return true;
  }
  return false;
}

size_t Converter::countNumStrLen(std::string val) {
  for (size_t i = 0; i < val.length(); i++) {
    if (!isDigit(val[i])) {
      return i;
    }
  }
  return val.length();
};

/*
** --------------------------------- ACCESSOR
*---------------------------------
*/

const std::string& Converter::getOriginalValue() const {
  return original_value_;
};
int Converter::getType() const { return static_cast<int>(type_); };

/* ************************************************************************** */