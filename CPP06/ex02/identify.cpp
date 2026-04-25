#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    int r = std::rand() % 3;
    if (r == 0) return new A;
    if (r == 1) return new B;
    return new C;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void identify(Base& r) {
    // Try A
    try {
        A& a = dynamic_cast<A&>(r);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception& e) {}

    try {
        B& b = dynamic_cast<B&>(r);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception& e) {}

    try {
        C& c = dynamic_cast<C&>(r);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception& e) {}

    std::cout << "Unknown Type" << std::endl;
}
