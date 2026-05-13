#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

void	print_testcase(std::string tcase) {
	std::cout << tcase << std::endl;
}

// Maps and stacks not included, out of scope.

int main() {
	print_testcase("Test 1: vectors");
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);

    try {
        std::vector<int>::iterator it = easyfind(v, 10); // returns pointer as proof
        std::cout << "Found: " << *it << std::endl;

        easyfind(v, 42); // this will fail
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

	print_testcase("Test 2: Lists");
	std::list<int> y;
	y.push_back(10);
	y.push_back(20);

	try {
		std::list<int>::iterator l_it = easyfind(y, 10);
		std::cout << "Found: " << *l_it << std::endl;
		
		easyfind(y, 42); // this will fail
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	print_testcase("Test 2: Deque");
	std::deque<int> z;
	z.push_back(10);
	z.push_back(20);
	try {
		std::deque<int>::iterator q_it = easyfind(z, 10);
		std::cout << "Found: " << *q_it << std::endl;
		
		easyfind(z, 42); // this will fail
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	print_testcase("Test 3: Null list");
	std::list<int> a;

	try {
        std::list<int>::iterator a_it = easyfind(a, 10); //this will fail
        std::cout << "Found: " << *a_it << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
