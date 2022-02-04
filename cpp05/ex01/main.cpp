#include "Bureaucrat.hpp"

int main() {
  Bureaucrat bureaucrat = Bureaucrat("Taro", 1);
  try {
    Form form = Form("Plan", 10, 10);
    std::cout << form << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "/////////////////////" << std::endl;
  try {
    Form form = Form("Plan", 0, 10);
    std::cout << form << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    Form form = Form("Plan", 10, 0);
    std::cout << form << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    Form form = Form("Plan", 151, 10);
    std::cout << form << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    Form form = Form("Plan", 10, 151);
    std::cout << form << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "/////////////////////" << std::endl;

  try {
    Bureaucrat bureaucrat = Bureaucrat("Taro", 1);
    Form form = Form("Plan", 10, 10);
    std::cout << bureaucrat << std::endl;
    std::cout << form << std::endl;
    bureaucrat.signForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}