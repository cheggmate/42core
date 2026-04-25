#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void  identify(Base* p);
void  identify(Base& r);

int main() {
    std::srand(std::time(NULL));

    std::cout << "--- Test 1: Random Generation and Identification ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Test [" << i + 1 << "]:" << std::endl;
        
        Base* randomInstance = generate();
        
        std::cout << "  Pointer ID:   ";
        identify(randomInstance);
        
        std::cout << "  Reference ID: ";
        identify(*randomInstance);
        
        delete randomInstance;
        std::cout << "-----------------------------------" << std::endl;
        usleep(100000); 
    }

    std::cout << "\n--- Test 2: Specific Manual Tests ---" << std::endl;
    
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();
    Base* unknown = NULL;

    std::cout << "Manual A: "; identify(a);
    std::cout << "Manual B: "; identify(b);
    std::cout << "Manual C: "; identify(c);
    std::cout << "NULL ptr: "; identify(unknown);

    delete a;
    delete b;
    delete c;

    return 0;
}
