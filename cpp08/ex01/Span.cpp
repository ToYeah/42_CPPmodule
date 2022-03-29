#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : size_(0) {}

Span::Span(unsigned int N) : size_(N) { vector_.reserve(N); }

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
    this->vector_ = rhs.vector_;
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char* Span::NotEnoughCapacityException::what() const throw() {
  return "This instance has not enough capacity.";
}
const char* Span::UncalculableSizeException::what() const throw() {
  return "This instance has not enough size.";
}
void Span::addNumber(int num) {
  if (vector_.size() == size_) {
    throw NotEnoughCapacityException();
  }
  vector_.push_back(num);
};

void Span::addNumber(vec_it start, vec_it end) {
  vec_type::difference_type distance = std::distance(start, end);
  if (vector_.size() + distance > size_) {
    throw NotEnoughCapacityException();
  }

  for (vec_it it = start; it != end; it++) {
    vector_.push_back(*it);
  }
}
unsigned int Span::calcAbs(int lhs, int rhs) {
  int res = lhs - rhs;

  if (lhs >= rhs) {
    return res;
  } else {
    return -1 * res;
  }
}

unsigned int Span::shortestSpan() {
  if (vector_.size() < 2) {
    throw UncalculableSizeException();
  }

  unsigned int res = calcAbs(vector_[0], vector_[1]);
  for (std::vector<int>::iterator lhs_it = this->vector_.begin();
       lhs_it != this->vector_.end(); lhs_it++) {
    for (std::vector<int>::iterator rhs_it = lhs_it + 1;
         rhs_it != this->vector_.end(); rhs_it++) {
      unsigned int calc_res = calcAbs(*lhs_it, *rhs_it);
      if (res > calc_res) res = calc_res;
    }
  }

  return res;
};

unsigned int Span::longestSpan() {
  if (vector_.size() < 2) {
    throw UncalculableSizeException();
  }

  std::vector<int>::iterator max_itr =
      std::max_element(vector_.begin(), vector_.end());
  std::vector<int>::iterator min_itr =
      std::min_element(vector_.begin(), vector_.end());

  return calcAbs(*max_itr, *min_itr);
};

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */