#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <stdlib.h>

#include <iostream>
#include <string>

#include "Form.hpp"

class RobotomyRequestForm : public Form {
 public:
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(RobotomyRequestForm const& src);
  ~RobotomyRequestForm();

  void execute(Bureaucrat const& executor) const;

  RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

 private:
  static const int k_sign_grade;
  static const int k_execution_grade;
  static const std::string k_name;
  RobotomyRequestForm();
};

std::ostream& operator<<(std::ostream& o, RobotomyRequestForm const& i);

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H \
        */