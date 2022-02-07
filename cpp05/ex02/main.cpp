#include <ctime>

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  Bureaucrat taro = Bureaucrat("Taro", 1);
  Bureaucrat hanako = Bureaucrat("Hanako", 100);

  std::cout << "-----RobotomyRequestForm Test----" << std::endl;

  try {
    std::cout << "Succes: " << std::endl;
    RobotomyRequestForm form = RobotomyRequestForm("Plan", "Target", 10, 10);
    form.signForm(taro);
    taro.executeForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "Sign Error: " << std::endl;
    RobotomyRequestForm form = RobotomyRequestForm("Plan", "Target", 10, 10);
    taro.executeForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "Grade Error: " << std::endl;
    RobotomyRequestForm form = RobotomyRequestForm("Plan", "Target", 10, 10);
    form.signForm(taro);
    hanako.executeForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}