#include "Converter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Converter::Converter() {}
Converter::Converter(std::string value) : original_value_(value), type_(NONE) {
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

Converter::FormatTypes Converter::judgeArgumentFormat() {
  const std::string charactors = "0123456789+-.f";

  for (size_t i = 0; i < original_value_.size(); i++) {
    if (charactors.find(original_value_.at(i)) == std::string::npos) {
      return NONE;  // charcheck
    }
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