#include "PhoneBook.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PhoneBook::PhoneBook() : contacts_() {}

PhoneBook::PhoneBook(const PhoneBook& src) {
  if (&src != this) {
    *this = src;
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PhoneBook::~PhoneBook() { std::cout << "PhoneBook Destructor executed\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PhoneBook& PhoneBook::operator=(PhoneBook const& src) {
  if (this != &src) {
    for (size_t i = 0; i < PhoneBook::k_max_contacts_length; i++) {
      this->contacts_[i] = src.contacts_[i];
    }
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PhoneBook::run() {
  std::cin.exceptions(std::ios::badbit);
  std::cout.exceptions(std::ios::badbit);

  size_t index = 0;
  std::string input_line;
  while (std::cin.good()) {
    input_line = "";

    std::cout << "Please Input ADD or SEARCH or EXIT"
              << "\n"
              << std::endl;

    std::getline(std::cin, input_line);
    std::cout << std::endl;

    if (input_line == "ADD") {
      add(index % PhoneBook::k_max_contacts_length);
      index++;
    } else if (input_line == "SEARCH") {
      Search();
    } else if (input_line == "EXIT") {
      return;
    }

    std::cout << std::endl;
  }
}

void PhoneBook::inputContactInformation(Contact& contact,
                                        void (Contact::*fn)(const std::string&),
                                        std::string s) {
  std::string input_line;

  std::cout << "Please Input " << s << std::endl;
  std::getline(std::cin, input_line);
  std::cout << std::endl;

  (contact.*fn)(input_line);
}

void PhoneBook::add(size_t index) {
  Contact newContact;

  std::cout << "Prease input new Contact"
            << "\n"
            << std::endl;

  inputContactInformation(newContact, &Contact::SetFirstName, "FirstName");
  inputContactInformation(newContact, &Contact::SetLastName, "LastName");
  inputContactInformation(newContact, &Contact::SetNickname, "Nickname");
  inputContactInformation(newContact, &Contact::SetPhoneNumber, "PhoneNumber");
  inputContactInformation(newContact, &Contact::SetDarkestSecret,
                          "DarkestSecret");
  SetContact(newContact, index);
}

bool PhoneBook::isEmptyContact(const Contact& contact) {
  return contact.GetFirstName().empty() || contact.GetLastName().empty() ||
         contact.GetNickname().empty() || contact.GetPhoneNumber().empty() ||
         contact.GetDarkestSecret().empty();
}

void PhoneBook::PrintHorizonSeparator() {
  std::cout << std::setfill('-') << std::setw(45) << "" << std::endl;
}

void PhoneBook::PrintVerticalSeparator() { std::cout << "|"; }

void PhoneBook::PrintItem(const std::string item) {
  std::cout << std::setfill(' ') << std::right << std::setw(10) << item;
  PrintVerticalSeparator();
}

std::string PhoneBook::FormatContactItem(const std::string& item) {
  return item.size() > 10 ? item.substr(0, 9) + "." : item;
}

void PhoneBook::PrintContactRow(const Contact& contact, size_t index) {
  std::stringstream ss;
  ss << index;

  PrintVerticalSeparator();
  PrintItem(ss.str());
  PrintItem(FormatContactItem(contact.GetFirstName()));
  PrintItem(FormatContactItem(contact.GetLastName()));
  PrintItem(FormatContactItem(contact.GetNickname()));
  std::cout << std::endl;
  PrintHorizonSeparator();

  std::cout << std::setfill(' ') << std::left;
}

void PhoneBook::PrintTitles() {
  PrintHorizonSeparator();
  PrintVerticalSeparator();
  PrintItem("INDEX");
  PrintItem("FIRSTNAME");
  PrintItem("LASTNAME");
  PrintItem("NICKNAME");
  std::cout << std::endl;

  PrintHorizonSeparator();
}

void PhoneBook::PrintContactsList() {
  PrintTitles();
  for (size_t i = 0; i < PhoneBook::k_max_contacts_length; i++) {
    if (!isEmptyContact(GetContact(i))) {
      PrintContactRow(GetContact(i), i);
    }
  }
  std::cout << std::endl;
}

void PhoneBook::PrintContactItem(const std::string& title,
                                 const std::string& s) {
  std::cout << std::setw(15) << title << ": " << s << std::endl;
}

void PhoneBook::PrintContact(const Contact& contact) {
  PrintContactItem("FirstName", contact.GetFirstName());
  PrintContactItem("LastName", contact.GetLastName());
  PrintContactItem("Nickname", contact.GetNickname());
  PrintContactItem("PhoneNumber", contact.GetPhoneNumber());
  PrintContactItem("DarkestSecret", contact.GetDarkestSecret());
}

void PhoneBook::Search() {
  std::string input_line;
  size_t index;

  PrintContactsList();
  std::cout << "Please input Index" << std::endl;
  std::getline(std::cin, input_line);
  std::cout << std::endl;
  std::istringstream(input_line) >> index;

  if (input_line.empty() ||
      input_line.find_first_not_of("0123456789") != std::string::npos ||
      index >= PhoneBook::k_max_contacts_length ||
      isEmptyContact(GetContact(index))) {
    std::cout << "Invalid index!!!!!!" << std::endl;
    return;
  }
  PrintContact(GetContact(index));
}
/*
** --------------------------------- ACCESSOR
*---------------------------------
*/

const Contact& PhoneBook::GetContact(const size_t& index) const {
  return contacts_[index];
}

void PhoneBook::SetContact(const Contact& src, const size_t& index) {
  if (index < k_max_contacts_length) {
    contacts_[index] = src;
  }
  return;
}

/* **************************************************************************
 */