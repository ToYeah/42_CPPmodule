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

  Converter& operator=(Converter const& rhs);

 private:
  const std::string original_value_;
  Converter();
};

std::ostream& operator<<(std::ostream& o, Converter const& i);

#endif /* ******************************************************* CONVERTER_H \
        */