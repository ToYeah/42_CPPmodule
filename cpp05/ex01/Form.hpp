#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
  Form(std::string name, int sign, int execution);
  Form(Form const& src);
  ~Form();

  Form& operator=(Form const& rhs);

  void beSigned(const Bureaucrat& bureaucrat);

  const std::string& getName() const;
  const bool& getIsSigned() const;
  const int& getSignGrade() const;
  const int& getExecutionGrade() const;

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

  class NotEnoughGradeException : public std::exception {
   public:
    const char* what() const throw();
  };

 private:
  Form();

  const std::string name_;
  const int sign_grade_;
  const int execution_grade_;
  bool is_signed_;
};

std::ostream& operator<<(std::ostream& o, Form const& i);

#endif /* ************************************************************ FORM_H \
        */