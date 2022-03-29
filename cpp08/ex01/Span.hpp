#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class Span {
 public:
  Span(unsigned int N);
  Span(Span const& src);
  ~Span();

  Span& operator=(Span const& rhs);

  void addNumber(int num);
  int shortestSpan();
  int longestSpan();

 private:
  std::vector<int> vector_;
  unsigned int size_;

  int calcAbs(int lhs, int rhs);
  bool hasCalculableSize();
  Span();
};

#endif /* ************************************************************ SPAN_H \
        */
