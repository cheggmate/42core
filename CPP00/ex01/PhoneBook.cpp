/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:04:13 by jotong            #+#    #+#             */
/*   Updated: 2025/11/13 23:17:45 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::findOldestContact()
{
	int	oldestOrder;
	int	oldestIndex;

	oldestIndex = 0;
	oldestOrder = ContactList[0].getCreatedOrder();
	for (int i = 1; i < MAX_CONTACTS; ++i)
	{
		int currentOrder = ContactList[i].getCreatedOrder();
		if (currentOrder < oldestOrder)
		{
			oldestOrder = currentOrder;
			oldestIndex = i;
		}
	}
	return oldestIndex;
};

int	is_valid_phone_number(std::string phone_number)
{
	int	p_len;
	int	start_i;

	start_i = 0;
	p_len = phone_number.length();
	if (p_len == 0)
		return 0;
	if (phone_number[0] == '-')
		return 0;
	if (phone_number[0] == '+')
		start_i = 1;
	for (int i = start_i; i < p_len; i++)
	{
		if (!std::isdigit(phone_number[i]) && phone_number[i] != '-')
			return 0;
	}
	return (1);
}

void	PhoneBook::addContact(void)
{
	Contact 	new_contact;
	std::string	first_name = "";
	std::string	last_name = "";
	std::string	nickname = "";
	std::string darkest_secret = "";
	std::string	phone_number = "";
	int			next_index;
	int			added_order;

	while (first_name == "")
	{
		std::cout << "First name: " << std::endl;
		std::getline(std::cin, first_name);
		
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return ;
		}
		if (first_name.empty())
		{
			std::cout << "First name cannot be empty." << std::endl;
		}
	}
	while (last_name == "")
	{
		std::cout << "Last name: " << std::endl;
		std::getline(std::cin, last_name);
		
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return ;
		}
		if (last_name.empty())
		{
			std::cout << "Last name cannot be empty." << std::endl;
		}
	}
	while (nickname == "")
	{
		std::cout << "Nickname: " << std::endl;
		std::getline(std::cin, nickname);
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return ;
		}
		if (nickname.empty())
		{
			std::cout << "Nickname cannot be empty." << std::endl;
		}
	}
	while (phone_number.empty() || is_valid_phone_number(phone_number) == 0)
	{
		std::cout << "Phone Number: " << std::endl;
		std::getline(std::cin, phone_number);
		
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return ;
		}
		if (phone_number.empty())
		{
			std::cout << "Phone Number cannot be empty." << std::endl;
		}
		else if (is_valid_phone_number(phone_number) == 0)
		{
			std::cout << "Phone Number contains unallowed characters. Please provide a valid number." << std::endl;
		}
	}
	while (darkest_secret == "")
	{
		std::cout << "Darkest Secret: " << std::endl;
		std::getline(std::cin, darkest_secret);
		
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return ;
		}
		if (darkest_secret.empty())
		{
			std::cout << "Darkest secret cannot be empty." << std::endl;
		}
	}
	next_index = this->getNextIndex();
	added_order = this->getCreatedOrder();
	new_contact.addDetails(first_name, last_name, nickname, darkest_secret,
					phone_number, added_order + 1);
	this->ContactList[next_index] = new_contact; // Todo: check if this works
	std::cout << "added contact at position " << next_index <<  std::endl;
	this->increaseCurrentCreatedOrder();
	this->increaseNextIndex();
	return ;
}

std::string PhoneBook::getContact(int i)
{
	if (i < 0 || i > 7)
	{
		std::cout << "Invalid index, out of range." << std::endl;
		return "";
	}
	if (ContactList[i].getFirstName() == "")
	{
		std::cout << "Empty contact." << std::endl;
		return "";
	}
	return ContactList[i].getContactInfo(1, i);
}
int	searchCommand(const PhoneBook *pb)
{
	int			curr;
	int			c_index;
	int			populated_entries;
	
	curr = pb->getCreatedOrder();
	c_index = -1;
	if (curr == 0)
	{
		std::cout << "No contacts in the phonebook." << std::endl;
		return 0;
	}
	else
		pb->displayContacts();
	
	std::cin.clear();
	std::cout << "\nProvide the index of contact of interest: " << std::endl;

	// Handling non-numeric input
	if (!(std::cin >> c_index))
	{
		std::cout << "Invalid input (non-numeric). Exiting.." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 1;
	}
	
	if (std::cin.eof())
	{
		std::cout << "EOF Detected. Exiting.." << std::endl;
		return 1;
	}
	if (std::cin.peek() == '\n')
	{
		std::cin.ignore(1, '\n');
	}
	populated_entries = curr > 8 ? 7 : curr - 1;
	if (c_index < 0 || c_index > populated_entries)
	{
		std::cout << "Invalid index provided. Exiting back to menu.." << std::endl;
		std::cin.clear();
		return 1;
	}
	pb->displayFullContact(c_index);
	return 0;
}

int	main() {
	std::string command;
	PhoneBook pb;

	std::cout << "Welcome!" << std::endl;
	
	do {
		std::cout << "Available commands: ADD | SEARCH | EXIT to begin" << std::endl;
		std::cin.clear();
		std::getline(std::cin, command);
		if (command == "EXIT" || command == "exit")
		{
			std::cout << "Goodbye!" << std::endl;
			break ;
		}
		else if (command == "ADD" || command == "add")
		{
			pb.addContact();
			continue ;
		}
		else if (command == "SEARCH" || command == "search")
		{
			if (searchCommand(&pb) == -1)
			{
				std::cout << "An error occurred. Aborting.." << std::endl;
				
			}
			continue ;
		}
		else
		{
			// std::cout << "Unknown command." << std::endl;
			continue ;
		}
	} while (command != "EXIT" || command != "exit");
	
	return 0;
}
