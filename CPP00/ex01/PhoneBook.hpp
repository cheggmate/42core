/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:18:02 by jotong            #+#    #+#             */
/*   Updated: 2025/10/25 01:06:17 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <cctype>

# ifndef MAX_CONTACTS
#  define MAX_CONTACTS 8
# endif

class Contact
{
	private :
		int			Index; // = 0; // TODO: check if its necessary to init these
		std::string FirstName; // = "";
		std::string LastName; //= "";
		std::string	NickName; // = "";
		std::string	PhoneNumber; // = -1;
		std::string	DarkestSecret; // = "";
		int			CountContacts; // = 0; // TODO: check if this field is needed
		int			CreatedOrder;	// order in which this contact is created
	
	public :
		Contact() :
			FirstName(""),
			LastName(""),
			NickName(""),
			PhoneNumber(""),
			DarkestSecret(""),
			CreatedOrder(0)
		{}
		
		//void	getBalance(int	index);
		std::string getContactInfo() const {
			return "Index			 : " + std::to_string(Index) + "\n"
				 + "First name       : " + FirstName + "\n"
				 + "Last name        : " + LastName + "\n"
				 + "Nickname         : " + NickName + "\n"
				 + "Phone number     : " + PhoneNumber + "\n"
				 + "Darkest secret   : " + DarkestSecret + "\n";
		};
		void	setFirstName(const std::string& input);
		void	setLastName(const std::string& input);
		void	setNickname(const std::string& input);
		void	setPhoneNumber(const int& input);
		void	setDarkestSecret(const std::string& input);
		int	getCreatedOrder() const {
			return CreatedOrder;
		};
		void	setCreatedOrder(int order) {
			CreatedOrder = order;
		}
	
		std::string getFirstName() const {
			return FirstName;
		}
};

class PhoneBook
{
	private:
		// int		CountContacts;
		Contact ContactList[8];
		int		CurrentCreatedOrder;
		int		NextIndex; // = 0;

	public:
		PhoneBook() :
			CurrentCreatedOrder(0),
			NextIndex(0)
		{}
		// getting properties of the phonebook
		// int	getContactCount()
		// {
		// 	return CountContacts;
		// };
		int	getNextIndex()
		{
			return NextIndex;
		}
		int	findOldestContact();

		// getting properties of a contact
		std::string getContact(int index);
		// void	increaseContactCount(){
		// 	int	currentContactCount = getContactCount();
		// 	currentContactCount += 1;
		// 	const int& currentContactCount;
		// };
		void	addContact(void);
		void	replaceContactAtIndex(int index, Contact new_contact);
		void	displayContacts() const;
};

#endif
