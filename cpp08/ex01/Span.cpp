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
    this->vector_ = rhs.vector_;
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

int Span::calcAbs(int lhs, int rhs) {
  int res = lhs - rhs;

  if (lhs >= rhs) {
    return res;
  } else {
    return -res;
  }
}

bool Span::hasCalculableSize() {
  if (vector_.size() < 2) {
    throw std::runtime_error("Span class has not enough elements.");
  }
  return true;
}

int Span::shortestSpan() {
  hasCalculableSize();

  int res = calcAbs(vector_[0], vector_[1]);
  for (std::vector<int>::iterator lhs_it = this->vector_.begin();
       lhs_it != this->vector_.end(); lhs_it++) {
    for (std::vector<int>::iterator rhs_it = lhs_it + 1;
         rhs_it != this->vector_.end(); rhs_it++) {
      int calc_res = calcAbs(*lhs_it, *rhs_it);
      if (res > calc_res) res = calc_res;
    }
  }

  return res;
};

int Span::longestSpan() {
  hasCalculableSize();

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