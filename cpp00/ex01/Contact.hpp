#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
 public:
  Contact();
  Contact(Contact const& src);
  ~Contact();

  Contact& operator=(Contact const& src);

  const std::string& GetFirstName() const;
  const std::string& GetLastName() const;
  const std::string& GetNickname() const;
  const std::string& GetPhoneNumber() const;
  const std::string& GetDarkestSecret() const;

  void SetFirstName(const std::string& src);
  void SetLastName(const std::string& src);
  void SetNickname(const std::string& src);
  void SetPhoneNumber(const std::string& src);
  void SetDarkestSecret(const std::string& src);

 private:
  std::string first_name_;
  std::string last_name_;
  std::string nickname_;
  std::string phone_number_;
  std::string darkest_secret_;
};

#endif