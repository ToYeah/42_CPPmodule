#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
 public:
  PhoneBook();
  PhoneBook(PhoneBook const& src);
  ~PhoneBook();
  PhoneBook& operator=(PhoneBook const& src);

  void run();

  const Contact& GetContact(const size_t& index) const;

  void SetContact(const Contact& src, const size_t& index);

 private:
  void add(size_t index);
  void inputContactInformation(Contact& contact,
                               void (Contact::*fn)(const std::string&),
                               std::string s);

  void Search();
  void PrintContactsList();
  static void PrintHorizonSeparator();
  static void PrintVerticalSeparator();
  static void PrintContactRow(const Contact& contact, size_t index);
  static void PrintItem(const std::string item);
  static bool isEmptyContact(const Contact& contact);
  static void PrintTitles();
  static void PrintContact(const Contact& contact);
  static void PrintContactItem(const std::string& title, const std::string& s);
  static std::string FormatContactItem(const std::string& item);

 private:
  static const size_t k_max_contacts_length = 8;

  Contact contacts_[PhoneBook::k_max_contacts_length];
};

#endif