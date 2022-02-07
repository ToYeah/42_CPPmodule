#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const int ShrubberyCreationForm::k_sign_grade = 145;
const int ShrubberyCreationForm::k_execution_grade = 137;
const std::string ShrubberyCreationForm::k_name = "ShrubberyCreationForm";
const std::string ShrubberyCreationForm::k_default_target = "None";
const std::string ShrubberyCreationForm::k_ascii_tree =
    "        /\\      \n       /  \\     \n      /    \\    \n     /      \\   "
    "\n    /________\\  \n        ||      \n        ||      \n";

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form(k_name, k_default_target, k_sign_grade, k_execution_grade) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form(k_name, target, k_sign_grade, k_execution_grade) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : Form(src) {
  *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const& rhs) {
  if (this != &rhs) {
    Form::operator=(rhs);
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const& i) {
  i.printStatus(o);
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (!isExecutable(executor)) {
    return;
  }
  std::ofstream output_file_stream((getTarget() + "_shrubbery").c_str());
  output_file_stream << k_ascii_tree;
  output_file_stream.close();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */