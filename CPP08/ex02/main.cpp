#include <iostream>
#include "MutantStack.hpp"
#include <list>

void	print_testinfo(std::string m) {
	std::cout << "\n" << m << std::endl;
}

void	test_list() {
	print_testinfo("Own test case - List");
	MutantStack<int> ostack;
	std::list<int> mylist;

	ostack.push(5);
	mylist.push_back(5);
	ostack.push(17);
	mylist.push_back(17);
	ostack.push(21);
	mylist.push_back(21);

	MutantStack<int>::iterator its = ostack.begin();
	std::list<int>::iterator itl = mylist.begin();

	MutantStack<int>::iterator itse = ostack.end();
	std::list<int>::iterator itle = mylist.end();

	while (its != itse && itl != itle) {
		std::cout << "Stack: " << *its << " | List: " << *itl << std::endl;
		++its;
		++itl;
	}
}

void	test_deque() {
	print_testinfo("Own test case - Deque");
	MutantStack<int> mstack;
    std::deque<int>  mydeque;

    for (int i = 0; i < 5; ++i) {
        mstack.push(i * 10);
        mydeque.push_back(i * 10);
    }

    MutantStack<int>::iterator it = mstack.begin();
    std::deque<int>::iterator itd = mydeque.begin();

    while (it != mstack.end()) {
		std::cout << "Stack: " << *it << " | Deque: " << *itd << std::endl;
        ++it;
        ++itd;
    }
}

int main()
{
	print_testinfo("from 42 assignment.");
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	test_list();
	test_deque();
	return 0;
}