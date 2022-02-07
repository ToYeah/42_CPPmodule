#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
 public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(ShrubberyCreationForm const& src);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const& executor) const;

  ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

  class FileErrorException : public std::exception {
   public:
    const char* what() const throw();
  };

 private:
  static const int k_sign_grade;
  static const int k_execution_grade;
  static const std::string k_name;
  static const std::string k_default_target;
  static const std::string k_ascii_tree;
  ShrubberyCreationForm();
};

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const& i);

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H \
        */