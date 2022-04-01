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
  typedef Form* (Intern::*FormFunc)(const std::string&);
  Intern();
  Intern(Intern const& src);
  ~Intern();

  Form* makeForm(const std::string& form_type, const std::string& target);

  Intern& operator=(Intern const& rhs);

 private:
  static const int k_form_type_count = 3;
  static const int k_form_func_count = 4;
  static const std::string k_form_types[k_form_type_count];
  static const FormFunc k_form_funcs[k_form_func_count];

  Form* makeRobotomyRequestForm(const std::string& target);
  Form* makeShrubberyCreationForm(const std::string& target);
  Form* makePresidentialPardonForm(const std::string& target);
  Form* makeUnknownForm(const std::string&);
  void printInternOutcome(const Form& form);
};

#endif /* ********************************************************** INTERN_H \
        */