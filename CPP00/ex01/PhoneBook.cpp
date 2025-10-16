/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:04:13 by jotong            #+#    #+#             */
/*   Updated: 2025/10/16 23:51:48 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::findOldestContact()
{
	int	Index;
	int	LastCreatedOrder;
	int	CurrentCreatedOrder;
	int	OldestIndex = 0;

	Index = 1;
	LastCreatedOrder = ContactList[0].getCreatedOrder();
	while (Index < 8)
	{
		CurrentCreatedOrder = ContactList[Index].getCreatedOrder();
		if (CurrentCreatedOrder < LastCreatedOrder)
		{
			LastCreatedOrder = CurrentCreatedOrder;
			OldestIndex = Index;
		}
		Index++;
	}
	return OldestIndex;
};

void	PhoneBook::replaceContactAtIndex(int index, Contact new_contact)
{
	this->ContactList[index] = new_contact;
	return ;
}

void	PhoneBook::addContact(void)
{
	Contact 	new_contact;
	std::string	first_name = "";
	std::string	last_name = "";
	std::string	nickname = "";
	std::string darkest_secret = "";
	int			phone_number = -1;
	int			index = 0;
	int			next_index;

	while (first_name == "")
	{
		std::cout << "First name: " << std::endl;
		std::getline(std::cin, first_name);
		std::cout << "First name cannot be empty." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return ;
		}
		new_contact.setFirstName(first_name);
	}
	while (last_name == "")
	{
		std::cout << "Last name: " << std::endl;
		std::getline(std::cin, last_name);
		std::cout << "Last name cannot be empty." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return ;
		}
		new_contact.setLastName(last_name);
	}
	while (nickname == "")
	{
		std::cout << "Nickname: " << std::endl;
		std::getline(std::cin, nickname);
		std::cout << "Nickname cannot be empty." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return ;
		}
		new_contact.setNickname(nickname);
	}
	while (phone_number < 0)
	{
		std::cout << "Nickname: " << std::endl;
		std::cin >> phone_number;
		std::cout << "Phone Number cannot be empty." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return ;
		}
		new_contact.setPhoneNumber(phone_number);
	}
	while (darkest_secret == "")
	{
		std::cout << "Nickname: " << std::endl;
		std::getline(std::cin, darkest_secret);
		std::cout << "Darkest secret cannot be empty." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return ;
		}
		new_contact.setDarkestSecret(darkest_secret);
	}
	next_index = this->getNextIndex();
	this->ContactList[next_index] = new_contact; // Todo: check if this works
	// Todo: need to increment the next_index in the PhoneBook
	return ;
}

std::string PhoneBook::getContact(int i)
{
	if (i < 0 && i > 7)
	{
		std::cout << "Invalid index, out of range." << std::endl;
		return "";
	}
	if (ContactList[i].getFirstName() == "")
	{
		std::cout << "Empty contact." << std::endl;
		return "";
	}
	return ContactList[i].getContactInfo();
}
int	searchCommand(PhoneBook pb)
{
	int			curr = pb.getContactCount();
	// std::string	contactInfo
	
	if (curr == 0)
		{
			std::cout << "No contacts in the phonebook." << std::endl;
			return 0;
		}
		std::cout << "Contacts: " << std::endl;
	while (curr < 0)
	{
		std::cout << pb.getContact(curr) << std::endl;
		curr--;
	}
	return 0;
}

int	main() {
	std::string command;
	PhoneBook pb;

	std::cout << "Welcome!" << std::endl;
	std::cout << "Available commands: ADD | SEARCH | EXIT to begin" << std::endl;
	std::getline(std::cin, command);
	if (command == "EXIT")
	{
		std::cout << "Goodbye!" << std::endl;
		return 0;
	}
	else if (command == "ADD")
	{
		pb.addContact();
		return 0;
	}
	else if (command == "SEARCH")
	{
		if (searchCommand(pb) == -1)
		{
			std::cout << "An error occurred. Aborting.." << std::endl;
			return 1;
		}
		return 0;
	}
	else
	{
		std::cout << "Unknown command." << std::endl;
		return 1;
	}
	return 0;
}