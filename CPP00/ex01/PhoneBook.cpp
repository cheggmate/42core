/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:04:13 by jotong            #+#    #+#             */
/*   Updated: 2025/10/16 00:25:34 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::addContact(void)
{
	Contact new_contact;
	
	// std::string	first_name = "";
	// std::string	last_name = "";
	// std::string	nickname = "";
	// std::string darkest_secret = "";
	// int			phone_number = -1;

	while (first_name == "")
	{
		std::cout << "First name: " << std::endl;
		std::getline(std::cin, new_contact.first_name);
		std::cout << "First name cannot be empty." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return -1;
		}
	}
	while (last_name == "")
	{
		std::cout << "Last name: " << std::endl;
		std::getline(std::cin, new_contact.last_name);
		std::cout << "Last name cannot be empty." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return -1;
		}
	}
	while (nickname == "")
	{
		std::cout << "Nickname: " << std::endl;
		std::getline(std::cin, new_contact.nickname);
		std::cout << "Nickname cannot be empty." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return -1;
		}
	}
	while (phone_number < 0)
	{
		std::cout << "Nickname: " << std::endl;
		std::cin >> new_contact.phone_number;
		std::cout << "Phone Number cannot be empty." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return -1;
		}
	}
	while (nickname == "")
	{
		std::cout << "Nickname: " << std::endl;
		std::getline(std::cin, new_contact.nickname);
		std::cout << "Nickname cannot be empty." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return -1;
		}
	}
	while (darkest_secret == "")
	{
		std::cout << "Nickname: " << std::endl;
		std::getline(std::cin, new_contact.darkest_secret);
		std::cout << "Darkest secret cannot be empty." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Detected EOF, exiting." << std::endl;
			return -1;
		}
	}
	
	// TODO: add function to:
	// check count of contacts
	// if count exceeds 8
	// get earliest contact and replace.
	
	
	if (insert_contact(first_name, last_name, nickname, phone_number, darkest_secret) == -1)
	{
		std::cout << "An error occurred." << std::endl;
	}
	return 0;
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
		if (command_add() == -1)
			return 1;
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