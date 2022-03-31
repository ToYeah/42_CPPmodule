#include "Bureaucrat.hpp"

int main() {
  try {
    Form form = Form("Plan", 10, 10);
    std::cout << form;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "\n"
            << "Constructor Error------------" << std::endl;
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

  std::cout << "\n"
            << "Success----------------------" << std::endl;

  try {
    Bureaucrat bureaucrat = Bureaucrat("Taro", 1);
    Form form = Form("Plan", 10, 10);
    std::cout << bureaucrat << std::endl;
    std::cout << form;
    bureaucrat.signForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    Bureaucrat bureaucrat = Bureaucrat("Hanako", 10);
    Form form = Form("Plan", 10, 10);
    std::cout << bureaucrat << std::endl;
    std::cout << form;
    bureaucrat.signForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "\n"
            << "Already signed---------------" << std::endl;

  try {
    Bureaucrat bureaucrat = Bureaucrat("Taro", 1);
    Form form = Form("Plan", 10, 10);
    std::cout << bureaucrat << std::endl;
    std::cout << form;
    bureaucrat.signForm(form);
    std::cout << form;
    bureaucrat.signForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "\n"
            << "Sign Error-------------------" << std::endl;

  try {
    Bureaucrat bureaucrat = Bureaucrat("Taro", 11);
    Form form = Form("Plan", 10, 10);
    std::cout << bureaucrat << std::endl;
    std::cout << form;
    bureaucrat.signForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}