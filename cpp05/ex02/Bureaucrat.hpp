#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat {
 public:
  static const int k_max_grade = 1;
  static const int k_min_grade = 150;
  Bureaucrat(std::string name, int grade);
  Bureaucrat(Bureaucrat const& src);
  ~Bureaucrat();

  Bureaucrat& operator=(Bureaucrat const& rhs);

  void incrementGrade();
  void decrementGrade();

  void signForm(Form& form);
  void executeForm(Form const& form);

  const std::string& getName() const;
  const int& getGrade() const;

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

 private:
  Bureaucrat();
  std::string name_;
  int grade_;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i);

#endif /* ****************************************************** BUREAUCRAT_H \
        */