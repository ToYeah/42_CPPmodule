#include "PhoneBook.hpp"

int main() {
  PhoneBook phone_book;
  try {
    phone_book.run();
  } catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }
}