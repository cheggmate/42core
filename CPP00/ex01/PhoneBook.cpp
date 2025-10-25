/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:04:13 by jotong            #+#    #+#             */
/*   Updated: 2025/10/26 00:55:32 by jotong           ###   ########.fr       */
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

void	PhoneBook::displayContacts()
{
	int i;
	int total;

	i = 0;
	total = this->getCreatedOrder();
	while (i < 8 && i < total)
	{
		std::cout << this->ContactList[i].getContactInfo() << '\n';
		i++;
	}
	return ;
}
// void	PhoneBook::replaceContactAtIndex(int index, Contact new_contact)
// {
// 	this->ContactList[index] = new_contact;
// 	return ;
// }

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
		// new_contact.setFirstName(first_name);
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
		// new_contact.setLastName(last_name);
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
		// new_contact.setNickname(nickname);
	}
	while (phone_number == "")
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
		// new_contact.setPhoneNumber(phone_number);
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
		// new_contact.setDarkestSecret(darkest_secret);
	}
	next_index = this->getNextIndex();
	added_order = this->getCreatedOrder();
	// Todo: need to increment the next_index in the PhoneBook
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
	return ContactList[i].getContactInfo();
}
int	searchCommand(PhoneBook pb)
{
	int			curr;
	// std::string	contactInfo
	
	curr = pb.getNextIndex();
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
	
	do {
		std::cout << "Available commands: ADD | SEARCH | EXIT to begin" << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			continue ;
		}
		else if (command == "ADD")
		{
			pb.addContact();
			continue ;
		}
		else if (command == "SEARCH")
		{
			if (searchCommand(pb) == -1)
			{
				std::cout << "An error occurred. Aborting.." << std::endl;
				continue ;
			}
			else
			{
				pb.displayContacts();
			}
		}
		else
		{
			std::cout << "Unknown command." << std::endl;
			continue ;
		}
	} while (command != "EXIT");
	
	return 0;
}