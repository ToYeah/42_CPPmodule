#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() {}

Fixed::Fixed(const int src) {
  int sign = INT_MAX | src;
  int value = (src << Fixed::k_fractional_bit_size) & -256;
  setRawBits(sign & value);
}

Fixed::Fixed(const float src) {
  setRawBits(roundf((src) * (1 << Fixed::k_fractional_bit_size)));
}

Fixed::Fixed(const Fixed& src) {
  if (&src != this) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed& Fixed::operator=(Fixed const& rhs) {
  std::cout << "Assignation operator called" << std::endl;
  if (this != &rhs) {
    this->value_ = rhs.getRawBits();
  }
  return *this;
}

bool Fixed::operator<(Fixed const& rhs) const {
  return this->value_ < rhs.value_;
}

bool Fixed::operator>(Fixed const& rhs) const {
  return this->value_ > rhs.value_;
}

bool Fixed::operator<=(Fixed const& rhs) const {
  return this->value_ <= rhs.value_;
}

bool Fixed::operator>=(Fixed const& rhs) const {
  return this->value_ >= rhs.value_;
}

bool Fixed::operator==(Fixed const& rhs) const {
  return this->value_ == rhs.value_;
}

bool Fixed::operator!=(Fixed const& rhs) const {
  return this->value_ != rhs.value_;
}

Fixed Fixed::operator+(Fixed const& rhs) {
  Fixed result;

  result.setRawBits(this->value_ + rhs.value_);
  return result;
}

Fixed Fixed::operator-(Fixed const& rhs) {
  Fixed result;

  result.setRawBits(this->value_ - rhs.value_);
  return result;
}

Fixed Fixed::operator*(Fixed const& rhs) {
  Fixed result;

  long long calc_result = this->value_ * rhs.value_;
  int sign = calc_result < 0 ? INT_MIN : 0;
  result.value_ = static_cast<int>(calc_result >> 8);
  result.value_ = result.value_ | sign;

  return result;
}

Fixed Fixed::operator/(Fixed const& rhs) {
  Fixed result;

  long long lhs_value = static_cast<long long>(this->value_) *
                        (1 << Fixed::k_fractional_bit_size);
  long long rhs_value = static_cast<long long>(rhs.value_);
  long long calc_result = lhs_value / rhs_value;
  result.value_ = static_cast<int>(calc_result);

  return result;
}

Fixed& Fixed::operator++() {
  ++this->value_;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp;

  temp = *this;
  this->value_++;
  return temp;
}

Fixed& Fixed::operator--() {
  --this->value_;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp;

  temp = *this;
  this->value_--;
  return temp;
}

std::ostream& operator<<(std::ostream& o, Fixed const& i) {
  o << i.toFloat();
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat(void) const {
  return static_cast<float>(getRawBits()) / (1 << 8);
}

int Fixed::toInt(void) const {
  return (getRawBits() >> Fixed::k_fractional_bit_size);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  if (a >= b) {
    return a;
  }
  return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  if (a >= b) {
    return a;
  }
  return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
  if (a <= b) {
    return a;
  }
  return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  if (a <= b) {
    return a;
  }
  return b;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const { return value_; }
void Fixed::setRawBits(int const raw) { value_ = raw; }

/* ************************************************************************** */
