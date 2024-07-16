#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdio>

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();

	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << initial_deposit << ";created" << std::endl;

	_nbAccounts += 1;
	_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << checkAmount() << ";closed" << std::endl;

	_nbAccounts -= 1;
	_totalAmount -= checkAmount();
	_totalNbDeposits -= this->_nbDeposits;
	_totalNbWithdrawals -= this->_nbWithdrawals;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << checkAmount();
	std::cout << ";deposit:" << deposit;

	this->_amount += deposit;
	this->_nbDeposits += 1;

	_totalAmount += deposit;
	_totalNbDeposits += 1;

	std::cout << ";amount:" << checkAmount();
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << checkAmount();
	std::cout << ";withdrawal:";

	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}

	std::cout << withdrawal;

	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;

	std::cout << ";amount:" << checkAmount();
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t	currentTime;
	struct tm	*localTime;
	char		buffer[50];

	currentTime = std::time(NULL);
	localTime = std::localtime(&currentTime);

	if (!localTime)
		return (perror("localTime"));

	std::strftime(buffer, 50, "%Y%m%d_%H%M%S", localTime);
	std::cout << '[' << buffer << "] ";
}

Account::Account(void) : _accountIndex(_nbAccounts++), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{

}

