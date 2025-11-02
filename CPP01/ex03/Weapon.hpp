#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string t) :
			type(t)
		{};
		const std::string& getType() const
		{
			return this->type;
		}
		void setType(std::string newType)
		{
			this->type = newType;
			return ;
		}
};

#endif