/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:28:11 by jotong            #+#    #+#             */
/*   Updated: 2025/10/28 00:41:23 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(NULL);
	std::tm* lt = std::localtime(&t);

	std::cout << "["
			<< lt->tm_year + 1900
			<< std::setw(2) << std::setfill('0') << lt->tm_mon + 1
			<< std::setw(2) << std::setfill('0') << lt->tm_mday << "_"
			<< std::setw(2) << std::setfill('0') << lt->tm_hour
			<< std::setw(2) << std::setfill('0') << lt->tm_min
			<< std::setw(2) << std::setfill('0') << lt->tm_sec
			<< "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();

	std::cout << "accounts:" << Account::getNbAccounts()
			<< ";total:" << Account::getTotalAmount()
			<< ";deposits:" << Account::getNbDeposits()
			<< ";withdrawals:" << Account::getNbWithdrawals()
			<< std::endl;
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created"
			<< std::endl;	
}

void	Account::makeDeposit( int deposit )
{
	int	prev = _amount;

	_amount += deposit;
	_nbDeposits++;
	
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << prev
			<< ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	prev = _amount;
	
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << prev
			<< ";withdrawal:refused"
			<< std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << prev
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_widthdrawals:" << _nbWithdrawals
			<< std::endl;
		return true;
	}
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}
	
Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" << std::endl;
}
