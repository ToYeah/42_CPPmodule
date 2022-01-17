#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int src) {
  std::cout << "Int constructor called" << std::endl;
  int sign = INT_MAX | src;
  int value = (src << Fixed::k_fractional_bit_size) & -256;
  setRawBits(sign & value);
}

Fixed::Fixed(const float src) {
  std::cout << "Float constructor called" << std::endl;
  setRawBits(roundf((src) * (1 << Fixed::k_fractional_bit_size)));
}

Fixed::Fixed(const Fixed& src) {
  std::cout << "Copy constructor called" << std::endl;
  if (&src != this) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

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

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const { return value_; }
void Fixed::setRawBits(int const raw) { value_ = raw; }

/* ************************************************************************** */
