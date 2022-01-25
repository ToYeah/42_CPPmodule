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
}