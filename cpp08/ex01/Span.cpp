#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : size_(0) {}

Span::Span(unsigned int N) : size_(N) {}

Span::Span(const Span& src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span& Span::operator=(Span const& rhs) {
  if (this != &rhs) {
    this->size_ = rhs.size_;
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int num) {
  if (vector_.size() == size_) {
    throw std::length_error("Span class is full.");
  }
  vector_.push_back(num);
};

int Span::shortestSpan() { return 0; };

int Span::longestSpan() {
  if (vector_.size() == 0) return 0;

  std::vector<int>::iterator max_itr =
      std::max_element(vector_.begin(), vector_.end());
  std::vector<int>::iterator min_itr =
      std::min_element(vector_.begin(), vector_.end());

  return *max_itr - *min_itr;
};

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */