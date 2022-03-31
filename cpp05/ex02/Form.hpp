#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
  Form(const std::string& name, const std::string& target, const int& sign,
       const int& execution);
  Form(Form const& src);
  virtual ~Form();

  Form& operator=(Form const& rhs);

  void beSigned(const Bureaucrat& bureaucrat);
  bool isExecutable(Bureaucrat const& executor) const;
  void execute(Bureaucrat const& executor) const;
  virtual void executeAction() const = 0;

  const std::string& getName() const;
  const bool& getIsSigned() const;
  const int& getSignGrade() const;
  const int& getExecutionGrade() const;
  const std::string& getTarget() const;
  std::ostream& printStatus(std::ostream& o) const;

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

  class NotSignedException : public std::exception {
   public:
    const char* what() const throw();
  };

 private:
  Form();

  const std::string name_;
  const std::string target_;
  const int sign_grade_;
  const int execution_grade_;
  bool is_signed_;
};

std::ostream& operator<<(std::ostream& o, Form const& i);

#endif /* ************************************************************ FORM_H \
        */