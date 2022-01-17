#include "Karen.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Karen::Karen() {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Karen::~Karen() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void Karen::complain(std::string level) {
  t_karen_func funcs[] = {&Karen::debug, &Karen::info, &Karen::warning,
                          &Karen::error, &Karen::nothing};
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  size_t index = 0;

  while (levels[index] != level && index < 4) {
    index++;
  }

  switch (index) {
    case 0:
      (this->*funcs[index])();
      index++;
    case 1:
      (this->*funcs[index])();
      index++;
    case 2:
      (this->*funcs[index])();
      index++;
    case 3:
      (this->*funcs[index])();
      index++;
      break;
    default:
      (this->*funcs[index])();
      break;
  }
}

void Karen::debug(void) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "I love to get extra bacon for my "
               "7XL-double-cheese-triple-pickle-special-ketchup burger. I just "
               "love it!"
            << std::endl;
}

void Karen::info(void) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon cost more money. You don’t "
               "put enough! If you did I would not have to ask for it!"
            << std::endl;
}

void Karen::warning(void) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming here for years and you just started working here last month."
      << std::endl;
}

void Karen::error(void) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable, I want to speak to the manager now."
            << std::endl;
}

void Karen::nothing(void) {
  std::cout << "[ Probably complaining about insignificant problems ]"
            << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */