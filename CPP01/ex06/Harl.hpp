/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:53:06 by jotong            #+#    #+#             */
/*   Updated: 2026/01/02 17:42:53 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <cctype>

class Harl
{
	private:
		std::string message;
		void	debug(void)
		{
			std::cout << "[ DEBUG ]\nI love having extra bacon for my"
				 << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
				 << std::endl;
			return ;
		}
		
		void	info(void)
		{
			std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put"
				<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
				<< std::endl;
			return ;
		}
		void	warning(void)
		{
			std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years, whereas you started working here just last month."
				<< std::endl;
			return ;
		}
		void	error(void)
		{
			std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now."
				<< std::endl;
			return ;
		}
	public:
		Harl () :
			message("")
		{};
		typedef void (Harl::*HarlMembers)(); // type alias for the member pointer function
		void complain(std::string level);
};

#endif