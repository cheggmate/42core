/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:18:02 by jotong            #+#    #+#             */
/*   Updated: 2025/10/12 23:57:56 by jotong           ###   ########.fr       */
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
		std::string FirstName;
		std::string LastName;
		std::string	NickName;
		int			PhoneNumber;
		std::string	DarkestSecret;
		int			CountContacts;
		int			CreatedOrder;
	
	public :
		//void	getBalance(int	index);
		void	addContact(const std::string& f, const std::string& l,\
			const std::string& n, const int& p,\
			const std::string& d, const int& o)
		{
			FirstName = f;
			LastName = l;
			NickName = n;
			PhoneNumber = p;
			DarkestSecret = d;
			CreatedOrder = o;
		};
		std::string getContactInfo() const {
			return "First name       : " + FirstName + "\n"
				 + "Last name        : " + LastName + "\n"
				 + "Nickname         : " + NickName + "\n"
				 + "Phone number     : " + std::to_string(PhoneNumber) + "\n"
				 + "Darkest secret   : " + DarkestSecret + "\n";
		};
		int	getCreatedOrder() const {
			return CreatedOrder;
		};
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

		// manipulating contacts in the phonebook
		// int	addContact(Contact) // TODO: This is not implemented
};

#endif
