#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
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
}