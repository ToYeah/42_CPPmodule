#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
  std::cout << "Copy constructor called" << std::endl;
  if (&src != this) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR
*--------------------------------
*/

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/*
** --------------------------------- OVERLOAD
*---------------------------------
*/

Fixed& Fixed::operator=(Fixed const& rhs) {
  std::cout << "Assignation operator called" << std::endl;
  if (this != &rhs) {
    this->value_ = rhs.getRawBits();
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return value_;
}
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  value_ = raw;
}

/* ************************************************************************** */