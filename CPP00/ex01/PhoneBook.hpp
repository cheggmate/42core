/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:18:02 by jotong            #+#    #+#             */
/*   Updated: 2025/10/26 23:43:53 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <sstream>
# include <cctype>

# ifndef MAX_CONTACTS
#  define MAX_CONTACTS 8
# endif

# ifndef VIEW_LEN
#  define VIEW_LEN 10
# endif

std::string i_to_s(int i)
{
	std::stringstream ss;

	ss << i;
	return ss.str();
}

class Contact
{
	private :
		std::string FirstName;
		std::string LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
		int			CreatedOrder;
	
	public :
		Contact() :
			FirstName(""),
			LastName(""),
			NickName(""),
			PhoneNumber(""),
			DarkestSecret(""),
			CreatedOrder(0)
		{}
		std::string getContactInfo(int full_info, int ind) const {

			int	fn_space;
			int	ln_space;
			int	nn_space;
			std::string	fn_display;
			std::string	ln_display;
			std::string	nn_display;
			std::string ind_display;

			if (full_info == 1)
			{
				return  "First name       : " + FirstName + "\n"
					+ "Last name        : " + LastName + "\n"
					+ "Nickname         : " + NickName + "\n"
					+ "Phone number     : " + PhoneNumber + "\n"
					+ "Darkest secret   : " + DarkestSecret + "\n";
			}
			
			ind_display = i_to_s(ind);
			fn_display = FirstName.length() > VIEW_LEN ? (FirstName.substr(0, VIEW_LEN - 1) + '.') : FirstName ;
			ln_display = LastName.length() > VIEW_LEN ? (LastName.substr(0, VIEW_LEN - 1) + '.') : LastName ;
			nn_display = NickName.length() > VIEW_LEN ? (NickName.substr(0, VIEW_LEN - 1) + '.') : NickName ;

			fn_space = fn_display.length() > VIEW_LEN ? 0 : VIEW_LEN - fn_display.length();
			ln_space = ln_display.length() > VIEW_LEN ? 0 : VIEW_LEN - ln_display.length();
			nn_space = nn_display.length() > VIEW_LEN ? 0 : VIEW_LEN - nn_display.length();

			std::string fn_str(fn_space, ' ');
			std::string ln_str(ln_space, ' ');
			std::string nn_str(nn_space, ' ');

			return  "         " + ind_display + "|"
				+ fn_str + fn_display + "|"
				+ ln_str + ln_display  + "|"
				+ nn_str + nn_display + "\n";
		};
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
		int	getCreatedOrder() const
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
		void	displayContacts() const
		{
			int i;
			int	n_contacts;
			int	n_added;

			i = 0;
			n_added = this->getCreatedOrder();
			if (n_added > 8)
				n_contacts = 8;
			else
				n_contacts = n_added;
			if (n_contacts > 0)
			{
				std::cout << "Contacts in table: " <<std::endl;
				std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
				std::cout << "-------------------------------------------" << std::endl;
			}
			while (i < n_contacts)
			{
				std::cout << this->ContactList[i].getContactInfo(0, i);
				i++;
			}
			return ;
		}
		void	displayFullContact(int index) const
		{
			std::cout << this->ContactList[index].getContactInfo(1, index);
			return ;
		}
};

#endif
