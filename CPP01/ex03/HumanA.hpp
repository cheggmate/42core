/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 22:01:29 by jotong            #+#    #+#             */
/*   Updated: 2025/10/31 22:18:55 by jotong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon&		weapon;
		std::string	name;
	public:
		HumanA(const std::string& name, Weapon& weapon) :
			weapon(weapon),
			name(name)
		{};
		void attack()
		{
			std::cout << name << " attacks with their " << weapon.getType() << std::endl;
			return ;
		};
};

#endif