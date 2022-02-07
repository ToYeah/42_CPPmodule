#include <ctime>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  Bureaucrat taro = Bureaucrat("Taro", 1);
  Bureaucrat hanako = Bureaucrat("Hanako", 150);

  std::cout << "\n-----RobotomyRequestForm Test----" << std::endl;

  try {
    std::cout << "\nSucces-----" << std::endl;
    RobotomyRequestForm form = RobotomyRequestForm("Target");
    taro.signForm(form);
    taro.executeForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "\nSign Error----- " << std::endl;
    RobotomyRequestForm form = RobotomyRequestForm("Target");
    hanako.signForm(form);
    hanako.executeForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "\nNot Sign Error----- " << std::endl;
    RobotomyRequestForm form = RobotomyRequestForm("Target");
    taro.executeForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "\nGrade Error----- " << std::endl;
    RobotomyRequestForm form = RobotomyRequestForm("Target");
    taro.signForm(form);
    hanako.executeForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "\n-----RobotomyRequestForm Test----" << std::endl;

  try {
    std::cout << "\nSucces-----" << std::endl;
    PresidentialPardonForm form = PresidentialPardonForm("Target");
    taro.signForm(form);
    taro.executeForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "\nSign Error----- " << std::endl;
    PresidentialPardonForm form = PresidentialPardonForm("Target");
    hanako.signForm(form);
    hanako.executeForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "\nNot Sign Error----- " << std::endl;
    PresidentialPardonForm form = PresidentialPardonForm("Target");
    taro.executeForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "\nGrade Error----- " << std::endl;
    PresidentialPardonForm form = PresidentialPardonForm("Target");
    taro.signForm(form);
    hanako.executeForm(form);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}