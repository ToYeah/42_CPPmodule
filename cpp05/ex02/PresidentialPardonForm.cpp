#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const int PresidentialPardonForm::k_sign_grade = 25;
const int PresidentialPardonForm::k_execution_grade = 5;
const std::string PresidentialPardonForm::k_name = "PresidentialPardonForm";
const std::string PresidentialPardonForm::k_default_target = "None";

PresidentialPardonForm::PresidentialPardonForm()
    : Form(k_name, k_default_target, k_sign_grade, k_execution_grade) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form(k_name, target, k_sign_grade, k_execution_grade) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& src)
    : Form(src) {
  *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm& PresidentialPardonForm::operator=(
    PresidentialPardonForm const& rhs) {
  if (this != &rhs) {
    Form::operator=(rhs);
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, PresidentialPardonForm const& i) {
  i.printStatus(o);
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::executeAction() const {
  std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox."
            << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */