#include "Contact.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Contact::Contact()
    : first_name_(),
      last_name_(),
      nickname_(),
      phone_number_(),
      darkest_secret_() {}

Contact::Contact(const Contact& src) {
  if (&src != this) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Contact::~Contact() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Contact& Contact::operator=(Contact const& src) {
  if (&src != this) {
    this->first_name_ = src.first_name_;
    this->last_name_ = src.last_name_;
    this->nickname_ = src.nickname_;
    this->phone_number_ = src.phone_number_;
    this->darkest_secret_ = src.darkest_secret_;
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Contact::GetFirstName() const { return first_name_; }
const std::string& Contact::GetLastName() const { return last_name_; }
const std::string& Contact::GetNickname() const { return nickname_; }
const std::string& Contact::GetPhoneNumber() const { return phone_number_; }
const std::string& Contact::GetDarkestSecret() const { return darkest_secret_; }

void Contact::SetFirstName(const std::string& src) { first_name_ = src; }
void Contact::SetLastName(const std::string& src) { last_name_ = src; }
void Contact::SetNickname(const std::string& src) { nickname_ = src; }
void Contact::SetPhoneNumber(const std::string& src) { phone_number_ = src; }
void Contact::SetDarkestSecret(const std::string& src) {
  darkest_secret_ = src;
}

/* ************************************************************************** */