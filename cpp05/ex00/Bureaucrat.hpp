#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
 public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(Bureaucrat const& src);
  ~Bureaucrat();

  Bureaucrat& operator=(Bureaucrat const& rhs);

  const std::string& getName() const;
  const int getGrade() const;

 private:
  Bureaucrat();
  std::string name_;
  int grade_;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i);

#endif /* ****************************************************** BUREAUCRAT_H \
        */