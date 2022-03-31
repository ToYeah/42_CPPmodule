#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
    : name_(name), grade_(grade) {
  if (grade < k_max_grade) {
    throw GradeTooHighException();
  }
  if (grade > k_min_grade) {
    throw GradeTooLowException();
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
  if (this != &rhs) {
    this->grade_ = rhs.grade_;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i) {
  o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade() {
  grade_--;
  if (grade_ < k_max_grade) {
    throw GradeTooHighException();
  }
};

void Bureaucrat::decrementGrade() {
  grade_++;
  if (grade_ > k_min_grade) {
    throw GradeTooLowException();
  }
};

void Bureaucrat::signForm(Form& form) {
  if (form.getIsSigned()) {
    std::cout << form.getName() << " is already signed" << std::endl;
  } else {
    form.beSigned(*this);
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is above the maximum.";
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is below the minimum.";
};

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Bureaucrat::getName() const { return name_; };

const int& Bureaucrat::getGrade() const { return grade_; };

/* ************************************************************************** */