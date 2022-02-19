#ifndef FIXED_HPP
#define FIXED_HPP

#include <climits>
#include <cmath>
#include <iostream>
#include <string>

class Fixed {
 public:
  Fixed();
  Fixed(const int src);
  Fixed(const float src);
  Fixed(Fixed const& src);
  ~Fixed();
  Fixed& operator=(Fixed const& rhs);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

 private:
  int value_;
  static const size_t k_fractional_bit_size = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& i);

#endif /* *********************************************************** FIXED_H \
        */
