#include "Converter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Converter::Converter() {}
Converter::Converter(std::string value)
    : original_value_(value), type_(NONE_FORMAT) {
  type_ = judgeArgumentFormat();
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
Converter::FormatTypes Converter::judgeNotNumberFormat() {
  const std::string special_values[] = {"nan",   "nanf", "+inf",
                                        "+inff", "-inf", "-inff"};
  const FormatTypes special_formats[] = {NAN_FORMAT,   NANF_FORMAT,
                                         P_INF_FORMAT, P_INFF_FORMAT,
                                         M_INF_FORMAT, M_INFF_FORMAT};
  for (size_t i = 0; i < sizeof(special_values) / sizeof(std::string); i++) {
    if (special_values[i] == original_value_) {
      return special_formats[i];
    }
  }
  return NONE_FORMAT;
};

Converter::FormatTypes Converter::judgeArgumentFormat() {
  FormatTypes res = NONE_FORMAT;
  res = judgeNotNumberFormat();
  if (res != NONE_FORMAT) {
    return res;
  }
  return INT_FORMAT;
};

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Converter::getOriginalValue() const {
  return original_value_;
};
int Converter::getType() const { return static_cast<int>(type_); };

/* ************************************************************************** */