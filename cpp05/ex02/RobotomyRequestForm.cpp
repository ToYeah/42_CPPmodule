#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target,
                                         int sign, int execution)
    : Form(name, target, sign, execution) {}

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

void RobotomyRequestForm::execute(Bureaucrat const& executor) {
  isExecutable(executor);

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