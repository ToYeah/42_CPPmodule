#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade)
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
    this->name_ = rhs.name_;
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
  const char* reason = form.signForm(*(this));
  if (reason == NULL) {
    std::cout << name_ << " signs " << form.getName() << std::endl;
  } else {
    std::cout << name_ << " cannot sign " << form.getName() << " because ";
    std::cout << reason << std::endl;
  }
}

void Bureaucrat::executeForm(Form const& form) {
  try {
    form.execute(*this);
    std::cout << name_ << " executes " << form.getName() << "." << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "An error has occured." << std::endl;
    std::cerr << e.what() << '\n';
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