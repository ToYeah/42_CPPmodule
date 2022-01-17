#include "Account.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Account::Account() {}

Account::Account(int initial_deposit) {
  _accountIndex = _nbAccounts++;
  _amount = initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;

  _totalAmount += _amount;

  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "created" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "closed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void Account::makeDeposit(int deposit) {
  int p_amount = _amount;
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;

  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << p_amount << ";"
            << "deposit:" << deposit << ";"
            << "amount:" << _amount << ";"
            << "nb_deposits:" << _nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";"
            << "withdrawal:";
  if (withdrawal > _amount) {
    std::cout << "refused" << std::endl;
    return false;
  }

  _nbWithdrawals++;
  _totalNbWithdrawals++;
  _amount -= withdrawal;
  _totalAmount -= withdrawal;

  std::cout << withdrawal << ";"
            << "amount:" << _amount << ";"
            << "nb_withdrawals:" << _nbWithdrawals << std::endl;

  return true;
}
int Account::checkAmount(void) const {
  // TODO
  return 1;
}
void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "deposits:" << _nbDeposits << ";"
            << "withdrawals:" << _nbWithdrawals << std::endl;
}
void Account::_displayTimestamp(void) {
  time_t now = std::time(NULL);
  const tm* localTime = localtime(&now);
  std::stringstream s;

  s << std::setfill('0');
  s << "[";
  s << "20" << std::setw(2) << localTime->tm_year - 100;
  s << std::setw(2) << localTime->tm_mon + 1;
  s << std::setw(2) << localTime->tm_mday;
  s << "_";
  s << std::setw(2) << localTime->tm_hour;
  s << std::setw(2) << localTime->tm_min;
  s << "] ";

  std::cout << s.str();
};

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << Account::getNbAccounts() << ";"
            << "total:" << Account::getTotalAmount() << ";"
            << "deposits:" << Account::getNbDeposits() << ";"
            << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/*
** --------------------------------- ACCESSOR
*---------------------------------
*/

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

/* **************************************************************************
 */