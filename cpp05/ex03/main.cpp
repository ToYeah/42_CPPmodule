#include <ctime>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  Bureaucrat taro = Bureaucrat("Taro", 1);
  Bureaucrat hanako = Bureaucrat("Hanako", 150);
  Intern intern = Intern();

  try {
    Form* form;
    form = intern.makeForm("robotomy request", "Target");
    if (form) {
      taro.signForm(*form);
      taro.executeForm(*form);
      delete form;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    Form* form;
    form = intern.makeForm("shrubbery creation", "Target");
    if (form) {
      taro.signForm(*form);
      taro.executeForm(*form);
      delete form;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    Form* form;
    form = intern.makeForm("presidential pardon", "Target");
    if (form) {
      taro.signForm(*form);
      taro.executeForm(*form);
      delete form;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    Form* form;
    form = intern.makeForm("RobotomyRequestForm", "Target");
    if (form) {
      taro.signForm(*form);
      taro.executeForm(*form);
      delete form;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}