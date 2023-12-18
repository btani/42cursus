/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:13:36 by btani             #+#    #+#             */
/*   Updated: 2023/12/12 17:40:08 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//constructor of the Account class
Account::Account(int initial_deposit) : _accountIndex(Account::getNbAccounts()), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += this->checkAmount();
};

//distructor of the Account class
Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "closed" << std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount -= this->checkAmount();
};

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
};

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
};

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
};

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
};

int	Account::checkAmount(void) const
{
	return this->_amount;
};

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
};

//structure holding a calendar date and time broken down into its components
void	Account::_displayTimestamp(void)
{
	std::time_t	currentTime;
	std::tm*	timeInfoLocal;

	currentTime = std::time(0);
	timeInfoLocal = std::localtime(&currentTime);
	std::cout << "[";
	std::cout << timeInfoLocal->tm_year + 1900;
	std::cout << timeInfoLocal->tm_mon + 1 << timeInfoLocal->tm_mday;
	std::cout << "_";
	std::cout << timeInfoLocal->tm_hour << timeInfoLocal->tm_min << timeInfoLocal->tm_sec; 
	std::cout << "] "; 
};

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;	
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	std::cout << "withdrawal:";
	if (withdrawal < 0 || withdrawal > this->checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
