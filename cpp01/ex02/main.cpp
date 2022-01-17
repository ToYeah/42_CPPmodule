#include <iomanip>
#include <iostream>

int main() {
  std::string str = "HI THIS IS BRAIN";
  std::string *str_ptr = &str;
  std::string &str_ref = str;

  std::cout << std::setw(15) << std::left << "string"
            << ":" << &str << std::endl;

  std::cout << std::setw(15) << std::left << "stringPTR"
            << ":" << str_ptr << std::endl;

  std::cout << std::setw(15) << std::left << "stringREF"
            << ":" << &str_ref << std::endl;

  std::cout << std::setw(15) << std::left << "stringfromPTR"
            << ":" << *str_ptr << std::endl;

  std::cout << std::setw(15) << std::left << "stringfromREF"
            << ":" << str_ref << std::endl;
}