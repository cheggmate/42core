#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(): std::stack<T>() {};
		MutantStack(const MutantStack& other): std::stack<T>(other) {};    // Copy Constructor
    	MutantStack<T>& operator=(const MutantStack<T>& other) { // Assignment Operator
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return *this;
   		};
    	virtual ~MutantStack() {};                            // Destructor

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin() {
			return this->c.begin();
		};
		iterator	end() {
			return this->c.end();
		};
};

#endif