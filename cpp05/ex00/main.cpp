#include "Bureaucrat.hpp"

int main() {
  Bureaucrat bureaucrat = Bureaucrat("Taro", 1);
  try {
    std::cout << bureaucrat << std::endl;
    bureaucrat.decrementGrade();
    std::cout << bureaucrat << std::endl;
    bureaucrat.incrementGrade();
    std::cout << bureaucrat << std::endl;
    bureaucrat.incrementGrade();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    bureaucrat = Bureaucrat("Taro", 150);
    std::cout << bureaucrat << std::endl;
    bureaucrat.incrementGrade();
    std::cout << bureaucrat << std::endl;
    bureaucrat.decrementGrade();
    std::cout << bureaucrat << std::endl;
    bureaucrat.decrementGrade();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    bureaucrat = Bureaucrat("Taro", 200);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    bureaucrat = Bureaucrat("Taro", 0);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}