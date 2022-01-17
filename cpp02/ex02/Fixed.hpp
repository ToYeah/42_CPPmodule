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
  bool operator<(Fixed const& rhs) const;
  bool operator>(Fixed const& rhs) const;
  bool operator<=(Fixed const& rhs) const;
  bool operator>=(Fixed const& rhs) const;
  bool operator==(Fixed const& rhs) const;
  bool operator!=(Fixed const& rhs) const;
  Fixed operator+(Fixed const& rhs);
  Fixed operator-(Fixed const& rhs);
  Fixed operator*(Fixed const& rhs);
  Fixed operator/(Fixed const& rhs);
  Fixed& operator++(void);
  Fixed operator++(int);
  Fixed& operator--(void);
  Fixed operator--(int);

  static Fixed& max(Fixed& a, Fixed& b);
  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);

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