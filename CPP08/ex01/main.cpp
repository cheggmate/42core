#include "Span.hpp"
#include <ctime>
#include <cstdlib>

void print_title(std::string title) {
    std::cout << title << std::endl;
}

int main() {
	print_title("Standard test cases");
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

    std::srand(std::time(NULL));

    print_title("Subject Basic Test");
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest: " << sp.shortestSpan() << " (Expected 2)" << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << " (Expected 14)" << std::endl;
    } catch (std::exception &e) { std::cerr << e.what() << std::endl; }

    print_title("Exception: Span too small");
    try {
        Span sp(5);
        sp.addNumber(1);
        sp.shortestSpan();
    } catch (std::exception &e) { std::cout << "Caught: " << e.what() << std::endl; }

    print_title("Exception: Span full");
    try {
        Span sp(1);
        sp.addNumber(1);
        sp.addNumber(2);
    } catch (std::exception &e) { std::cout << "Caught: " << e.what() << std::endl; }

    print_title("Range Insertion (10k numbers)");
    try {
        Span bigSpan(10000);
        std::vector<int> v;
        for (int i = 0; i < 10000; ++i) v.push_back(std::rand());
        
        bigSpan.addRange(v.begin(), v.end());
        std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest:  " << bigSpan.longestSpan() << std::endl;
    } catch (std::exception &e) { std::cerr << e.what() << std::endl; }

    return 0;
}
