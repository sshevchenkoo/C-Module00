#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);

    std::cout << "[" << now->tm_year + 1900 
                << std::setw(2) << std::setfill('0') << now->tm_mon + 1
                << std::setw(2) << std::setfill('0') << now->tm_mday << "_"
                << std::setw(2) << std::setfill('0') << now->tm_hour 
                << std::setw(2) << std::setfill('0') << now->tm_min
                << std::setw(2) << std::setfill('0') << now->tm_sec
                << "] ";
}

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0),  _nbWithdrawals(0)
{
    this->_accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts( void )
{
    return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
   return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "account:" << getNbAccounts()
                << ";total:" << getTotalAmount()
                << ";deposit:" << getNbDeposits()
                << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
            << ";p_amount:" << this->_amount - deposit
            << ";deposit:" << deposit
            << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits
            << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    if (this->_amount >= withdrawal)
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << "index:" << this->_accountIndex
                << ";p_amount:" << this->_amount + withdrawal
                << ";withdrawal:" << withdrawal
                << ";amount:" << this->_amount
                << ";nb_withdrawals:" << this->_nbWithdrawals
                << std::endl;
        return (true);
    }
    else
    {
        std::cout << "index:" << this->_accountIndex
                << ";p_amount:" << this->_amount
                << ";withdrawal:refused" << std::endl;
        return (false);
    }
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
            << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals
            << std::endl;
}
