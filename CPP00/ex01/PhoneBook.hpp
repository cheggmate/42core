/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:18:02 by jotong            #+#    #+#             */
/*   Updated: 2025/10/26 00:50:28 by jotong           ###   ########.fr       */
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
		// int			CountContacts; // = 0; // TODO: check if this field is needed
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
		// void	setFirstName(const std::string& input);
		// void	setLastName(const std::string& input);
		// void	setNickname(const std::string& input);
		// void	setPhoneNumber(const std::string& input);
		// void	setDarkestSecret(const std::string& input);
		void addDetails(const std::string& f_name, const std::string& l_name,
						const std::string& n_name, const std::string& d_secret,
						const std::string& p_num, const int c_order)
		{
			this->FirstName = f_name;
			this->LastName = l_name;
			this->NickName = n_name;
			this->DarkestSecret = d_secret;
			this->PhoneNumber = p_num;
			this->CreatedOrder = c_order;
		}
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
		int	getNextIndex()
		{
			return NextIndex;
		}
		int	getCreatedOrder()
		{
			return CurrentCreatedOrder;
		}
		int	findOldestContact();

		// getting properties of a contact
		std::string getContact(int index);
		void	addContact(void);
		void	increaseNextIndex()
		{
			if (NextIndex <= 6)
				NextIndex++;
			else
				NextIndex = 0;
			return ;
		}
		void	increaseCurrentCreatedOrder()
		{
			CurrentCreatedOrder++;
			return ;
		}
		// void	replaceContactAtIndex(int index, Contact new_contact);
		void	displayContacts();
};

#endif
