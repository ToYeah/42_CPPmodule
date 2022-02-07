#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
  Intern();
  Intern(Intern const& src);
  ~Intern();

  Form* makeForm(std::string form_type, std::string target);

  Intern& operator=(Intern const& rhs);

 private:
  static const int k_form_type_count = 3;
  static const std::string k_form_types[k_form_type_count];
};

#endif /* ********************************************************** INTERN_H \
        */