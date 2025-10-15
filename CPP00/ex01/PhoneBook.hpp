/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:18:02 by jotong            #+#    #+#             */
/*   Updated: 2025/10/16 00:30:53 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <cctype>

class Contact
{
	private :
		int			Index = 0;
		std::string FirstName = "";
		std::string LastName = "";
		std::string	NickName = "";
		int			PhoneNumber = -1;
		std::string	DarkestSecret = "";
		int			CountContacts = 0;
		// int			CreatedOrder;
	
	public :
		//void	getBalance(int	index);
		std::string getContactInfo() const {
			return "Index			 : " + std::to_string(PhoneNumber) + "\n"
				 + "First name       : " + FirstName + "\n"
				 + "Last name        : " + LastName + "\n"
				 + "Nickname         : " + NickName + "\n"
				 + "Phone number     : " + std::to_string(PhoneNumber) + "\n"
				 + "Darkest secret   : " + DarkestSecret + "\n";
		};
		// int	getCreatedOrder() const {
		// 	return CreatedOrder;
		// };
		std::string getFirstName() const {
			return FirstName;
		}
};

class PhoneBook
{
	private:
		int		CountContacts;
		int		LastCreatedOrder;
		Contact ContactList[8];
		int		CurrentCreatedOrder;

	public:
		// getting properties of the phonebook
		int	getContactCount()
		{
			return CountContacts;
		};
		int	findOldestContact()
		{
			int	index;

			index = 1;
			LastCreatedOrder = ContactList[0].getCreatedOrder();
			while (index < 8)
			{
				CurrentCreatedOrder = ContactList[index].getCreatedOrder();
				if (CurrentCreatedOrder < LastCreatedOrder)
					LastCreatedOrder = CurrentCreatedOrder;
			}
			return LastCreatedOrder;
		};

		// getting properties of a contact
		std::string getContact(int index);
		void	addContact(void);
		// void	addContact(void)
		// {
			
		// 	const std::string& f, const std::string& l,\
		// 	const std::string& n, const int& p,\
		// 	const std::string& d, const int& o
		// 	FirstName = f;
		// 	LastName = l;
		// 	NickName = n;
		// 	PhoneNumber = p;
		// 	DarkestSecret = d;
		// 	CreatedOrder = o;
		// };
		// manipulating contacts in the phonebook
		// int	addContact(Contact) // TODO: This is not implemented
};

#endif
