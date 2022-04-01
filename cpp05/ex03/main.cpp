#include <ctime>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Bureaucrat taro = Bureaucrat("Taro", 1);
  Intern intern;

  try {
    std::cout << "\nrobotomy request-------" << std::endl;
    Form* form = intern.makeForm("robotomy request", "Target");
    taro.signForm(*form);
    taro.executeForm(*form);
    delete form;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "\nshrubbery creation-----" << std::endl;
    Form* form = intern.makeForm("shrubbery creation", "Target");
    taro.signForm(*form);
    taro.executeForm(*form);
    delete form;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "\npresidential pardon-----" << std::endl;
    Form* form = intern.makeForm("presidential pardon", "Target");
    taro.signForm(*form);
    taro.executeForm(*form);
    delete form;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "\nunknown form-----------" << std::endl;
    Form* form = intern.makeForm("hello world", "Target");
    if (form) {
      taro.signForm(*form);
      taro.executeForm(*form);
    }
    delete form;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}