#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : sign_grade_(1), execution_grade_(1) {}

Form::Form(const std::string& name, const int& sign, const int& execution)
    : name_(name),
      sign_grade_(sign),
      execution_grade_(execution),
      is_signed_(false) {
  if (sign < Bureaucrat::k_max_grade || execution < Bureaucrat::k_max_grade) {
    throw GradeTooHighException();
  }
  if (sign > Bureaucrat::k_min_grade || execution > Bureaucrat::k_min_grade) {
    throw GradeTooLowException();
  }
}

Form::Form(const Form& src)
    : name_(src.name_),
      sign_grade_(src.sign_grade_),
      execution_grade_(src.execution_grade_),
      is_signed_(false) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form& Form::operator=(Form const& rhs) {
  if (this != &rhs) {
    this->is_signed_ = rhs.is_signed_;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, Form const& i) {
  o << "-----------" << std::endl;
  o << "Form status" << std::endl;
  o << "Name: " << i.getName() << std::endl;
  o << "Sign: " << i.getIsSigned() << std::endl;
  o << "SignGrade: " << i.getSignGrade() << std::endl;
  o << "ExecutionGrade: " << i.getExecutionGrade() << std::endl;
  o << "-----------" << std::endl;
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > sign_grade_) {
    throw NotEnoughGradeException();
  }
  is_signed_ = true;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is above the maximum.";
};

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is below the minimum.";
};

const char* Form::NotEnoughGradeException::what() const throw() {
  return "Not enough grade to sign.";
};
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Form::getName() const { return name_; };

const bool& Form::getIsSigned() const { return is_signed_; };

const int& Form::getSignGrade() const { return sign_grade_; };

const int& Form::getExecutionGrade() const { return execution_grade_; };

/* ************************************************************************** */