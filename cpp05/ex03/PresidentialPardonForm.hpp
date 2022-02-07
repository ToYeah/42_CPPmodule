#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>

#include "Form.hpp"

class PresidentialPardonForm : public Form {
 public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(PresidentialPardonForm const& src);
  ~PresidentialPardonForm();

  void execute(Bureaucrat const& executor) const;

  PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

 private:
  static const int k_sign_grade;
  static const int k_execution_grade;
  static const std::string k_name;
  static const std::string k_default_target;
  PresidentialPardonForm();
};

std::ostream& operator<<(std::ostream& o, PresidentialPardonForm const& i);

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H \
        */