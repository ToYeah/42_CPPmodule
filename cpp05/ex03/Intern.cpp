#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const Intern::FormFunc Intern::k_form_funcs[k_form_func_count] = {
    &Intern::makeRobotomyRequestForm, &Intern::makeShrubberyCreationForm,
    &Intern::makePresidentialPardonForm, &Intern::makeUnknownForm};

const std::string Intern::k_form_types[k_form_type_count] = {
    "robotomy request", "shrubbery creation", "presidential pardon"};

Intern::Intern() {}

Intern::Intern(const Intern& src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern& Intern::operator=(Intern const&) { return *this; }

/*
** --------------------------------- METHODS ----------------------------------
*/

void Intern::printInternOutcome(const Form& form) {
  std::cout << "Intern creates " << form.getName() << std::endl;
}

Form* Intern::makeRobotomyRequestForm(const std::string& target) {
  Form* res;
  res = new RobotomyRequestForm(target);
  printInternOutcome(*res);
  return res;
};

Form* Intern::makeShrubberyCreationForm(const std::string& target) {
  Form* res;
  res = new ShrubberyCreationForm(target);
  printInternOutcome(*res);
  return res;
};

Form* Intern::makePresidentialPardonForm(const std::string& target) {
  Form* res;
  res = new PresidentialPardonForm(target);
  printInternOutcome(*res);
  return res;
};

Form* Intern::makeUnknownForm(const std::string&) {
  std::cout << "Failed to create the Form." << std::endl;
  return NULL;
}

Form* Intern::makeForm(const std::string& form_type,
                       const std::string& target) {
  int index = 0;
  while (index < k_form_type_count && form_type != k_form_types[index]) {
    index++;
  }
  return (this->*k_form_funcs[index])(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */