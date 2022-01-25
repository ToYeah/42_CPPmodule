#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name_(name), grade_(grade) {}

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
  o << i.getName() << ", bureaucrat grade" << i.getGrade() << ".";
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Bureaucrat::getName() const { return this->name_; };

const int Bureaucrat::getGrade() const { return this->grade_; };

/* ************************************************************************** */