#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : sign_grade_(1), execution_grade_(1) {}

Form::Form(const std::string& name, const std::string& target, const int& sign,
           const int& execution)
    : name_(name),
      target_(target),
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
      target_(src.target_),
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
  i.printStatus(o);
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

void Form::execute(Bureaucrat const& executor) const {
  if (!isExecutable(executor)) {
    return;
  }
  executeAction();
}

bool Form::isExecutable(Bureaucrat const& executor) const {
  if (!is_signed_) {
    throw NotSignedException();
    return false;
  }
  if (execution_grade_ < executor.getGrade()) {
    throw GradeTooLowException();
    return false;
  }
  return true;
}

std::ostream& Form::printStatus(std::ostream& o) const {
  o << "-----------" << std::endl;
  o << "Form status" << std::endl;
  o << "Name: " << name_ << std::endl;
  o << "Sign: " << is_signed_ << std::endl;
  o << "SignGrade: " << sign_grade_ << std::endl;
  o << "ExecutionGrade: " << execution_grade_ << std::endl;
  o << "Target: " << target_ << std::endl;
  o << "-----------" << std::endl;
  return o;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is above the maximum.";
};

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is below the minimum.";
};

const char* Form::NotSignedException::what() const throw() {
  return "This Form is not signed yet.";
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

const std::string& Form::getTarget() const { return target_; };

/* ************************************************************************** */
