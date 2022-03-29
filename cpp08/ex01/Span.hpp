#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class Span {
 private:
  typedef std::vector<int> vec_type;
  typedef vec_type::iterator vec_it;

 public:
  Span(unsigned int N);
  Span(Span const& src);
  ~Span();

  Span& operator=(Span const& rhs);

  void addNumber(int num);
  void addNumber(vec_it start, vec_it end);
  unsigned int shortestSpan();
  unsigned int longestSpan();

 private:
  vec_type vector_;
  unsigned int size_;

  unsigned int calcAbs(int lhs, int rhs);
  bool hasCalculableSize();
  Span();
};

#endif /* ************************************************************ SPAN_H \
        */
