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
    NONE,
    CHAR_FORMAT,
    INT_FORMAT,
    FLOAT_FORMAT,
    DOUBLE_FORMAT
  };

  FormatTypes judgeArgumentFormat();

  const std::string original_value_;
  FormatTypes type_;
  Converter();
};

std::ostream& operator<<(std::ostream& o, Converter const& i);

#endif /* ******************************************************* CONVERTER_H \
        */