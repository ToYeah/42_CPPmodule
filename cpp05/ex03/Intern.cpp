#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const std::string Intern::k_form_types[k_form_type_count] = {
    "robotomy request", "shrubbery creation", "presidential pardon"};

Intern::Intern() {}

Intern::Intern(const Intern& src) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern& Intern::operator=(Intern const& rhs) { return *this; }

/*
** --------------------------------- METHODS ----------------------------------
*/

Form* Intern::makeForm(std::string form_type, std::string target) {
  int index = 0;
  while (index < k_form_type_count && form_type != k_form_types[index]) {
    index++;
  }

  Form* res;

  switch (index) {
    case 0:
      res = new RobotomyRequestForm(target);
      break;
    case 1:
      res = new ShrubberyCreationForm(target);
      break;
    case 2:
      res = new PresidentialPardonForm(target);
      break;
    default:
      std::cout << "Failed to create the Form." << std::endl;
      return NULL;
  }

  std::cout << "Intern creates " << res->getName() << std::endl;
  return res;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */