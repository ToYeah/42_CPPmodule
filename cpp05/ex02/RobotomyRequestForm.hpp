#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <stdlib.h>

#include <iostream>
#include <string>

#include "Form.hpp"

class RobotomyRequestForm : public Form {
 public:
  RobotomyRequestForm(std::string name, std::string target, int sign,
                      int execution);
  RobotomyRequestForm(RobotomyRequestForm const& src);
  ~RobotomyRequestForm();

  void execute(Bureaucrat const& executor) const;

  RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

 private:
  RobotomyRequestForm();
};

std::ostream& operator<<(std::ostream& o, RobotomyRequestForm const& i);

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H \
        */