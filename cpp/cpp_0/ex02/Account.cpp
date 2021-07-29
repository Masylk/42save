#include "Account.hpp"
#include <iostream>

int      Account::_nbAccounts = 0;
int      Account::_totalAmount = 0;
int      Account::_totalNbDeposits = 0;
int      Account::_totalNbWithdrawals = 0;

int      Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int      Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int      Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int      Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void     Account::displayAccountsInfos( void )
{
	std::cout << Account::_nbAccounts << std::endl;
}

Account::Account( int initial_deposit = 0 )
{
	Account::_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	Account::_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	Account::_nbWithdrawals = 0;
}

Account::~Account( void )
{
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;
}

void    Account::makeDeposit( int deposit )
{
	this->_nbDeposits += 1;
	this->_amount = deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
}

bool    Account::makeWithdrawal( int withdrawal )
{
	if (Account::_amount < withdrawal)
		return (false);
	this->_nbWithdrawals = 1;
	this->_amount -= withdrawal;
	return (true);
}

int             Account::checkAmount( void ) const
{
	return (Account::_amount);
}

void    Account::displayStatus( void ) const
{
	std::cout << this->_nbDeposits << std::endl;
}
