#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const int RobotomyRequestForm::k_sign_grade = 72;
const int RobotomyRequestForm::k_execution_grade = 45;
const std::string RobotomyRequestForm::k_name = "RobotomyRequestForm";
const std::string RobotomyRequestForm::k_default_target = "None";

RobotomyRequestForm::RobotomyRequestForm()
    : Form(k_name, k_default_target, k_sign_grade, k_execution_grade) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form(k_name, target, k_sign_grade, k_execution_grade) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : Form(src) {
  *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm& RobotomyRequestForm::operator=(
    RobotomyRequestForm const& rhs) {
  if (this != &rhs) {
    Form::operator=(rhs);
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, RobotomyRequestForm const& i) {
  i.printStatus(o);
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (!isExecutable(executor)) {
    return;
  }
  std::string res = rand() % 2 ? "successfully" : "unsuccessfully";
  std::cout << "wheeeeeeeee" << std::endl;
  std::cout << "wheeeeeeeeeeeee" << std::endl;
  std::cout << "wheeeeeeeeeeeeeeeeeeeeeee" << std::endl;
  std::cout << getName() << " has been robotomized " << res << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */