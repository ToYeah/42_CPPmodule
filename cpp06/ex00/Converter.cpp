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
    if (!isdigit(val[index])) {
      return false;
    }
  }
  return true;
};

Converter::FormatTypes Converter::judgeArgumentFormat(std::string& val) {
  if (isIntFormat(val)) {
    return INT_FORMAT;
  };
  if (isCharFormat(val)) {
    return CHAR_FORMAT;
  };

  return judgeNotNumberFormat(val);
};

bool Converter::isPrintableChar(char c) {
  if (c >= 32 && c <= 126) {
    return true;
  }
  return false;
}

bool Converter::isdigit(char c) {
  if (c >= '0' && c <= '9') {
    return true;
  }
  return false;
}

/*
** --------------------------------- ACCESSOR
*---------------------------------
*/

const std::string& Converter::getOriginalValue() const {
  return original_value_;
};
int Converter::getType() const { return static_cast<int>(type_); };

/* ************************************************************************** */