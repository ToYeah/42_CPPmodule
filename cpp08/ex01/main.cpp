#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Span.hpp"

int main() {
  Span sp = Span(5);
  sp.addNumber(5);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  Span rand_sp = Span(10002);
  rand_sp.addNumber(0);
  rand_sp.addNumber(10000000);

  std::srand(std::time(NULL));

  for (size_t i = 0; i < 10000; i++) {
    rand_sp.addNumber(std::rand() % 10000 + 1);
  }

  std::cout << "-----------------" << std::endl;

  std::cout << "rand value test" << std::endl;
  std::cout << "rand value sample:  " << std::rand() % 10000 + 1 << std::endl;

  std::cout << rand_sp.shortestSpan() << std::endl;
  std::cout << rand_sp.longestSpan() << std::endl;

  std::cout << "-----------------" << std::endl;

  std::cout << "0, 10 Span test" << std::endl;

  Span mini_sp = Span(2);
  mini_sp.addNumber(10);
  mini_sp.addNumber(0);

  std::cout << mini_sp.shortestSpan() << std::endl;
  std::cout << mini_sp.longestSpan() << std::endl;

  std::cout << "-----------------" << std::endl;
  std::cout << "length error test" << std::endl;
  try {
    Span len_span = Span(1);
    len_span.addNumber(0);
    len_span.addNumber(0);
    len_span.addNumber(0);
    len_span.addNumber(0);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "-----------------" << std::endl;
  std::cout << "few elem longestSpan test" << std::endl;
  try {
    Span few_span = Span(1);
    few_span.addNumber(0);

    few_span.longestSpan();

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "-----------------" << std::endl;
  std::cout << "few elem shortestSpan test" << std::endl;
  try {
    Span few_span = Span(1);
    few_span.addNumber(0);

    few_span.shortestSpan();

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "-----------------" << std::endl;
  std::cout << "add number from iterator test" << std::endl;

  Span it_span = Span(5);

  std::vector<int> test_vec;
  test_vec.push_back(0);
  test_vec.push_back(10);
  test_vec.push_back(100);

  it_span.addNumber(test_vec.begin(), test_vec.end());
  std::cout << it_span.shortestSpan() << std::endl;
  std::cout << it_span.longestSpan() << std::endl;

  std::cout << "-----------------" << std::endl;
  std::cout << "length error from iterator test" << std::endl;
  try {
    it_span.addNumber(test_vec.begin(), test_vec.end());
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}